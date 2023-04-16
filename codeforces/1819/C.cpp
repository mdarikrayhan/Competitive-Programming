#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long
#define pb push_back
#define mid ((l+r)/2)
int n,U,dg[N],a[N],ans[N];vector<int> e[N];
void dfs(int u,int f)
{
	if(!dg[u]) return;a[++a[0]]=u;
	for(auto v:e[u]) if(v!=f) dfs(v,u);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
		scanf("%d %d",&u,&v),e[u].pb(v),e[v].pb(u);
	for(int i=1;i<=n;++i) dg[i]=e[i].size();
	for(int i=1;i<=n;++i) if(e[i].size()==1) dg[i]=0,--dg[e[i][0]];
	for(int i=1;i<=n;++i) if(dg[i]>2) {printf("No\n");return 0;}
	for(int i=1;i<=n;++i) if(dg[i]==1 || e[i].size()==n-1) U=i;
	printf("Yes\n");dg[U]=1;dfs(U,0);
	for(int i=1;i<=a[0];i+=2)
	{
		printf("%d ",a[i]);
		if(i<a[0]) for(auto j:e[a[i+1]]) if(!dg[j]) printf("%d ",j);
	}if(a[0]&1) {for(auto j:e[a[a[0]]]) if(!dg[j]) printf("%d ",j);--a[0];}
	for(int i=a[0];i;i-=2)
	{
		printf("%d ",a[i]);
		for(auto j:e[a[i-1]]) if(!dg[j]) printf("%d ",j);
	}return 0;
}