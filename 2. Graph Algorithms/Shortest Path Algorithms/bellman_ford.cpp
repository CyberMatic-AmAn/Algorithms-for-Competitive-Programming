#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Bellman-Ford to find shortest paths and detect negative cycles
bool bellman_ford(int src, int n, vector<tuple<int, int, ll>>& edges, vector<ll>& dist) {
    dist[src] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != LLONG_MAX && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }
    // Check for negative cycles
    for (auto [u, v, w] : edges) {
        if (dist[u] != LLONG_MAX && dist[v] > dist[u] + w) {
            return false; // Negative cycle exists
        }
    }
    return true;
}

int main() {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, ll>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }
    vector<ll> dist(n + 1, LLONG_MAX);
    bool no_cycle = bellman_ford(1, n, edges, dist);
    if (!no_cycle) {
        cout << "Negative cycle detected\n";
    } else {
        for (int i = 1; i <= n; ++i) {
            cout << (dist[i] == LLONG_MAX ? -1 : dist[i]) << ' ';
        }
        cout << '\n';
    }
    return 0;
}