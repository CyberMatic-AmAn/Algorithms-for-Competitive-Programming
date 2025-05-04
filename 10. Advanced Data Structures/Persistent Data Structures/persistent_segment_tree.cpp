#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Persistent Segment Tree for range sum queries
struct PersistentSegmentTree {
    struct Node {
        ll sum;
        int left, right;
        Node(ll s = 0, int l = -1, int r = -1) : sum(s), left(l), right(r) {}
    };
    vector<Node> nodes;
    vector<int> roots;
    int n;

    PersistentSegmentTree(int n) : n(n) {
        nodes.emplace_back();
        roots.push_back(0);
    }

    int build(int tl, int tr) {
        int v = nodes.size();
        nodes.emplace_back();
        if (tl != tr) {
            int tm = (tl + tr) / 2;
            nodes[v].left = build(tl, tm);
            nodes[v].right = build(tm + 1, tr);
        }
        return v;
    }

    int update(int v, int tl, int tr, int idx, ll val) {
        int u = nodes.size();
        nodes.push_back(nodes[v]);
        if (tl == tr) {
            nodes[u].sum += val;
            return u;
        }
        int tm = (tl + tr) / 2;
        if (idx <= tm) {
            nodes[u].left = update(nodes[v].left, tl, tm, idx, val);
        } else {
            nodes[u].right = update(nodes[v].right, tm + 1, tr, idx, val);
        }
        nodes[u].sum = nodes[nodes[u].left].sum + nodes[nodes[u].right].sum;
        return u;
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) return 0;
        if (l <= tl && r >= tr) return nodes[v].sum;
        int tm = (tl + tr) / 2;
        return query(nodes[v].left, tl, tm, l, r) + query(nodes[v].right, tm + 1, tr, l, r);
    }

    void update_version(int idx, ll val) {
        roots.push_back(update(roots.back(), 0, n - 1, idx, val));
    }

    ll query_version(int version, int l, int r) {
        return query(roots[version], 0, n - 1, l, r);
    }
};

int main() {
    fast_io();
    int n, q;
    cin >> n >> q;
    PersistentSegmentTree pst(n);
    for (int i = 0; i < n; ++i) {
        ll val;
        cin >> val;
        pst.update_version(i, val);
    }
    while (q--) {
        int type, version, l, r;
        cin >> type;
        if (type == 1) {
            cin >> l >> version;
            ll val;
            cin >> val;
            pst.update_version(l, val);
        } else {
            cin >> version >> l >> r;
            cout << pst.query_version(version, l, r) << '\n';
        }
    }
    return 0;
}