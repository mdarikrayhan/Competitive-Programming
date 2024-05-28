// LUOGU_RID: 159260564
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1e6 + 5;

int t, n, k, a[N], b[N];

class MaxFlow
{
public:
	int e[N], h[N], c[N], w[N], ne[N], idx, S, T, cost;
	int dis[N], cur[N];
	bool isin[N];
	void Init(int s, int t)
	{
		for (int i = 0; i <= t; i++) h[i] = -1;
		for (int i = 0; i <= idx; i++)
		{
			e[i] = c[i] = w[i] = ne[i] = 0;
		}
		S = s, T = t;
		idx = 0;
		cost = 0;
	}
	int add(int u, int v, int cs, int op) // derricklo
	{
		op = -op; // derricklo
		e[idx] = v, ne[idx] = h[u], c[idx] = cs, w[idx] = op, h[u] = idx++; // derricklo
		if (idx == 1)
		{
			//cout << "?????: " << u << " " << v << "\n";
		}
		e[idx] = u, ne[idx] = h[v], c[idx] = 0, w[idx] = -op, h[v] = idx++; // derricklo
		if (c[idx - 1] > 0 && v == 1)
		{
			//cout << "Error\n";
		}
		return idx - 2;
	}
	bool spfa()
	{
		for (int i = 0; i <= T; i++)
		{
			isin[i] = 0;
			dis[i] = (int)1e9;
			cur[i] = -1;
		}
		queue<int> q;
		q.push(S);
		cur[S] = h[S];
		dis[S] = 0;
		while (q.size())
		{
			int u = q.front();
			q.pop();
			//cout << u << " " << dis[u] << "\n";
			//system("pause");
			isin[u] = 0;
			for (int i = h[u]; ~i; i = ne[i])
			{
				int j = e[i];
				if (dis[j] > dis[u] + w[i] && c[i] > 0)
				{
					//cout << "???: " << u << " " << j << " " << dis[j] << " " << c[i] << " " << i << "\n";
					dis[j] = dis[u] + w[i];
					cur[j] = h[j];
					if (!isin[j])
					{
						isin[j] = 1;
						q.push(j);
					}
				}
			}
		}
		return (dis[T] != (int)1e9);
	}
	int dfs(int u, int lim)
	{
		if (u == T) return lim;
		isin[u] = 1;
		int s = 0;
		for (int i = cur[u]; ~i && s < lim; i = ne[i])
		{
			cur[u] = i;
			int j = e[i];
			if (dis[j] == dis[u] + w[i] && c[i] > 0 && !isin[j])
			{
				int x = dfs(j, min(c[i], lim - s));
				s += x;
				c[i] -= x;
				c[i ^ 1] += x;
				cost += x * w[i];
			}
		}
		isin[u] = 0;
		return s;
	}
	void dinic()
	{
		while (spfa())
		{
			//cout << "???\n";
			while (dfs(S, (int)1e9));
		}
	}
}mf;

int d[80][80];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	memset(mf.h, -1, sizeof mf.h);
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i] >> b[i];
		}
		mf.Init(0, 2 * n + 1);
		for (int i = 1; i <= n; i++) mf.add(0, i, 1, 0);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int cs = (i <= k ? a[j] + (i - 1) * b[j] : (k - 1) * b[j]);
				d[i][j] = mf.add(i, j + n, 1, cs);
			}
		}
		for (int i = 1; i <= n; i++) mf.add(i + n, 2 * n + 1, 1, 0);
		mf.dinic();
		vector<int> ans;
		for (int i = 1; i <= k - 1; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (mf.c[d[i][j]] == 0) ans.emplace_back(j);
			}
		}
		for (int i = k + 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (mf.c[d[i][j]] == 0) ans.emplace_back(j), ans.emplace_back(-j);
			}
		}
		for (int i = k; i <= k; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (mf.c[d[i][j]] == 0) ans.emplace_back(j);
			}
		}
		cout << ans.size() << "\n";
		for (auto& j : ans) cout << j << " ";
		cout << "\n";
	}
	return 0;
}