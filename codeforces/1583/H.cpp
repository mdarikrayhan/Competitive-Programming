#include <iostream>
#include <algorithm>
using namespace std;

const int maxm=400005;
const int maxn=200005;
int n,m,a[maxn];
pair<int,int>ans[maxn];
struct edge
{
	int u,v,w,t;
	bool const operator < (edge &rhs)
	{
		return w>rhs.w;
	}
}e[maxn];

bool cmp(edge e1,edge e2)
{
	return e1.t<e2.t;
}
struct query
{
	int u,x,id;
	bool const operator < (query &rhs)
	{
		return x>rhs.x;
	}
}q[maxn];
int fa[maxn],mx[maxn],tot,lca[maxn],ls[maxm],rs[maxm],val[maxm],anc[maxm][19],dep[maxm];

int fd(int x)
{
	return fa[x]==x?x:fa[x]=fd(fa[x]);
}

void build()
{
	sort(e+1,e+n,cmp);for (int i=1;i<=n;i++){fa[i]=i;}tot=n;
	for (int i=1;i<n;i++)
	{
		int u=fd(e[i].u),v=fd(e[i].v);
		fa[u]=fa[v]=++tot;fa[tot]=tot;val[tot]=e[i].t;ls[tot]=u;rs[tot]=v;
	}
}
void dfs(int u,int f)
{
	anc[u][0]=f;dep[u]=dep[f]+1;
	for (int i=1;i<=18;i++)
	{
		anc[u][i]=anc[anc[u][i-1]][i-1];
	}
	if (ls[u])
	{
		dfs(ls[u],u);
	}
	if (rs[u])
	{
		dfs(rs[u],u);
	}
}

int LCA(int u,int v)
{
	if (dep[u]<dep[v]){swap(u,v);}
	for (int i=18;i>=0;i--)
	{
		if (dep[anc[u][i]]>=dep[v]){u=anc[u][i];}
	}
	if (u==v){return u;}
	for (int i=18;i>=0;i--)
	{
		if (anc[u][i]!=anc[v][i]){u=anc[u][i];v=anc[v][i];}
	}
	return anc[u][0];
} 

void add(int u,int v)
{
	u=fd(u);v=fd(v);
	if (mx[u]>mx[v])
	{
		fa[v]=u;
	}
	else if (mx[u]<mx[v])
	{
		fa[u]=v;
	}
	else
	{
		fa[v]=u;lca[u]=LCA(lca[u],lca[v]);
	}
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<n;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w>>e[i].t;
	}
	build();dfs(tot,0);
	for (int i=1;i<=n;i++){fa[i]=i;lca[i]=i;mx[i]=a[i];}
	for (int i=1;i<=m;i++)
	{
		cin>>q[i].x>>q[i].u;q[i].id=i;
	}
	sort(q+1,q+m+1);sort(e+1,e+n);
	for (int i=1,j=0;i<=m;i++)
	{
		while (j<n-1&&e[j+1].w>=q[i].x)
		{
			j++;
			add(e[j].u,e[j].v);
		}
		ans[q[i].id].first=mx[fd(q[i].u)];ans[q[i].id].second=val[LCA(q[i].u,lca[fd(q[i].u)])];
	}
	for (int i=1;i<=m;i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
}
/*
5 1
1 2 2 2 2
1 2 5 8
1 3 6 3
1 4 4 5
1 5 7 1
6 1
*/