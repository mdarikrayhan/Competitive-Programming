// LUOGU_RID: 159836564
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=0;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return f?x:-x;

}

void cmax(int &x,int v){x=max(x,v);}
void cmin(int &x,int v){x=min(x,v);}

const int N=2e5+5;
#define fi first
#define se second
#define mk make_pair
vector<pair<int,double>>G[N];
int sz[N],n,mx[N],rt,all;

double val[N],dis[N];
bool vis[N];

void getroot(int u,int fa){
	sz[u]=1,mx[u]=0;
	for(auto e:G[u]){
		int v=e.fi;
		if(v==fa||vis[v]) continue;
		getroot(v,u),sz[u]+=sz[v],cmax(mx[u],sz[v]);
	}
		cmax(mx[u],all-sz[u]);
		if(mx[u]<mx[rt]||rt==0) rt=u;
}	
vector<int>nodes;
void dfs(int u,int fa)
{
		nodes.emplace_back(u);
		for(auto e:G[u]){
			int v=e.fi;double w=e.se;
			if(v==fa) continue;
			dis[v]=dis[u]+w,dfs(v,u);
		}
}
double ans=1e30;
int ansu=0;
void solve(int u){
	if(vis[u]) return ;vis[u]=1,dis[u]=0;
	double sum=0,mx=0;int to=0;
	for(auto e:G[u]){
		int v=e.fi;double w=e.se;
		nodes.clear(),dis[v]=w,dfs(v,u);
		double dt=0;for(int x:nodes) dt+=sqrt(dis[x])*val[x];
		sum+=dt;if(dt>mx) mx=dt,to=v;
	}
	double cur=0;
	for(int i=1;i<=n;i++) cur+=dis[i]*val[i]*sqrt(dis[i]);
	if(cur<ans) ans=cur,ansu=u;
	if(mx>sum-mx) rt=0,all=sz[to],getroot(to,u),getroot(rt,u),solve(rt);
}

signed main(void){
	n=read();
	for(int i=1;i<=n;i++)  val[i]=read();
	for(int i=1;i<=n-1;i++){
		int u=read(),v=read();double w=read();
		G[u].emplace_back(mk(v,w)),G[v].emplace_back(mk(u,w));
	}
	rt=0,all=n,getroot(1,0),getroot(rt,0),solve(rt);
	cout<<ansu<<" "<<fixed<<setprecision(9)<<ans<<endl;
	
	return 0;
}
