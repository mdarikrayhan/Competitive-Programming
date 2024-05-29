// LUOGU_RID: 159935707
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=4e5+5;
int n,m,ec,eh[N];
struct E{int nxt,to;}e[N<<1];
basic_string<int> g0[N];
ll ans1,ans2,ans3;
struct Fwk{
	int n;ll s[N];
	inline void init(int _){n=_,memset(s+1,0,n*sizeof(int));}
	inline void add(int x,int v){for(;x<=n;x+=x&-x)s[x]+=v;}
	inline ll sum(int x){int v{0};for(;x;x^=x&-x)v+=s[x];return v;}
	inline ll query(int l,int r){return sum(r)-sum(l-1);}
}fwk;
struct DSU{
	int fa[N];
	void init(int n){iota(fa+1,fa+n+1,1);}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	void merge(int x,int y){
		if((x=find(x))==(y=find(y))) return;
		fa[x]=y;
	}
}dsu;
struct Tree{
	basic_string<int> g[N];
	int dep[N],fa[N],sz[N],dfn[N],dfp[N],dft;
	void adde(int u,int v){
		g[u]+=v;
	}
	void dfs(int u,int ff){
		dfp[dfn[u]=++dft]=u;
		dep[u]=dep[fa[u]=ff]+(sz[u]=1);
		for(int v:g[u]){
			dfs(v,u);
			sz[u]+=sz[v];
		}
	}
}tr1,tr2;
void dfs2(int u){
	ans3+=fwk.query(tr2.dfn[u],tr2.dfn[u]+tr2.sz[u]-1);
	fwk.add(tr2.dfn[u],1);
	for(int v:tr1.g[u]) dfs2(v);
	fwk.add(tr2.dfn[u],-1);
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i{1};i<n;++i){
		int u,v; cin>>u>>v;
		g0[u]+=v,g0[v]+=u;
	}
	dsu.init(n);
	for(int i{1};i<=n;++i){
		for(int v:g0[i]){
			if(v>i) continue;
			int b=dsu.find(v);
			if(b!=i) tr1.adde(i,b),dsu.merge(b,i);
		}
	}
	dsu.init(n);
	for(int i{n};i>=1;--i){
		for(int v:g0[i]){
			if(v<i) continue;
			int b=dsu.find(v);
			if(b!=i) tr2.adde(i,b),dsu.merge(b,i);
		}
	}
	tr1.dfs(n,0),tr2.dfs(1,0);
	for(int i{1};i<=n;++i){
		ans1+=tr1.sz[i]-1,
		ans2+=tr2.sz[i]-1;
	}
	fwk.init(n);
	dfs2(n);

	printf("%lld\n",ans1+ans2-ans3-ans3);
	cin>>m;
	for(int i{n+1};i<=n+m;++i){
		int f; cin>>f;
		tr2.dep[i]=tr2.dep[f]+1;
		ans1+=i-1;
		ans2+=tr2.dep[i]-1;
		ans3+=tr2.dep[i]-1;
		printf("%lld\n",ans1+ans2-ans3-ans3);
	}
	return 0;
}

/*
(1) u is max
(2) u is min
(3) u is min && v is max

(1): T1 u子树大小
(2): T2 u子树大小
(3): v 在 T1 中是 u 的祖先，在 T2 的 u子树中

新加点，在 T1 中加根，在 T2 中加叶子
ans1+=tot
ans2+=dep-1
ans3+=dep-1
*/