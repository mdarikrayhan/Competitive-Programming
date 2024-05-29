// Problem: F. Edge Queries
// Contest: Codeforces - Codeforces Round 840 (Div. 2) and Enigma 2022 - Cybros LNMIIT
// URL: https://codeforces.com/problemset/problem/1763/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
const int mod=998244353,maxn=500005;
void chkmax(int &x,int y){ x=max(x,y); }
void chkmin(int &x,int y){ x=min(x,y); }
vector<int>e[maxn],g[maxn];
int low[maxn],dfn[maxn],tim,st[maxn],top,id,n,sjy,cmh;
void DFS(int u){
	dfn[u]=low[u]=++tim,st[++top]=u;
	for(int v:e[u])
		if(!dfn[v]){
			DFS(v),chkmin(low[u],low[v]);
			if(low[v]!=dfn[u]) continue;
			++id;
			while(1){
				int x=st[top--];
				g[id].push_back(x),g[x].push_back(id);
				if(x==v) break;
			}
			g[id].push_back(u),g[u].push_back(id);
		}
		else chkmin(low[u],dfn[v]);
}
int fa[maxn],anc[maxn][20],dep[maxn],pre[maxn],val[maxn];
void dfs(int u,int f=0){ fa[u]=f; for(int v:g[u]) if(v^f) dfs(v,u); }
void dfs1(int u,int f=0){ dep[u]=dep[anc[u][0]=f]+1,pre[u]=pre[f]+val[u]; F(i,1,19) anc[u][i]=anc[anc[u][i-1]][i-1]; for(int v:g[u]) if(v^f) dfs1(v,u); }
int lca(int u,int v){
	if(u==v)return u;
	if(dep[u]<dep[v]) swap(u,v);
	dF(i,19,0) if(dep[anc[u][i]]>=dep[v]) u=anc[u][i];
	if(u==v)return u;
	dF(i,19,0) if(anc[u][i]^anc[v][i]) u=anc[u][i],v=anc[v][i];
	return fa[u];
}
signed main(){
	id=n=read(),sjy=read();
	cmh(sjy){
		int u=read(),v=read();
		e[u].push_back(v),e[v].push_back(u);
	}
	DFS(1),dfs(1);
	F(u,1,n) for(int v:e[u]) if(u<v){
		if(fa[u]==fa[v]) val[fa[u]]++;
		else if(fa[fa[u]]==v) val[fa[u]]++;
		else val[fa[v]]++;
	}
	F(i,n+1,id) if(val[i]==1) val[i]=0;
	dfs1(1),cmh=read();
	cmh(cmh){
		int u=read(),v=read(),t=lca(u,v);
		printf("%d\n",pre[u]+pre[v]-pre[t]-pre[fa[t]]);
	}
}