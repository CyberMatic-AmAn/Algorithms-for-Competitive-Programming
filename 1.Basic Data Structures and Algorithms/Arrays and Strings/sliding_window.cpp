#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Sliding window to find max sum of k consecutive elements
ll sliding_window(vector<int>& arr, int k) {
    ll max_sum = 0, curr_sum = 0;
    for (int i = 0; i < k; ++i) curr_sum += arr[i];
    max_sum = curr_sum;
    for (int i = k; i < arr.size(); ++i) {
        curr_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}

int main() {
    fast_io();
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << sliding_window(arr, k) << '\n';
    return 0;
}