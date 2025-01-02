// LUOGU_RID: 113825551
//洛谷 CF855G
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int fa[N],sz[N],d[N],sum[N],from[N],cnt[N],n,ans;
vector<int> nodes[N];
void dfs(int u)
{
	sz[u]=cnt[u]=1,d[u]=d[fa[u]]+1,from[u]=u;
	for(int v:nodes[u])
	{
		if(v==fa[u])continue;
		fa[v]=u;
		dfs(v);
		sz[u]+=sz[v];
		sum[u]+=sz[v]*sz[v];
	}
	sum[u]+=(n-sz[u])*(n-sz[u]);
	ans-=sum[u];
	return;
}
int find(int u)
{
	if(u!=from[u])return from[u]=find(from[u]);
	return from[u];
}
int calc(int u){return cnt[u]*((n-1)*(n-1)-(cnt[u]-1)-sum[u]);}
void Merge(int u,int v)
{
	ans-=calc(u),ans-=calc(v);
	from[u]=v;
	cnt[v]+=cnt[u];
	sum[v]=(sum[v]-sz[u]*sz[u])+(sum[u]-(n-sz[u])*(n-sz[u]));
	ans+=calc(v);
	return;
}
void work(int u,int v)
{
	u=find(u),v=find(v);
	while(u!=v)
	{
		if(d[u]<d[v])swap(u,v);
		Merge(u,find(fa[u]));
		u=find(u);
	}
	return;
}
signed main()
{
	scanf("%lld",&n);
	ans=(n-1)*(n-1)*n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%lld %lld",&u,&v);
		nodes[u].push_back(v);
		nodes[v].push_back(u);
	}
	dfs(1);
	printf("%lld\n",ans);
	int q;
	scanf("%lld",&q);
	while(q--)
	{
		int u,v;
		scanf("%lld %lld",&u,&v);
		work(u,v);
		printf("%lld\n",ans);
	}
	return 0;
}