// Problem: G. Optimizations From Chelsu
// Contest: Codeforces - Good Bye 2023
// URL: https://codeforces.com/contest/1916/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Author: nullptr_qwq
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define ll long long
#define int long long
#define pb push_back
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
void chkmax(int &x,int y){ x=max(x,y); }
void chkmin(int &x,int y){ x=min(x,y); }
const int mod=998244353,maxn=200005,lim=1000000000000ll;
vector<pii>g[maxn];
int vis[maxn],sz[maxn],mxs[maxn],R,sum,n,ln[maxn],gd[maxn],ans;
map<int,pii>mpf,mps;
void dfs(int u,int fa=0){
	sz[u]=1,mxs[u]=0;
	for(auto [v,w]:g[u]) if(!vis[v]&&v^fa) dfs(v,u),sz[u]+=sz[v],chkmax(mxs[u],sz[v]);
	chkmax(mxs[u],sum-sz[u]);
	if(mxs[u]<mxs[R]) R=u;
}
void calc(int u,int fa){
	for(auto [v,w]:g[u]) if(!vis[v]&&v^fa) gd[v]=__gcd(gd[u],w),ln[v]=ln[u]+1,calc(v,u);
}
void dfs1(int u,int fa,int top){
	chkmax(ans,gd[u]*ln[u]);
	int col=gd[u];
	pii pf=mpf[col],ps=mps[col];
	pii tmp=make_pair(ln[u],top);
	if(ln[u]>pf.first) {
		if(top!=pf.second) ps=pf,pf=tmp;
		else pf=tmp;
	}
	else if(ln[u]>ps.first&&top!=pf.second) ps=tmp;
	mpf[col]=pf,mps[col]=ps;
	for(auto [v,w]:g[u]) if(!vis[v]&&v^fa) dfs1(v,u,top);
}
void dfs2(int u,int fa,int top){
	if(2*ln[u]*gd[u]>=ans){
		int col=gd[u];
		if(make_pair(ln[u],top)==mpf[col]||make_pair(ln[u],top)==mps[col]){
			F(i,1,ln[u]) {
				if(i*col>lim) break;
				if(mpf[i*col].second==top) chkmax(ans,col*(ln[u]+mps[i*col].first));
				else chkmax(ans,col*(ln[u]+mpf[i*col].first));
			}
		}
	}
	for(auto [v,w]:g[u]) if(!vis[v]&&v^fa) dfs2(v,u,top);
}
void DFS(int u){
	vis[u]=1,ln[u]=gd[u]=0,mps.clear(),mpf.clear();
	for(auto [v,w]:g[u]) if(!vis[v]) gd[v]=w,ln[v]=1,calc(v,u);
	for(auto [v,w]:g[u]) if(!vis[v]) dfs1(v,u,v);
	for(auto [v,w]:g[u]) if(!vis[v]) dfs2(v,u,v);
	for(auto [v,w]:g[u]) if(!vis[v]) sum=sz[v],mxs[R=0]=inf,dfs(v),DFS(R);
}
int testcase,debug_flag;
void dfs_output(int u,int fa=0){ for(auto [v,w]:g[u]) if(v^fa) cout<<u<<' '<<v<<' '<<w<<'\n',dfs_output(v,u); }
void output(){ cout<<n<<'\n'; dfs_output(1); }
void solve(){
	n=read(),ans=0;
	F(i,1,n) g[i].clear(),vis[i]=mxs[i]=sz[i]=0;
	F(i,1,n-1) {
		int u=read(),v=read(),w=read();
		g[u].push_back(make_pair(v,w)),g[v].push_back(make_pair(u,w));
	}
	mxs[R=0]=sum=n,dfs(1),DFS(R);
	cout<<ans<<'\n';
}
signed main(){
	int sjy=read();
	cmh(sjy) solve();
}