#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Pre-order traversal of tree
void pre_order(int u, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[u] = true;
    cout << u << ' ';
    for (int v : adj[u]) {
        if (!vis[v]) {
            pre_order(v, adj, vis);
        }
    }
}

int main() {
    fast_io();
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pre_order(1, adj, vis);
    cout << '\n';
    return 0;
}