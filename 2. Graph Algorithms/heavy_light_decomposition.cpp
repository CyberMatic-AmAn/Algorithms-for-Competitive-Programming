#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Heavy-Light Decomposition
struct HLD {
    vector<vector<int>> adj;
    vector<int> par, sz, heavy, head, pos;
    vector<ll> seg;
    int n, cur_pos;

    HLD(int n) : n(n), adj(n + 1), par(n + 1), sz(n + 1), heavy(n + 1, -1), head(n + 1), pos(n + 1), seg(4 * n), cur_pos(0) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int p) {
        sz[u] = 1;
        int max_sz = 0;
        for (int v : adj[u]) {
            if (v != p) {
                par[v] = u;
                dfs(v, u);
                sz[u] += sz[v];
                if (sz[v] > max_sz) {
                    max_sz = sz[v];
                    heavy[u] = v;
                }
            }
        }
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = cur_pos++;
        if (heavy[u] != -1) decompose(heavy[u], h);
        for (int v : adj[u]) {
            if (v != par[u] && v != heavy[u]) {
                decompose(v, v);
            }
        }
    }

    void update(int idx, ll val, int node, int tl, int tr) {
        if (tl == tr) {
            seg[node] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (idx <= tm) update(idx, val, 2 * node + 1, tl, tm);
            else update(idx, val, 2 * node + 2, tm + 1, tr);
            seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
        }
    }

    ll query(int l, int r, int node, int tl, int tr) {
        if (l > tr || r < tl) return 0;
        if (l <= tl && r >= tr) return seg[node];
        int tm = (tl + tr) / 2;
        return query(l, r, 2 * node + 1, tl, tm) + query(l, r, 2 * node + 2, tm + 1, tr);
    }

    ll path_query(int u, int v) {
        ll res = 0;
        while (head[u] != head[v]) {
            if (pos[head[u]] > pos[head[v]]) swap(u, v);
            res += query(pos[head[v]], pos[v], 0, 0, n - 1);
            v = par[head[v]];
        }
        if (pos[u] > pos[v]) swap(u, v);
        res += query(pos[u], pos[v], 0, 0, n - 1);
        return res;
    }

    void init() {
        dfs(1, 0);
        decompose(1, 1);
    }
};

int main() {
    fast_io();
    int n, q;
    cin >> n >> q;
    HLD hld(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        hld.add_edge(u, v);
    }
    hld.init();
    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            hld.update(hld.pos[u], v, 0, 0, n - 1);
        } else {
            cout << hld.path_query(u, v) << '\n';
        }
    }
    return 0;
}