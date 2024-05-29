// Problem: E. Distance Matching
// Contest: Codeforces - Codeforces Round 666 (Div. 1)
// URL: https://codeforces.com/contest/1396/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Author: nullptr_qwq
// 
// Powered by CP Editor (https://cpeditor.org)

// 私は猫です
 
#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define inf 1e9
#define infll 1e18
#define pii pair<int,int>
#define F(i,a,b) for(int i=a;i<=(b);i++)
#define dF(i,a,b) for(int i=a;i>=(b);i--)
#define wh(lzm) while(lzm--)
#define cmh(sjy) while(sjy--)
#define lowbit(x) (x&(-x))
#define HH printf("\n")
#define eb emplace_back
using namespace std;
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
void chkmax(int &x,int y){ x=max(x,y); }
void chkmin(int &x,int y){ x=min(x,y); }
const int mod=232232232,maxn=500005;
vector<int>g[maxn],vec[maxn];
int siz[maxn],n,dep[maxn],mxs[maxn],R,fa[maxn],top[maxn],deg[maxn];
ll k,mn,mx;
void init_dfs(int u,int fa=0){
	siz[u]=1;
	for(int v:g[u]) if(v^fa) init_dfs(v,u),siz[u]+=siz[v],chkmax(mxs[u],siz[v]);
	chkmax(mxs[u],n-siz[u]);
	if(mxs[u]<=n/2) R=u;
	if(fa) mn+=(siz[u]&1),mx+=min(siz[u],n-siz[u]);
}
set<pii>s[maxn];
void dfs0(int u,int moss,int t){
	siz[u]=1,dep[u]=dep[fa[u]=moss]+1,top[u]=t;
	for(int v:g[u]) if(v^moss) dfs0(v,u,t),siz[u]+=siz[v],++deg[u];
	if(deg[u]) s[t].insert(mkp(dep[u],u));
}
vector<int>tmp,bnds;
bool vis[maxn];
void dfs1(int u,int fa=0){
	if(!vis[u]) bnds.push_back(u);
	for(int v:g[u]) if(v^fa) dfs1(v,u);
}
void del(int u){
	vis[u]=1;
	if(!--deg[fa[u]])s[top[u]].erase(mkp(dep[fa[u]],fa[u]));
}
void construct(int u){
	tmp.clear();
	for(;(int)tmp.size()<2&&!vec[u].empty();vec[u].pop_back()){
		int x=vec[u].back();
		if(x^fa[u]&&!vis[x]) tmp.push_back(x);
	}
	if(!vis[u]) tmp.push_back(u);
	printf("%d %d\n",tmp[0],tmp[1]);
	del(tmp[0]),del(tmp[1]);
}
signed main(){
	n=read(),k=read();
	F(i,1,n-1){
		int u=read(),v=read();
		g[u].push_back(v),g[v].push_back(u);
	}
	init_dfs(1);
	if(mn>k||mx<k||((mx-k)&1)) return puts("NO"),0;
	puts("YES");
	F(i,1,n) vec[i]=g[i];
	set<pii>st;
	for(int v:g[R]) {
		dfs0(v,R,v);
		if(siz[v]>1) st.insert(mkp(siz[v],v));
	}
	k=mx-k;
	for(;k;){
		int u=(--st.end())->second,x=(--s[u].end())->second;
		st.erase(mkp(siz[u],u));
		if((dep[x]<<1)>k){
			x=s[u].lower_bound(mkp(k/2,0))->second;
			k-=(dep[x]<<1);
			construct(x);
			break;
		}
		k-=(dep[x]<<1);
		construct(x),siz[u]-=2;
		if(siz[u]>1) st.insert(mkp(siz[u],u));
	}
	dfs1(R);
	int len=bnds.size();
	F(i,0,len/2-1) printf("%d %d\n",bnds[i],bnds[len/2+i]);
}
// g++ A.cpp -o a -std=c++14 -O2