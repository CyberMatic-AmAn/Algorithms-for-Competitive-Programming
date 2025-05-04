#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// LCA using binary lifting
const int LG = 20;
vector<vector<int>> up, adj;
vector<int> depth;

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            up[v][0] = u;
            for (int j = 1; j < LG; ++j) {
                up[v][j] = up[up[v][j - 1]][j - 1];
            }
            dfs(v, u);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int j = LG - 1; j >= 0; --j) {
        if (depth[u] - (1 << j) >= depth[v]) {
            u = up[u][j];
        }
    }
    if (u == v) return u;
    for (int j = LG - 1; j >= 0; --j) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

int main() {
    fast_io();
    int n, q;
    cin >> n >> q;
    adj.assign(n + 1, {});
    up.assign(n + 1, vector<int>(LG));
    depth.assign(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
    return 0;
}