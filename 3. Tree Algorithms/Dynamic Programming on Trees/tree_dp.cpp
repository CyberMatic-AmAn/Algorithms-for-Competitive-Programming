#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Tree DP: Maximum independent set
vector<vector<int>> adj;
vector<vector<ll>> dp;

void tree_dp(int u, int p) {
    dp[u][0] = 0; // Not include u
    dp[u][1] = 1; // Include u
    for (int v : adj[u]) {
        if (v != p) {
            tree_dp(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    }
}

int main() {
    fast_io();
    int n;
    cin >> n;
    adj.assign(n + 1, {});
    dp.assign(n + 1, vector<ll>(2, 0));
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    tree_dp(1, 0);
    cout << max(dp[1][0], dp[1][1]) << '\n';
    return 0;
}