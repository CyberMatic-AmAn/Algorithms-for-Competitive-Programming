#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Coordinate Compression
vector<int> coordinate_compression(vector<ll>& arr) {
    int n = arr.size();
    vector<ll> sorted = arr;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    vector<int> compressed(n);
    for (int i = 0; i < n; ++i) {
        compressed[i] = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin();
    }
    return compressed;
}

int main() {
    fast_io();
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    vector<int> compressed = coordinate_compression(arr);
    for (int x : compressed) cout << x << ' ';
    cout << '\n';
    return 0;
}