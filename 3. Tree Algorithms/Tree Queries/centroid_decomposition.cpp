#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Centroid Decomposition
struct CentroidDecomposition {
    vector<vector<int>> adj;
    vector<int> sz, par;
    vector<bool> vis;
    int n;

    CentroidDecomposition(int n) : n(n), adj(n + 1), sz(n + 1), par(n + 1), vis(n + 1, false) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int get_size(int u, int p) {
        sz[u] = 1;
        for (int v : adj[u]) {
            if (v != p && !vis[v]) {
                sz[u] += get_size(v, u);
            }
        }
        return sz[u];
    }

    int find_centroid(int u, int p, int tree_size) {
        for (int v : adj[u]) {
            if (v != p && !vis[v] && sz[v] * 2 > tree_size) {
                return find_centroid(v, u, tree_size);
            }
        }
        return u;
    }

    void decompose(int u, int p) {
        get_size(u, -1);
        int centroid = find_centroid(u, -1, sz[u]);
        vis[centroid] = true;
        par[centroid] = p;
        for (int v : adj[centroid]) {
            if (!vis[v]) {
                decompose(v, centroid);
            }
        }
    }

    // Example: Update and query distance to closest marked node
    vector<int> dist;
    void update(int u) {
        dist[u] = 0;
        // Add logic to update distances in centroid tree
    }

    int query(int u) {
        return dist[u]; // Modify for actual query logic
    }
};

int main() {
    fast_io();
    int n, q;
    cin >> n >> q;
    CentroidDecomposition cd(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        cd.add_edge(u, v);
    }
    cd.decompose(1, 0);
    while (q--) {
        int type, u;
        cin >> type >> u;
        if (type == 1) {
            cd.update(u);
        } else {
            cout << cd.query(u) << '\n';
        }
    }
    return 0;
}