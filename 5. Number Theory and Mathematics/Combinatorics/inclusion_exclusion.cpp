#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Inclusion-Exclusion: Count numbers not divisible by any of given primes
ll inclusion_exclusion(vector<ll>& primes, ll n) {
    ll ans = 0;
    int m = primes.size();
    for (int mask = 1; mask < (1 << m); ++mask) {
        ll prod = 1;
        int bits = 0;
        for (int i = 0; i < m; ++i) {
            if (mask & (1 << i)) {
                prod *= primes[i];
                bits++;
            }
        }
        if (bits % 2 == 1) {
            ans += n / prod;
        } else {
            ans -= n / prod;
        }
    }
    return n - ans;
}

int main() {
    fast_io();
    ll n, m;
    cin >> n >> m;
    vector<ll> primes(m);
    for (int i = 0; i < m; ++i) cin >> primes[i];
    cout << inclusion_exclusion(primes, n) << '\n';
    return 0;
}