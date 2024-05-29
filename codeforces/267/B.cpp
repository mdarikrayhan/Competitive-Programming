#include <bits/stdc++.h>
using namespace std;

#define For(i, n) for(int i = 0; i < (n); ++i)
#define rFor(i, n) for(int i = (n - 1); i >= 0; i--)
#define FoR(i, st, ed) for(int i = (st); i < (ed); ++i)
#define rFoR(i, st, ed) for(int i = (ed) - 1; i >= (st); --i)
#define FOR(i, st, ed) for(int i = (st); i <= (ed); ++i)
#define rFOR(i, st, ed) for(int i = (ed); i >= (st); --i)
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define all(a) a.begin(),a.end()
using i64 = long long;
const int INF  = 1e9+7;
const int MAX = 1e5;
const int mod  = 1e9+7;
const double eps = 0.001;
//--------------------------------------------
void solve() {
	int n;
	cin >> n;
	vector<vector<pair<int, pii> > > adj(7);
	For(i, n){
		int u, v;
		cin >> u >> v;
		adj[u].pb({v, {i, 0}});
		adj[v].pb({u, {i, 1}});
	}

	int cnt = 0, flag = 0;
	FOR(i, 0, 6){
		if(adj[i].size() % 2){
			++ cnt;
		}
	}
	if(cnt != 0 && cnt != 2 || flag == 2){
		cout << "No solution\n";
		return;
	}

	vector<bool> vis(n);
	vector<int> pos(7);
	vector<pii> ans;
	function<void(int)> dfs = [&](int u){
		while(pos[u] < adj[u].size()){
			pair<int, pii> p = adj[u][pos[u]];
			if(vis[p.second.first]){
				++ pos[u]; 
				continue;
			}
			++ pos[u]; 
			vis[p.second.first] = 1;
			dfs(p.first);
			ans.pb({p.second.first + 1,(p.second.second ? '+' : '-')});
		}
	};

	auto print = [&](){
		if(ans.size() < n){
			cout << "No solution\n";
		}
		else{
			for(pii p : ans){
				cout << p.first << " " << p.second << "\n";
			}
		}
	};

	FOR(i, 0, 6){
		if(adj[i].size() % 2){
			dfs(i);
			print();
			return;
		}
	}
	FOR(i, 0, 6){
		if(adj[i].size()){
			dfs(i);
			print();
			return;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);

	int t = 1;
	//cin >> t;
	while (t--)solve();
	return 0;
}
/*
*/