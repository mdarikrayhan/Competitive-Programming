#include <bits/stdc++.h>
using namespace std;
int T,n,m,k,p,a[200010],sz[200010],head[200010],o=0;
struct edge{
	int to,link;
}e[400010];
void add_edge(int u,int v){
	e[++o]={v,head[u]},head[u]=o;
	e[++o]={u,head[v]},head[v]=o;
}
void dfs(int u,int pre){
	if(sz[u]) a[++m]=u;
	for(int i=head[u],v;i;i=e[i].link) if((v=e[i].to)^pre){
		dfs(v,u),sz[u]+=sz[v];
		if(!p&&sz[u]>=k) p=u; 
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),add_edge(u,v);
	for(int i=1,w;i<=2*k;i++) scanf("%d",&w),sz[w]=1;
	dfs(1,0);
	printf("1\n%d\n",p);
	for(int i=1;i<=k;i++) printf("%d %d %d\n",a[i],a[i+k],p);
}