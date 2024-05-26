#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5, INF = LONG_LONG_MAX;
int Q, n;
int c[N];
string s, t;
int lowbit(int x) {
	return x & (-x);
}
void change(int x, int v) {
	for (int i = x; i <= n; i += lowbit(i))
		c[i] += v;
}
int sum(int x) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i))
		res += c[i];
	return res;
}
signed main() {
	scanf("%lld", &Q);
	while (Q--) {
		int ans = INF, opt = 0, cnt = 0;
		queue<int>q[30];
		memset(c, 0, sizeof c);
		scanf("%lld", &n);
		cin >> s >> t;
		s = " " + s;
		t = " " + t;
		for (int i = 1; i <= n; i++)
			q[s[i] - 'a'].push(i);
		for (int i = 1; i < n; i++)
			change(i, 1);
		for (int i = 1; i <= n; i++) {
			cnt = n + 1;
			for (int j = 0; j < t[i] - 'a'; j++) {
				if (!q[j].empty())
					cnt = min(cnt, q[j].front());
			}
			if (cnt != n + 1)
				ans = min(ans, opt + sum(cnt - 1));
			if (q[t[i] - 'a'].empty())
				break;
			cnt = q[t[i] - 'a'].front();
			q[t[i] - 'a'].pop();
			opt += sum(cnt - 1);
			change(cnt, -1);
		}
		printf("%lld\n", ans == INF ? -1 : ans);
	}
	return 0;
}