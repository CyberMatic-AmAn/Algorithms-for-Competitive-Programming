#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Dinic's Algorithm for Maximum Flow
struct Dinic {
    vector<vector<ll>> cap;
    vector<vector<int>> adj;
    vector<int> level, ptr;
    int n, src, sink;

    Dinic(int n, int src, int sink) : n(n), src(src), sink(sink) {
        cap.assign(n, vector<ll>(n, 0));
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int u, int v, ll c) {
        cap[u][v] += c;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool bfs() {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[src] = 0;
        q.push(src);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (level[v] == -1 && cap[u][v] > 0) {
                    level[v] = level[u] + 1;
                    q.push(v);
                }
            }
        }
        return level[sink] != -1;
    }

    ll dfs(int u, ll flow) {
        if (u == sink) return flow;
        for (; ptr[u] < adj[u].size(); ++ptr[u]) {
            int v = adj[u][ptr[u]];
            if (level[v] == level[u] + 1 && cap[u][v] > 0) {
                ll pushed = dfs(v, min(flow, cap[u][v]));
                if (pushed > 0) {
                    cap[u][v] -= pushed;
                    cap[v][u] += pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    ll max_flow() {
        ll flow = 0;
        while (bfs()) {
            fill(ptr.begin(), ptr.end(), 0);
            while (ll pushed = dfs(src, LLONG_MAX)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

int main() {
    fast_io();
    int n, m;
    cin >> n >> m;
    Dinic dinic(n + 1, 1, n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        dinic.add_edge(u, v, c);
    }
    cout << dinic.max_flow() << '\n';
    return 0;
}