#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Determine winner of Nim game
string nim_game(vector<int>& piles) {
    int xor_sum = 0;
    for (int x : piles) {
        xor_sum ^= x;
    }
    return xor_sum == 0 ? "Second" : "First";
}

int main() {
    fast_io();
    int n;
    cin >> n;
    vector<int> piles(n);
    for (int i = 0; i < n; ++i) {
        cin >> piles[i];
    }
    cout << nim_game(piles) << '\n';
    return 0;
}