// LUOGU_RID: 160324026
#include<bits/stdc++.h>
#define mk(x, y) make_pair(x, y)
using namespace std;
const int N = 2e5 + 5;
int n, m, sz[N];
int a[45], cnt[45];
vector< pair<int, int> > v[N];
int solve(int x)
{
	if(!v[x].size()) return 0;
	int l = 0, r = 0, ans = 1;
	memset(a, 0, sizeof(a));
	memset(cnt, 0, sizeof(cnt));
	while(r < v[x].size())
	{
		if(l < r && v[x][r].first != v[x][r - 1].first + 1)
			while(l < r) cnt[sz[v[x][l].first]]--, l++;
		int mod = sz[v[x][r].first], p = v[x][r].second;
		while(cnt[mod] && a[mod] != p)
		{
			cnt[sz[v[x][l].first]]--;
			l++;
		}
		cnt[mod]++; a[mod] = p;
		while(l < r)
		{
			int flag = 0;
			for(int i = 1; i <= 40; i++)
				if(cnt[i] && abs(a[i] - p) % __gcd(mod, i))
				{
					flag = 1;
					break;
				}
			if(flag) cnt[sz[v[x][l].first]]--, l++;
			else break;
		}
		ans = max(ans, r - l + 1); r++;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> sz[i];
		for(int j = 1, x; j <= sz[i]; j++)
		{
			cin >> x;
			v[x].push_back(mk(i, j));
		}
	}
	for(int i = 1; i <= m; i++)
		cout << solve(i) << '\n';
	return 0;
}