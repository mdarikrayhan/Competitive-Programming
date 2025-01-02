/* practice with Dukkha */
#include <stdio.h>

#define N	100000
#define LN	16	/* LN = floor(log2(N)) */

int min(int a, int b) { return a < b ? a : b; }

int oo[1 + (N - 1) * 2], oj[1 + (N - 1) * 2];

int link(int o, int j) {
	static int _ = 1;

	oo[_] = o, oj[_] = j;
	return _++;
}

int ae[N], sz[N], dd_[N], cc[N][LN], dd[N][LN], kk[N]; char used[N];
int c_;

void dfs(int p, int i, int n, int h, int c, int d) {
	int o, centroid;

	if (h >= 0)
		cc[i][h] = c, dd[i][h] = d, kk[i]++;
	centroid = 1;
	sz[i] = 1;
	for (o = ae[i]; o; o = oo[o]) {
		int j = oj[o];

		if (j != p && !used[j]) {
			dfs(i, j, n, h, c, d + 1);
			if (sz[j] * 2 > n)
				centroid = 0;
			sz[i] += sz[j];
		}
	}
	if ((n - sz[i]) * 2 > n)
		centroid = 0;
	if (centroid)
		c_ = i;
}

void cd(int i, int n, int h, int c) {
	int o;

	dfs(-1, i, n, h, c, 1);
	used[c = c_] = 1;
	for (o = ae[c]; o; o = oo[o]) {
		i = oj[o];
		if (!used[i])
			cd(i, sz[i] < sz[c] ? sz[i] : n - sz[c], h + 1, c);
	}
}

void update(int i) {
	int h;

	dd_[i] = 0;
	for (h = 0; h < kk[i]; h++) {
		int j = cc[i][h];

		dd_[j] = min(dd_[j], dd[i][h]);
	}
}

int query(int i) {
	int h, ans = dd_[i];

	for (h = 0; h < kk[i]; h++) {
		int j = cc[i][h];

		ans = min(ans, dd[i][h] + dd_[j]);
	}
	return ans;
}

int main() {
	int n, q, h, i, j;

	scanf("%d%d", &n, &q);
	for (h = 0; h < n - 1; h++) {
		scanf("%d%d", &i, &j), i--, j--;
		ae[i] = link(ae[i], j);
		ae[j] = link(ae[j], i);
	}
	for (i = 0; i < n; i++)
		dd_[i] = n;
	cd(0, n, -1, -1);
	update(0);
	while (q--) {
		int t;

		scanf("%d%d", &t, &i), i--;
		if (t == 1)
			update(i);
		else
			printf("%d\n", query(i));
	}
	return 0;
}
