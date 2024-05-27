#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <bitset> 
#include <cmath> 
#include <queue>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;

#define x first
#define y second

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<double,double> PDD; 
typedef pair<LD,int> PLDI;
typedef pair<LD,LD> PLDLD;
typedef pair<PII,int> PIII;
typedef pair<LL,int> PLI;
typedef pair<LL,PII> PLII;
const int N = 300010,M=2*N,U=300000,INF=1e9+10,mod=998244353,P=13331;
const double PI=acos(-1),eps=1e-10;
	
const int mod0 = 402653189,mod1 = 805306457,BASE0 = 13331,BASE1 = 23333;

int T,n;
int dfn[N],sz[N],ts;
int h[N],e[M],ne[M],idx;
int tr[N],fa[N],depth[N];
LL f[N]; 
bool st[N];

void add(int x,int y)
{
	e[idx]=y,ne[idx]=h[x],h[x]=idx++;
}

int lowbit(int x)
{
	return x&-x;
}

void modify(int x,int k)
{
	for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=k;
}

int query(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i)) res+=tr[i];
	return res;
}

void dfs(int u,int father)
{
	dfn[u]=++ts,sz[u]=1,fa[u]=father;
	for(int i=h[u];~i;i=ne[i])
	{
		int j=e[i];
		if(j==father) continue;
		depth[j]=depth[u]+1;
		dfs(j,u);
		sz[u]+=sz[j]; 
	}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ts=idx=0;
		memset(h,-1,4*(n+1));
		memset(depth,0,4*(n+1));
		memset(st,0,n+1);
		memset(tr,0,4*(n+1));
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x++,y++;
			add(x,y),add(y,x);
		}
		depth[1]=1;
		dfs(1,-1);
		st[1]=true;
		f[0]=(LL)n*(n-1)/2;
		int p=2;
		st[2]=true;
		while(depth[p]>2) p=fa[p],st[p]=true;
		f[1]=f[0];
		for(int i=h[1];~i;i=ne[i]) f[1]-=(LL)sz[e[i]]*(sz[e[i]]-1)/2;
		modify(1,1),modify(dfn[p],-1),modify(dfn[p]+sz[p],1),modify(n+1,-1);
		modify(dfn[2],2),modify(dfn[2]+sz[2],-2);
		f[2]=(LL)sz[2]*(n-sz[p]);
		for(int i=3;i<=n;i++)
		{
			f[i]=f[i-1];
			if(st[i]) continue;
			int s=query(dfn[i]);
			if(!s)
			{
				for(int j=i;j<=n;j++) f[j]=0;
				break;
			}
			if(s==1) modify(1,-1),modify(dfn[p],1),modify(dfn[p]+sz[p],-1),modify(n+1,1),f[i]/=(n-sz[p]);	
			else modify(dfn[s],-s),modify(dfn[s]+sz[s],s),f[i]/=sz[s];
			modify(dfn[i],i),modify(dfn[i]+sz[i],-i);
			f[i]*=sz[i];
			int t=i;
			while(t!=s) st[t]=true,t=fa[t];
		}
		for(int i=0;i<n;i++) f[i]-=f[i+1];
		for(int i=0;i<=n;i++)
		printf("%lld ",f[i]);
		puts("");
	}
}
