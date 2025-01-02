# include <iostream>
# include <cstdio>
# include <cmath>
# include <algorithm>
# include <cstring>
# include <vector>
# include <map>
# include <queue>
# include <unordered_map>
using namespace std;
const int MAXN = 1e6 + 10, MAXM = 1e3 + 10;
#define ll long long
int dx[MAXN], dy[MAXN], fx[MAXN], fy[MAXN];
int a[MAXM], b[MAXM];
bool vx[MAXM], vy[MAXM];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		scanf("%d", &n);
		int sa = 0, sb = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			sa += a[i];
			vx[i] = 0;
		}
		sort(a + 1, a + n + 1);
		scanf("%d", &m);
		for (int i = 1; i <= m; ++i) {
			scanf("%d", &b[i]);
			sb += b[i];
			vy[i] = 0;
		}
		sort(b + 1, b + m + 1, cmp);
		for (int i = 1; i <= sa; ++i) {
			dx[i] = fx[i] = 0;
		}
		dx[0] = 1;
		for (int i = 1; i <= sb; ++i) {
			dy[i] = fy[i] = 0;
		}
		dy[0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = sa; j >= a[i]; --j) {
				if (dx[j - a[i]] && !dx[j]) {
					dx[j] = 1;
					fx[j] = i;
				}
			}
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = sb; j >= b[i]; --j) {
				if (dy[j - b[i]] && !dy[j]) {
					dy[j] = 1;
					fy[j] = i;
				}
			}
		}
		if (sa % 2 || sb % 2 || !dx[sa / 2] || !dy[sb / 2] || n != m) {
			puts("No");
			continue;
		}
		puts("Yes");
		queue<int> ax, bx, ay, by;
		int px = sa / 2, py = sb / 2;
		while (px) {
			ax.push(a[fx[px]]);
			vx[fx[px]] = 1;
			px = px - a[fx[px]];
		}
		while (py) {
			ay.push(b[fy[py]]);
			vy[fy[py]] = 1;
			py = py - b[fy[py]];
		}

		for (int i = n; i >= 1; --i) {
			if (!vx[i]) bx.push(a[i]);
		}
		for (int i = n; i >= 1; --i) {
			if (!vy[i]) by.push(b[i]);
		}
		if (ax.size() > bx.size()) {
			swap(ax, bx);
		}
		if (ay.size() < by.size()) {
			swap(ay, by);
		}
		px = py = 0;
		for (int i = 1; i <= n + m; ++i) {
			if (i % 2 == 1) {
				int d = 0;
				if (!ax.empty()) {
					d = ax.front();
					ax.pop();
				}
				else
				{
					d = -bx.front();
					bx.pop();
				}
				px += d;
			}
			else {
				int d = 0;
				if (!ay.empty()) {
					d = ay.front();
					ay.pop();
				}
				else {
					d = -by.front();
					by.pop();
				}
				py += d;
			}
			printf("%d %d\n", px, py);
		}
	}
	return 0;
}
