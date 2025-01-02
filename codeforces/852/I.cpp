// LUOGU_RID: 158707515
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

ll ans;
int n,m,tm,B;
int a[400005];
int c[400005];
int d[400005];
int h0[100005];
int h1[100005];
int st[400005];
int ed[400005];
int fa[400005];
int sz[400005];
int son[400005];
int top[400005];
int dep[400005];
int oul[800005];
bool mp[400005];
ll anss[100005];
vector <int> g[400005];
struct node{int l,r,id,x;}q[100005];

inline void in(int &n){
	n=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0'&&c<='9') n=n*10+c-'0',c=getchar();
	return ;
}

inline void dfsfind(int u,int fath){
	dep[u]=dep[fath]+(sz[u]=1);
	fa[u]=fath;
	for(int v:g[u]){
		if(v==fath) continue;
		dfsfind(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
	return ;
}

inline void dfstime(int u,int tp){
	st[u]=++tm;
	oul[tm]=u;
	top[u]=tp;
	if(son[u]) dfstime(son[u],tp);
	for(int v:g[u]){
		if(v==son[u]||v==fa[u]) continue;
		dfstime(v,v);
	}
	ed[u]=++tm;
	oul[tm]=u;
	return ;
}

inline int LCA(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}

inline void add(int u){
	if(d[u]){
		ans+=h0[a[u]];
		h1[a[u]]++;
	}
	else{
		ans+=h1[a[u]];
		h0[a[u]]++;
	}
	return ;
}

inline void del(int u){
	if(d[u]){
		ans-=h0[a[u]];
		h1[a[u]]--;
	}
	else{
		ans-=h1[a[u]];
		h0[a[u]]--;
	}
	return ;
}

inline void D(int x){
	if(mp[oul[x]]) del(oul[x]);
	else add(oul[x]);
	mp[oul[x]]^=1;
	return ;
}

int main(){
	in(n);
	for(int i=1;i<=n;i++) in(d[i]);
	for(int i=1;i<=n;i++) in(a[i]),c[i]=a[i];
	for(int i=1;i<n;i++){
		int u,v;
		in(u),in(v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	in(m);
	sort(c+1,c+1+n);
	int ct=unique(c+1,c+1+n)-c-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(c+1,c+1+ct,a[i])-c;
	dfsfind(1,0);
	dfstime(1,1);
	for(int i=1;i<=m;i++){
		int u,v;
		in(u),in(v);
		if(dep[u]>dep[v]) swap(u,v);
		if(st[u]<=st[v]&&ed[v]<=st[u]) q[i]={st[u],st[v],i,0};
		else{
			if(st[u]>st[v]) swap(u,v);
			q[i]={ed[u],st[v],i,LCA(u,v)};
		}
	}
	B=tm/((int)sqrt(m))+1;
	sort(q+1,q+1+m,[](node p,node q){return p.l/B==q.l/B?(p.l/B)&1?p.r<q.r:p.r>q.r:p.l<q.l;});
	int L=1,R=0;
	for(int i=1;i<=m;i++){
		while(R<q[i].r) D(++R);
		while(L>q[i].l) D(--L);
		while(R>q[i].r) D(R--);
		while(L<q[i].l) D(L++);
		ll s=ans;
		if(q[i].x) s+=d[q[i].x]?h0[a[q[i].x]]:h1[a[q[i].x]];
		anss[q[i].id]=s;
	}
	for(int i=1;i<=m;i++) printf("%lld\n",anss[i]);

	return 0;
}