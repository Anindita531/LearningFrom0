#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

// Function to compute the Square-Free Part (SFP) of a number x
// The SFP is the product of all prime factors that appear an odd number of times.
ll get_sfp(ll x) {
    if (x == 0) return 0;
    ll sfp = 1;
    ll temp = x;

    for (ll p = 2; p * p <= temp; ++p) {
        if (temp % p == 0) {
            int count = 0;
            while (temp % p == 0) {
                temp /= p;
                count++;
            }
            if (count % 2 != 0) {
                sfp *= p;
            }
        }
    }
    // If temp > 1, the remaining temp is a prime factor itself with exponent 1
    if (temp > 1) {
        sfp *= temp;
    }
    return sfp;
}

// Global variable to store the final sum
ll total_beauty_sum = 0;

/**
 * DFS function to calculate the frequency map (SFP counts) for the subtree of u
 * and update the total_beauty_sum.
 * @param u The current node (1-indexed).
 * @param adj The adjacency list of the tree.
 * @param b The pre-calculated SFP array (1-indexed).
 * @return The frequency map of SFP values in the subtree of u.
 */
map<ll, int> DFS(int u, const vector<vector<int>>& adj, const vector<ll>& b) {
    // M_u: Map of SFP value -> count of nodes with that SFP in u's subtree
    map<ll, int> M_u;
    M_u[b[u]] = 1; // Node u itself contributes to its SFP count

    for (int v : adj[u]) {
        map<ll, int> M_v = DFS(v, adj, b);
        
        // DSU-on-Tree (Small-to-Large) Optimization: Merge smaller map into larger
        if (M_v.size() > M_u.size()) {
            swap(M_u, M_v);
        }

        // Merge M_v into M_u
        for (auto const& [K, C_v] : M_v) {
            // Note: We don't need to calculate pairs during the merge, 
            // as we calculate the total pairs (beauty) once M_u is complete.
            M_u[K] += C_v;
        }
    }

    // After processing all children, M_u contains the final counts for u's subtree.
    
    // Calculate beauty(u)
    ll beauty_u = 0;
    for (auto const& [K, C] : M_u) {
        // Number of pairs for SFP K is C * (C - 1) / 2
        // Since C <= 10^5, C * (C - 1) fits in ll (long long).
        // The modulo operation is only needed for the final sum.
        ll pairs_with_K = ((ll)C * (C - 1) / 2) % MOD;
        beauty_u = (beauty_u + pairs_with_K) % MOD;
    }

    total_beauty_sum = (total_beauty_sum + beauty_u) % MOD;

    return M_u;
}

/**
 * Main function to solve the Tree Beauty Problem.
 * @param n The size of the tree.
 * @param par The parent array (par[0] is root indicator).
 * @param a The values written on the nodes.
 * @return The sum of beauty of each node modulo 10^9 + 7.
 */
int get_ans(int n, const vector<int>& par, const vector<int>& a) {
    if (n == 0) return 0;

    // 1. Build Adjacency List (1-indexed)
    // The parent array par is 0-indexed in the input format but describes 1-indexed nodes.
    // par[i] is the parent of node i+1 (for i=0 to n-1)
    // Node 1 is the root, par[0] = 0.
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; ++i) { // par[0] is for node 1
        int parent_node = par[i];
        int child_node = i + 1;
        if (parent_node != 0) {
            adj[parent_node].push_back(child_node);
        }
    }

    // 2. Pre-calculate SFP for all node values (1-indexed b array)
    // b[i] = SFP(a[i-1])
    vector<ll> b(n + 1);
    for (int i = 1; i <= n; ++i) {
        b[i] = get_sfp(a[i - 1]);
    }

    // 3. Perform DFS from the root (node 1)
    total_beauty_sum = 0;
    DFS(1, adj, b);

    return total_beauty_sum;
}


// Example Usage for Sample 1:
// Input:
// 5
// 0 1 1 2 2
// 2 3 6 12 27
int main() {
    int n = 5;
    vector<int> par = {0, 1, 1, 2, 2}; // 0-indexed: par[i] is parent of node i+1
    vector<int> a = {2, 3, 6, 12, 27}; // 0-indexed: a[i] is value of node i+1

    int result = get_ans(n, par, a);
    // Expected Output: 6
    cout << "Result: " << result << endl; // Output: 6

    return 0;
}
