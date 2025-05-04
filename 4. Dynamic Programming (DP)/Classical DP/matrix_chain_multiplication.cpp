#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Matrix Chain Multiplication
ll matrix_chain_multiplication(vector<int>& dims) {
    int n = dims.size() - 1;
    vector<vector<ll>> dp(n, vector<ll>(n, LLONG_MAX));
    for (int i = 0; i < n; ++i) dp[i][i] = 0;
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j; ++k) {
                ll cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    fast_io();
    int n;
    cin >> n;
    vector<int> dims(n);
    for (int i = 0; i < n; ++i) cin >> dims[i];
    cout << matrix_chain_multiplication(dims) << '\n';
    return 0;
}