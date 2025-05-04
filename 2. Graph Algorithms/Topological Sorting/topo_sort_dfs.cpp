#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// DFS-based topological sort
void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& topo) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v, adj, vis, topo);
        }
    }
    topo.push_back(u);
}

vector<int> topo_sort(int n, vector<vector<int>>& adj) {
    vector<bool> vis(n + 1, false);
    vector<int> topo;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i, adj, vis, topo);
        }
    }
    reverse(topo.begin(), topo.end());
    return topo;
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
    vector<int> topo = topo_sort(n, adj);
    for (int x : topo) cout << x << ' ';
    cout << '\n';
    return 0;
}