#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Topological Sort using DFS
void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& order) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v, adj, vis, order);
        }
    }
    order.push_back(u);
}

vector<int> topological_sort(vector<vector<int>>& adj, int n) {
    vector<bool> vis(n + 1, false);
    vector<int> order;
    for (int u = 1; u <= n; ++u) {
        if (!vis[u]) {
            dfs(u, adj, vis, order);
        }
    }
    reverse(order.begin(), order.end());
    return order;
}

int main() {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> order = topological_sort(adj, n);
    if (order.size() != n) {
        cout << "Graph has a cycle\n";
    } else {
        for (int u : order) {
            cout << u << ' ';
        }
        cout << '\n';
    }
    return 0;
}