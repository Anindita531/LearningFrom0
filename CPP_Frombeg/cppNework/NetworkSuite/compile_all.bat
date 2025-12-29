@echo off
REM ===============================
REM Compile all C++ networking modules
REM ===============================

set SRC_DIR=src
set BUILD_DIR=build

REM Ensure build folder exists
if not exist %BUILD_DIR% mkdir %BUILD_DIR%

echo Compiling ping...
g++ %SRC_DIR%\ping.cpp -o %BUILD_DIR%\ping.exe -lws2_32 -liphlpapi -std=c++17 -mconsole

echo Compiling UDP Server...
g++ %SRC_DIR%\udp_server.cpp -o %BUILD_DIR%\udp_server.exe -lws2_32 -std=c++17 -mconsole

echo Compiling UDP Client...
g++ %SRC_DIR%\udp_client.cpp -o %BUILD_DIR%\udp_client.exe -lws2_32 -std=c++17 -mconsole

echo Compiling TCP Server...
g++ %SRC_DIR%\tcp_server.cpp -o %BUILD_DIR%\tcp_server.exe -lws2_32 -std=c++17 -mconsole

echo Compiling TCP Client...
g++ %SRC_DIR%\tcp_client.cpp -o %BUILD_DIR%\tcp_client.exe -lws2_32 -std=c++17 -mconsole

echo Compiling Traceroute...
g++ %SRC_DIR%\traceroute.cpp -o %BUILD_DIR%\traceroute.exe -lws2_32 -liphlpapi -std=c++17 -mconsole

echo Compiling DNS Lookup...
g++ %SRC_DIR%\dns_lookup.cpp -o %BUILD_DIR%\dns_lookup.exe -lws2_32 -std=c++17 -mconsole

echo ===============================
echo Compilation completed! All executables are in %BUILD_DIR%
echo ===============================
pause

