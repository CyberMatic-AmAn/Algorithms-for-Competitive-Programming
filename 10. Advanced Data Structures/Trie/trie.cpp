#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Trie for string storage and prefix queries
struct Trie {
    struct Node {
        vector<int> next;
        bool end;
        Node() : next(26, -1), end(false) {}
    };
    vector<Node> trie;
    Trie() { trie.emplace_back(); }

    void insert(string& s) {
        int v = 0;
        for (char c : s) {
            int ch = c - 'a';
            if (trie[v].next[ch] == -1) {
                trie[v].next[ch] = trie.size();
                trie.emplace_back();
            }
            v = trie[v].next[ch];
        }
        trie[v].end = true;
    }

    bool search(string& s) {
        int v = 0;
        for (char c : s) {
            int ch = c - 'a';
            if (trie[v].next[ch] == -1) return false;
            v = trie[v].next[ch];
        }
        return trie[v].end;
    }

    bool prefix_exists(string& s) {
        int v = 0;
        for (char c : s) {
            int ch = c - 'a';
            if (trie[v].next[ch] == -1) return false;
            v = trie[v].next[ch];
        }
        return true;
    }
};

int main() {
    fast_io();
    int n, q;
    cin >> n >> q;
    Trie trie;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        trie.insert(s);
    }
    while (q--) {
        string s;
        cin >> s;
        cout << (trie.search(s) ? "Found" : "Not Found") << '\n';
    }
    return 0;
}