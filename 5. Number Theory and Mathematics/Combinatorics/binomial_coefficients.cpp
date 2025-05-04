#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Binomial Coefficient C(n, k) % mod
ll mod_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

ll binomial_coefficient(ll n, ll k, ll mod) {
    if (k > n) return 0;
    ll num = 1, den = 1;
    for (ll i = 0; i < k; ++i) {
        num = (num * (n - i)) % mod;
        den = (den * (i + 1)) % mod;
    }
    return (num * mod_pow(den, mod - 2, mod)) % mod;
}

int main() {
    fast_io();
    ll n, k, mod;
    cin >> n >> k >> mod;
    cout << binomial_coefficient(n, k, mod) << '\n';
    return 0;
}