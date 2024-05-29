#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define N 1000000
using namespace std;
int read()
{
	char c=0;
	int sum=0;
	while (c<'0'||c>'9') c=getchar();
	while ('0'<=c&&c<='9') sum=sum*10+c-'0',c=getchar();
	return sum;
}
int T,n,m,s,t,cater,X[N+1],Y[N+1],rk[N+1],fa[N+1],dfn[N+1],low[N+1],leng,rev[N+1],tong[N+1],length;
bool used[N+1];
vector<int>E[N+1];
vector<int>ES[N+1];
void add(int x,int y)
{
	E[x].push_back(y),E[y].push_back(x);
	return;
}
void tarjan(int x)
{
	dfn[x]=low[x]=++leng,rev[dfn[x]]=x;
	for (int i=0;i<E[x].size();++i)
	{
		if (!dfn[E[x][i]]) fa[E[x][i]]=x,tarjan(E[x][i]),low[x]=min(low[x],low[E[x][i]]);
		else low[x]=min(low[x],dfn[E[x][i]]);
	}
	return;
}
void dfs(int x)
{
	rk[x]=++cater;
	for (int i=ES[x].size()-1;i>=0;--i)
		if (!rk[ES[x][i]])
			dfs(ES[x][i]);
	return;
}
int main()
{
	int x;
	bool op;
	T=read();
	while (T--)
	{
		n=read(),m=read(),s=read(),t=read(),leng=length=cater=0,op=1;
		for (int i=1;i<=n;++i) E[i].clear(),ES[i].clear(),dfn[i]=low[i]=rk[i]=fa[i]=used[i]=0;
		for (int i=1;i<=m;++i) X[i]=read(),Y[i]=read(),add(X[i],Y[i]);
		tarjan(s),x=t;
		while (x!=s) tong[++length]=x,x=fa[x];
		tong[++length]=x,reverse(tong+1,tong+length+1);
		for (int i=1;i<=length;++i) used[tong[i]]=1;
		for (int i=1;i<=n;++i)
			if (!used[i]&&rev[low[i]]==fa[i])
				op=0;
		if (!op)
		{
			puts("No");
			continue;
		}
		puts("Yes");
		for (int i=1;i<=n;++i)
		{
			x=rev[i];
			if (!used[x]) ES[rev[low[x]]].push_back(x),ES[fa[x]].push_back(x);
		}
		for (int i=1;i<=length;++i) dfs(tong[i]);
		for (int i=1;i<=m;++i)
		{
			if (rk[X[i]]<rk[Y[i]]) printf("%d %d\n",X[i],Y[i]);
			else printf("%d %d\n",Y[i],X[i]);
		}
	}
	return 0;
}
