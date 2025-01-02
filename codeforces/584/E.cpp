#include <bits/stdc++.h>
using namespace std;
struct NODE{
	int x, y;
}node[2000005];
int a[2005], b[2005];
int to[2005];
signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		to[b[i]] = i;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = to[a[i]];
		ans += abs(a[i] - i);
	}
	cout << ans / 2 << endl;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		to[a[i]] = i;
	}
	for (int i = n, now = to[n]; i; --i, now = to[i]) {
		for (int j = to[i] + 1; j <= n; j++) {
			if (a[j] <= now) {
				node[++cnt] = (NODE){j, now};
				swap(a[now], a[j]);
				now = j;
			}
		}
	}
	cout << cnt << endl;
	for (int i = 1; i <= cnt; i++) {
		printf("%d %d\n", node[i].x, node[i].y);
	}
	return 0;
}
