#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define in insert
const ll N = 1e6 + 10, P = 131, INF = 1e18;
const ll mod = 1e9 + 7, mod2 = 998244353;
typedef pair<ll, ll> PII;
// unordered_map<ll, ll> mp, ma;
map<ll, ll> mp, ma;
map<char, ll> mp1;
list<char> l1;
list<char> l2;
struct Node
{
	ll x, y, dir;
} f[N];

ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
// ll dx[6]={0,0,0,0,1,-1};
// ll dy[6]={0,0,1,-1,0,0};
// ll dz[6]={1,-1,0,0,0,0};
// ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
// ll dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll fac[N], invfac[N];

ll qmi(ll a, ll b)
{
	ll ans = 1;

	while (b)
	{
		if (b & 1)
			ans = (ans * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return ans;
}

void init()
{
	ll n = 1e7 + 10;
	fac[0] = 1;
	for (ll i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % mod;

	invfac[n] = qmi(fac[n], mod - 2);

	for (ll i = n - 1; i >= 0; i--)
		invfac[i] = invfac[i + 1] * (i + 1) % mod;
}

ll C(ll n, ll m)
{
	if (m > n)
		return 0;
	if (m == 0)
		return 1;

	return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}


void solve()
{
	mp.clear();
	ll n;
	cin>>n;
	vector<ll> a(n);
	ll mx=-INF;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	
	if(mp[1]==n)
	{
		cout<<0<<"\n";
		return ;
	}
	if(mp[0]==n-2)
	{
		cout<<n-1<<"\n";
		return;
	}
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			while(a[i]==0)
				i++;
			ans++;
		}
	}
	ll l=0;
	while(a[l]==1)
		l++;
	ll r=n-1;
	while(a[r]==1)
		r--;

	if(ans==1)
		cout<<mp[0]+1<<'\n';
	else
		cout<<r-l+2<<"\n";
}

/*
1,1  4,1
1,2 3,1

*/

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll T = 1;
	cin >> T;
	while (T--)
		solve();

	return 0;
}
