#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Kadane’s Algorithm for maximum subarray sum
ll kadane(vector<int>& arr) {
    ll max_so_far = LLONG_MIN, max_ending_here = 0;
    for (int x : arr) {
        max_ending_here += x;
        max_so_far = max(max_so_far, max_ending_here);
        if (max_ending_here < 0) max_ending_here = 0;
    }
    return max_so_far;
}

int main() {
    fast_io();
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << kadane(arr) << '\n';
    return 0;
}