// LUOGU_RID: 160582042
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e17 + 7,B = 1e12 + 7;
struct edge{
	int to,nxt,w;
}e[200010];
int n,m,s,t,nE = 1,maxflow = 0;
int hd[1010],cur[1010],d[1010];
void add(int u,int v,int w){
	e[++nE] = (edge){v,hd[u],w};
	hd[u] = nE;
}
void addedge(int u,int v,int w){
	add(u,v,w),add(v,u,0);
}
bool bfs(){
	memset(d,0,sizeof(d));
	d[s] = 1;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = hd[u]; i; i = e[i].nxt){
			int v = e[i].to,w = e[i].w;
			if(!d[v] && w){
				d[v] = d[u] + 1;
				q.push(v);
				if(v == t) return 1;
			}
		}
	}
	return 0;
}
int dinic(int x,int flow){
	if(x == t || flow <= 0) return flow;
	int rest = flow,k;
	for(int& i = cur[x]; i; i = e[i].nxt){
		int v = e[i].to,w = e[i].w;
		if(w && d[v] == d[x] + 1){
			k = dinic(v,min(rest,w));
			if(!k) d[v] = 0;
			e[i].w -= k;
			e[i ^ 1].w += k;
			rest -= k;
			if(rest <= 0) break;
		}
	}
	return flow - rest;
}
int val[20],id[20][20],tot;
#define id(i,j) ((i - 1) * n + j)
bool vis[1010];
void dfs(int u){
	vis[u] = 1;
	for(int i = hd[u]; i; i = e[i].nxt){
		int v = e[i].to;
		if(!vis[v] && e[i].w > 0) dfs(v);
	}
}
signed main(){
	scanf("%lld %lld",&n,&m);
	s = ++tot,t = ++tot;
	for(int i = 1; i <= n; i++) for(int j = 0; j <= n; j++) id[i][j] = ++tot;
	for(int i = 1,u,v,w; i <= m; i++){
		scanf("%lld %lld %lld",&u,&v,&w),val[u] += w,val[v] -= w;
		for(int j = 0; j < n; j++) addedge(id[v][j],id[u][j + 1],INF); 
	}
	for(int i = 1; i <= n; i++){
		addedge(s,id[i][0],INF),addedge(id[i][n],t,INF);
		for(int j = 0; j < n; j++) addedge(id[i][j],id[i][j + 1],val[i] * j + B);
	}
	int flow;
	while(bfs()){
		memcpy(cur,hd,sizeof(hd));
		while(flow = dinic(s,INF)) maxflow += flow;
	}
	dfs(s);
	for(int i = 1; i <= n; i++){
		int ans;
		for(int j = 0; j <= n; j++){
			if(vis[id[i][j]]) ans = j;
		}
		printf("%lld ",ans);
	}
	return 0;
}