#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Huffman Coding
struct Node {
    char ch;
    ll freq;
    Node *left, *right;
    Node(char c, ll f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    bool operator>(const Node& other) const { return freq > other.freq; }
};

ll huffman_coding(vector<pair<char, ll>>& freq) {
    priority_queue<Node*, vector<Node*>, greater<Node*>> pq;
    for (auto [ch, f] : freq) {
        pq.push(new Node(ch, f));
    }
    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    Node *root = pq.top();
    ll total_length = 0;
    function<void(Node*, int)> calc_length = [&](Node* node, int depth) {
        if (!node->left && !node->right) {
            total_length += node->freq * depth;
            return;
        }
        if (node->left) calc_length(node->left, depth + 1);
        if (node->right) calc_length(node->right, depth + 1);
    };
    calc_length(root, 0);
    return total_length;
}

int main() {
    fast_io();
    int n;
    cin >> n;
    vector<pair<char, ll>> freq(n);
    for (int i = 0; i < n; ++i) {
        cin >> freq[i].first >> freq[i].second;
    }
    cout << huffman_coding(freq) << '\n';
    return 0;
}