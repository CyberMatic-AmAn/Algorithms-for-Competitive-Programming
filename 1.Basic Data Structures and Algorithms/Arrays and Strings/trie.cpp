#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Trie for storing and searching strings
struct Trie {
    struct Node {
        vector<int> next;
        bool is_end;
        Node() : next(26, -1), is_end(false) {}
    };
    vector<Node> nodes;

    Trie() { nodes.emplace_back(); }

    void insert(string& s) {
        int curr = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (nodes[curr].next[idx] == -1) {
                nodes[curr].next[idx] = nodes.size();
                nodes.emplace_back();
            }
            curr = nodes[curr].next[idx];
        }
        nodes[curr].is_end = true;
    }

    bool search(string& s) {
        int curr = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (nodes[curr].next[idx] == -1) return false;
            curr = nodes[curr].next[idx];
        }
        return nodes[curr].is_end;
    }
};

int main() {
    fast_io();
    Trie trie;
    int n, q;
    cin >> n >> q;
    while (n--) {
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