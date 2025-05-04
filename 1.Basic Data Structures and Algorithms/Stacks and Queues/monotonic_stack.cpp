#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Monotonic stack to find next greater element
vector<int> next_greater(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            result[st.top()] = arr[i];
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
    vector<int> result = next_greater(arr);
    for (int x : result) cout << x << ' ';
    cout << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast I/O setup
void fast_io() {
    ios_base::sync with_stdio(false);
    cin.tie(nullptr);
}

// Sliding window minimum using deque
vector<int> sliding_window_min(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < arr.size(); ++i) {
        // Remove elements outside window
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        // Remove larger elements
        while (!dq.empty() && arr[dq.back()] >= arr[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(arr[dq.front()]);
    }
    return result;
}

int main() {
    fast_io();
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    vector<int> result = sliding_window_min(arr, k);
    for (int x : result) cout << x << ' ';
    cout << '\n';
    return 0;
}