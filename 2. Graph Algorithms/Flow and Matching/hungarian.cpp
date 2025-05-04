#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Hungarian Algorithm for weighted bipartite matching
ll hungarian(vector<vector<ll>>& cost, int n) {
    vector<ll> u(n + 1), v(n + 1), p(n + 1), way(n + 1);
    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        ll j0 = 0;
        vector<ll> minv(n + 1, LLONG_MAX);
        vector<char> used(n + 1, false);
        do {
            used[j0] = true;
            ll i0 = p[j0], delta = LLONG_MAX, j1;
            for (int j = 1; j <= n; ++j) {
                if (!used[j]) {
                    ll cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j <= n; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);
        do {
            ll j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    return -v[0];
}

int main() {
    fast_io();
    int n;
    cin >> n;
    vector<vector<ll>> cost(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }
    cout << hungarian(cost, n) << '\n';
    return 0;
}