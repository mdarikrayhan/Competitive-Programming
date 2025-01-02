// LUOGU_RID: 160451471
#include <bits/stdc++.h>
using namespace std;
int n, ans, f[201][40005];
int k, v, t, maxx, s;
int main()
{
	//freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		int id = 0;
		while (k--)
		{
			cin >> v >> t;
			while (t--)
			{
				id++;
				f[i][id] = f[i][id - 1] + v;
			}
		}
		maxx = max(maxx, id);
	}
	for (int tim = 2; tim <= maxx; tim++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (f[i][tim])
			{
				for (int j = 1; j <= n; j++)
				{
					if (i != j && f[j][tim])
					{
						if (f[i][tim] == f[j][tim])
						{
							if (f[i][tim - 1] < f[j][tim - 1] && f[i][tim + 1] > f[j][tim + 1])
							{
								ans++;
							}
						}
						else
						{
							if (f[i][tim - 1] < f[j][tim - 1] && f[i][tim] > f[j][tim])
							{
								ans++;
							}
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}