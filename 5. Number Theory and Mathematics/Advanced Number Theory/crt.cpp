#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Extended Euclidean GCD
ll ext_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll g = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Chinese Remainder Theorem
ll crt(vector<ll>& a, vector<ll>& m) {
    ll p = 1, ans = 0;
    for (ll x : m) p *= x;
    for (int i = 0; i < a.size(); ++i) {
        ll pi = p / m[i], x, y;
        ext_gcd(pi, m[i], x, y);
        ans = (ans + a[i] * pi * x) % p;
    }
    return (ans + p) % p;
}

int main() {
    fast_io();
    int n;
    cin >> n;
    vector<ll> a(n), m(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> m[i];
    cout << crt(a, m) << '\n';
    return 0;
}