
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin()+1, (x).begin()+1+n
#define ls id << 1
#define rs id << 1 | 1

const int inf = 0x3f3f3f3f3f3f3f3f;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int>fa(n+5), vis(m+5);
	iota(all(fa), 0);
	vector<vector<int>>g(n+5);
	vector<array<int,2>>E(m+5);
	for(int i = 1, u, v;i <= m;i++){
		cin >> u >> v;
		E[i] = {u, v};
	}

	auto find = [&](auto self, int x) -> int {
		return x == fa[x] ? x : fa[x] = self(self, fa[x]);
	};
	auto merg = [&](int a, int b) -> void {
		a = find(find, a);
		b = find(find, b);
		fa[a] = b;
	};

	for(int i = 1;i <= m;i++){
		auto [u, v] = E[i];
		if(find(find, u) != find(find, v)){
			vis[i] = 1;
			merg(u, v);
			//cerr << u << ' ' << v << ' ' << i << endl;
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}

	vector<array<int,20>>par(n+5);
	vector<int>dep(n+5);

	auto dfs = [&](auto self, int u, int fa) -> void {
		dep[u] = dep[fa] + 1;
		par[u][0] = fa;
		for(int i = 1;i < 20;i++) par[u][i] = par[par[u][i-1]][i-1];
		for(auto v : g[u]) if(v != fa){
			self(self, v, u);
		}
	};
	dfs(dfs, 1, 0);
	auto lca = [&](int u, int v) -> int {
		if(dep[u] < dep[v]) swap(u, v);
		for(int i = 19;i >= 0;i--) if(dep[par[u][i]] >= dep[v]) u = par[u][i];
		if(u == v) return u;
		for(int i = 19;i >= 0;i--) if(par[u][i] != par[v][i]) 
			u = par[u][i], v = par[v][i];
		return par[u][0];
	};

	vector<int>d(n+5);
	for(int i = 1;i <= m;i++) if(!vis[i]){
		auto [u, v] = E[i];
		if(dep[u] < dep[v]) swap(u, v);
		if(lca(u, v) == v) {
			d[u]--;
			for(int i = 19;i >= 0;i--) if(dep[par[u][i]] > dep[v]) u = par[u][i];
			d[u]++;
		}else{
			d[1]++;
			d[u]--;
			d[v]--;
		}
	}

	auto dfs2 = [&](auto self, int u, int fa) -> void {
		for(auto v : g[u]) if(v != fa){
			d[v] += d[u];
			self(self, v, u);
		}
	};
	dfs2(dfs2, 1, 0);

	for(int i = 1;i <= n;i++) {
		if(d[i]) cout << 0;
		else cout << 1;
	}
	cout << endl;
}

signed main(){

	IO;
	int t = 1;
	//cin >> t;
	while(t--) solve();

	return 0;
}
