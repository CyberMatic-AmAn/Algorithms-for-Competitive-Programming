#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Sieve of Eratosthenes
const int MAXN = 1e7 + 10;
vector<bool> is_prime(MAXN, true);
vector<int> primes;

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i < MAXN; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j < MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    fast_io();
    sieve();
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << (is_prime[x] ? "Prime" : "Not Prime") << '\n';
    }
    return 0;
}