// LUOGU_RID: 159912491
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define ull unsigned long long
#define int ll
int read()
{
    int now = 0, nev = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            nev = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        now = (now << 1) + (now << 3) + (c & 15);
        c = getchar();
    }
    return now * nev;
}
const int MAXN = 1e6+10;
const int mod = 1e9+7;
int n;
int head[MAXN],tt=0;
struct edge
{
	int to,nxt;
}e[MAXN<<1];
void add(int x,int y)
{
	e[++tt].nxt=head[x];
	head[x]=tt;
	e[tt].to=y;
}
int du[MAXN];
int f[MAXN][2],g[MAXN][2];//f[i][0/1]表示节点i不选/选时以i为根的子树中好的节点数。g[i][0/1]表示节点i不选/选时以i为根的子树的最小权值和 
void dfs(int u,int fa)
{
	g[u][0]=1;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa)
			continue;
		dfs(v,u);
		if(f[v][0]>f[v][1])
		{
			f[u][0]+=f[v][0];
			g[u][0]+=g[v][0];
		}
		if(f[v][0]<f[v][1])
		{
			f[u][0]+=f[v][1];
			g[u][0]+=g[v][1]+1;
		}
		if(f[v][0]==f[v][1])
		{
			f[u][0]+=f[v][0];
			g[u][0]+=min(g[v][0],g[v][1]+1);
		}
		f[u][1]+=f[v][0];
		g[u][1]+=g[v][0];
	}
	f[u][1]++;
	g[u][1]+=du[u];
	if(fa)
		g[u][1]--;
}
int flag[MAXN];
void dfsans(int u,int fa,int c)
{
	flag[u]=c;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa)
			continue;
		if(c==1)
			dfsans(v,u,0);
		else
		{
			if(f[v][0]>f[v][1])
				dfsans(v,u,0);
			else if(f[v][0]<f[v][1])
				dfsans(v,u,1);
			else
			{
				if(g[v][0]<=g[v][1])
					dfsans(v,u,0);
				else
					dfsans(v,u,1);
			}
		}
	}
}
signed main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		add(x,y),add(y,x);
		du[x]++,du[y]++;
	}
	if(n==2)
	{
		printf("2 2\n1 1\n");
		return 0;
	}
	dfs(1,0);
	if(f[1][0]>f[1][1])
		dfsans(1,0,0);
	else if(f[1][0]<f[1][1])
		dfsans(1,0,1);
	else
	{
		if(g[1][0]<g[1][1])
			dfsans(1,0,0);
		else
			dfsans(1,0,1);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(flag[i])
			ans+=du[i];
		else
			ans++;
	}
	printf("%lld %lld\n",max(f[1][1],f[1][0]),ans);
	for(int i=1;i<=n;i++)
	{
		if(flag[i])
			printf("%lld ",du[i]);
		else
			printf("1 ");
	}
	return 0;
}