#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Meet in the Middle for subset sum
ll meet_in_middle(vector<ll>& arr, ll target) {
    int n = arr.size();
    int half = n / 2;
    vector<ll> left, right;
    // Generate all subset sums for first half
    for (int mask = 0; mask < (1 << half); ++mask) {
        ll sum = 0;
        for (int i = 0; i < half; ++i) {
            if (mask & (1 << i)) sum += arr[i];
        }
        left.push_back(sum);
    }
    // Generate all subset sums for second half
    for (int mask = 0; mask < (1 << (n - half)); ++mask) {
        ll sum = 0;
        for (int i = 0; i < n - half; ++i) {
            if (mask & (1 << i)) sum += arr[half + i];
        }
        right.push_back(sum);
    }
    sort(right.begin(), right.end());
    ll count = 0;
    for (ll x : left) {
        auto range = equal_range(right.begin(), right.end(), target - x);
        count += range.second - range.first;
    }
    return count;
}

int main() {
    fast_io();
    int n;
    ll target;
    cin >> n >> target;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << meet_in_middle(arr, target) << '\n';
    return 0;
}