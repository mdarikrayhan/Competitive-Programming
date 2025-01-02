/*
code copied from amiya, problem is the same as 1260-F which I have already solved
*/



#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=501000;
int q[N],f[N],vis[N],sz[N],ms[N],col[N];
vector<PII> br,e[N];
ll ret=1,ret2=1,dp[N];
int m,n,u[N],v[N],w[N],ww[10],sn;
pair<int,ll> c[N];
int find(int u) {
	int t=1;q[0]=u;f[u]=-1;
	rep(i,0,t) {
		u=q[i];
		rep(j,0,e[u].size()) {
			int v=e[u][j].fi;
			if (!vis[v]&&v!=f[u]) f[q[t++]=v]=u;
		}
		ms[q[i]]=0;
		sz[q[i]]=1;
	}
	sn=t;
	for (int i=t-1;i>=0;i--) {
		ms[q[i]]=max(ms[q[i]],t-sz[q[i]]);
		if (ms[q[i]]*2<=t) return q[i];
		sz[f[q[i]]]+=sz[q[i]];
		ms[f[q[i]]]=max(ms[f[q[i]]],sz[q[i]]);
	}
	return 0;
}
void pre(int u,int f) {
	sz[u]=1;
	for (auto p:e[u]) {
		int v=p.fi,id=p.se;
		if (v==f) continue;
		pre(v,u);
		sz[u]=sz[u]+sz[v];
		ret=ret*powmod(w[id],(ll)sz[v]*(n-sz[v]))%mod;
	}
}
pair<int,ll> operator * (pair<int,ll> a,pair<int,ll> b) {
	return mp(a.fi+b.fi,a.se*b.se%mod);
}
pair<int,ll> query(int x) {
	pair<int,ll> s=mp(0,1);
	for (;x;x-=x&-x) s=s*c[x];
	return s;
}
void modify(int x,pair<int,ll> s) {
	for (;x<=m;x+=x&-x) c[x]=c[x]*s;
}
void dfs(int u,int f,int dep,ll W) {
	pair<int,ll> cw=query(4*sn-1-dep);
	ret2=(ret2*powmod(W,cw.fi)%mod*cw.se)%mod;
//	printf("fa %d %d %lld\n",u,dep-2*sn,W);
	br.pb(mp(dep,W));
	for (auto p:e[u]) {
		if (p.fi==f||vis[p.fi]) continue;
//		printf("gg %d %d\n",p.se,w[p.se]);
		dfs(p.fi,u,dep+ww[col[p.se]],W*w[p.se]%mod);
	}
}
void solve(int u) {
	u=find(u);
	m=4*sn;
	for (int i=0;i<=m;i++) c[i]=mp(0,1);
	modify(2*sn,mp(1,1));
	for (auto p:e[u]) {
		int v=p.fi;
		if (vis[v]) continue;
		br.clear();
		dfs(v,u,2*sn+ww[col[p.se]],w[p.se]);
		for (auto p:br) modify(p.fi,mp(1,p.se));
	}
	vis[u]=1;
	for (auto p:e[u]) if (!vis[p.fi]) solve(p.fi);
}
int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d%d%d",u+i,v+i,w+i,col+i);
		e[u[i]].pb(mp(v[i],i));
		e[v[i]].pb(mp(u[i],i));
	}
	pre(1,0);
	ww[0]=2; ww[1]=-1;
	solve(1);
//	printf("%lld\n",ret2);
	rep(i,1,n+1) vis[i]=0;
	ww[0]=-1; ww[1]=2;
	solve(1);
	ret=ret*powmod(ret2,mod-2)%mod;
	printf("%lld\n",ret);
}
