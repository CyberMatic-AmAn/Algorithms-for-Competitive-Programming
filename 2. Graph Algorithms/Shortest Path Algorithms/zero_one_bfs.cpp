#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// 0-1 BFS for shortest paths with 0/1 edge weights
void zero_one_bfs(int src, vector<vector<pair<int, int>>>& adj, vector<ll>& dist) {
    deque<int> dq;
    dist[src] = 0;
    dq.push_back(src);
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
}

int main() {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w; // w is 0 or 1
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<ll> dist(n + 1, LLONG_MAX);
    zero_one_bfs(1, adj, dist);
    for (int i = 1; i <= n; ++i) {
        cout << (dist[i] == LLONG_MAX ? -1 : dist[i]) << ' ';
    }
    cout << '\n';
    return 0;
}