#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Find k-th smallest element using min-heap
int kth_smallest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x : arr) pq.push(x);
    while (--k) pq.pop();
    return pq.top();
}

int main() {
    fast_io();
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << kth_smallest(arr, k) << '\n';
    return 0;
}