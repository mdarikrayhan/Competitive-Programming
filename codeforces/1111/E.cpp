// LUOGU_RID: 160010144
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
const int inf=5e16L;
const int mod=1e9+7;
struct node
{
	int to,next;
}e[2*N];
int n,h[N],cnt,f[N][21],dep[N],q,m,dfn[N],pos;
int g[N],vis[N],kong[N],rez,in[N],num,t[N],rt,lzj[N],zeq,dis[N];
int dp[2][305],ans;
vector<int>v[N];
void add(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].next=h[x];
	h[x]=cnt;
}
void dfs(int root,int father)
{
	dfn[root]=++pos;
	for(int i=h[root];i;i=e[i].next)
	{
		int y=e[i].to;
		if(y==father)continue;
		f[y][0]=root;
		dep[y]=dep[root]+1;
		dfs(y,root);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int j=20;j>=0;j--)
	{
		if(dep[f[x][j]]>=dep[y])x=f[x][j];
	}
	if(x==y)return x;
	for(int j=20;j>=0;j--)
	{
		if(f[x][j]!=f[y][j])
		{
			x=f[x][j];
			y=f[y][j];
		}
	}
	return f[x][0];
}
int cmp(int x,int y)
{
	return dfn[x]<dfn[y];
}
void Dfs(int root,int father)
{
	lzj[++zeq]=root;
	for(int i=0;i<v[root].size();i++)
	{
		int y=v[root][i];
		if(y==father)continue;
		// cout<<"Dfs: "<<root<<' '<<y<<'\n';
		dis[y]=dis[root]+t[y];
		Dfs(y,root);
	}
}
void clear(int x)
{
	for(int j=0;j<=m+1;j++)dp[x][j]=0;
}
void solve()
{
	zeq=ans=0;
	dis[rt]=t[rt];
	Dfs(rt,-1);
	int res=0;
	clear(res);
	clear(res^1);
	dp[res][0]=1;
	for(int i=1;i<=zeq;i++)
	{
		res^=1;
		clear(res);
		for(int j=0;j<=min(i,m);j++)
		{
			if(t[lzj[i]])
			{
				if(j-1>=0)dp[res][j]=(dp[res][j]+dp[res^1][j-1])%mod;
				dp[res][j]=(dp[res][j]+dp[res^1][j]*max(0ll,j-(dis[lzj[i]]-1))%mod)%mod;
			}
			else dp[res][j]=dp[res^1][j];
			// cout<<"dp: "<<lzj[i]<<' '<<t[lzj[i]]<<' '<<i<<' '<<j<<' '<<dp[i][j]<<' '<<dp[i-1][j-1]<<' '<<dp[i-1][j]<<' '<<max(0ll,j-(dis[lzj[i]]-1))<<'\n';
		}
		// cout<<"------------------\n";
	}
	for(int j=0;j<=m;j++)ans=(ans+dp[res][j])%mod;
}
void work()
{
	num=rez=0;
	int k;
	cin>>k>>m>>rt;
	for(int i=1;i<=k;i++)
	{
		cin>>g[i];
		t[g[i]]=1;
		vis[g[i]]=1;
	}
	if(!vis[rt])g[++k]=rt;
	sort(g+1,g+1+k,cmp);
	for(int i=1;i<=k-1;i++)
	{
		kong[++rez]=g[i];
		kong[++rez]=lca(g[i],g[i+1]);
	}
	kong[++rez]=g[k];
	if(!vis[1])kong[++rez]=1;
	sort(kong+1,kong+1+rez,cmp);
	rez=unique(kong+1,kong+1+rez)-(kong+1);
	for(int i=1;i<=rez-1;i++)
	{
		int sb=lca(kong[i],kong[i+1]);
		// cout<<"aminos; "<<kong[i]<<' '<<kong[i+1]<<' '<<sb<<'\n';
		v[sb].push_back(kong[i+1]);
		v[kong[i+1]].push_back(sb);
	}
	solve();
	cout<<ans<<'\n';
	for(int i=1;i<=zeq;i++)dis[lzj[i]]=0;
	for(int i=1;i<=rez-1;i++)
	{
		int sb=lca(kong[i],kong[i+1]);
		v[sb].clear();
		v[kong[i+1]].clear();
	}
	for(int i=1;i<=k;i++)vis[g[i]]=0,t[g[i]]=0;
}
signed main()
{
#ifdef LOCAL
	freopen("test.in", "r",stdin);
	freopen("test.out", "w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>q;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dep[1]=1;
	dfs(1,-1);
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=n;i++)
		{
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
	for(int i=1;i<=q;i++)work();
	return 0;
}
/*
按dfs序展开dp
dp[i][j]表示前i个数一共分了j组
*/