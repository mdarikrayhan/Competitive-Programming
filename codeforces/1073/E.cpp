#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const mod = 998244353;
ll dp[19][2][2][1025][2],dp2[19][2][2][1025][2];
#define int long long
ll fastPower(ll a, ll n) {
    if (n == 0) {
        return 1;
    }
    ll a2 = fastPower(a, n / 2);
    ll res = a2 * a2 * (n % 2 == 1 ? a : 1);
    return res;
}
void solve(){
    vector cnt(20 , vector(11 , 0));
    memset(dp , -1 , sizeof dp);
    memset(dp2 , -1 , sizeof dp2);

    ll le ,ri , k  , y= 0;
    cin >> le >> ri >> k;
    string l = to_string(le) , r = to_string(ri);
    while(l.size()<r.size()) l ='0' + l;
    int n = r.size();
    auto go1 = [&](auto && go1 , int idx  , int up ,int down ,int mask,int ok)->ll{
        if (idx == n) return (__popcount(mask)<=k);
        if (~dp2[idx][up][down][mask][ok]) return dp2[idx][up][down][mask][ok];
        ll ans = 0 , nk = ok;
        int end = (up ? r[idx]-'0' : 9);
        int start = (down ? l[idx] - '0' : 0);
        for (int i = start;i<=end;i++){
            nk|=(i!=0);
            (ans += go1(go1, idx + 1, up & (i == r[idx] - '0'),down & (i == l[idx] - '0'), (nk ? (mask | (1 << i)) : mask), nk))%=mod;
        }
        return dp2[idx][up][down][mask][ok] = ans;
    };
    auto go = [&](auto && go , int idx  , int up ,int down ,int mask,int ok)->ll{
        if (idx == n) return 0;
        if (~dp[idx][up][down][mask][ok]) return dp[idx][up][down][mask][ok];
        ll ans = 0 , nk = ok;
        int end = (up ? r[idx]-'0' : 9);
        int start = (down ? l[idx] - '0' : 0);
        for (int i = start;i<=end;i++){
            nk |= (i != 0);
            ll x = go(go, idx + 1, up & (i == r[idx] - '0'), down & (i == l[idx] - '0'),
                      (nk ? (mask | (1 << i)) : mask), nk)%mod;
            (ans += (i * fastPower(10, n - idx - 1)%mod *
                    go1(go1, idx + 1, up & (i == r[idx] - '0'), down & (i == l[idx] - '0'),
                        (nk ? (mask | (1 << i)) : mask), nk))%mod) %= mod;
            (ans += x) %= mod;
        }
        return dp[idx][up][down][mask][ok] = ans % mod;
    };
    cout << go(go , 0 , 1, 1, 0, 0) % mod;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >>t;
    while(t--)
    solve();
}
