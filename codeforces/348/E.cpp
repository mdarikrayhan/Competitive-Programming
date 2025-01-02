// LUOGU_RID: 128697138
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,mxd,id,st,ed,maxn,maxc;
int c[N],f[N],a[N],cnt,sum[N],maxd[N];
int cnte,h[N];
int dis[2][N],L[N],R[N],ans[N];
bool vis[N];
struct edge{
	int to,nxt,w;
}e[N<<1];
void add(int u,int v,int w){
	e[++cnte].to=v;
	e[cnte].nxt=h[u];
	e[cnte].w=w;
	h[u]=cnte;
}
void dfs(int x,int fa,int d,int p){
	if(c[x]&&mxd<d){
		mxd=d;
		id=x;
	}
	dis[p][x]=d;
	for(int i=h[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==fa) continue;
		f[y]=x;
		dfs(y,x,d+e[i].w,p);
	}
}
void dfs2(int x,int fa,int d){
	if(c[x]&&mxd<d){
		mxd=d;
	}
	sum[x]=c[x];
	for(int i=h[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==fa||vis[y]) continue;
		vis[y]=1;
		dfs2(y,x,d+e[i].w);
		sum[x]+=sum[y];
	}
}
signed main(){
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		c[x]=1;
	}
	for(int i=1;i<=n-1;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	mxd=-1;
	dfs(1,0,0,0);
	mxd=-1;
	ed=id;
	dfs(ed,0,0,0);
	st=id;
	dfs(st,0,0,1);
	for(int i=ed;;i=f[i]){
		a[++cnt]=i;
		vis[i]=1;
		if(i==st) break;
	}
	for(int i=1;i<=cnt;i++){
		mxd=-1;
		dfs2(a[i],0,0);
		maxd[i]=mxd;
	} 
	for(int i=1;i<=cnt&&a[i]!=st;i++){
		L[i]=L[i-1];
		if(dis[1][a[i]]>dis[0][a[i]]){
			L[i]+=sum[a[i]];
		}
	}
	for(int i=cnt;i>=1&&a[i]!=ed;i--){
		R[i]=R[i+1];
		if(dis[0][a[i]]>dis[1][a[i]]){
			R[i]+=sum[a[i]];
		}
	}
	for(int i=1;i<=cnt;i++) ans[a[i]]=L[i-1]+R[i+1];
	for(int i=1;i<=n;i++) ans[i]+=sum[i];
	for(int i=1;i<=n;i++){
		if(c[i]) continue;
		if(ans[i]>maxn){
			maxn=ans[i];
			maxc=1;
		}
		else if(ans[i]==maxn){
			maxc++;
		}
	}
	cout<<maxn<<" "<<maxc<<'\n';
    return 0;
}