// LUOGU_RID: 133827902
#include <bits/stdc++.h>
const double inf = 1e18, eps = 1e-8;
const int maxn = 1 << 19;
int n, N, x[maxn], y[maxn], X, op[maxn]; double dis[maxn];
std::vector<int> Q[maxn], A[maxn], D[maxn];
struct node {double k, b; int id;} L[maxn];
bool operator < (const node &p1, const node &p2)
{
    double f1 = p1.k * X + p1.b, f2 = p2.k * X + p2.b;
    return fabs(f1 - f2) < eps ? p1.k < p2.k : f1 < f2;
}
std::set<node> s;
std::vector<std::pair<int, double>> e[maxn];
std::map<int, int> E[maxn];
void addedge (int u, int v, double w) {e[u].emplace_back(v, w);}
void addedges (int u, int v, double w) {addedge(u, v, w); addedge(v, u, w);}
signed main ()
{
	assert(scanf("%d", &n) == 1); N = n;
	for (int i = 0; i < n; i++) assert(scanf("%d%d", &x[i], &y[i]) == 2), x[i] += 10000, y[i] += 10000;
	for (int i = 0; i < n; i++)
	{
		Q[x[i]].emplace_back(i);
		if (x[i] != x[(i + 1) % n]) {double k = 1.0 * (y[(i + 1) % n] - y[i]) / (x[(i + 1) % n] - x[i]), b = y[i] - k * x[i]; L[i] = {k, b, i};}
		if (x[i] < x[(i + 1) % n]) A[x[i]].emplace_back(i), D[x[(i + 1) % n]].emplace_back(i), E[i][x[i]] = i, E[i][x[(i + 1) % n]] = (i + 1) % n;
		if (x[i] > x[(i + 1) % n]) A[x[(i + 1) % n]].emplace_back(i), D[x[i]].emplace_back(i), E[i][x[i]] = i, E[i][x[(i + 1) % n]] = (i + 1) % n;
		if (x[i] == x[(i + 1) % n]) addedges(i, (i + 1) % n, abs(y[i] - y[(i + 1) % n]));
	}
	for (X = 0; X <= 20000; X++)
	{
		auto solve = [&] (const int &p)
		{
			auto it1 = s.lower_bound({0, static_cast<double>(y[p]) + 1e-6, 0});
			auto it2 = s.lower_bound({0, static_cast<double>(y[p]) - 1e-6, 0});
			if (it1 != s.end() and op[it1 -> id])
			{
				auto [k, b, id] = *it1;
				if (!E[id].count(X)) E[id][X] = N++;
				addedge(E[id][X], p, k * X + b - y[p]);
			}
			if (it2 != s.begin() and !op[(--it2) -> id])
			{
				auto [k, b, id] = *it2;
				if (!E[id].count(X)) E[id][X] = N++;
				addedge(p, E[id][X], y[p] - k * X - b);
			}
		};
		for (int p: Q[X]) solve(p);
		for (int p: D[X]) s.erase(L[p]);
		std::sort(A[X].begin(), A[X].end(), [&] (const int &x, const int &y) {return L[x] < L[y];});
		for (int p: A[X]) if (auto it = s.insert(L[p]).first; it != s.begin()) op[p] = op[std::prev(it) -> id] ^ 1;
		for (int p: Q[X]) solve(p);
	}
	for (int i = 0; i < n; i++) if (x[i] != x[(i + 1) % n])
	{
		double k0 = sqrt(1 + L[i].k * L[i].k);
		for (auto it = std::next(E[i].begin()); it != E[i].end(); it = std::next(it))
			addedges(std::prev(it) -> second, it -> second, k0 * (it -> first - std::prev(it) -> first));
	}
	int S, T; assert(scanf("%d%d", &S, &T) == 2); S--; T--;
	for (int i = 0; i < N; i++) dis[i] = inf;
	std::priority_queue<std::pair<double, int>> Q;
	Q.emplace(dis[S] = 0, S);
	while (!Q.empty())
	{
		auto [d, u] = Q.top(); Q.pop(); if (d + dis[u] != 0) continue;
		for (auto [v, w]: e[u]) if (dis[v] > dis[u] + w) Q.emplace(-(dis[v] = dis[u] + w), v);
	}
	return !printf("%.12lf\n", dis[T]);
}