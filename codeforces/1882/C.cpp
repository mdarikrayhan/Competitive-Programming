#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

#define Ahmed cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define all(v) v.begin(), v.end()
#define clr(arr, val) memset(arr, val, sizeof(arr))
#define ll long long
#define F first
#define S second
#define el '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

ll mod = 1e9 + 7;
const int N = 2e5 + 5;
int dirX[4] = {0, 0, 1, -1};
int dirY[4] = {1, -1, 0, 0};

void solve() {
    int n;cin >> n;
    vector<ll> v(n), pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        pref[i] = pref[i + 1] + max(0LL, v[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2)
            ans = max(ans, pref[i + 1]);
        else
            ans = max(ans, v[i] + pref[i + 1]);
    }
    cout << ans << el;
}

int main() {
    Ahmed
//    cout << fixed << setprecision(6);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}