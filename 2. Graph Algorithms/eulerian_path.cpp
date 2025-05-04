#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Eulerian Path for undirected graph
vector<int> eulerian_path(vector<vector<int>>& adj, int n) {
    vector<int> deg(n + 1, 0), path;
    for (int u = 1; u <= n; ++u) {
        deg[u] = adj[u].size();
    }
    int start = 1, odd = 0;
    for (int u = 1; u <= n; ++u) {
        if (deg[u] % 2) {
            start = u;
            odd++;
        }
    }
    if (odd != 0 && odd != 2) return {}; // No Eulerian path
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int u = st.top();
        if (adj[u].empty()) {
            path.push_back(u);
            st.pop();
        } else {
            int v = adj[u].back();
            adj[u].pop_back();
            adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
            st.push(v);
        }
    }
    return path;
}

int main() {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> path = eulerian_path(adj, n);
    if (path.empty()) {
        cout << "No Eulerian path\n";
    } else {
        for (int x : path) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}