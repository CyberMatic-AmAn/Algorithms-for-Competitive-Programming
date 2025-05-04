#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Prim's for Minimum Spanning Tree
ll prim(vector<vector<pll>>& adj, int n) {
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<bool> vis(n + 1, false);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    ll mst_weight = 0;
    while (!pq.empty()) {
        ll d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        mst_weight += d;
        for (auto [v, w] : adj[u]) {
            if (!vis[v] && dist[v] > w) {
                dist[v] = w;
                pq.push({w, v});
            }
        }
    }
    return mst_weight;
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
    cout << prim(adj, n) << '\n';
    return 0;
}