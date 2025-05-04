#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Disjoint Set Union for Kruskal's
struct DSU {
    vector<int> par, sz;
    DSU(int n) : par(n + 1), sz(n + 1, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int u) {
        if (par[u] != u) par[u] = find(par[u]);
        return par[u];
    }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

// Kruskal's for Minimum Spanning Tree
ll kruskal(vector<tuple<ll, int, int>>& edges, int n) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    ll mst_weight = 0;
    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            mst_weight += w;
        }
    }
    return mst_weight;
}

int main() {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<tuple<ll, int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.emplace_back(w, u, v);
    }
    cout << kruskal(edges, n) << '\n';
    return 0;
}