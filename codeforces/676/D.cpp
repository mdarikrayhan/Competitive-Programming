#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
typedef int ll;
vector<string> s;
bool L(char c) {
    return (c == '-' || c == '<' || c == '+' || c == 'U' || c == 'R' || c == 'D');
}
bool R(char c) {
    return (c == '-' || c == '>' || c == '+' || c == 'U' || c == 'L' || c == 'D');
}
bool U(char c) {
    return (c == '|' || c == '^' || c == '+' || c == 'L' || c == 'R' || c == 'D');
}
bool D(char c) {
    return (c == '|' || c == 'v' || c == '+' || c == 'U' || c == 'R' || c == 'L');
}
vector<ll> z(ll x, ll n, ll m) {
    ll t = x / (n * m), i = (x % (n * m)) / m, j = x % m;
    vector<ll> v;
    if (t == 0 && i) {
        if (U(s[i][j]) && D(s[i - 1][j])) v.push_back((i - 1) * m + j);
    }
    if (t == 0 && j) {
        if (L(s[i][j]) && R(s[i][j - 1])) v.push_back(i * m + j - 1);
    }
    if (t == 0 && i + 1 < n) {
        if (D(s[i][j]) && U(s[i + 1][j])) v.push_back((i + 1) * m + j);
    }
    if (t == 0 && j + 1 < m) {
        if (R(s[i][j]) && L(s[i][j + 1])) v.push_back(i * m + j + 1);
    }
    if (t == 1 && i) {
        if (L(s[i][j]) && R(s[i - 1][j])) v.push_back(n * m + (i - 1) * m + j);
    }
    if (t == 1 && j) {
        if (D(s[i][j]) && U(s[i][j - 1])) v.push_back(n * m + i * m + j - 1);
    }
    if (t == 1 && i + 1 < n) {
        if (R(s[i][j]) && L(s[i + 1][j])) v.push_back(n * m + (i + 1) * m + j);
    }
    if (t == 1 && j + 1 < m) {
        if (U(s[i][j]) && D(s[i][j + 1])) v.push_back(n * m + i * m + j + 1);
    }
    if (t == 2 && i) {
        if (D(s[i][j]) && U(s[i - 1][j])) v.push_back(2 * n * m + (i - 1) * m + j);
    }
    if (t == 2 && j) {
        if (R(s[i][j]) && L(s[i][j - 1])) v.push_back(2 * n * m + i * m + j - 1);
    }
    if (t == 2 && i + 1 < n) {
        if (U(s[i][j]) && D(s[i + 1][j])) v.push_back(2 * n * m + (i + 1) * m + j);
    }
    if (t == 2 && j + 1 < m) {
        if (L(s[i][j]) && R(s[i][j + 1])) v.push_back(2 * n * m + i * m + j + 1);
    }
    if (t == 3 && i) {
        if (R(s[i][j]) && L(s[i - 1][j])) v.push_back(3 * n * m + (i - 1) * m + j);
    }
    if (t == 3 && j) {
        if (U(s[i][j]) && D(s[i][j - 1])) v.push_back(3 * n * m + i * m + j - 1);
    }
    if (t == 3 && i + 1 < n) {
        if (L(s[i][j]) && R(s[i + 1][j])) v.push_back(3 * n * m + (i + 1) * m + j);
    }
    if (t == 3 && j + 1 < m) {
        if (D(s[i][j]) && U(s[i][j + 1])) v.push_back(3 * n * m + i * m + j + 1);
    }
    v.push_back(((t + 1) % 4) * n * m + i * m + j);
    return v;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    s.resize(n);
    for (ll i = 0; i < n; ++i) cin >> s[i];
    ll xt, yt, xm, ym;
    cin >> xt >> yt >> xm >> ym;
    vector<ll> d(4 * n * m, 1e9);
    d[(--xt) * m + (--yt)] = 0;
    vector<ll> q = {xt * m + yt};
    for (ll i = 0; i < (ll)q.size(); ++i) {
        for (auto to : z(q[i], n, m)) {
            if (d[to] == 1e9) d[to] = d[q[i]] + 1, q.push_back(to);
        }
    }
    --xm, --ym;
    ll ans = min(min(d[xm * m + ym], d[n * m + xm * m + ym]), min(d[2 * n * m + xm * m + ym], d[3 * n * m + xm * m + ym]));
    if (ans == 1e9) ans = -1;
    cout << ans;
}