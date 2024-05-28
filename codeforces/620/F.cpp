#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5, M = 5e3 + 5, A = 1e6 + 5;
int n, m, a[N], l[M], r[M], sum[A], f[N], ans[M];
int main(){
	for (int i = 1; i <= A - 5; i++) sum[i] = i ^ sum[i - 1];
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)scanf("%d%d", &l[i], &r[i]);
	for (int i = 1; i <= n; i++){
		f[i] = a[i];
		for (int j = i + 1; j <= n; j++)
			f[j] = max(f[j - 1], sum[min(a[i], a[j]) - 1] ^ sum[max(a[i], a[j])]);
		for (int j = 1; j <= m; j++)
			if (l[j] <= i && i <= r[j])
				ans[j] = max(ans[j], f[r[j]]);
	}
	for (int i = 1; i <= m; i++)printf("%d\n", ans[i]);
}
