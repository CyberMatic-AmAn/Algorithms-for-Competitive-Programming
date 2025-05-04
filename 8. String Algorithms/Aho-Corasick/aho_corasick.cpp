#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Aho-Corasick for multiple pattern matching
struct AhoCorasick {
    static const int ALPHA = 26;
    struct Node {
        vector<int> next, go;
        int p, link, ch;
        bool leaf;
        Node(int p = -1, int ch = -1) : p(p), ch(ch), link(-1), leaf(false) {
            next.assign(ALPHA, -1);
            go.assign(ALPHA, -1);
        }
    };
    vector<Node> trie;
    AhoCorasick() { trie.emplace_back(); }

    void add_string(string& s) {
        int v = 0;
        for (char c : s) {
            int ch = c - 'a';
            if (trie[v].next[ch] == -1) {
                trie[v].next[ch] = trie.size();
                trie.emplace_back(v, ch);
            }
            v = trie[v].next[ch];
        }
        trie[v].leaf = true;
    }

    int get_link(int v) {
        if (trie[v].link == -1) {
            if (v == 0 || trie[v].p == 0) {
                trie[v].link = 0;
            } else {
                trie[v].link = go(get_link(trie[v].p), trie[v].ch);
            }
        }
        return trie[v].link;
    }

    int go(int v, int ch) {
        if (trie[v].go[ch] == -1) {
            if (trie[v].next[ch] != -1) {
                trie[v].go[ch] = trie[v].next[ch];
            } else {
                trie[v].go[ch] = v == 0 ? 0 : go(get_link(v), ch);
            }
        }
        return trie[v].go[ch];
    }

    vector<int> find(string& text) {
        vector<int> matches;
        int v = 0;
        for (int i = 0; i < text.size(); ++i) {
            v = go(v, text[i] - 'a');
            int u = v;
            while (u != 0) {
                if (trie[u].leaf) matches.push_back(i);
                u = get_link(u);
            }
        }
        return matches;
    }
};

int main() {
    fast_io();
    int n;
    string text;
    cin >> text >> n;
    AhoCorasick ac;
    for (int i = 0; i < n; ++i) {
        string pat;
        cin >> pat;
        ac.add_string(pat);
    }
    auto matches = ac.find(text);
    for (int pos : matches) cout << pos << ' ';
    cout << '\n';
    return 0;
}