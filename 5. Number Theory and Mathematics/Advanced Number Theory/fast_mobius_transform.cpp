#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Fast Mobius Transform for subset convolution
void fast_mobius_transform(vector<ll>& a, ll mod, bool inverse = false) {
    int n = a.size();
    int log_n = __builtin_ctz(n);
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += len << 1) {
            for (int j = 0; j < len; ++j) {
                ll x = a[i + j], y = a[i + j + len];
                a[i + j] = (x + y) % mod;
                a[i + j + len] = (x - y + mod) % mod;
                if (inverse) {
                    a[i + j] = a[i + j] * (mod + 1) / 2 % mod;
                    a[i + j + len] = a[i + j + len] * (mod + 1) / 2 % mod;
                }
            }
        }
    }
}

// Example: Compute subset sum convolution
vector<ll> subset_convolution(vector<ll>& a, vector<ll>& b, ll mod) {
    int n = a.size();
    vector<ll> fa = a, fb = b;
    fast_mobius_transform(fa, mod);
    fast_mobius_transform(fb, mod);
    for (int i = 0; i < n; ++i) {
        fa[i] = fa[i] * fb[i] % mod;
    }
    fast_mobius_transform(fa, mod, true);
    return fa;
}

int main() {
    fast_io();
    int k;
    ll mod;
    cin >> k >> mod;
    int n = 1 << k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector<ll> result = subset_convolution(a, b, mod);
    for (ll x : result) cout << x << ' ';
    cout << '\n';
    return 0;
}