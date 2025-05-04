#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Implicit Treap for dynamic array operations
struct Treap {
    struct Node {
        int val, size, priority;
        Node *left, *right;
        Node(int v) : val(v), size(1), priority(rand()), left(nullptr), right(nullptr) {}
    };
    Node* root = nullptr;

    int get_size(Node* node) { return node ? node->size : 0; }

    void update(Node* node) {
        if (node) {
            node->size = get_size(node->left) + get_size(node->right) + 1;
        }
    }

    pair<Node*, Node*> split(Node* node, int k) {
        if (!node) return {nullptr, nullptr};
        int left_size = get_size(node->left);
        if (left_size < k) {
            auto [l, r] = split(node->right, k - left_size - 1);
            node->right = l;
            update(node);
            return {node, r};
        } else {
            auto [l, r] = split(node->left, k);
            node->left = r;
            update(node);
            return {l, node};
        }
    }

    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;
        if (left->priority > right->priority) {
            left->right = merge(left->right, right);
            update(left);
            return left;
        } else {
            right->left = merge(left, right->left);
            update(right);
            return right;
        }
    }

    void insert(int pos, int val) {
        auto [l, r] = split(root, pos);
        Node* new_node = new Node(val);
        root = merge(merge(l, new_node), r);
    }

    int query(int l, int r) {
        auto [tmp, r1] = split(root, r + 1);
        auto [l1, mid] = split(tmp, l);
        int sum = 0;
        function<void(Node*)> calc = [&](Node* node) {
            if (node) {
                sum += node->val;
                calc(node->left);
                calc(node->right);
            }
        };
        calc(mid);
        root = merge(merge(l1, mid), r1);
        return sum;
    }
};

int main() {
    fast_io();
    srand(time(0));
    int n, q;
    cin >> n >> q;
    Treap treap;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        treap.insert(i, val);
    }
    while (q--) {
        int type, l, r;
        cin >> type >> l;
        if (type == 1) {
            cin >> r;
            treap.insert(l, r);
        } else {
            cin >> r;
            cout << treap.query(l, r) << '\n';
        }
    }
    return 0;
}