// LUOGU_RID: 160031357
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <unordered_map>

#pragma GCC optimize(2)

using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], len[N], sum1[N], sum2[N];
int n, m, ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	a[0] = 0, a[n + 1] = m;
	sort(a, a + n + 2);
	for (int i = 1; i <= n + 1; i++)
	{
		len[i] = a[i] - a[i - 1];
		if (i % 2) 
			ans += len[i];
	}
	for (int i = 1; i <= n + 1; i++)
	{
		sum1[i] = sum1[i - 1] + ((i % 2) ? len[i] : 0);
		sum2[i] = sum2[i - 1] + ((!(i % 2)) ? len[i] : 0);
	}
	for (int i = 1; i <= n + 1; i++)
	{
		if (len[i] == 1) 
			continue;
		int cnt = sum1[i - 1] + len[i] - 1 + sum2[n + 1] - sum2[i];
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}