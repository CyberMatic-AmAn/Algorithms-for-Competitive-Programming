#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Example check function (modify as needed)
bool check(vector<ll>& arr, ll mid, ll k) {
    ll count = 0;
    for (ll x : arr) count += mid / x;
    return count >= k;
}

// Binary search on answer
ll binary_search_answer(vector<ll>& arr, ll k) {
    ll lo = 1, hi = 1e18, ans = -1;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(arr, mid, k)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    fast_io();
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << binary_search_answer(arr, k) << '\n';
    return 0;
}