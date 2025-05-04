#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Gaussian Elimination for system of linear equations
vector<double> gaussian_elimination(vector<vector<double>>& a, vector<double>& b) {
    int n = a.size();
    vector<vector<double>> aug(n, vector<double>(n + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) aug[i][j] = a[i][j];
        aug[i][n] = b[i];
    }
    for (int i = 0; i < n; ++i) {
        int pivot = i;
        for (int j = i + 1; j < n; ++j) {
            if (abs(aug[j][i]) > abs(aug[pivot][i])) pivot = j;
        }
        swap(aug[i], aug[pivot]);
        if (abs(aug[i][i]) < 1e-9) return {};
        for (int j = i + 1; j <= n; ++j) aug[i][j] /= aug[i][i];
        aug[i][i] = 1;
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                double c = aug[j][i];
                for (int k = i; k <= n; ++k) {
                    aug[j][k] -= c * aug[i][k];
                }
            }
        }
    }
    vector<double> x(n);
    for (int i = 0; i < n; ++i) x[i] = aug[i][n];
    return x;
}

int main() {
    fast_io();
    int n;
    cin >> n;
    vector<vector<double>> a(n, vector<double>(n));
    vector<double> b(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> a[i][j];
        cin >> b[i];
    }
    auto x = gaussian_elimination(a, b);
    if (x.empty()) {
        cout << "No solution\n";
    } else {
        for (double val : x) cout << fixed << setprecision(6) << val << ' ';
        cout << '\n';
    }
    return 0;
}