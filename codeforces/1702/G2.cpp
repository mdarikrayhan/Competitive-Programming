#include<bits/stdc++.h>
using namespace std;const int N=2e5+7;
basic_string<int>e[N];int n,m,i,j,x,y,k,ind,dfn[N],f[N][21],d[N],a[N];
void dfs(int x,int fa){dfn[x]=++ind;f[x][0]=fa;d[x]=d[fa]+1;for(auto&y:e[x])if(y!=fa)dfs(y,x);}
int lca(int x,int y){
	if(d[x]<d[y])swap(x,y);int t=d[x]-d[y];
	for(int i=20;i>=0;--i)if(t>>i&1)x=f[x][i];
	for(int i=20;i>=0;--i)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return x==y?x:f[x][0];
}
int main(){
	for(scanf("%d",&n),i=1;i<n;++i)scanf("%d%d",&j,&k),e[j]+=k,e[k]+=j;
	for(dfs(1,0),i=1;i<=20;++i)for(int j=1;j<=n;++j)f[j][i]=f[f[j][i-1]][i-1];
	for(scanf("%d",&m);m--;){
		for(scanf("%d",&k),i=1;i<=k;++i)scanf("%d",a+i);
		for(sort(a+1,a+k+1,[&](int x,int y){return dfn[x]<dfn[y];}),x=0,y=0,i=1;i<k;++i)if(lca(a[i],a[i+1])!=a[i]){
			x++;
			if(lca(a[i],a[i+1])!=lca(a[1],a[k]))y++;
		}
		puts(x<=1&&y==0?"YES":"NO");
	}
}