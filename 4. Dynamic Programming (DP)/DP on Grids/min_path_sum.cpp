#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Minimum Path Sum in a grid
ll min_path_sum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<ll>> dp(m, vector<ll>(n, LLONG_MAX));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    fast_io();
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    cout << min_path_sum(grid) << '\n';
    return 0;
}