#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	auto solve = [&](){
		int n;
		cin >> n;
		vector <int> a(n + 1);

		vector <vector <int>>  g(n + 1);
		for(int i=1;i<n;i++){
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector <int> sz(n + 1);
		vector <int> dp(n + 1);
		vector <int> dep(n + 1);
		auto dfs = [&](auto && self,int u,int f)->void{
			sz[u] = 1; dep[u] = dep[f] + 1;
			for(auto v : g[u]){
				if(v==f) continue;
				self(self,v,u);
				sz[u] += sz[v];

			}
		};
		auto dfs2 = [&](auto && self,int u,int f)->void{
			for(auto v : g[u]){
				if(v==f) continue;
				dp[v] = dp[u] + n - 2*sz[v];
				self(self,v,u);
			}
		};
		int id = 0;
		dfs(dfs,1,0);
		for(int i =1;i<=n;i++) {
			dp[1] += dep[i];
		}
		dfs2(dfs2,1,0);
		int ans = 0;
		for(int i=1;i<=n;i++){
			if(dp[i] > ans){
				id = i;
				ans = dp[i];
			}
		}
		cout << ans ;


	};
	int t=1;
//	cin >> t;
	for(int k=1;k<=t;k++){
		solve();
	}
	return 0;
}