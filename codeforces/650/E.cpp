// LUOGU_RID: 157223859
#include<bits/stdc++.h>
using namespace std;
int n,fa1[500005],fa2[500005],f[500005],cnt,ans[500005][4];
vector<int> g1[500005],g2[500005];
int find(int x)
{
	while(f[x]!=x) x=f[x]=f[f[x]];
	return x;
}
void dfs(int x,int fa)
{
	for(int i=0;i<g1[x].size();i++)
	{
		int y=g1[x][i];
		if(y==fa) continue;
		dfs(y,x);
		fa1[y]=x;
	}
}
void dfs1(int x,int fa)
{
	for(int i=0;i<g2[x].size();i++)
	{
		int y=g2[x][i];
		if(y==fa) continue;
		dfs1(y,x);
		fa2[y]=x;
	}
}
void dfs2(int x,int fa)
{
	for(int i=0;i<g1[x].size();i++)
	{
		int y=g1[x][i];
		if(y==fa) continue;
		dfs2(y,x);
		if(fa2[y]!=x&&fa2[x]!=y) ans[++cnt][0]=y,ans[cnt][1]=x,ans[cnt][2]=find(y),ans[cnt][3]=fa2[find(y)];
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g1[u].push_back(v);
		g1[v].push_back(u);
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g2[u].push_back(v);
		g2[v].push_back(u);
	}
	dfs(1,0);dfs1(1,0);
	for(int i=2;i<=n;i++)
	{
		int now=fa2[i];
		if(fa1[i]==now||fa1[now]==i) f[i]=now;
		else f[i]=i;
	}
	dfs2(1,0);
	cout<<cnt<<"\n";
	for(int i=1;i<=cnt;i++) printf("%d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
	return 0;
}