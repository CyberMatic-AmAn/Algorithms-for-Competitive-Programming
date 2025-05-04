#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Kosaraju's for Strongly Connected Components
void dfs1(int u, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& order) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs1(v, adj, vis, order);
        }
    }
    order.push_back(u);
}

void dfs2(int u, vector<vector<int>>& rev, vector<bool>& vis, vector<int>& component) {
    vis[u] = true;
    component.push_back(u);
    for (int v : rev[u]) {
        if (!vis[v]) {
            dfs2(v, rev, vis, component);
        }
    }
}

vector<vector<int>> kosaraju(int n, vector<vector<int>>& adj) {
    vector<bool> vis(n + 1, false);
    vector<int> order;
    vector<vector<int>> rev(n + 1);
    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            rev[v].push_back(u);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs1(i, adj, vis, order);
        }
    }
    vis.assign(n + 1, false);
    vector<vector<int>> sccs;
    reverse(order.begin(), order.end());
    for (int u : order) {
        if (!vis[u]) {
            vector<int> component;
            dfs2(u, rev, vis, component);
            sccs.push_back(component);
        }
    }
    return sccs;
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
    vector<vector<int>> sccs = kosaraju(n, adj);
    for (auto& scc : sccs) {
        for (int x : scc) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}