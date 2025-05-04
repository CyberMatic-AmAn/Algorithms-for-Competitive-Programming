#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Link-Cut Tree for dynamic tree connectivity
struct LinkCutTree {
    struct Node {
        int val, sum;
        Node *left, *right, *parent;
        bool rev;
        Node(int v) : val(v), sum(v), left(nullptr), right(nullptr), parent(nullptr), rev(false) {}
    };
    vector<Node*> nodes;

    LinkCutTree(int n) {
        nodes.resize(n + 1);
        for (int i = 1; i <= n; ++i) nodes[i] = new Node(0);
    }

    void update(Node* node) {
        if (!node) return;
        node->sum = node->val;
        if (node->left) node->sum += node->left->sum;
        if (node->right) node->sum += node->right->sum;
    }

    void push(Node* node) {
        if (!node || !node->rev) return;
        swap(node->left, node->right);
        if (node->left) node->left->rev ^= 1;
        if (node->right) node->right->rev ^= 1;
        node->rev = false;
    }

    bool is_root(Node* node) {
        return !node->parent || (node != node->parent->left && node != node->parent->right);
    }

    void rotate(Node* node) {
        Node* p = node->parent;
        Node* g = p->parent;
        push(p);
        push(node);
        if (!is_root(p)) {
            if (p == g->left) g->left = node;
            else g->right = node;
        }
        if (node == p->left) {
            p->left = node->right;
            node->right = p;
        } else {
            p->right = node->left;
            node->left = p;
        }
        node->parent = g;
        p->parent = node;
        if (p->left) p->left->parent = p;
        if (p->right) p->right->parent = p;
        update(p);
        update(node);
    }

    void splay(Node* node) {
        while (!is_root(node)) {
            Node* p = node->parent;
            if (!is_root(p)) {
                Node* g = p->parent;
                if ((p == g->left && node == p->left) || (p == g->right && node == p->right)) {
                    rotate(p);
                } else {
                    rotate(node);
                }
            }
            rotate(node);
        }
        push(node);
        update(node);
    }

    Node* access(int u) {
        Node* node = nodes[u];
        Node* last = nullptr;
        for (Node* curr = node; curr; curr = curr->parent) {
            splay(curr);
            curr->right = last;
            update(curr);
            last = curr;
        }
        splay(node);
        return node;
    }

    void make_root(int u) {
        access(u);
        Node* node = nodes[u];
        if (node->left) {
            node->left->rev ^= 1;
            node->left = nullptr;
        }
        update(node);
    }

    void link(int u, int v) {
        make_root(u);
        access(v);
        nodes[u]->parent = nodes[v];
    }

    void cut(int u, int v) {
        make_root(u);
        access(v);
        if (nodes[v]->left == nodes[u]) {
            nodes[v]->left->parent = nullptr;
            nodes[v]->left = nullptr;
            update(nodes[v]);
        }
    }

    int query_path(int u, int v) {
        make_root(u);
        access(v);
        return nodes[v]->sum;
    }
};

int main() {
    fast_io();
    int n, q;
    cin >> n >> q;
    LinkCutTree lct(n);
    while (q--) {
        string op;
        int u, v;
        cin >> op >> u >> v;
        if (op == "link") {
            lct.link(u, v);
        } else if (op == "cut") {
            lct.cut(u, v);
        } else {
            cout << lct.query_path(u, v) << '\n';
        }
    }
    return 0;
}