#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Disjoint Set Union for Kruskal
struct DSU {
    vector<int> par, rank;
    DSU(int n) : par(n + 1), rank(n + 1, 0) {
        for (int i = 1; i <= n; ++i) par[i] = i;
    }
    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (rank[u] < rank[v]) swap(u, v);
        par[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
        return true;
    }
};

// Kruskal’s Algorithm for Minimum Spanning Tree
ll kruskal(vector<tuple<int, int, ll>>& edges, int n) {
    sort(edges.begin(), edges.end(), [](auto a, auto b) {
        return get<2>(a) < get<2>(b);
    });
    DSU dsu(n);
    ll total_weight = 0;
    int edges_used = 0;
    for (auto [u, v, w] : edges) {
        if (dsu.unite(u, v)) {
            total_weight += w;
            edges_used++;
        }
    }
    return edges_used == n - 1 ? total_weight : -1;
}

int main() {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, ll>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    ll mst_weight = kruskal(edges, n);
    if (mst_weight == -1) cout << "No MST exists\n";
    else cout << mst_weight << '\n';
    return 0;
}