// LUOGU_RID: 160365855
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e5+5,M=1e6+5;
int n,m,k,x,y,st[N],top,dfn[N],low[N],tot,cnt,d[N],an[N][20];
vector<int> vee[N],ve[N];
inline int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
void tj(int u){
	st[++top]=u,dfn[u]=low[u]=++tot;
	for(int v:vee[u]){
		if(!dfn[v]){
			tj(v),low[u]=min(low[u],low[v]);
			if(low[v]==dfn[u]){cnt++;do ve[st[top]].pb(cnt),ve[cnt].pb(st[top]);while(st[top--]!=v);ve[u].pb(cnt),ve[cnt].pb(u);}
		}
		else low[u]=min(low[u],dfn[v]);
	}
}
void dfs(int u){for(int v:ve[u])if(v!=an[u][0])an[v][0]=u,d[v]=d[u]+1,dfs(v);}
inline int lca(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=0,t=d[x]-d[y];t;i++,t>>=1)if(t&1)x=an[x][i];
	if(x==y)return x;
	for(int i=17;~i;i--)if(an[x][i]!=an[y][i])x=an[x][i],y=an[y][i];
	return an[x][0];
}
inline int dis(int x,int y){return d[x]+d[y]-(d[lca(x,y)]<<1);}
signed main(){
	cnt=n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)x=read(),y=read(),vee[x].pb(y),vee[y].pb(x);
	tj(1),dfs(1);
	//for(int i=1;i<=n;i++)for(int v:ve[i])printf("#%d %d\n",i,v);
	for(int j=1;j<=17;j++)for(int i=1;i<=cnt;i++)an[i][j]=an[an[i][j-1]][j-1];
	while(k--)x=read(),y=read(),printf("%d\n",dis(x,y)>>1);
	return 0;
}