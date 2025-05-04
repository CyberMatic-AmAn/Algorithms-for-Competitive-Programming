#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Longest Increasing Subsequence (O(n log n))
int lis(vector<int>& arr) {
    vector<int> tail;
    for (int x : arr) {
        if (tail.empty() || x > tail.back()) {
            tail.push_back(x);
        } else {
            *lower_bound(tail.begin(), tail.end(), x) = x;
        }
    }
    return tail.size();
}

int main() {
    fast_io();
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << lis(arr) << '\n';
    return 0;
}