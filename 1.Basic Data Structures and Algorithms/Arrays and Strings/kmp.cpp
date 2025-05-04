#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Compute LPS (Longest Prefix Suffix) array for KMP
void compute_lps(string& pat, vector<int>& lps) {
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < pat.size()) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP: Find all occurrences of pattern in text
vector<int> kmp_search(string& text, string& pat) {
    vector<int> lps(pat.size()), positions;
    compute_lps(pat, lps);
    int i = 0, j = 0;
    while (i < text.size()) {
        if (text[i] == pat[j]) {
            i++;
            j++;
        }
        if (j == pat.size()) {
            positions.push_back(i - j); // 0-based index
            j = lps[j - 1];
        } else if (i < text.size() && text[i] != pat[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return positions;
}

int main() {
    fast_io();
    string text, pat;
    cin >> text >> pat;
    vector<int> positions = kmp_search(text, pat);
    for (int pos : positions) {
        cout << pos << ' ';
    }
    cout << '\n';
    return 0;
}