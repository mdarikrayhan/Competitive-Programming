/* https://codeforces.com/blog/entry/64310 */
#include <stdio.h>
#include <string.h>

#define N	30000
#define B	20
#define M	60
#define N_	(N * B)
#define X	1000000000000000000
#define LG	60	/* LG = ceil(log2(X)) */
#define LN	15	/* LN = ceil(log2(N)) */

int m;

long long rotate(long long x, int r) {
	return x >> r | (x & (1LL << r) - 1) << m - r;
}

int main() {
	static int ww[B], ss[N], ssu[LG + 1], ssv[LG + 1];
	static long long pp[LG + 1], dp[N_], dq[N], dr[LN + 1][N], ds[LG + 1][M];
	int n, n_, b, lg, ln, i, j, d, du, dv, l, s, sp, sq, q;
	long long u, v, x, r, ans;

	scanf("%d%d", &b, &m);
	for (d = 0; d < b; d++)
		scanf("%d", &ww[d]);
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &ss[i]);
	scanf("%lld%lld", &u, &v), u--, v -= n - 1;
	pp[0] = 1;
	for (l = 0; pp[l] <= X / b; l++)
		pp[l + 1] = pp[l] * b;
	pp[l + 1] = X + 1;
	lg = l + 1;
	ln = 0;
	while (pp[ln] < n)
		ln++;
	n_ = pp[ln];
	for (l = 0; l <= ln; l++)
		for (i = 0; i < n && i + pp[l] <= n_; i++)
			if (l == 0)
				dr[l][i] = (1LL << ss[i] + 1) - 1;
			else {
				dr[l][i] = (1LL << m) - 1;
				for (d = 0; d < b && (j = i + d * pp[l - 1]) < n; d++)
					dr[l][i] &= rotate(dr[l - 1][j], ww[d]);
			}
	dp[0] = (1LL << m) - 1;
	for (l = 1; l <= ln; l++) {
		for (j = pp[l - 1]; j < pp[l]; j++) {
			q = j / pp[l - 1], i = j - q * pp[l - 1];
			dp[j] = rotate(dp[i], ww[b - q - 1]);
			for (d = b - q; d < b && (i = j - (b - d) * pp[l - 1]) < n; d++)
				dp[j] &= rotate(dr[l - 1][i], ww[d]);
		}
		for (j = 0; j < pp[l - 1]; j++)
			dp[j] = rotate(dp[j], ww[b - 1]);
	}
	for (i = n - 1, l = 0; i >= 0; i--) {
		while (i + pp[l + 1] <= n_)
			l++;
		q = (n_ - i) / pp[l], j = i + q * pp[l];
		dq[i] = j >= n ? (1LL << m) - 1 : rotate(dq[j], ww[q]);
		for (d = 0; d < q && (j = i + d * pp[l]) < n; d++)
			dq[i] &= rotate(dr[l][j], ww[d]);
	}
	ssu[lg] = ssv[lg] = 0;
	for (l = lg; l > ln; l--) {
		du = u / pp[l - 1] % b, dv = v / pp[l - 1] % b;
		ssu[l - 1] = (ssu[l] + ww[du]) % m;
		ssv[l - 1] = (ssv[l] + ww[dv]) % m;
		for (s = 0; s < m; s++) {
			x = ds[l][s];
			if (x == 0)
				continue;
			for (d = 0; d < b; d++)
				ds[l - 1][(s + ww[d]) % m] += x;
		}
		for (d = 0; d < dv; d++)
			ds[l - 1][(ssv[l] + ww[d]) % m]++;
		for (d = 0; d < du; d++)
			ds[l - 1][(ssu[l] + ww[d]) % m]--;
	}
	ans = 0;
	for (s = 0; s < m; s++)
		if ((dr[ln][0] & 1LL << s) != 0) {
			ans += ds[ln][s];
			if (ssv[ln] == s && v % n_ != 0)
				ans++;
			if (ssu[ln] == s && u % n_ != 0)
				ans--;
		}
	for (i = 1; i < n_; i++)
		if (i >= n) {
			for (s = 0; s < m; s++)
				if ((dp[i] & 1LL << s) != 0) {
					ans += ds[ln][s];
					r = n_ - i;
					if (ssv[ln] == s && r < v % n_)
						ans++;
					if (ssu[ln] == s && r < u % n_)
						ans--;
				}
		} else
			for (l = ln; l < lg; l++)
				for (d = 0; d + 1 < b; d++)
					for (s = 0; s < m; s++) {
						sp = (s + ww[d] + (l - ln) * ww[b - 1]) % m, sq = (s + ww[d + 1]) % m;
						if ((dp[i] & 1LL << sp) != 0 && (dq[i] & 1LL << sq) != 0) {
							ans += ds[l + 1][s];
							r = d > X / pp[l] ? X : d * pp[l] + pp[l] - pp[ln] + n_ - i;
							if (ssv[l + 1] == s && r < v % pp[l + 1])
								ans++;
							if (ssu[l + 1] == s && r < u % pp[l + 1])
								ans--;
						}
					}
	printf("%lld\n", ans);
	return 0;
}
