#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Lucas Theorem: Compute C(n, k) % p for prime p
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

ll comb(ll n, ll k, ll p) {
    if (k > n) return 0;
    ll num = 1, den = 1;
    for (ll i = 0; i < k; ++i) {
        num = (num * (n - i)) % p;
        den = (den * (i + 1)) % p;
    }
    return (num * mod_pow(den, p - 2, p)) % p;
}

ll lucas(ll n, ll k, ll p) {
    if (k < 0 || k > n) return 0;
    ll res = 1;
    while (n || k) {
        res = (res * comb(n % p, k % p, p)) % p;
        n /= p;
        k /= p;
    }
    return res;
}

int main() {
    fast_io();
    ll n, k, p;
    cin >> n >> k >> p;
    cout << lucas(n, k, p) << '\n';
    return 0;
}