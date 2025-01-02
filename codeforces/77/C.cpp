// LUOGU_RID: 155203068
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

const int maxn = 1e5 + 5;
vector<int>t[maxn];
int a[maxn],dp[maxn],g[maxn];
int rt;

void dfs(int u,int f) {
	vector<pair<int,int>>edge;
	for (auto i : t[u]) {
		if (i == f) continue;
		dfs(i,u);
		edge.push_back({dp[i],i});
	}
	sort(edge.begin(),edge.end(),greater<>());
	int cnt = a[u];
	if (u != rt) cnt--;
	if (cnt == 0) return ;
	for (auto i : edge) {
		dp[u] += dp[i.second] + 2;
		cnt--;
		if (cnt == 0) return ;
	}
	for (auto i : edge) {
		if (cnt >= g[i.second]) {
			dp[u] += g[i.second] * 2;
			cnt -= g[i.second];
		}
		else {
			dp[u] += cnt * 2;
			return ;
		}
	}
	g[u] = cnt;
	//dbg(u,g[u]);
}

void solve() {
	int n;cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i < n;i++) {
		int u,v;cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	cin >> rt;
	dfs(rt,0);
	cout << dp[rt] << '\n';
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int T = 1;
	//cin >> T;
	while (T--) solve();
	return 0;
}