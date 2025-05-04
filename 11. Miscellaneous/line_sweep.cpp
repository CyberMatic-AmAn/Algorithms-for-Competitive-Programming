#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Line Sweep for counting overlapping intervals
ll count_overlaps(vector<pair<ll, ll>>& intervals) {
    vector<pair<ll, int>> events;
    for (auto [l, r] : intervals) {
        events.emplace_back(l, 1);
        events.emplace_back(r + 1, -1);
    }
    sort(events.begin(), events.end());
    ll max_overlap = 0, curr = 0;
    for (auto [x, type] : events) {
        curr += type;
        max_overlap = max(max_overlap, curr);
    }
    return max_overlap;
}

int main() {
    fast_io();
    int n;
    cin >> n;
    vector<pair<ll, ll>> intervals(n);
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    cout << count_overlaps(intervals) << '\n';
    return 0;
}