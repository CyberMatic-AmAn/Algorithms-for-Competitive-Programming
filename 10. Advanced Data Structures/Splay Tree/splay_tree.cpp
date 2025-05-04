#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Splay Tree for dynamic operations
struct SplayTree {
    struct Node {
        int val, size;
        Node *left, *right, *parent;
        Node(int v) : val(v), size(1), left(nullptr), right(nullptr), parent(nullptr) {}
    };
    Node* root = nullptr;

    void update(Node* node) {
        if (!node) return;
        node->size = 1 + (node->left ? node->left->size : 0) + (node->right ? node->right->size : 0);
    }

    void set_parent(Node* node, Node* par) {
        if (node) node->parent = par;
    }

    void rotate(Node* node) {
        Node* p = node->parent;
        Node* g = p->parent;
        if (g) {
            if (p == g->left) g->left = node;
            else g->right = node;
        } else {
            root = node;
        }
        if (node == p->left) {
            p->left = node->right;
            node->right = p;
        } else {
            p->right = node->left;
            node->left = p;
        }
        set_parent(p->left, p);
        set_parent(p->right, p);
        set_parent(node, g);
        set_parent(node->left, node);
        set_parent(node->right, node);
        update(p);
        update(node);
    }

    void splay(Node* node) {
        while (node->parent) {
            Node* p = node->parent;
            Node* g = p->parent;
            if (g) {
                if ((p == g->left && node == p->left) || (p == g->right && node == p->right)) {
                    rotate(p);
                } else {
                    rotate(node);
                }
            }
            rotate(node);
        }
    }

    Node* find(int val) {
        Node* curr = root;
        while (curr && curr->val != val) {
            if (val < curr->val) curr = curr->left;
            else curr = curr->right;
        }
        if (curr) splay(curr);
        return curr;
    }

    void insert(int val) {
        if (!root) {
            root = new Node(val);
            return;
        }
        Node* curr = root, *par = nullptr;
        while (curr) {
            par = curr;
            if (val < curr->val) curr = curr->left;
            else curr = curr->right;
        }
        Node* new_node = new Node(val);
        if (val < par->val) par->left = new_node;
        else par->right = new_node;
        new_node->parent = par;
        splay(new_node);
    }
};

int main() {
    fast_io();
    int q;
    cin >> q;
    SplayTree st;
    while (q--) {
        string op;
        int val;
        cin >> op >> val;
        if (op == "insert") {
            st.insert(val);
        } else {
            cout << (st.find(val) ? "Found" : "Not Found") << '\n';
        }
    }
    return 0;
}