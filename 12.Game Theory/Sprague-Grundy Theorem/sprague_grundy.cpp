#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Compute Grundy number for a graph-based game
int sprague_grundy(int u, vector<vector<int>>& adj, vector<int>& memo) {
    if (memo[u] != -1) return memo[u];
    set<int> s;
    for (int v : adj[u]) {
        s.insert(sprague_grundy(v, adj, memo));
    }
    int g = 0;
    while (s.count(g)) g++;
    return memo[u] = g;
}

// Determine winner of graph-based game
string graph_game(vector<vector<int>>& adj, int start) {
    int n = adj.size() - 1;
    vector<int> memo(n + 1, -1);
    int g = sprague_grundy(start, adj, memo);
    return g == 0 ? "Second" : "First";
}

int main() {
    fast_io();
    int n, m, start;
    cin >> n >> m >> start;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << graph_game(adj, start) << '\n';
    return 0;
}