//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N ((1<<20)+10)
using namespace std;
ll n,v[N];
vector<pair<ll,ll> > vec[N];
void solve(ll x,ll l,ll r)
{
	if(l+1==r)
	{
		vec[x].push_back(make_pair(0,v[l]&v[r]));
		vec[x].push_back(make_pair(1,v[l]&(v[r]>>1)));
		return;
	}
	ll a=x<<1,mid=(l+r)>>1,i;
	solve(a,l,mid);
	solve(a|1,mid+1,r);
	for(i=0;i<vec[a].size();i++)
	{
		vec[x].push_back(make_pair(vec[a][i].F,vec[a][i].S&vec[a|1][i].S));
	}
	for(i=0;i<vec[a].size();i++)
	{
		vec[x].push_back(make_pair(vec[a][i].F+vec[a].size(),vec[a][i].S&(vec[a|1][i].S>>1)));
	}
	return;
}
int main(){
	ll i;
	scanf("%d",&n);
	v[0]=(1<<(n+1))-1;
	for(i=1;i<(1<<n);i++)
	{
		scanf("%d",&v[i]);
	}
	solve(1,0,(1<<n)-1);
	vector<ll> ans;
	for(i=0;i<vec[1].size();i++)
	{
		if(vec[1][i].S&1)
		{
			ans.push_back(vec[1][i].F);
		}
	}
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}