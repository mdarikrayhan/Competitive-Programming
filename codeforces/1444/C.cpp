// LUOGU_RID: 160262524
#include <bits/stdc++.h>
using lld = long long;
const int N = 5e5 + 5;
int n, m, K, C[N], F[N], dep[N], dis[N], pstk;
bool flg[N];
std::vector<int> to[N], col[N];
int Find(int x, int &d) {
	if (x == F[x]) return x;
	d ^= dis[x];
	return Find(F[x], d);
}
struct Undo {
	int u, v, f, ds, dp;
	void undo() { F[u] = f, dis[u] = ds, dep[v] = dp; }
} stk[N];
bool Link(int u, int v) {
	int du = 0, dv = 0;
	u = Find(u, du), v = Find(v, dv);
	if (dep[u] > dep[v]) std::swap(u, v), std::swap(du, dv);
	if (u == v) return !(du ^ dv ^ 1);
	stk[++pstk] = { u, v, F[u], dis[u], dep[v] };
	F[u] = v, dis[u] = 1 ^ du ^ dv;
	dep[v] += dep[u] == dep[v];
	return true;
}
int main() {
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= n; i++) scanf("%d", &C[i]), col[C[i]].push_back(i), F[i] = i, dep[i] = 1;
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		if (C[u] == C[v]) {
			if (!flg[C[u]]) flg[C[u]] |= !Link(u, v);
		} else to[u].push_back(v), to[v].push_back(u);
	}
	lld ans = 0;
	for (int i = 1; i <= K; i++) ans += !flg[i];
	ans = 1ll * ans * (ans - 1);
	for (int i = 1; i <= K; i++) {
		if (flg[i]) continue;
		std::vector<int> SC;
		std::vector<std::pair<int, int>> T;
		for (int u : col[i]) for (int v : to[u])
			if (!flg[C[v]]) T.push_back({ u, v }), SC.push_back(C[v]);
		std::sort(SC.begin(), SC.end());
		SC.erase(std::unique(SC.begin(), SC.end()), SC.end());
		std::sort(T.begin(), T.end(), [](auto x, auto y) { return C[x.second] < C[y.second]; });
		int p = 0;
		for (int c : SC) {
			int sz = pstk, f = 0;
			for (; p < T.size(); p++) {
				int u = T[p].first, v = T[p].second;
				if (C[v] != c) break;
				if (!f) f |= !Link(u, v);
			}
			ans -= f;
			while (pstk > sz) stk[pstk--].undo();
		}
	}
	printf("%lld\n", ans / 2);
	return 0;
}