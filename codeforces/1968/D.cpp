#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <bitset>
#include <cmath>
#include <map>
#include <stack>
#include <set>

#define x first
#define y second

using namespace std;

typedef long long LL;

typedef pair<int, int> PII;

const LL INFF = 0x3f3f3f3f3f3f3f3f;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

int n, k, pb, ps;
bool vis[N];
LL p[N], a[N], f[N];

LL dfs(int pos, int k)
{
	if (vis[pos]) return k * a[pos];
	vis[pos] = true;
	if (k == 0) return 0;
	if (p[pos] == pos) return k * a[pos];
	LL res = dfs(p[pos], k - 1);
	return max(k * a[pos], res + a[pos]);
}

inline void solve()
{
	cin >> n >> k >> pb >> ps;
	for (int i = 1; i <= n; i ++ ) cin >> p[i];
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	LL res_b = 0, res_s = 0;
	memset(vis, false, sizeof vis);
	res_b = dfs(pb, k);
	memset(vis, false, sizeof vis);
	res_s = dfs(ps, k);
	if (res_b > res_s) puts("Bodya");
	else if (res_b < res_s) puts("Sasha");
	else puts("Draw");
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	t = 1;
	cin >> t;
	while (t -- )
	{
//		init();
		solve();
	}
	return 0;
}