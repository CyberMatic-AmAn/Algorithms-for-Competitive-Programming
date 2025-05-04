#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Extended Euclidean Algorithm
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

int main() {
    fast_io();
    ll a, b, x, y;
    cin >> a >> b;
    ll g = ext_gcd(a, b, x, y);
    cout << "GCD: " << g << ", x: " << x << ", y: " << y << '\n';
    return 0;
}