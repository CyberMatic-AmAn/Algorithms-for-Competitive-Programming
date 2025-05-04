#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// String Hashing for pattern matching
struct StringHash {
    vector<ll> h, p;
    ll mod, base;
    StringHash(string& s, ll mod = 1e9 + 7, ll base = 31) : mod(mod), base(base) {
        int n = s.size();
        h.resize(n + 1);
        p.resize(n + 1);
        p[0] = 1;
        h[0] = 0;
        for (int i = 0; i < n; ++i) {
            h[i + 1] = (h[i] * base + s[i] - 'a' + 1) % mod;
            p[i + 1] = (p[i] * base) % mod;
        }
    }
    ll get_hash(int l, int r) {
        ll res = (h[r + 1] - h[l] * p[r - l + 1]) % mod;
        return res < 0 ? res + mod : res;
    }
};

vector<int> find_occurrences(string& text, string& pat) {
    StringHash text_hash(text), pat_hash(pat);
    vector<int> positions;
    ll pat_h = pat_hash.get_hash(0, pat.size() - 1);
    for (int i = 0; i <= text.size() - pat.size(); ++i) {
        if (text_hash.get_hash(i, i + pat.size() - 1) == pat_h) {
            positions.push_back(i);
        }
    }
    return positions;
}

int main() {
    fast_io();
    string text, pat;
    cin >> text >> pat;
    vector<int> positions = find_occurrences(text, pat);
    if (positions.empty()) {
        cout << "No occurrences\n";
    } else {
        for (int pos : positions) {
            cout << pos << ' ';
        }
        cout << '\n';
    }
    return 0;
}