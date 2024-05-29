#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 5;
const ll MOD = 1000000028000000147;
int n, m, u, v, w, s, t, c, dfn[N], fa[N], fw[N];
ll f[50][1 << 17 | 1];
basic_string<pii> adj[N];
ll PLUS(ll x, ll y) { return (x += y) >= MOD ? x - MOD : x; }
void DFT(ll *f, bool o)
{
	for (int i = 0; i < 17; i++)
		for (int j = 0; j < 1 << 17; j++)
			if (!(j & 1 << i))
			{
				int k = j | 1 << i;
				ll _ = PLUS(f[j], MOD - f[k]);
				f[j] = PLUS(f[j], f[k]), f[k] = _;
				if (o)
					f[j] = f[j] + (f[j] & 1 ? MOD : 0) >> 1, f[k] = f[k] + (f[k] & 1 ? MOD : 0) >> 1;
			}
}
void dfs(int u)
{
	dfn[u] = ++t;
	for (pii e : adj[u])
	{
		int v = e.first, w = e.second;
		if (!dfn[v])
			fa[v] = u, fw[v] = w, dfs(v);
		else if (v != fa[u] && dfn[v] < dfn[u])
		{
			f[++c][w] = 1;
			for (int x = u; x ^ v; x = fa[x])
				f[c][fw[x]]++;
			DFT(f[c], 0);
		}
	}
}
int main()
{
	cin >> n >> m;
	while (m--)
		scanf("%d%d%d", &u, &v, &w), s ^= w, adj[u] += pii(v, w), adj[v] += pii(u, w);
	f[0][s] = 1, DFT(f[0], 0), dfs(1);
	for (int i = 1; i <= c; i++)
		for (int j = 0; j < 1 << 17; j++)
			f[0][j] = (__int128)f[0][j] * f[i][j] % MOD;
	DFT(f[0], 1);
	for (int j = 0; j < 1 << 17; j++)
		if (f[0][j])
			return printf("%d %lld\n", j, f[0][j] % 1000000007), 0;
}