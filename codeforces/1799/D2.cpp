#include <bits/stdc++.h>
#include <climits>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 3e5;
int a[mxn];
int sv[mxn];

template<class T> using v = vector<T>;

void solve() {
    int n, k; cin >> n >> k;
    
    for (int i = 0; i < n; i++)
        cin >> a[i], --a[i];
    for (int i = 0; i < k; i++)
        cin >> sv[i];
    
    int ans = 0;

    for (int i = 0; i < n; i++)
        ans += sv[a[i]];
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        sv[i] -= x;
    }
    
    v<int> b;
    v<int> occ(k, -1);

    int last = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == last) ans -= sv[a[i]];
        else b.push_back(a[i]);
        last = a[i];
    }

    v<v<int>> dp(b.size(), v<int>(2, 0));
    occ[b[0]] = 0;

    for (int i = 1; i < b.size(); i++) {
        if (occ[b[i]] == -1) dp[i][1] = LLONG_MIN, dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
        else {
            int prv = occ[b[i]];

            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = max({dp[prv][1], dp[prv + 1][1], dp[prv][0]}) + sv[b[i]];
        } 
        occ[b[i]] = i;
    }
    
    //cout << dp.back()[0] << " " << dp.back()[1] << nl;;
    cout << ans - max(dp.back()[0], dp.back()[1]) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}