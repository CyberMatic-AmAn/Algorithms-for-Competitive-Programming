#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Miller-Rabin Primality Test
ll mul_mod(ll a, ll b, ll mod) {
    ll res = 0;
    a %= mod;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        a = (a * 2) % mod;
        b >>= 1;
    }
    return res;
}

ll mod_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = mul_mod(res, base, mod);
        base = mul_mod(base, base, mod);
        exp >>= 1;
    }
    return res;
}

bool check_composite(ll n, ll a, ll d, int s) {
    ll x = mod_pow(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int r = 1; r < s; ++r) {
        x = mul_mod(x, x, n);
        if (x == n - 1) return false;
    }
    return true;
}

bool miller_rabin(ll n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    int s = 0;
    ll d = n - 1;
    while (d % 2 == 0) {
        s++;
        d /= 2;
    }
    vector<ll> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (ll a : bases) {
        if (n == a) return true;
        if (check_composite(n, a, d, s)) return false;
    }
    return true;
}

int main() {
    fast_io();
    ll n;
    cin >> n;
    cout << (miller_rabin(n) ? "Prime" : "Not Prime") << '\n';
    return 0;
}