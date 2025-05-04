#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Activity selection
int activity_selection(vector<pair<int, int>>& activities) {
    sort(activities.begin(), activities.end(), [](auto a, auto b) {
        return a.second < b.second;
    });
    int count = 1, last_end = activities[0].second;
    for (int i = 1; i < activities.size(); ++i) {
        if (activities[i].first >= last_end) {
            count++;
            last_end = activities[i].second;
        }
    }
    return count;
}

int main() {
    fast_io();
    int n;
    cin >> n;
    vector<pair<int, int>> activities(n);
    for (int i = 0; i < n; ++i) cin >> activities[i].first >> activities[i].second;
    cout << activity_selection(activities) << '\n';
    return 0;
}