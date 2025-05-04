#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Fractional Knapsack
double fractional_knapsack(vector<pair<ll, ll>>& items, ll W) {
    sort(items.begin(), items.end(), [](auto a, auto b) {
        return (double)a.first / a.second > (double)b.first / b.second;
    });
    double total_value = 0;
    ll rem_weight = W;
    for (auto [v, w] : items) {
        if (rem_weight >= w) {
            total_value += v;
            rem_weight -= w;
        } else {
            total_value += (double)v * rem_weight / w;
            break;
        }
    }
    return total_value;
}

int main() {
    fast_io();
    int n;
    ll W;
    cin >> n >> W;
    vector<pair<ll, ll>> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].first >> items[i].second; // Value, weight
    }
    cout << fixed << setprecision(6) << fractional_knapsack(items, W) << '\n';
    return 0;
}