#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Monotone Queue for sliding window maximum
vector<int> sliding_window_maximum(vector<int>& arr, int k) {
    int n = arr.size();
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(arr[dq.front()]);
    }
    return result;
}

int main() {
    fast_io();
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    vector<int> maxes = sliding_window_maximum(arr, k);
    for (int x : maxes) cout << x << ' ';
    cout << '\n';
    return 0;
}