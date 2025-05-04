#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Mo’s Algorithm for range queries
struct Query {
    int l, r, idx;
    Query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
};

void mo_algorithm(vector<int>& arr, vector<Query>& queries) {
    int n = arr.size(), q = queries.size();
    int block = sqrt(n);
    sort(queries.begin(), queries.end(), [&](Query a, Query b) {
        if (a.l / block != b.l / block) return a.l < b.l;
        return a.r < b.r;
    });
    vector<ll> ans(q);
    vector<int> freq(1e6 + 1, 0);
    ll curr_ans = 0;
    int curr_l = 0, curr_r = -1;
    auto add = [&](int idx) {
        int val = arr[idx];
        curr_ans -= freq[val] * freq[val] * val;
        freq[val]++;
        curr_ans += freq[val] * freq[val] * val;
    };
    auto remove = [&](int idx) {
        int val = arr[idx];
        curr_ans -= freq[val] * freq[val] * val;
        freq[val]--;
        curr_ans += freq[val] * freq[val] * val;
    };
    for (auto& query : queries) {
        while (curr_l > query.l) add(--curr_l);
        while (curr_r < query.r) add(++curr_r);
        while (curr_l < query.l) remove(curr_l++);
        while (curr_r > query.r) remove(curr_r--);
        ans[query.idx] = curr_ans;
    }
    for (ll x : ans) cout << x << '\n';
}

int main() {
    fast_io();
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    vector<Query> queries;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        queries.emplace_back(l - 1, r - 1, i);
    }
    mo_algorithm(arr, queries);
    return 0;
}