#include <bits/stdc++.h>
using namespace std;
#define N 2005
#define pb push_back
mt19937 rand1(0);
int T,n,m,o,U[N],V[N],fe[N],dep[N];bool vs[N];
struct Edge {int v,w;};vector<Edge> e[N];
bool chk(int u,int v)
{
	for(int i=1;i<=40;++i)
	{
		printf("? %d\n",rand1()&1?u:v);
		fflush(stdout);scanf("%d",&o);if(!o) return 0;
	}return 1;
}
void dfs(int u,int f)
{
	dep[u]=dep[f]+1;
	for(auto [v,w]:e[u]) if(v!=f) fe[v]=w,dfs(v,u);
}
void slv()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) e[i].clear();
	for(int i=1;i<=m;++i) scanf("%d %d",&U[i],&V[i]);
	for(int i=1;i<=m;++i)
	{
		printf("- %d\n",i);fflush(stdout);
		vs[i]=!chk(U[i],V[i]);
		if(vs[i])
		{
			e[U[i]].pb((Edge) {V[i],i});
			e[V[i]].pb((Edge) {U[i],i});
			printf("+ %d\n",i);fflush(stdout);
		}
	}dfs(1,0);
	for(int i=1,t;i<=m;++i) if(!vs[i])
	{
		t=fe[dep[U[i]]>dep[V[i]]?U[i]:V[i]];
		assert(t);
		printf("+ %d\n",i);fflush(stdout);
		printf("- %d\n",t);fflush(stdout);
		vs[i]=chk(U[i],V[i]);
		printf("- %d\n",i);fflush(stdout);
		printf("+ %d\n",t);fflush(stdout);
	}printf("! ");
	for(int i=1;i<=m;++i) printf("%d ",vs[i]);
	fflush(stdout);scanf("%d",&o);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}