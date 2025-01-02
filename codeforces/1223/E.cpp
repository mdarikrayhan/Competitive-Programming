// LUOGU_RID: 158914733
// LUOGU_RID: 158911172
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)

void err() {
	std::cout << std::endl;
}

template<class T, class... Ts>
void err(T arg, Ts &... args) {
	std::cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}


struct node{
	int v,w,dp0,dp1;//dp0有K-1，dp1有k
	bool operator < (const node & b)const {
		return  dp0 + w - dp1 > b.dp0 + b.w - b.dp1;
	}
};
const int maxn = 5e5 + 5;
vector<node>t[maxn];

void solve() {
	int n,k;cin >> n >> k;
	for (int i = 1;i <= n;i++) t[i].clear();
	for (int i = 1;i < n;i++) {
		int u,v,w;cin >> u >> v >> w;
		t[u].push_back({v,w});
		t[v].push_back({u,w});
	}
	vector dp(n + 10,vector<int>(2,0));
	auto dfs = [&](auto dfs,int u,int f) -> void {
		for (auto &i : t[u]) {
			if (i.v == f) continue;
			dfs(dfs,i.v,u);
			i.dp0 = dp[i.v][0];
			i.dp1 = dp[i.v][1];
			//dbg(i.dp0,i.dp1,i.v);
		}
		sort(t[u].begin(),t[u].end());
		int cnt = 0;
		for (auto i : t[u]) {
		//	dbg(u,i.v,i.dp1,i.dp0);
			if (i.v == f) continue;
			if (i.dp0 + i.w - i.dp1 <= 0) {
				dp[u][0] += i.dp1;
				dp[u][1] += i.dp1;
			}
			else {
				cnt++;
				if (cnt < k) {
					dp[u][0] += i.dp0 + i.w;
					dp[u][1] += i.dp0 + i.w;
				}
				else if (cnt == k) {
					dp[u][1] += i.dp0 + i.w;
					dp[u][0] += i.dp1;
				}
				else {
					dp[u][1] += i.dp1;
					dp[u][0] += i.dp1;
				}
			}
		}
	//	dbg(u,dp[u][0],dp[u][1]);
	};
	dfs(dfs,1,0);
	cout << dp[1][1] << '\n';
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}