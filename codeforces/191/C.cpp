// LUOGU_RID: 160495000
#include<bits/stdc++.h>
 typedef int int32;
 #define int long long
using namespace std;
const int N = 3e5 + 5;
int n, m, s, dep[N], dp[N][32], dis[N], diff[N], id[N];
vector<pair<int, int>>nbr[N];
void pre_lca(int x, int fa)
{
	dp[x][0] = fa;
	dep[x] = dep[fa] + 1;
	for (int i = 1; (1 << i) <= dep[x]; i++)
		dp[x][i] = dp[dp[x][i - 1]][i - 1];
	for (auto [nxt, i] : nbr[x])
		if (nxt != fa)
			pre_lca(nxt, x), id[i] = nxt;
	return;
}
int lca(int x, int y)
{
	if (dep[x] > dep[y])
		swap(x, y);
	for (int i = 20; i >= 0; i--)
		if (dep[x] <= dep[dp[y][i]])
			y = dp[y][i];
	if (x == y)
		return x;
	for (int i = 20; i >= 0; i--)
		if (dp[x][i] != dp[y][i])
			x = dp[x][i], y = dp[y][i];
	return dp[x][0];
}
int work(int x, int y, int* z = dep, int _lca = 0)
{
	if (_lca == 0)
		_lca = lca(x, y);
	return z[x] + z[y] - 2 * z[_lca];
}
void dfs(int x, int fa)
{
	for (auto [nxt, i] : nbr[x])
		if (nxt != fa)
			dfs(nxt, x), diff[x] += diff[nxt];
	return;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	s = 1;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		nbr[x].push_back({ y,i });
		nbr[y].push_back({ x,i });
	}
	pre_lca(s, 0);
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		diff[x]++, diff[y]++, diff[lca(x, y)] -= 2;
	}
	dfs(s, 0);
	for (int i = 1; i < n; i++)
		cout << diff[id[i]] << ' ';
	return 0;
}