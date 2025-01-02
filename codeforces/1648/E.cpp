// LUOGU_RID: 160249158
// 2024 HOPE IN VALUABLE
#include<bits/stdc++.h>
using namespace std;
const int LG=19;
const int N=200005;
int tc,tid,n,m,tot,f1[N],f2[N],head[N],lg[N],dep[N],fa[LG][N],cst[LG][N],ans[N]; vector<int>g[N],nxt; unordered_set<int>cant[N],tmp;
inline int find1(int x){ return f1[x]==x?x:f1[x]=find1(f1[x]); }
inline int find2(int x){ return f2[x]==x?x:f2[x]=find2(f2[x]); }
struct Graph{
	int u,v,w,id;
	bool operator < (const Graph &a) const { return w<a.w; }
}e[N];
struct Edge{ int to,nxt,w; }t[N<<1];
inline void ade(int u,int v,int w){ t[++tot]={v,head[u],w}; head[u]=tot; }
inline void dfs(int u){
	for(int i=head[u];i;i=t[i].nxt){
		int v=t[i].to,w=t[i].w; if(v==fa[0][u]) continue;
		fa[0][v]=u; cst[0][v]=w; dep[v]=dep[u]+1; dfs(v);
	}
}
inline int ask(int u,int v){
	if(dep[u]>dep[v]) swap(u,v);
	int ans=0;
	for(int i=lg[dep[v]-dep[u]];~i;i--)
		if(dep[fa[i][v]]>=dep[u])
			ans=max(ans,cst[i][v]),v=fa[i][v];
	if(u==v) return ans;
	for(int i=lg[dep[u]];~i;i--)
		if(fa[i][u]!=fa[i][v])
			ans=max({ans,cst[i][u],cst[i][v]}),u=fa[i][u],v=fa[i][v];
	ans=max({ans,cst[0][u],cst[0][v]});
	return ans;
}
inline void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w,e[i].id=i;
	for(int i=1;i<=n;i++) f1[i]=f2[i]=i,head[i]=0,g[i].clear(),g[i].emplace_back(i),cant[i].clear(); tot=0;
	for(int i=1;i<=m;i++) cant[e[i].u].emplace(e[i].v),cant[e[i].v].emplace(e[i].u);
	sort(e+1,e+m+1);
	for(int _=1;_<=m;_++){
		int u=find1(e[_].u),v=find1(e[_].v);
		if(u==v) continue; f1[v]=u;
		for(int x:g[u])
			for(int y:g[v]){
				x=find2(x); y=find2(y);
				if(x==y||cant[x].count(y)) continue;
				ade(x,y,e[_].w); ade(y,x,e[_].w);
				f2[y]=x; tmp.clear();
				for(int z:cant[y])
					if(cant[x].count(z)) tmp.emplace(z);
					else cant[z].erase(y);
				for(int z:cant[x])
					if(!tmp.count(z)) cant[z].erase(x);
				swap(cant[x],tmp);
			}
		nxt.clear();
		for(int x:g[u]) if(find2(x)==x) nxt.emplace_back(x);
		for(int x:g[v]) if(find2(x)==x) nxt.emplace_back(x);
		swap(g[u],nxt);
	}
	dfs(1);
	for(int j=1;j<=lg[n];j++)
		for(int i=1;i<=n;i++){
			fa[j][i]=fa[j-1][fa[j-1][i]];
			cst[j][i]=max(cst[j-1][i],cst[j-1][fa[j-1][i]]);
		}
	for(int i=1;i<=m;i++) ans[e[i].id]=ask(e[i].u,e[i].v);
	for(int i=1;i<=m;i++) cout<<ans[i]<<(i==m?'\n':' ');
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i=2;i<N;i++) lg[i]=lg[i>>1]+1;
	cin>>tc; while(tc--) solve();
	return 0;
}