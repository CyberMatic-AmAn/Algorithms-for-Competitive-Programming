#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Binary Indexed Tree for range sum queries
struct FenwickTree {
    vector<ll> bit;
    int n;
    FenwickTree(int n) : n(n), bit(n + 1, 0) {}
    void update(int idx, ll delta) {
        for (++idx; idx <= n; idx += idx & -idx) {
            bit[idx] += delta;
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

int main() {
    fast_io();
    int n, q;
    cin >> n >> q;
    FenwickTree ft(n);
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        ft.update(i, arr[i]);
    }
    while (q--) {
        int type, l, r;
        cin >> type >> l;
        if (type == 1) {
            ll val;
            cin >> val;
            ft.update(l - 1, val - arr[l - 1]);
            arr[l - 1] = val;
        } else {
            cin >> r;
            cout << ft.query_range(l - 1, r - 1) << '\n';
        }
    }
    return 0;
}