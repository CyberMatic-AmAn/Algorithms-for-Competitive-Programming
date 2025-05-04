#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Traveling Salesman Problem with bitmask DP
ll tsp(vector<vector<ll>>& dist, int n) {
    vector<vector<ll>> dp(1 << n, vector<ll>(n, LLONG_MAX));
    dp[1][0] = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            if (mask & (1 << u)) {
                for (int v = 0; v < n; ++v) {
                    if (!(mask & (1 << v))) {
                        ll new_mask = mask | (1 << v);
                        if (dp[mask][u] != LLONG_MAX && dist[u][v] != LLONG_MAX) {
                            dp[new_mask][v] = min(dp[new_mask][v], dp[mask][u] + dist[u][v]);
                        }
                    }
                }
            }
        }
    }
    ll ans = LLONG_MAX;
    for (int u = 1; u < n; ++u) {
        if (dp[(1 << n) - 1][u] != LLONG_MAX && dist[u][0] != LLONG_MAX) {
            ans = min(ans, dp[(1 << n) - 1][u] + dist[u][0]);
        }
    }
    return ans == LLONG_MAX ? -1 : ans;
}

int main() {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, LLONG_MAX));
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
    cout << tsp(dist, n) << '\n';
    return 0;
}