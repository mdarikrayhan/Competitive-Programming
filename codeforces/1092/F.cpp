#include <bits/stdc++.h>
 
using namespace std;
 
#define int int64_t
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    vector<int>A(N);
    for(auto &a : A) cin >> a;
    vector adj(N, vector<int>());
    for(int i = 1; i < N; ++i) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>subtree(N, 0);
    vector<int>dp(N, 0);
    int ans = 0;

    auto dfs1 = [&](auto self, int v, int p, int d) -> void {
        dp[0] += d * A[v];
        subtree[v] = A[v];
        for(auto to : adj[v]) {
            if(to == p) continue;
            self(self, to, v, d + 1);
            subtree[v] += subtree[to];
        }
    };

    auto dfs2 = [&](auto self, int v, int p) -> void {
        ans = max(ans, dp[v]);
        for(auto to : adj[v]) {
            if(to != p) {
                dp[to] = dp[v] + subtree[0] - 2 * subtree[to];
                self(self, to, v);        
            }
        }
    };
 
    dfs1(dfs1, 0, -1, 0);
    dfs2(dfs2, 0, -1);

    cout << ans << '\n';

    return (0 - 0);
}
	     	 	 			  								 	     	