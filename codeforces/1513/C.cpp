#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll dp[200005];

void solve()
{
    string n;
    ll m;
    cin >> n >> m;
    ll ans = 0;
    for (auto &c : n)
    {
        ll x = c - '0';
        ll val = m - 10 + x;
        if (val >= 0)
			ans = (ans + dp[val])%MOD;
        else
            ans = (ans + 1)%MOD;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	for(ll i = 0; i<=8; i++)dp[i] = 2;
	dp[9] = 3;
	for(ll i = 10; i<200005; i++)dp[i] = (dp[i-10] + dp[i-9])%MOD;
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}