#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Compute prefix sums and answer range sum queries
void prefix_sum(vector<ll>& arr, vector<ll>& ps) {
    ps[0] = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        ps[i] = ps[i - 1] + arr[i];
    }
}

// Get sum of range [l, r] (0-based indexing)
ll range_sum(vector<ll>& ps, int l, int r) {
    if (l == 0) return ps[r];
    return ps[r] - ps[l - 1];
}

int main() {
    fast_io();
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n), ps(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    prefix_sum(arr, ps);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << range_sum(ps, l - 1, r - 1) << '\n'; // 1-based to 0-based
    }
    return 0;
}