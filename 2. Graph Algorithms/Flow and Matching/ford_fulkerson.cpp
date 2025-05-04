#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// BFS for finding augmenting path
bool bfs(int src, int sink, vector<vector<ll>>& cap, vector<int>& par) {
    int n = cap.size();
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(src);
    vis[src] = true;
    par[src] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; ++v) {
            if (!vis[v] && cap[u][v] > 0) {
                q.push(v);
                vis[v] = true;
                par[v] = u;
            }
        }
    }
    return vis[sink];
}

// Ford-Fulkerson with BFS (Edmonds-Karp)
ll ford_fulkerson(int src, int sink, vector<vector<ll>>& cap) {
    int n = cap.size();
    vector<vector<ll>> res_cap = cap;
    vector<int> par(n);
    ll max_flow = 0;
    while (bfs(src, sink, res_cap, par)) {
        ll flow = LLONG_MAX;
        for (int v = sink; v != src; v = par[v]) {
            flow = min(flow, res_cap[par[v]][v]);
        }
        for (int v = sink; v != src; v = par[v]) {
            res_cap[par[v]][v] -= flow;
            res_cap[v][par[v]] += flow;
        }
        max_flow += flow;
    }
    return max_flow;
}

int main() {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> cap(n + 1, vector<ll>(n + 1, 0));
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        cap[u][v] += c;
    }
    cout << ford_fulkerson(1, n, cap) << '\n';
    return 0;
}