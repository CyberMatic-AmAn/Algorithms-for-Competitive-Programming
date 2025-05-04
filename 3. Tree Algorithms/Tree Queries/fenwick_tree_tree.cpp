#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Fenwick Tree for subtree queries
struct Fenwick {
    vector<ll> bit;
    int n;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void update(int idx, ll val) {
        for (++idx; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }
    ll query(int idx) {
        ll sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }
    ll query_range(int l, int r) {
        return query(r) - query(l - 1);
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
    Fenwick fen(n);
    while (q--) {
        int type, u;
        cin >> type >> u;
        if (type == 1) {
            ll val;
            cin >> val;
            fen.update(in[u], val);
        } else {
            cout << fen.query_range(in[u], out[u]) << '\n';
        }
    }
    return 0;
}