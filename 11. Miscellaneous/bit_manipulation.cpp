#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Bit manipulation utilities
struct BitTricks {
    // Count set bits
    static int count_bits(ll x) {
        return __builtin_popcountll(x);
    }

    // Find lowest set bit position (0-based)
    static int lowest_set_bit(ll x) {
        return __builtin_ctzll(x);
    }

    // Turn off rightmost set bit
    static ll turn_off_rightmost(ll x) {
        return x & (x - 1);
    }

    // Check if power of 2
    static bool is_power_of_two(ll x) {
        return x && !(x & (x - 1));
    }

    // Compute subset sums using SOS DP
    static vector<ll> subset_sum(vector<int>& arr, ll mod) {
        int n = arr.size();
        int max_mask = 1 << n;
        vector<ll> dp(max_mask);
        dp[0] = 0;
        for (int mask = 1; mask < max_mask; ++mask) {
            int low = lowest_set_bit(mask);
            dp[mask] = dp[mask ^ (1 << low)] + arr[low];
            dp[mask] %= mod;
        }
        return dp;
    }
};

int main() {
    fast_io();
    int n;
    ll mod;
    cin >> n >> mod;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<ll> sums = BitTricks::subset_sum(arr, mod);
    for (ll x : sums) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}