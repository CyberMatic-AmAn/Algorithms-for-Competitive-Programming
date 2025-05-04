#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Two pointers to find pairs with sum equal to target
vector<pair<int, int>> two_pointers(vector<int>& arr, int target) {
    vector<pair<int, int>> result;
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            result.push_back({arr[left], arr[right]});
            left++;
            right--;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return result;
}

int main() {
    fast_io();
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    auto pairs = two_pointers(arr, target);
    for (auto [x, y] : pairs) {
        cout << x << ' ' << y << '\n';
    }
    return 0;
}