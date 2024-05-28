// LUOGU_RID: 159722426
#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 10;

int n, k, deg[N], ans, rt;

vector<int> G[N];
inline void add(int u, int v) {G[u].emplace_back(v), G[v].emplace_back(u);}

int dfs(int u, int fa) {
	if (deg[u] == 1) return 1;
	int dm = 0;
	for (int v : G[u]) if (v != fa) {
		int d = dfs(v, u);
		if (dm + d > k) ans++, dm = min(dm, d);
		else dm = max(dm, d);
	}
	return dm ? dm + 1 : 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> k;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v, add(u, v);
		if (++deg[u] >= 2) rt = u;
		if (++deg[v] >= 2) rt = v;
	}
	cout << (dfs(rt, -1) > 0) + ans;
	return 0;
}