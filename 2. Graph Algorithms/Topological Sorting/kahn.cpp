#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Kahn's algorithm for topological sort
vector<int> kahn(int n, vector<vector<int>>& adj) {
    vector<int> in_degree(n + 1, 0), topo;
    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            in_degree[v]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            if (--in_degree[v] == 0) {
                q.push(v);
            }
        }
    }
    return topo.size() == n ? topo : vector<int>{}; // Empty if cycle exists
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
    }
    vector<int> topo = kahn(n, adj);
    if (topo.empty()) {
        cout << "Cycle detected\n";
    } else {
        for (int x : topo) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}