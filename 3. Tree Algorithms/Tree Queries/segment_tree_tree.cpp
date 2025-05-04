#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Segment Tree for subtree sum queries
struct SegmentTree {
    vector<ll> tree;
    int n;
    SegmentTree(int sz) : n(sz), tree(4 * sz, 0) {}
    void update(int idx, ll val, int node, int tl, int tr) {
        if (tl == tr) {
            tree[node] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (idx <= tm) update(idx, val, 2 * node + 1, tl, tm);
            else update(idx, val, 2 * node + 2, tm + 1, tr);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    ll query(int l, int r, int node, int tl, int tr) {
        if (l > tr || r < tl) return 0;
        if (l <= tl && r >= tr) return tree[node];
        int tm = (tl + tr) / 2;
        return query(l, r, 2 * node + 1, tl, tm) + query(l, r, 2 * node + 2, tm + 1, tr);
    }
};

// Euler tour for subtree queries
vector<int> in, out;
vector<vector<int>> adj;
int timer = 0;

void euler_tour(int u, int p) {
    in[u] = timer++;
    for (int v : adj[u]) {
        if (v != p) euler_tour(v, u);
    }
    out[u] = timer - 1;
}

int main() {
    fast_io();
    int n, q;
    cin >> n >> q;
    adj.assign(n + 1, {});
    in.assign(n + 1, 0);
    out.assign(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    euler_tour(1, 0);
    SegmentTree seg(n);
    while (q--) {
        int type, u;
        cin >> type >> u;
        if (type == 1) {
            ll val;
            cin >> val;
            seg.update(in[u], val, 0, 0, n - 1);
        } else {
            cout << seg.query(in[u], out[u], 0, 0, n - 1) << '\n';
        }
    }
    return 0;
}