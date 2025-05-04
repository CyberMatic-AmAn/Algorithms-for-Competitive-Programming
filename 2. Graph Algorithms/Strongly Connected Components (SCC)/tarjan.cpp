#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Tarjan's for Strongly Connected Components
void tarjan(int u, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low, stack<int>& st, vector<bool>& in_stack, vector<vector<int>>& sccs) {
    static int time = 0;
    disc[u] = low[u] = ++time;
    st.push(u);
    in_stack[u] = true;
    for (int v : adj[u]) {
        if (disc[v] == 0) {
            tarjan(v, adj, disc, low, st, in_stack, sccs);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (disc[u] == low[u]) {
        vector<int> scc;
        while (true) {
            int v = st.top();
            st.pop();
            in_stack[v] = false;
            scc.push_back(v);
            if (v == u) break;
        }
        sccs.push_back(scc);
    }
}

vector<vector<int>> tarjan_scc(int n, vector<vector<int>>& adj) {
    vector<int> disc(n + 1, 0), low(n + 1, 0);
    vector<bool> in_stack(n + 1, false);
    stack<int> st;
    vector<vector<int>> sccs;
    for (int i = 1; i <= n; ++i) {
        if (disc[i] == 0) {
            tarjan(i, adj, disc, low, st, in_stack, sccs);
        }
    }
    return sccs;
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
    vector<vector<int>> sccs = tarjan_scc(n, adj);
    for (auto& scc : sccs) {
        for (int x : scc) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}