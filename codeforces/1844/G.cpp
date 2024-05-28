// LUOGU_RID: 160467446
#include<iostream>
#include<cstring>
#include<vector>

const int N = 2e5, L = 60;
std::vector<int>g[N];
unsigned long long d[N], t[N];
bool vs[N];
int n, u[N], v[N], f[N], p[N], fa[N];
int gf(int u) { return ~f[u] ? f[u] = gf(f[u]) : u; }
void dfs(int u) {
	if (vs[u] = 1, u && vs[u-1]) p[u] = gf(u-1);
	if (u < n-1 && vs[u+1]) p[u+1] = gf(u+1);
	for (int x, y; int v : g[u]) if (vs[v]) fa[u] = v;
		else dfs(v), f[gf(v)] = u;
}
int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	std::cin >> n, memset(f, -1, n*4);
	for (int i=1; i<n; i++) std::cin >> u[i] >> v[i],
		g[--u[i]].push_back(--v[i]), g[v[i]].push_back(u[i]);
	for (int i=1; i<n; i++) std::cin >> d[i];
	dfs(0);
	for (int i=0, j; i<L; i++) for (j=1; j<n; j++)
		t[j] |= t[p[j]]*2-t[j-1]+d[j]&1ll<<i;
	for (int i=1; i<n; i++) if (t[i]<=t[fa[i]] ||
			t[i]+t[i-1]-2*t[p[i]]!=d[i])
		return std::cout << -1, 0;
	for (int i=1; i<n; i++) std::cout <<
		std::min(t[u[i]]-t[v[i]], t[v[i]]-t[u[i]]) << '\n';
}
