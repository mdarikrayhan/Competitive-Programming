// LUOGU_RID: 160261610
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5010;
int n, k, x, a[N], q[N]; ll ret, dp[N][N];

int main()
{
	memset(dp, -0x3f, sizeof(dp)), scanf("%d%d%d", &n, &k, &x);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	if (n / k > x) return puts("-1"), 0;
	dp[0][0] = 0;
	for (int i = 1; i <= x; i++)
	{
		int l = 1, r = 1; q[1] = 0;
		for (int j = 1; j <= n; j++)
		{
			while (l <= r && q[l] + k < j) l++;
			dp[j][i] = dp[q[l]][i - 1] + a[j];
			while (l <= r && dp[j][i - 1] >= dp[q[r]][i - 1]) r--;
			q[++r] = j;
		}
	} for (int i = n - k + 1; i <= n; i++) ret = max(ret, dp[i][x]);
	printf("%lld\n", ret);
	return 0;
}