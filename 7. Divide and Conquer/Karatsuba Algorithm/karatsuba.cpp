#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Karatsuba Multiplication
vector<ll> karatsuba(vector<ll>& a, vector<ll>& b) {
    int n = max(a.size(), b.size());
    if (n <= 10) { // Base case: use standard multiplication
        vector<ll> res(a.size() + b.size() - 1, 0);
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                res[i + j] += a[i] * b[j];
            }
        }
        return res;
    }
    n = (n + 1) / 2;
    vector<ll> a0(a.begin(), a.begin() + min((int)a.size(), n));
    vector<ll> a1(a.begin() + min((int)a.size(), n), a.end());
    vector<ll> b0(b.begin(), b.begin() + min((int)b.size(), n));
    vector<ll> b1(b.begin() + min((int)b.size(), n), b.end());
    vector<ll> p1 = karatsuba(a0, b0);
    vector<ll> p2 = karatsuba(a1, b1);
    vector<ll> a0a1(a0.size() + a1.size()), b0b1(b0.size() + b1.size());
    for (int i = 0; i < a0.size(); ++i) a0a1[i] += a0[i];
    for (int i = 0; i < a1.size(); ++i) a0a1[i] += a1[i];
    for (int i = 0; i < b0.size(); ++i) b0b1[i] += b0[i];
    for (int i = 0; i < b1.size(); ++i) b0b1[i] += b1[i];
    vector<ll> p3 = karatsuba(a0a1, b0b1);
    vector<ll> mid(p3.size());
    for (int i = 0; i < p3.size(); ++i) {
        mid[i] = p3[i] - (i < p1.size() ? p1[i] : 0) - (i < p2.size() ? p2[i] : 0);
    }
    vector<ll> res(p1.size() + 2 * n);
    for (int i = 0; i < p1.size(); ++i) res[i] += p1[i];
    for (int i = 0; i < mid.size(); ++i) res[i + n] += mid[i];
    for (int i = 0; i < p2.size(); ++i) res[i + 2 * n] += p2[i];
    return res;
}

int main() {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    auto res = karatsuba(a, b);
    for (ll x : res) cout << x << ' ';
    cout << '\n';
    return 0;
}