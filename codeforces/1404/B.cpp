// LUOGU_RID: 159962813
#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << '\n';
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
std :: vector <int> adj[N];
void solve() {
	int n, a, b, da, db;
	std :: cin >> n >> a >> b >> da >> db;
	for(int i = 1; i <= n; ++ i) {
		adj[i].clear();
	}
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	if(da * 2 >= db) {
		std :: cout << "Alice\n";
		return ;
	}
	std :: vector <int> dis(n+1);
	auto dfs = [&](auto dfs, int u, int fa) -> void {
		for(auto &v : adj[u]) {
			if(v == fa) {
				continue ;
			}
			dis[v] = dis[u] + 1;
			dfs(dfs, v, u);
		}
	};
	dfs(dfs, b, 0);
	if(dis[a] <= da) {
		std :: cout << "Alice\n";
		return ;
	}
	int lgt = 0;
	auto dfs2 = [&](auto dfs2, int u, int fa, int d) -> void {
		lgt = max(lgt, d);
		for(auto &v : adj[u]) {
			if(v == fa) {
				continue ;
			}
			dfs2(dfs2, v, u, d + 1);
		}
	};
	int rt = 1;
	for(int i = 1; i <= n; ++ i) {
		if(dis[rt] < dis[i]) {
			rt = i;
		}
	}
	dfs2(dfs2, rt, rt, 0);
	if(lgt <= da * 2) {
		std :: cout << "Alice\n";
		return ;
	}
	std :: cout << "Bob\n";
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}