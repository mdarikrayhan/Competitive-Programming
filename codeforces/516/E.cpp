// LUOGU_RID: 160524824
#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long LL;
const LL Infll = 0x3f3f3f3f3f3f3f3f;
const int MS = 200005;

int exgcd(int a, int b, int &x, int &y) {
	if (!b) return x = 1, y = 0, a;
	int d = exgcd(b, a % b, y, x);
	return y -= a / b * x, d;
}

int N, M, D, G, B;
std::vector<int> g[MS], b[MS];
LL Ans;

int s[MS], d[MS], p[MS], cnt;
inline LL Try(int m, int n, int x, std::vector<int> &gv, std::vector<int> &bv) {
	if ((int)gv.size() == m) return -1;
	cnt = 0;
	for (int i : gv) s[++cnt] = (LL)i * x % m, d[cnt] = i, p[cnt] = cnt;
	for (int j : bv) s[++cnt] = (LL)j * x % m, d[cnt] = j, p[cnt] = cnt;
	std::sort(p + 1, p + cnt + 1, [](int i, int j) { return s[i] == s[j] ? i > j : s[i] < s[j]; });
	s[p[0] = 0] = s[p[cnt]] - m, s[p[cnt + 1] = cnt + 1] = s[p[1]] + m;
	LL dis = Infll, ans = 0;
	for (int I = 1; I <= cnt; ++I)
		dis = std::min(dis + (LL)n * (s[p[I]] - s[p[I - 1]]), (LL)d[p[I]]);
	for (int I = 1; I <= cnt; ++I) {
		dis = std::min(dis + (LL)n * (s[p[I]] - s[p[I - 1]]), (LL)d[p[I]]);
		if (s[p[I]] == s[p[I + 1]]) continue;
		if (s[p[I]] + 1 == s[p[I + 1]] && p[I] <= (int)gv.size()) continue;
		ans = std::max(ans, dis + (LL)n * (s[p[I + 1]] - s[p[I]] - 1));
	}
	return ans;
}

int main() {
	int X, Y;
	scanf("%d%d", &N, &M);
	if ((D = exgcd(M, N, X, Y)) > 200000) return puts("-1"), 0;
	for (int i = 0, x = scanf("%d", &B); i < B; ++i) scanf("%d", &x), b[x % D].push_back(x / D);
	for (int i = 0, x = scanf("%d", &G); i < G; ++i) scanf("%d", &x), g[x % D].push_back(x / D);
	(X += N) %= N, (Y += M) %= M;
	for (int i = 0; i < D; ++i) {
		if (g[i].empty() && b[i].empty()) return puts("-1"), 0;
		Ans = std::max(Ans, Try(M / D, N / D, Y, g[i], b[i]) * D + i);
		Ans = std::max(Ans, Try(N / D, M / D, X, b[i], g[i]) * D + i);
	}
	printf("%lld\n", Ans);
	return 0;
}