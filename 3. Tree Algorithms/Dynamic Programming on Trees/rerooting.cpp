#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Rerooting: Compute answer for each node as root
struct Rerooting {
    vector<vector<int>> adj;
    vector<ll> dp, ans;
    int n;

    Rerooting(int n) : n(n), adj(n + 1), dp(n + 1), ans(n + 1) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs1(int u, int p) {
        dp[u] = 0; // Example: Sum of distances
        for (int v : adj[u]) {
            if (v != p) {
                dfs1(v, u);
                dp[u] += dp[v] + 1; // Add distance to child
            }
        }
    }

    void dfs2(int u, int p, ll up) {
        ans[u] = dp[u] + (p ? up + 1 : 0);
        vector<ll> prefix, suffix;
        for (int v : adj[u]) {
            if (v != p) {
                prefix.push_back(dp[v] + 1);
                suffix.push_back(dp[v] + 1);
            }
        }
        int m = prefix.size();
        for (int i = 1; i < m; ++i) prefix[i] += prefix[i - 1];
        for (int i = m - 2; i >= 0; --i) suffix[i] += suffix[i + 1];
        int idx = 0;
        for (int v : adj[u]) {
            if (v != p) {
                ll new_up = (p ? up + 1 : 0) + (idx > 0 ? prefix[idx - 1] : 0) + (idx < m - 1 ? suffix[idx + 1] : 0);
                dfs2(v, u, new_up);
                idx++;
            }
        }
    }

    void solve() {
        dfs1(1, 0);
        dfs2(1, 0, 0);
    }
};

int main() {
    fast_io();
    int n;
    cin >> n;
    Rerooting rr(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        rr.add_edge(u, v);
    }
    rr.solve();
    for (int i = 1; i <= n; ++i) {
        cout << rr.ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}