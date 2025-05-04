#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Monotone Stack for next greater element
vector<int> next_greater_element(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            result[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return result;
}

int main() {
    fast_io();
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    vector<int> nge = next_greater_element(arr);
    for (int x : nge) cout << x << ' ';
    cout << '\n';
    return 0;
}