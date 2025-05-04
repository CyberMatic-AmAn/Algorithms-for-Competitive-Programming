#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Prime factorization
map<ll, int> prime_factorization(ll n) {
    map<ll, int> factors;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) factors[n]++;
    return factors;
}

int main() {
    fast_io();
    ll n;
    cin >> n;
    auto factors = prime_factorization(n);
    for (auto [p, e] : factors) {
        cout << p << "^" << e << ' ';
    }
    cout << '\n';
    return 0;
}