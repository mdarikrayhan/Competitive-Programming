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
#define ll long long
#define N 200010
using namespace std;
ll n,dfn[N],dep[N],f[18][N],val[N],dcnt=0;
vector<ll> vt[N];
multiset<ll> mxd[N];
void dfs(ll x,ll lst)
{
	ll i;
	dfn[x]=++dcnt;
	f[0][dcnt]=lst;
	mxd[x].insert(0);
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			dep[vt[x][i]]=dep[x]+1;
			dfs(vt[x][i],x);
			mxd[x].insert((*prev(mxd[vt[x][i]].end()))+1);
		}
	}
	return;
}
void trs(ll x,ll y)
{
	mxd[x].erase(mxd[x].lower_bound((*prev(mxd[y].end()))+1));
	mxd[y].insert((*prev(mxd[x].end()))+1);
	return;
}
void dfs2(ll x,ll lst)
{
	ll i;
	val[x]=*prev(mxd[x].end());
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			trs(x,vt[x][i]);
			dfs2(vt[x][i],x);
			trs(vt[x][i],x);
		}
	}
	return;
}
ll glca(ll x,ll y)
{
	if(x==y)
	{
		return x;
	}
	x=dfn[x],y=dfn[y];
	if(x>y)
	{
		swap(x,y);
	}
	ll lg=31^__builtin_clz((int)(y-x));
	return dfn[f[lg][x+1]]<dfn[f[lg][y-(1<<lg)+1]]?f[lg][x+1]:f[lg][y-(1<<lg)+1];
}
ll getdist(ll x,ll y)
{
	return dep[x]+dep[y]-dep[glca(x,y)]*2;
}
int main(){
	ll T,i,j,x,y;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			mxd[i].clear();
			vt[i].clear();
		}
		ll s,t;
		scanf("%lld%lld",&s,&t);
		for(i=1;i<n;i++)
		{
			scanf("%lld%lld",&x,&y);
			x--,y--;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		dcnt=dep[0]=0;
		dfs(0,-1);
		dfs2(0,-1);
		for(i=1;i<18;i++)
		{
			for(j=2;j+(1<<i)-1<=n;j++)
			{
				f[i][j]=dfn[f[i-1][j]]<dfn[f[i-1][j+(1<<(i-1))]]?f[i-1][j]:f[i-1][j+(1<<(i-1))];
			}
		}
		x=t-1,y=s-1;
		ll ans=INF;
		for(i=0;i<n;i++)
		{
			ll v1=getdist(i,x),v2=getdist(i,y);
			if(v1<v2)
			{
				if((v2^v1)&1)
				{
					v2++;
				}
				v1=v2;
			}
			ans=min(ans,v1+(n-1)*2-val[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}