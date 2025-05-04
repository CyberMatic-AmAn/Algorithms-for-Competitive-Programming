#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Z Algorithm: Compute Z-array for string (length of longest substring starting from i matching prefix)
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

int main() {
    fast_io();
    string s;
    cin >> s;
    vector<int> z = z_algorithm(s);
    for (int i = 1; i < s.size(); ++i) {
        cout << z[i] << ' ';
    }
    cout << '\n';
    return 0;
}