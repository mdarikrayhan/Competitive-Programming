// LUOGU_RID: 160499585
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMaxN = 2e5 + 5;

int n, id, ans, a[kMaxN], diff[kMaxN], sizes[kMaxN], dfn[kMaxN];
map<int, int> cnt, sum;
vector<int> nbr[kMaxN];

void pre_dfs(int x, int fa)
{
	sizes[x] = 1;
	dfn[x] = ++id;
	for(auto i : nbr[x])
		if(i != fa)
			pre_dfs(i, x), sizes[x] += sizes[i];
}

void dfs(int x, int fa)
{
	int tmp = cnt[a[x]]++;
	for(auto i : nbr[x])
	{
		if(i == fa)
			continue;
		int tmp = cnt[a[x]];
		dfs(i, x);
		if(tmp != cnt[a[x]])
		{
			diff[1]++, diff[dfn[i] + sizes[i]]++;
			diff[dfn[i]]--, diff[n + 1]--;
		}
	}
	if(cnt[a[x]] - tmp != sum[a[x]])
		diff[dfn[x]]++, diff[dfn[x] + sizes[x]]--;
}

signed main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], sum[a[i]]++;
	for(int i = 1, u, v; i < n; i++)
	{
		cin >> u >> v;
		nbr[u].emplace_back(v);
		nbr[v].emplace_back(u);
	}
	pre_dfs(1, 0);
	dfs(1, 0);
	for(int i = 1; i <= n; i++)
		ans += !(diff[i] += diff[i - 1]);
	cout << ans << endl;
	return 0;
}
