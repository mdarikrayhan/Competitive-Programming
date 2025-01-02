#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N (int)2e5

vector<ll> p[N + 1][2];

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        p[a[i]][i & 1].push_back(i);
    }
    ll ans = (k / 2) * (n - k + 1);
    for (ll i = 1; i <= N; i++) {
        if (p[i][0].size() > 1) {
            for (ll j : p[i][0]) {
                ll mn = max(0LL, k / 2 - j - 1);
                ll mx = min(k / 2, n - k / 2 - 1 - j);
                ll l = lower_bound(p[i][0].begin(), p[i][0].end(), j + 2 * mn + 2) - p[i][0].begin();
                ll r = lower_bound(p[i][0].begin(), p[i][0].end(), j + 2 * mx + 2) - p[i][0].begin();
                r--;
                ans -= max(0LL, r - l + 1);
                //cerr << "j: " << j << " len: " << (r - l + 1) << '\n';
            }
        }
        if (p[i][1].size() > 1) {
            for (ll j : p[i][1]) {
                ll mn = max(0LL, k / 2 - j - 1);
                ll mx = min(k / 2, n - k / 2 - 1 - j);
                ll l = lower_bound(p[i][1].begin(), p[i][1].end(), j + 2 * mn + 2) - p[i][1].begin();
                ll r = lower_bound(p[i][1].begin(), p[i][1].end(), j + 2 * mx + 2) - p[i][1].begin();
                r--; 
                ans -= max(0LL, r - l + 1);
                //cerr << "j: " << j << " len: " << (r - l + 1) << '\n';
            }
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll T = 1;
    //cin >> T;
    while (T--)
        solve();
}