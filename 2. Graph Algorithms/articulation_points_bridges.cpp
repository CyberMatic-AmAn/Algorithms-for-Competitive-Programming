#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Find articulation points and bridges
void dfs(int u, int p, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low, vector<bool>& ap, vector<pair<int, int>>& bridges, int& time) {
    disc[u] = low[u] = ++time;
    int children = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (disc[v] == 0) {
            children++;
            dfs(v, u, adj, disc, low, ap, bridges, time);
            low[u] = min(low[u], low[v]);
            if (p == -1 && children > 1) ap[u] = true;
            if (p != -1 && low[v] >= disc[u]) ap[u] = true;
            if (low[v] > disc[u]) bridges.emplace_back(min(u, v), max(u, v));
        } else {
            low[u] = min(low[u], disc[v]);
        }
    }
}

pair<vector<int>, vector<pair<int, int>>> find_ap_bridges(vector<vector<int>>& adj, int n) {
    vector<int> disc(n + 1, 0), low(n + 1, 0);
    vector<bool> ap(n + 1, false);
    vector<pair<int, int>> bridges;
    int time = 0;
    for (int u = 1; u <= n; ++u) {
        if (disc[u] == 0) {
            dfs(u, -1, adj, disc, low, ap, bridges, time);
        }
    }
    vector<int> aps;
    for (int u = 1; u <= n; ++u) {
        if (ap[u]) aps.push_back(u);
    }
    return {aps, bridges};
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
    auto [aps, bridges] = find_ap_bridges(adj, n);
    cout << "Articulation Points: ";
    for (int x : aps) cout << x << ' ';
    cout << '\n';
    cout << "Bridges: ";
    for (auto [u, v] : bridges) cout << u << '-' << v << ' ';
    cout << '\n';
    return 0;
}