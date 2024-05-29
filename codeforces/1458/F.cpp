// LUOGU_RID: 138650967
#include<bits/stdc++.h>
#define within :
#define LJY main
using namespace std;
typedef long long ll;
const int N=1e5+5;
inline int read(){
	char ch=getchar();int x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
int n,head[N],ce;struct E{int v,nxt;}e[N<<1];
void addedge(int u,int v){e[++ce]=E{v,head[u]};head[u]=ce;}
int dep[N],dfn[N],cdfn,Tst[17][N],lg[N]={-1};
int Get(int x,int y){return dep[x]<dep[y]?x:y;}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;Tst[0][dfn[u]=++cdfn]=fa;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v!=fa) dfs(v,u);
	}
}
int LCA(int u,int v){
	if(u==v) return u;u=dfn[u];v=dfn[v];
	if(u>v) swap(u,v);int d=lg[v-u++];
	return Get(Tst[d][u],Tst[d][v-(1<<d)+1]);
}
int dist(int u,int v){return dep[u]+dep[v]-(dep[LCA(u,v)]<<1);}
struct Node{int u,v,d;void gmax(int a,int b){int c=dist(a,b);if(c>d) u=a,v=b,d=c;}}f[17][N];
Node operator+(Node a,Node b){
	if(a.u==b.u&&a.v==b.v) return a;
	Node c=a.d<b.d?b:a;
	if(a.u==b.u) c.gmax(a.v,b.v);
	else if(a.u==b.v) c.gmax(a.v,b.u);
	else if(a.v==b.u) c.gmax(a.u,b.v);
	else if(a.v==b.v) c.gmax(a.u,b.u);
	else c.gmax(a.u,b.u),c.gmax(a.v,b.u),c.gmax(a.u,b.v),c.gmax(a.v,b.v);
	if(c.u>c.v) swap(c.u,c.v);return c;
}ll ans;
int calc(int l,int r){
	int d=lg[r-l+1];return (f[d][l]+f[d][r-(1<<d)+1]).d;
}
void solve(int l,int r){
	if(l==r) return;int mid=(l+r)>>1;
	solve(l,mid);solve(mid+1,r);
	ll tot=0;for(int i=mid+1;i<=r;i++) tot+=calc(mid,i);ans+=tot;
	for(int i=mid-1;i>=l;i--){
		int nw=mid+1;
		while(nw<=r){
			ll dt=calc(i,nw)-calc(i+1,nw);
			int L=nw,R=r,ttt=nw;
			while(L<=R){
				int M=(L+R)>>1;
				if(calc(i,M)-calc(i+1,M)==dt) L=(ttt=M)+1;
				else R=ttt-1;
			}tot+=(ttt-nw+1)*dt;
			nw=ttt+1;
		}ans+=tot;
	}
}
signed LJY(){
	n=read();int u,v;
	for(int i=1;i<n;i++){
		u=read();v=read();
		addedge(u,v);addedge(v,u);
	}dfs(1,0);
	for(int i=1;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=16;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			Tst[i][j]=Get(Tst[i-1][j],Tst[i-1][j+(1<<i-1)]);
	for(int i=1;i<=n;i++) f[0][i]=Node{i,i,0};
	for(int i=1;i<=16;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			f[i][j]=f[i-1][j]+f[i-1][j+(1<<i-1)];
	solve(1,n);printf("%lld\n",ans);
	return 0;
}