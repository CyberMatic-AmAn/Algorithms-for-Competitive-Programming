#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Flood fill to count size of connected component
void flood_fill(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& vis, int& size) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || vis[x][y] || grid[x][y] != '.') return;
    vis[x][y] = true;
    size++;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    for (int i = 0; i < 4; ++i) {
        flood_fill(x + dx[i], y + dy[i], grid, vis, size);
    }
}

int main() {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    int size = 0;
    flood_fill(0, 0, grid, vis, size); // Start from (0,0)
    cout << size << '\n';
    return 0;
}