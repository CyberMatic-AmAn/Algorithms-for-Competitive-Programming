#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Rabin-Karp for string matching
vector<int> rabin_karp(string& text, string& pat, ll mod = 1e9 + 7, ll p = 31) {
    int n = text.size(), m = pat.size();
    vector<ll> p_pow(max(n, m));
    p_pow[0] = 1;
    for (int i = 1; i < p_pow.size(); ++i) p_pow[i] = (p_pow[i - 1] * p) % mod;
    vector<ll> h(n + 1);
    for (int i = 0; i < n; ++i) h[i + 1] = (h[i] + (text[i] - 'a' + 1) * p_pow[i]) % mod;
    ll h_pat = 0;
    for (int i = 0; i < m; ++i) h_pat = (h_pat + (pat[i] - 'a' + 1) * p_pow[i]) % mod;
    vector<int> positions;
    for (int i = 0; i <= n - m; ++i) {
        ll curr_h = (h[i + m] - h[i] + mod) % mod;
        if (curr_h == (h_pat * p_pow[i]) % mod) {
            positions.push_back(i);
        }
    }
    return