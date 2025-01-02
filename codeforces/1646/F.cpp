// LUOGU_RID: 160479007
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <set>
using namespace std;

const int N = 105;

int a[N][N], n;

int check()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (a[i][j] == a[i][j + 1]) return i;
		}
	}
	return 0;
}

int nxt[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) cin >> a[i][j];
		sort(a[i] + 1, a[i] + n + 1);
	}
	vector<vector<int>> ans;
	while (int pos = check())
	{
		for (int i = pos; i <= n; i++)
		{
			bool flag = 0;
			for (int j = 1; j < n; j++)
			{
				if (a[i][j] == a[i][j + 1])
				{
					nxt[i] = a[i][j];
					flag = 1;
					break;
				}
			}
			if (!flag) nxt[i] = nxt[i - 1];
		}
		for (int i = 1; i < pos; i++)
		{
			bool flag = 0;
			for (int j = 1; j < n; j++)
			{
				if (a[i][j] == a[i][j + 1])
				{
					nxt[i] = a[i][j];
					flag = 1;
					break;
				}
			}
			if (!flag) nxt[i] = (i != 1 ? nxt[i - 1] : nxt[n]);
		}
		vector<int> res;
		for (int i = 1; i <= n; i++) res.emplace_back(nxt[i]);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (a[i][j] == nxt[i])
				{
					a[i][j] = (i == 1 ? nxt[n] : nxt[i - 1]);
					break;
				}
			}
			sort(a[i] + 1, a[i] + n + 1);
		}
		ans.emplace_back(res);
	}
	for (int i = 2; i <= n; i++)
	{
		vector<int> now;
		int idx = i;
		for (int j = 1; j <= n; j++)
		{
			now.emplace_back(idx);
			if (idx == n) idx = 1;
			else idx++;
		}
		for (int j = 1; j < i; j++)
		{
			ans.emplace_back(now);
			vector<int> rn = now;
			int res = now.back();
			for (int k = 0; k + 1 < now.size(); k++) now[k + 1] = rn[k];
			now[0] = res;
		}
	}
	cout << ans.size() << "\n";
	for (auto& i : ans)
	{
		for (auto& j : i) cout << j << " ";
		cout << "\n";
	}
	return 0;
}