#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// DSU with rollback for dynamic connectivity
struct DSU {
    vector<int> par, rank;
    vector<pair<int, int>> history;
    int comps;

    DSU(int n) : par(n + 1), rank(n + 1, 0), comps(n) {
        for (int i = 1; i <= n; ++i) par[i] = i;
    }

    int find(int u) {
        while (u != par[u]) u = par[u];
        return u;
    }

    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (rank[u] < rank[v]) swap(u, v);
        history.emplace_back(v, par[v]);
        par[v] = u;
        if (rank[u] == rank[v]) {
            history.emplace_back(u, -rank[u]);
            rank[u]++;
        }
        comps--;
        return true;
    }

    void rollback(int steps) {
        while (steps-- && !history.empty()) {
            auto [u, val] = history.back();
            history.pop_back();
            if (val < 0) {
                rank[u] = -val;
            } else {
                par[u] = val;
                comps++;
            }
        }
    }
};

int main() {
    fast_io();
    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    while (q--) {
        string type;
        int u, v;
        cin >> type >> u >> v;
        if (type == "add") {
            dsu.unite(u, v);
        } else if (type == "remove") {
            dsu.rollback(1);
        } else {
            cout << (dsu.find(u) == dsu.find(v) ? "Connected" : "Not Connected") << '\n';
        }
    }
    return 0;
}