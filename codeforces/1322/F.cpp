#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define N	500000

int max(int a, int b) { return a > b ? a : b; }

unsigned int Z;

int rand_() {
	return (Z *= 3) >> 1;
}

void srand_() {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	Z = tv.tv_sec ^ tv.tv_usec | 1;
}

int *ej[N], eo[N], fo[N], n;

void append(int i, int j) {
	int o = eo[i]++;

	if (o >= 2 && (o & o - 1) == 0)
		ej[i] = (int *) realloc(ej[i], o * 2 * sizeof *ej[i]);
	ej[i][o] = j;
}

int dd[N], pp[N], qq[N], ta[N], tb[N], qu[N];

int dfs1(int p, int i, int d) {
	int o, o_, s, k_, j_;

	pp[i] = p, dd[i] = d;
	s = 1, k_ = 0, j_ = -1;
	for (o = 0, o_ = 0; o < eo[i]; o++) {
		int j = ej[i][o];

		if (j != p) {
			int k = dfs1(i, j, d + 1);

			ej[i][o_++] = j;
			s += k;
			if (k_ < k)
				k_ = k, j_ = j;
		}
	}
	eo[i] = o_;
	qq[i] = j_;
	return s;
}

void dfs2(int i, int q) {
	static int t;
	int o, j_;

	qu[ta[i] = t++] = i;
	j_ = qq[i], qq[i] = q;
	if (j_ != -1)
		dfs2(j_, q);
	for (o = eo[i]; o--; ) {
		int j = ej[i][o];

		if (j != j_)
			dfs2(j, j);
	}
	tb[i] = t;
}

int ds[N * 2];

int find(int i) {
	return ds[i] < 0 ? i : (ds[i] = find(ds[i]));
}

void join(int i, int j) {
	i = find(i);
	j = find(j);
	if (i == j)
		return;
	if (ds[i] > ds[j])
		ds[i] = j;
	else {
		if (ds[i] == ds[j])
			ds[i]--;
		ds[j] = i;
	}
}

char cc[N], cc_[N]; int rr[N], dp[N], d;

void sort(int *ii, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r, i_ = ii[l + rand_() % (r - l)], tmp;

		while (j < k)
			if (rr[ii[j]] == rr[i_])
				j++;
			else if (rr[ii[j]] < rr[i_]) {
				tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
				i++, j++;
			} else {
				k--;
				tmp = ii[j], ii[j] = ii[k], ii[k] = tmp;
			}
		sort(ii, l, i);
		l = k;
	}
}

int solve() {
	int h, i, j, o, o_, o1, r, r_, d0, d0_, d0__, d1, d1_, d1__, tmp;

	memcpy(cc_, cc, n * sizeof *cc);
	for (h = n - 1; h >= 0; h--) {
		i = qu[h];
		r_ = i == 0 ? -1 : rr[i];
		d0__ = 0, d1__ = 0, d0_ = 0, d1_ = 0;
		for (o = 0; o < eo[i]; o = o_) {
			o_ = o + 1, r = rr[ej[i][o]];
			while (o_ < eo[i] && rr[ej[i][o_]] == r)
				o_++;
			d0 = d1 = 0;
			for (o1 = o; o1 < o_; o1++) {
				j = ej[i][o1];
				if (cc[j] == 0)
					d0 = max(d0, dp[j]);
				else
					d1 = max(d1, dp[j]);
			}
			if (r == r_)
				d0__ = d0, d1__ = d1;
			else {
				if (d0 > d1) {
					tmp = d0, d0 = d1, d1 = tmp;
					for (o1 = o; o1 < o_; o1++) {
						j = ej[i][o1];
						cc_[j] ^= 1;
					}
				}
				d0_ = max(d0_, d0), d1_ = max(d1_, d1);
			}
		}
		if (d0_ + d1_ > d)
			return 0;
		if (i != 0) {
			if (max(d0__, d0_) + max(d1__, d1_) > d) {
				tmp = d0_, d0_ = d1_, d1_ = tmp;
				if (max(d0__, d0_) + max(d1__, d1_) > d)
					return 0;
				for (o = 0; o < eo[i]; o++) {
					j = ej[i][o];
					if (rr[j] != r_)
						cc_[j] ^= 1;
				}
			}
			if ((dp[i] = max(d0__, d0_) + 1) > d)
				return 0;
		}
	}
	return 1;
}

