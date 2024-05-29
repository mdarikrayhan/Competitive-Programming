/*
BuzzyBeez
18:10 UTC+7
10/04/2024 
*/
#include <bits/stdc++.h>
using namespace std;

int a[100008], b[100008];
int cnt[100008];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, y0, y1; cin >> n >> m >> y0 >> y1;
	int pt1, pt2 = 1, ans = n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= m; ++i) cin >> b[i];
	if (!m) {cout << n; return 0;}
	for (pt1 = 1; pt1 <= n; ++pt1) {
		while (pt2 <= m && abs(a[pt1] - b[pt2]) > abs(a[pt1] - b[pt2 + 1])) ++pt2;
		if (!cnt[pt2]) ++cnt[pt2];
		else {
			if (pt1 > 1 && a[pt1] + a[pt1 - 1] == 2 * b[pt2]) cnt[pt2] = 2;
			else if (pt2 < m && b[pt2] + b[pt2 + 1] == 2 * a[pt1]) cnt[pt2 + 1] = 1;
		}
	}
	for (int i = 1; i <= m; ++i) ans -= cnt[i];
	cout << ans;
}