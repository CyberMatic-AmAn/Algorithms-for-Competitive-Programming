#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Z Algorithm for string matching
vector<int> z_algorithm(string& s) {
    int n = s.size();
    vector<int> z(n);
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

// Find all occurrences of pattern in text
vector<int> find_occurrences(string& text, string& pat) {
    string s = pat + "#" + text;
    vector<int> z = z_algorithm(s);
    vector<int> positions;
    for (int i = pat.size() + 1; i < s.size(); ++i) {
        if (z[i] == pat.size()) {
            positions.push_back(i - pat.size() - 1);
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