// LUOGU_RID: 159261135
#include <bits/stdc++.h>
using namespace std;

const int N = 51, M = 2.5e6 + 5;

int a[N], n, ans[3][N];
bitset<M> bt[N][25];
bool vis[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) cin >> a[i];
	sort(a + 1, a + 2 * n + 1);
	ans[1][1] = a[1], ans[2][n] = a[2];
	int sum = 0;
	for (int i = 3; i <= 2 * n; i++) sum += a[i];
	bt[2][0][0] = 1;
	for (int i = 3; i <= 2 * n; i++)
	{
		int c = min(i - 2, n - 1);
		for (int j = c; j >= 1; j--)
		{
			bt[i][j] = (bt[i - 1][j] | (bt[i - 1][j - 1] << a[i])); 
		}
		bt[i][0] = bt[i - 1][0];
	}
	for (int i = sum / 2; i >= 0; i--)
	{
		if (bt[2 * n][n - 1][i])
		{
			int nowi = i, nowc = n - 1;
			int cc = 0;
			for (int j = 2 * n; j >= 3; j--)
			{
				if (!bt[j - 1][nowc][nowi])
				{
					cc++;
					vis[j] = 1;
					nowc--;
					nowi -= a[j];
				}
			}
			int idx = 2;
			for (int j = 3; j <= 2 * n; j++)
			{
				if (vis[j])
				{
					ans[1][idx++] = a[j];
				}
			}
			idx = 1;
			for (int j = 2 * n; j >= 3; j--)
			{
				if (!vis[j]) ans[2][idx++] = a[j];
			}
			for (int j = 1; j <= n; j++) cout << ans[1][j] << " ";
			cout << "\n";
			for (int j = 1; j <= n; j++) cout << ans[2][j] << " ";
			cout << "\n";
			return 0;
		}
	}
	return 0;
}