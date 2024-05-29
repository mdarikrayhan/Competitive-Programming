// LUOGU_RID: 157028587
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pushf push_front
#define pushb push_back
#define popf pop_front
#define popb pop_back
#define lowbit(x) (x&(-x))
using namespace std;
const int N = 110;
const ull msk = 20090617;

struct Edge{
	int u, v;
} ;

int n, m[N];

int sz[N];
bool vis[N];
vector<int> e[N];
vector<Edge> E[N];
map<vector<ull>, int> mp, mp2;
void dfs0(int u, int pr){
	sz[u] = 1;
	for (int v : e[u])
		if (v != pr){
			dfs0(v, u);
			sz[u] += sz[v];
		}
}
pii G;
int tot, mn;
void dfs1(int u, int pr){
	int val = tot - sz[u];
	for (int v : e[u])
		if (v != pr){
			val = max(val, sz[v]);
			dfs1(v, u);
		}
	if (val < mn)
		mn = val, G = {u, 0};
	else if (val == mn){
		if (!G.first)
			G.first = u;
		else
			G.second = u;
	}
}
ull shift(ull x){
	x ^= msk;
	x ^= x << 11;
	x ^= x >> 7;
	x ^= x << 13;
	return x ^ msk;
}
ull dfs2(int u, int pr){
	ull f = 1;
	vis[u] = true;
	for (int v : e[u])
		if (v != pr)
			f += shift(dfs2(v, u));
	return f;
}
vector<ull> get(vector<Edge> &E){
	for (int i = 1; i <= n; i++)
		e[i].clear();
	for (Edge i : E){
		e[i.u].push_back(i.v);
		e[i.v].push_back(i.u);
	}
	
	vector<ull> hsh;
	memset(vis, false, sizeof(vis));
	for (Edge i : E){
		if (!vis[i.u]){
			dfs0(i.u, 0);
			G = {0, 0}, mn = n, tot = sz[i.u], dfs1(i.u, 0);
			hsh.push_back(!G.second ? dfs2(G.first, 0) : min(dfs2(G.first, 0), dfs2(G.second, 0)));
		}
	}
	sort(hsh.begin(), hsh.end());
	return hsh; 
}

bool chk(vector<Edge> &E){
	mp2 = mp;
	for (int i = 1; i <= n; i++){
		vector<Edge> Tr;
		for (Edge j : E)
			if (j.u != i && j.v != i)
				Tr.push_back(j);
		vector<ull> tmp = get(Tr);
		if (--mp2[tmp] < 0)
			return false;
	}
	return true;
}

void solve(){
	scanf("%d %d", &n, &n);
	
	mp.clear();
	for (int i = 1; i <= n; i++)
		E[i].clear();
	for (int i = 1; i <= n; i++){
		scanf("%d", &m[i]);
		for (int j = 1, u, v; j <= m[i]; j++){
			scanf("%d %d", &u, &v);
			E[i].push_back({u, v});
		}
		mp[get(E[i])]++;
	}
	
	for (int i = 1; i <= n; i++)
		if (m[i] == n - 2){
			int sp = 0;
			static bool apr[N];
			memset(apr, false, sizeof(apr));
			for (Edge j : E[i])
				apr[j.u] = apr[j.v] = true;
			for (int j = 1; j <= n; j++)
				if (!apr[j])
					sp = j;
			for (int j = 1; j <= n; j++)
				if (apr[j]){
					E[i].push_back({j, sp});
					if (chk(E[i])){
						printf("YES\n");
						for (Edge k : E[i])
							printf("%d %d\n", k.u, k.v);
						return ;
					}
					E[i].pop_back();
				}
			printf("NO\n");
			return ;
		}
}

int main(){
	int T;
	scanf("%d", &T);
	for (int it = 1; it <= T; it++)
		solve();
	return 0;
}