int main() {
	static int kk[N];
	int m, cnt, h, i, i_, j, j_, u, v, p, r0, r1, o, lower, upper;

	srand_();
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		ej[i] = (int *) malloc(2 * sizeof *ej[i]);
	for (h = 0; h < n - 1; h++) {
		scanf("%d%d", &i, &j), i--, j--;
		append(i, j), append(j, i);
	}
	dfs1(-1, 0, 0);
	dfs2(0, 0);
	memset(ds, -1, n * 2 * sizeof *ds);
	while (m--) {
		scanf("%d%d", &i, &j), i--, j--;
		i_ = i, j_ = j, u = -1, v = -1;
		while (qq[i_] != qq[j_])
			if (dd[qq[i_]] > dd[qq[j_]])
				u = qq[i_], i_ = pp[qq[i_]];
			else
				v = qq[j_], j_ = pp[qq[j_]];
		if (dd[i_] < dd[j_])
			v = qu[ta[i_] + 1];
		else if (dd[i_] > dd[j_])
			u = qu[ta[j_] + 1];
		if (u != -1)
			kk[i]++, kk[u]--;
		if (v != -1)
			kk[j]++, kk[v]--;
		if (u != -1 && v != -1)
			join(u << 1 | 0, v << 1 | 1), join(u << 1 | 1, v << 1 | 0);
	}
	for (h = n - 1; h > 0; h--) {
		i = qu[h], p = pp[i];
		if (kk[i] > 0)
			join(p << 1 | 0, i << 1 | 0), join(p << 1 | 1, i << 1 | 1);
		kk[p] += kk[i];
	}
	for (i = 0; i < n; i++)
		if (find(i << 1 | 0) == find(i << 1 | 1)) {
			printf("-1\n");
			return 0;
		}
	cc[0] = 0;
	for (i = 1; i < n; i++) {
		r0 = find(i << 1 | 0), r1 = find(i << 1 | 1);
		if (r0 < r1)
			cc[i] = 0, rr[i] = r0;
		else
			cc[i] = 1, rr[i] = r1;
	}
	for (h = n - 1; h > 0; h--) {
		i = qu[h];
		cc[i] ^= cc[pp[i]];
	}
	for (i = 0; i < n; i++)
		sort(ej[i], 0, eo[i]);
	lower = 0, upper = n - 1;
	while (upper - lower > 1) {
		d = (lower + upper) / 2;
		if (solve())
			upper = d;
		else
			lower = d;
	}
	d = upper;
	solve();
	for (i = 0; i < n; i++)
		free(ej[i]);
	for (i = 0; i < n; i++)
		ej[i] = (int *) malloc(2 * sizeof *ej[i]), eo[i] = 0;
	for (h = 1; h < n; h++) {
		i = qu[h], p = pp[i];
		cc_[i] ^= cc_[p];
		if (cc_[i] == 0)
			append(p, i), fo[i]++;
		else
			append(i, p), fo[p]++;
	}
	memset(dp, 0, n * sizeof *dp);
	cnt = 0;
	for (i = 0; i < n; i++)
		if (fo[i] == 0)
			qu[cnt++] = i;
	while (cnt) {
		i = qu[--cnt];
		for (o = eo[i]; o--; ) {
			j = ej[i][o];
			dp[j] = max(dp[j], dp[i] + 1);
			if (--fo[j] == 0)
				qu[cnt++] = j;
		}
	}
	printf("%d\n", upper + 1);
	for (i = 0; i < n; i++)
		printf("%d ", dp[i] + 1);
	printf("\n");
	return 0;
}
