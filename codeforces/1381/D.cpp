// LUOGU_RID: 160508246
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e16 + 7;
struct edge{
	int to,nxt;
}e[200010];
int t,n,S,T,L,rt,nE = 0;
int dep[200010],hd[200010],f[200010][20],g[200010][3],id[200010],sz[200010];
void add(int u,int v){
	e[++nE] = (edge){v,hd[u]};
	hd[u] = nE;
}
void upd(int u,int v){
	if(v > g[u][0]) g[u][2] = g[u][1],g[u][1] = g[u][0],g[u][0] = v;
	else if(v > g[u][1]) g[u][2] = g[u][1],g[u][1] = v;
	else if(v > g[u][2]) g[u][2] = v;
}
void dfs(int u,int fa){
	f[u][0] = fa;
	dep[u] = dep[fa] + 1;
	for(int i = 1; i < 20; i++) f[u][i] = f[f[u][i - 1]][i - 1];
	g[u][0] = -INF,g[u][1] = -INF,g[u][2] = -INF;
	id[u] = u;
	bool flag = 0;
	for(int i = hd[u]; i; i = e[i].nxt){
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v,u);
		upd(u,g[v][0] + 1);
		if(dep[id[v]] > dep[id[u]]) id[u] = id[v];
		flag = 1;
	}
	if(!flag) g[u][0] = 0;
}
int LCA(int u,int v){
	if(dep[u] < dep[v]) swap(u,v);
	for(int i = 19; i >= 0; i--) if(dep[f[u][i]] >= dep[v]) u = f[u][i];
	if(u == v) return u;
	for(int i = 19; i >= 0; i--) if(f[u][i] != f[v][i]) u = f[u][i],v = f[v][i];
	return f[u][0];
}
int anc(int u,int k){
	for(int i = 19; i >= 0; i--) if(k & (1LL << i)) u = f[u][i];
	return u;
}
int dis(int u,int v){
	return dep[u] + dep[v] - 2 * dep[LCA(u,v)];
}
unordered_map<int,int>mp;
void solve(int u,int fa,int pre){
	upd(u,pre);
	vector<int>tmp,P,N;
	tmp.push_back(-INF);
	for(int i = hd[u]; i; i = e[i].nxt){
		int v = e[i].to;
		if(v == fa) continue;
		tmp.push_back(g[v][0] + 1);
	}
	int sz = (int)(tmp.size());
	P.resize(sz + 1),N.resize(sz + 1);
	P[0] = -INF;
	for(int j = 1; j < sz; j++) P[j] = max(P[j - 1],tmp[j]);
	N[sz] = -INF;
	for(int j = sz - 1; j >= 0; j--) N[j] = max(N[j + 1],tmp[j]);
	int oo = 0;
	for(int i = hd[u]; i; i = e[i].nxt){
		int v = e[i].to;
		if(v == fa) continue;
		oo++;
		int coef = max(P[oo - 1],N[oo + 1]);
		solve(v,u,max(pre,coef) + 1);
	}
}
signed main(){
	scanf("%lld",&t);
	int timer = 0;
	while(t--){
		timer++;
		scanf("%lld %lld %lld",&n,&S,&T);
		nE = 0;
		for(int i = 0; i <= n; i++) hd[i] = 0;
		for(int i = 1,u,v; i < n; i++){
			scanf("%lld %lld",&u,&v);
			add(u,v),add(v,u);
		}
		dfs(1,0);
		solve(1,0,0);
		L = dis(S,T);
		rt = -1;
		for(int i = 1; i <= n; i++) if(g[i][2] >= L) rt = i;
//		for(int i = 1; i <= n; i++) printf("%lld %lld %lld\n",g[i][0],g[i][1],g[i][2]);
//		if(timer == 13) printf("%lld %lld %lld\n",g[rt][0],g[rt][1],g[rt][2]);
		if(rt == -1){
			printf("NO\n");
			continue;
		}
		dfs(rt,0);
		int u = S,v = T;
		mp.clear();
		while(LCA(u,v) != u && LCA(u,v) != v){
			if(id[u] == u){
				if(mp[u * (n + 1) + v]) break;
				mp[u * (n + 1) + v] = 1;
				swap(u,v);
				continue;
			}
			int tmp = dep[id[u]] - dep[u];
			u = id[u];
			if(dep[v] - dep[LCA(u,v)] <= tmp){
				v = anc(u,L);
				break;
			}
			else v = anc(v,tmp);
			if(mp[u * (n + 1) + v]) break;
			mp[u * (n + 1) + v] = 1;
			swap(u,v);
		}
		if(LCA(u,v) == u || LCA(u,v) == v) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 