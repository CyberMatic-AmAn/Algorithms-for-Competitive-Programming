#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Dijkstra's algorithm for single-source shortest paths
void dijkstra(int src, vector<vector<pll>>& adj, vector<ll>& dist) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        ll d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<vector<pll>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<ll> dist(n + 1, LLONG_MAX);
    dijkstra(1, adj, dist);
    for (int i = 1; i <= n; ++i) {
        cout << (dist[i] == LLONG_MAX ? -1 : dist[i]) << ' ';
    }
    cout << '\n';
    return 0;
}