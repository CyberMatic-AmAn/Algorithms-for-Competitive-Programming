#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Manacher's Algorithm: Find longest palindromic substring
vector<int> manacher(string& s) {
    string t = "#";
    for (char c : s) t += c, t += '#';
    int n = t.size();
    vector<int> p(n);
    int c = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        if (i <= r) p[i] = min(r - i, p[2 * c - i]);
        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1]) {
            p[i]++;
        }
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }
    return p;
}

int main() {
    fast_io();
    string s;
    cin >> s;
    vector<int> p = manacher(s);
    int max_len = 0, center = 0;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] > max_len) {
            max_len = p[i];
            center = i;
        }
    }
    int start = (center - max_len) / 2;
    cout << s.substr(start, max_len) << '\n';
    return 0;
}