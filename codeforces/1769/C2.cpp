#include<bits/stdc++.h>
#define Imron ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define TXT freopen ("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define ll long long
#define ld long double
#define ull unsigned long long
#define se second
#define fi first
const ll mod = 1e18;
const ld pi = 3.14159265;
using namespace std;
bool gb(ll x, ll i)
{
	return x & (1ll << i);
}
ll binpow(ll a, ll n, ll m)
{
	if(n == 0)
	{
		return 1;
	}
    else if(n == 1)
    {
        return a % m;
    }
    else if(n % 2 == 0)
    {
        ll x = binpow(a, n / 2, m) % m;
        return (x * x) % m;
    }
    else
    {
        return (a * (binpow(a, n - 1, m) % m) % m) % m;
    }
}
ll t_n;
void IM()
{
	ll n;
	cin >> n;
	ll a[n + 17];
	vector<ll> dp(1000000, 0);
	for(ll i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	ll ans = -1e18;
	for(ll i = n; i >= 1; i--)
	{
		dp[a[i]] = max(dp[a[i]], dp[a[i] + 1] + 1);
		dp[a[i] + 1] = max(dp[a[i] + 2] + 1, dp[a[i] + 1]);
		ans = max({ans, dp[a[i]], dp[a[i] + 1]});
	} 
	cout << ans << '\n';
}
signed main()
{
    Imron
    //TXT
    ll T = 1;
    cin >> T;
    for(t_n = 1; t_n <= T; t_n++)
    {
        IM();
    }
} 