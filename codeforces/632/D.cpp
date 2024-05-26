#include<bits/stdc++.h>
using namespace std;
int n, m, N, mx, Lcm, a[1000005], b[1000005], cnt[1000005], ans[1000005];
int main() {
	scanf("%d%d", &n, &m);
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), b[i] = a[i];
	for (int i = 1; i <= n; i++)
		if (a[i] <= m) ++cnt[a[i]];
	sort(b + 1, b + n + 1), N = unique(b + 1, b + n + 1) - b - 1, mx = -1;
	for (int i = 1; i <= N && b[i] <= m; i++)
		for (int j = b[i]; j <= m; j += b[i])
			ans[j] += cnt[b[i]];
	for (int i = 1; i <= m; i++)
		if (mx < ans[i])
			mx = ans[i], Lcm = i;
	printf("%d %d\n", Lcm, mx);
	for (int i = 1; i <= n; i++)
		if (Lcm % a[i] == 0)
			printf("%d ", i);
}