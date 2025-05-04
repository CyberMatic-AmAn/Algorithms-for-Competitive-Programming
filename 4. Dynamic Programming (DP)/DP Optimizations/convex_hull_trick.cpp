#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Convex Hull Trick for line queries
struct ConvexHullTrick {
    vector<ll> m, b;
    vector<double> x;

    void add_line(ll slope, ll intercept) {
        while (!x.empty() && (b.back() - intercept) / (double)(slope - m.back()) <= x.back()) {
            m.pop_back();
            b.pop_back();
            x.pop_back();
        }
        if (m.empty()) {
            m.push_back(slope);
            b.push_back(intercept);
        } else {
            x.push_back((b.back() - intercept) / (double)(slope - m.back()));
            m.push_back(slope);
            b.push_back(intercept);
        }
    }

    ll query(ll x_val) {
        int idx = lower_bound(x.begin(), x.end(), x_val) - x.begin();
        return m[idx] * x_val + b[idx];
    }
};

int main() {
    fast_io();
    int n;
    cin >> n;
    ConvexHullTrick cht;
    for (int i = 0; i < n; ++i) {
        ll m, b;
        cin >> m >> b;
        cht.add_line(m, b);
    }
    int q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        cout << cht.query(x) << '\n';
    }
    return 0;
}