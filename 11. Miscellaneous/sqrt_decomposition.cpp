#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Square Root Decomposition for range sum queries
struct SqrtDecomposition {
    vector<ll> arr, blocks;
    int n, block_size;

    SqrtDecomposition(vector<ll>& a) : n(a.size()), arr(a) {
        block_size = sqrt(n) + 1;
        blocks.assign((n + block_size - 1) / block_size, 0);
        for (int i = 0; i < n; ++i) {
            blocks[i / block_size] += arr[i];
        }
    }

    void update(int idx, ll val) {
        ll delta = val - arr[idx];
        arr[idx] = val;
        blocks[idx / block_size] += delta;
    }

    ll query(int l, int r) {
        ll sum = 0;
        int start_block = l / block_size, end_block = r / block_size;
        if (start_block == end_block) {
            for (int i = l; i <= r; ++i) sum += arr[i];
        } else {
            for (int i = l; i < (start_block + 1) * block_size; ++i) sum += arr[i];
            for (int i = start_block + 1; i < end_block; ++i) sum += blocks[i];
            for (int i = end_block * block_size; i <= r; ++i) sum += arr[i];
        }
        return sum;
    }
};

int main() {
    fast_io();
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    SqrtDecomposition sqd(arr);
    while (q--) {
        int type, l, r;
        cin >> type >> l;
        if (type == 1) {
            ll val;
            cin >> val;
            sqd.update(l - 1, val);
        } else {
            cin >> r;
            cout << sqd.query(l - 1, r - 1) << '\n';
        }
    }
    return 0;
}