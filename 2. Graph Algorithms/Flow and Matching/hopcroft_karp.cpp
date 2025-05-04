#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// BFS for Hopcroft-Karp
bool bfs(vector<vector<int>>& adj, vector<int>& match, vector<int>& dist, int n1) {
    queue<int> q;
    for (int u = 1; u <= n1; ++u) {
        if (match[u] == 0) {
            dist[u] = 0;
            q.push(u);
        } else {
            dist[u] = INT_MAX;
        }
    }
    dist[0] = INT_MAX;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (dist[u] < dist[0]) {
            for (int v : adj[u]) {
                if (dist[match[v]] == INT_MAX) {
                    dist[match[v]] = dist[u] + 1;
                    q.push(match[v]);
                }
            }
        }
    }
    return dist[0] != INT_MAX;
}

// DFS for Hopcroft-Karp
bool dfs(int u, vector<vector<int>>& adj, vector<int>& match, vector<int>& dist) {
    if (u == 0) return true;
    for (int v : adj[u]) {
        if (dist[match[v]] == dist[u] + 1 && dfs(match[v], adj, match, dist)) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    dist[u] = INT_MAX;
    return false;
}

// Hopcroft-Karp for maximum bipartite matching
int hopcroft_karp(vector<vector<int>>& adj, int n1, int n2) {
    vector<int> match(n1 + n2 + 1, 0), dist(n1 + n2 + 1);
    int max_matching = 0;
    while (bfs(adj, match, dist, n1)) {
        for (int u = 1; u <= n1; ++u) {
            if (match[u] == 0 && dfs(u, adj, match, dist)) {
                max_matching++;
            }
        }
    }
    return max_matching;
}

int main() {
    fast_io();
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    vector<vector<int>> adj(n1 + n2 + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(n1 + v);
        adj[n1 + v].push_back(u);
    }
    cout << hopcroft_karp(adj, n1, n2) << '\n';
    return 0;
}