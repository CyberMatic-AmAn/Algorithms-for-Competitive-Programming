#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Matrix Exponentiation
struct Matrix {
    vector<vector<ll>> mat;
    int n;
    ll mod;
    Matrix(int n, ll mod) : n(n), mod(mod), mat(n, vector<ll>(n, 0)) {}
    Matrix operator*(const Matrix& other) const {
        Matrix res(n, mod);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % mod;
                }
            }
        }
        return res;
    }
};

Matrix mod_pow(Matrix base, ll exp, ll mod) {
    Matrix res(base.n, mod);
    for (int i = 0; i < base.n; ++i) res.mat[i][i] = 1;
    while (exp > 0) {
        if (exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

int main() {
    fast_io();
    int n;
    ll exp, mod;
    cin >> n >> exp >> mod;
    Matrix mat(n, mod);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat.mat[i][j];
        }
    }
    mat = mod_pow(mat, exp, mod);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mat.mat[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}