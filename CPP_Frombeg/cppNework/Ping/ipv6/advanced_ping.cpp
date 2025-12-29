#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <atomic>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <sstream>   // ? Fix for istringstream
#include <cmath>     // ? Fix for round()

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <icmpapi.h>
#include <windows.h>


using namespace std;
using namespace std::chrono;

static atomic<bool> keep_running(true);

// Called when Ctrl+C is pressed; sets flag so main loop can finish and print stats.
BOOL WINAPI consoleHandler(DWORD signal) {
    if (signal == CTRL_C_EVENT || signal == CTRL_CLOSE_EVENT) {
        keep_running = false;
        return TRUE; // we've handled it
    }
    return FALSE;
}

struct Stats {
    int sent = 0;
    int recv = 0;
    long long sum_ms = 0;
    double min_ms = -1;
    double max_ms = -1;

    void add(double ms) {
        sent++;
        if (ms >= 0) {
            recv++;
            sum_ms += (long long)ms;
            if (min_ms < 0 || ms < min_ms) min_ms = ms;
            if (max_ms < 0 || ms > max_ms) max_ms = ms;
        }
    }

    double avg() const { return recv ? (double)sum_ms / recv : 0.0; }
    int loss_percent() const { return sent ? (int)round((1.0 - (double)recv / sent) * 100.0) : 0; }
};

/// Helper: try to parse "time=XXms" from a line (IPv6 popen output parsing)
double parse_time_ms_from_ping_line(const char* line) {
    // search for "time=" or "time<"
    const char* p = strstr(line, "time=");
    if (!p) p = strstr(line, "time<"); // sometimes "time<1ms"
    if (!p) return -1;
    p += strlen("time=");
    // read number (may be like "24ms" or "<1ms")
    if (*p == '<') { // time<1ms -> treat as 0.5 ms
        p++;
        // skip digits if any
        double v = 0.5;
        return v;
    }
    double val = 0.0;
    if (sscanf(p, "%lf", &val) == 1) {
        return val;
    }
    return -1;
}

int ping_ipv4_once(const char* ipStr, int timeout_ms, double &rtt_ms) {
    // Create ICMP handle and send echo
    HANDLE hIcmp = IcmpCreateFile();
    if (hIcmp == INVALID_HANDLE_VALUE) {
        return -1; // failure
    }

    char sendData[32] = "ICMP Ping Test";
    DWORD replySize = sizeof(ICMP_ECHO_REPLY) + sizeof(sendData) + 8;
    LPVOID replyBuffer = malloc(replySize);
    if (!replyBuffer) {
        IcmpCloseHandle(hIcmp);
        return -1;
    }

    unsigned long ip = inet_addr(ipStr);
    if (ip == INADDR_NONE) {
        free(replyBuffer);
        IcmpCloseHandle(hIcmp);
        return -1;
    }

    DWORD ret = IcmpSendEcho(hIcmp, ip, sendData, (WORD)sizeof(sendData), NULL, replyBuffer, replySize, timeout_ms);

    if (ret != 0) {
        PICMP_ECHO_REPLY echo = (PICMP_ECHO_REPLY)replyBuffer;
        rtt_ms = (double)echo->RoundTripTime;
        free(replyBuffer);
        IcmpCloseHandle(hIcmp);
        return 0; // success
    } else {
        rtt_ms = -1;
        free(replyBuffer);
        IcmpCloseHandle(hIcmp);
        return 1; // timeout / no reply
    }
}

int ping_ipv6_once_popen(const string &host, int timeout_ms, double &rtt_ms) {
    // Use Windows ping for IPv6 and capture output for one ping (-n 1 -6)
    // We set a small timeout in the command, but parsing might be simpler to rely on output.
    string cmd = "ping -n 1 -w " + to_string(timeout_ms) + " -6 " + host + " 2>&1";
    FILE *pipe = _popen(cmd.c_str(), "r");
    if (!pipe) return -1;

    char line[512];
    double parsed_time = -1;
    while (fgets(line, sizeof(line), pipe)) {
        // Example relevant line: "Reply from 2404:...: time=24ms"
        double t = parse_time_ms_from_ping_line(line);
        if (t >= 0) parsed_time = t;
    }
    int rc = _pclose(pipe);
    rtt_ms = parsed_time;
    // rc == 0 means ping command returned success; if parsed_time >=0 we consider success
    return (parsed_time >= 0) ? 0 : 1;
}

