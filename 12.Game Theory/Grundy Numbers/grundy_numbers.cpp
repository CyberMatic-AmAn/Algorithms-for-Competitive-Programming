#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Compute Grundy number for a single pile
int grundy(int n, vector<int>& moves) {
    if (n == 0) return 0;
    static map<int, int> memo;
    if (memo.count(n)) return memo[n];
    set<int> s;
    for (int m : moves) {
        if (n >= m) {
            s.insert(grundy(n - m, moves));
        }
    }
    int g = 0;
    while (s.count(g)) g++;
    return memo[n] = g;
}

// Determine winner of game with multiple piles
string grundy_game(vector<int>& piles, vector<int>& moves) {
    int xor_sum = 0;
    for (int x : piles) {
        xor_sum ^= grundy(x, moves);
    }
    return xor_sum == 0 ? "Second" : "First";
}

int main() {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<int> piles(n), moves(m);
    for (int i = 0; i < n; ++i) {
        cin >> piles[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> moves[i];
    }
    cout << grundy_game(piles, moves) << '\n';
    return 0;
}