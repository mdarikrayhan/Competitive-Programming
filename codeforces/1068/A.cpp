#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
const int N = 8 * 1e5;

/*ll merge(ll a, ll b) {
    return min(a, b);
}

ll merge1(ll a, ll b) {
    return gcd(a, b);
}

ll v[N], g[N][20], mn[N][20], lg[N], power[N];
ll n;

void build() {
    lg[0] = -1;
    for (int i = 1; i < N; i++) lg[i] = lg[i / 2] + 1;
    power[0] = 1;
    for (int i = 1; i <= 20; i++) power[i] = power[i - 1] * 2;
    for (int i = N - 1; i >= 1; i--) {
        for (int j = 0; j <= 20; j++)
            mn[i][j] = 1e9;
    }
    for (int i = n; i >= 1; i--) {
        g[i][0] = mn[i][0] = v[i];
        for (int j = 1; j <= 18; j++) {
            g[i][j] = __gcd(g[i][j - 1], g[i + power[j - 1]][j - 1]);
            mn[i][j] = min(mn[i][j - 1], mn[i + power[j - 1]][j - 1]);
        }
    }

}

int query1(int l, int r) {
    return gcd(g[l][lg[r - l + 1]], g[r - power[lg[r - l + 1]] + 1][lg[r - l + 1]]);
}

int query2(int l, int r) {
    return min(mn[l][lg[r - l + 1]], mn[r - power[lg[r - l + 1]] + 1][lg[r - l + 1]]);
}

bool valid(int mid) {
    for (int i = mid; i <= n; ++i) {
        if (query1(i - mid + 1, i) == query2(i - mid + 1, i))
            return true;
    }
    return false;
}*/

void solve() {
    ll n, m, k, l;
    cin >> n >> m >> k >> l;
    if (((k + l + m - 1) / m) * m > n) {
        cout << -1 << endl;
        return;
    }
    cout << (k + l + m - 1) / m << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
