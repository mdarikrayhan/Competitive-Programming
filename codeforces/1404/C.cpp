//starting with the name of almighty ALLAH
// Practice is the only shortcut to improve
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define vc vector
#define vi vc<int>
#define vl vc<ll>
#define mp(x,y) make_pair(x,y)
#define yes cout<<"YES"<<'\n';
#define no cout<<"NO"<<'\n';
#define tst int t;cin>>t;while(t--)
#define srt(v) sort(v.begin(),v.end());
#define rsrt(v) sort(v.rbegin(),v.rend());
#define rj ios::sync_with_stdio(false);cin.tie(0);
#define rvs(v) reverse(v.begin(),v.end());
#define F first
#define S second
#define MOD 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define PI 2*acos(0.0)
#define pii pair<int,int>
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define coutv(v) for(auto it:v)cout<<it<<' ';cout<<endl;
#define cinv(v) for(auto &it:v)cin>>it;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ld long double
#define nl '\n'
const int N = 1e5;
using namespace std;
/* #ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(x...)
#endif */
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r)
{
	return uniform_int_distribution<int>(l, r) (rng);
}
template <class DT>
struct BIT
{
	int n;
	vector<DT> fanwick;
	BIT() {}
	BIT(int nn)
	{
		n = nn;
		fanwick.assign(n + 1, 0);// 1-indexed
	}
	DT presum(int i)
	{
		DT an = 0;
		for (; i >= 1; i -= (i & -i))
			an += fanwick[i];
		return an;
	}
	void update(int i, DT val)
	{
		if (i <= 0)
			return;
		for (; i <= n; i += (i & -i))
			fanwick[i] += val;
	}
	void update(int lf, int rt, DT val)
	{
		update(lf, val);
		update(rt + 1, -val);
	}
	DT query(int l, int r)
	{
		return presum(r) - presum(l - 1);
	}
};
void solve()
{
	int a, b;
	cin >> a >> b;
	vector<int>v(a + 1), ans(b);
	BIT<int>bt(a + 1);
	for (int i = 1; i <= a; i++)
	{
		cin >> v[i];
		v[i] = i - v[i];
	}
	vector<pair<int, int>>q[a + 1];
	for (int i = 0; i < b; i++)
	{
		int x, y;
		cin >> x >> y;
		x++;
		y = a - y;
		q[y].push_back({x, i});
	}
	for (int i = 1; i <= a; i++)
	{
		int lo = 1, hi = i + 1;
		while (lo + 1 < hi)
		{
			int mid = (lo + hi) >> 1;
			if (bt.presum(mid) >= v[i])
				lo = mid;
			else hi = mid;
		}
		if (v[i] >= 0 and bt.presum(lo) >= v[i])
		{
			bt.update(1, lo, 1);
		}
		for (auto it : q[i])
		{
			ans[it.second] = bt.presum(it.first);
		}
	}
	for (auto it : ans)
		cout << it << nl;
}
int main()
{
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE*/
	rj
	//int t;cin>>t;fr(i,1,t) cout<<"Case "<<i<<": ",solve();
	//ll t;scanf("%lld",&t);fr(i,1,t) printf("Case %lld: ",i),solve();
	solve();
	return 0;
}