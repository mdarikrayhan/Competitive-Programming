#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const ll p = 720720;
void solve() {
    ll n, a0, x, y, k, m;
    cin >> n >> a0 >> x >> y >> k >> m;
    vector<ll> a(n);
    a[0] = a0;
    for (int i = 1; i < n; i++)
        a[i] = (a[i - 1] * x % m + y) % m;
    ll ans = 0;
    vector<ll> tpow(k + 1);
    vector<vector<ll>> dp(k + 1, vector<ll>(p + 1));
    tpow[0] = 1;
    for (int i = 1; i <= k; i++)
        tpow[i] = tpow[i - 1] * n % mod;
    for (int i = 0; i < n; i++) {
        ans = (ans + (a[i] - a[i] % p) * k % mod * tpow[k - 1] % mod) % mod;
        a[i] = a[i] % p;
        dp[0][a[i]]++;
    }
    for (int i = 0; i <= k - 1; i++) {
        for (int j = 0; j < p; j++) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * (n - 1ll) % mod) % mod;
            int l = j - j % (i + 1);
            dp[i + 1][l] = (dp[i + 1][l] + dp[i][j]) % mod;
        }
    }
    for (int i = 1; i <= k; i++)
        for (int j = 0; j < p; j++)
            ans = (ans + dp[i - 1][j] * j % mod * tpow[k - i] % mod) % mod;
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}