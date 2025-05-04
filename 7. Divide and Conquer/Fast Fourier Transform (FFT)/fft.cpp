#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using cd = complex<double>;

// Fast I/O setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Fast Fourier Transform
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    if (n == 1) return;
    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    fft(a0, invert);
    fft(a1, invert);
    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; i < n / 2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

vector<ll> multiply_polynomials(vector<ll>& a, vector<ll>& b) {
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; ++i) fa[i] *= fb[i];
    fft(fa, true);
    vector<ll> res(n);
    for (int i = 0; i < n; ++i) res[i] = round(fa[i].real());
    return res;
}

int main() {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), b(m + 1);
    for (int i = 0; i <= n; ++i) cin >> a[i];
    for (int i = 0; i <= m; ++i) cin >> b[i];
    auto res = multiply_polynomials(a, b);
    for (int i = 0; i <= n + m; ++i) cout << res[i] << ' ';
    cout << '\n';
    return 0;
}