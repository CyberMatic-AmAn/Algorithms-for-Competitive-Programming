#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Count unique paths in a grid
int unique_paths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    fast_io();
    int m, n;
    cin >> m >> n;
    cout << unique_paths(m, n) << '\n';
    return 0;
}