int main() {
    // install ctrl-c handler
    SetConsoleCtrlHandler(consoleHandler, TRUE);

    // Initialize Winsock (needed for getaddrinfo / inet_ntop)
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        cerr << "WSAStartup failed." << endl;
        return 1;
    }

    cout << "Advanced Ping Tool (IPv4 + IPv6 support)\n";
    cout << "Enter hostname or IP (prefix with [v6:] to force IPv6), optionally with count (e.g. example.com 5):\n";
    cout << "If you enter a single hostname only, it pings continuously until Ctrl+C.\n";
    cout << "Examples:\n  www.google.com\n  www.google.com 4\n  [v6:]www.google.com\n\n";

    string line;
    while (true) {
        cout << "target> ";
        if (!std::getline(cin, line)) break;
        if (line.size() == 0) continue;
        if (line == "exit") break;

        // parse input: possible "host count"
        string host;
        int count = 0; // 0 => continuous until Ctrl+C
        {
            // simple parse
            std::istringstream iss(line);
            iss >> host;
            if (!(iss >> count)) count = 0;
        }

        bool force_v6 = false;
        if (host.rfind("[v6:]", 0) == 0) { // starts with [v6:]
            force_v6 = true;
            host = host.substr(5);
        }

        // Resolve host addresses (we'll try IPv4 unless forced v6)
        addrinfo hints = {};
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;
        hints.ai_family = force_v6 ? AF_INET6 : AF_UNSPEC; // try both unless forced v6

        addrinfo *res = nullptr;
        int ga = getaddrinfo(host.c_str(), nullptr, &hints, &res);
        if (ga != 0 || !res) {
            cerr << "Unable to resolve host: " << host << "\n";
            if (res) freeaddrinfo(res);
            continue;
        }

        // pick addr: prefer IPv4 if available (unless forced v6)
        addrinfo *use = nullptr;
        if (!force_v6) {
            for (addrinfo *p = res; p; p = p->ai_next) {
                if (p->ai_family == AF_INET) { use = p; break; }
            }
            if (!use) use = res; // use whatever (likely IPv6)
        } else {
            use = res; // first should be IPv6
        }

        bool is_ipv6 = (use->ai_family == AF_INET6);
        char ipbuf[INET6_ADDRSTRLEN] = {0};
        if (is_ipv6) {
            sockaddr_in6 *a6 = (sockaddr_in6*)use->ai_addr;
            inet_ntop(AF_INET6, &(a6->sin6_addr), ipbuf, sizeof(ipbuf));
        } else {
            sockaddr_in *a4 = (sockaddr_in*)use->ai_addr;
            inet_ntop(AF_INET, &(a4->sin_addr), ipbuf, sizeof(ipbuf));
        }

        cout << "\nPinging " << host << " [" << ipbuf << "]\n";

        Stats stats;
        int sent = 0;
        int iter = 0;
        // perform pings (count times or continuous)
        while (keep_running && (count == 0 ? true : iter < count)) {
            iter++;
            double rtt = -1;

            if (!is_ipv6) {
                // IPv4 path using IcmpSendEcho
                int rc = ping_ipv4_once(ipbuf, 1000, rtt);
                stats.add(rtt);
                sent++;
                if (rc == 0) {
                    cout << "Reply from " << ipbuf << ": bytes=32 time=" << (rtt >= 0 ? rtt : -1) << "ms\n";
                } else if (rc == 1) {
                    cout << "Request timed out.\n";
                } else {
                    cout << "Ping error (ICMP API)!\n";
                }
            } else {
                // IPv6 path using Windows ping -6 (captures output)
                int rc = ping_ipv6_once_popen(host, 1000, rtt);
                stats.add(rtt);
                sent++;
                if (rc == 0 && rtt >= 0) {
                    cout << "Reply from " << ipbuf << ": time=" << rtt << "ms\n";
                } else {
                    cout << "Request timed out or no reply (IPv6 path).\n";
                }
            }

            // if user had provided a finite count and we've completed, break
            if (count != 0 && iter >= count) break;

            // sleep 1 second between pings unless we're stopping
            for (int s=0; s<10 && keep_running; ++s) Sleep(100); // 1 second total, check flag
        }

        // Print statistics summary
        cout << "\n--- " << host << " ping statistics ---\n";
        cout << stats.sent << " packets transmitted, " << stats.recv << " received, " << stats.loss_percent() << "% packet loss\n";
        if (stats.recv > 0) {
            cout << "rtt min/avg/max = " << stats.min_ms << " / " << stats.avg() << " / " << stats.max_ms << " ms\n";
        }
        cout << endl;

        freeaddrinfo(res);

        // If Ctrl+C was pressed, user wants to quit the overall program
        if (!keep_running) break;
    }

    WSACleanup();
    cout << "Exiting.\n";
    return 0;
}

