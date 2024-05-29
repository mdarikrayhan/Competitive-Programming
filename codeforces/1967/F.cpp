#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
 
#define N	300300
#define INF	0x3f3f3f3f
#define STRESS	0
#if STRESS
#define B	10
#else
#define B	548	/* B = ceil(sqrt(N)) */
#endif
 
int min(int a, int b) { return a < b ? a : b; }
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
 
void generate(int *aa, int n) {
	int i, j, tmp;
 
	for (i = 0; i < n; i++)
		aa[i] = i;
	for (i = 0; i < n; i++) {
		j = rand_() % (i + 1);
		tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
	}
}
 
int *ec[N], eo[N];
 
long long brute(int *aa, int n, int a, int c) {
	static int aa_[N], pp[N], qq[N], qu[N];
	int m, cnt, h, i;
	long long ans;
 
	m = 0;
	for (i = 0; i < n; i++)
		if (aa[i] <= a)
			aa_[m++] = aa[i];
	cnt = 0;
	for (h = 0; h < m; h++) {
		while (cnt && aa_[qu[cnt - 1]] < aa_[h])
			cnt--;
		pp[h] = cnt == 0 ? -INF : qu[cnt - 1], qu[cnt++] = h;
	}
	cnt = 0;
	for (h = m - 1; h >= 0; h--) {
		while (cnt && aa_[qu[cnt - 1]] < aa_[h])
			cnt--;
		qq[h] = cnt == 0 ? INF : qu[cnt - 1], qu[cnt++] = h;
	}
	ans = 0;
	for (h = 0; h < m; h++)
		ans += min(qq[h] - pp[h], c);
	return ans;
}
 
int tt[N * 2];
 
void sort(int *hh, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r, h = hh[l + rand_() % (r - l)], tmp;
 
		while (j < k)
			if (tt[hh[j]] == tt[h])
				j++;
			else if (tt[hh[j]] < tt[h]) {
				tmp = hh[i], hh[i] = hh[j], hh[j] = tmp;
				i++, j++;
			} else {
				k--;
				tmp = hh[j], hh[j] = hh[k], hh[k] = tmp;
			}
		sort(hh, l, i);
		l = k;
	}
}
 
void update(int *ftk, long long *fts, int i, int n, int k, int x) {
	while (i < n) {
		ftk[i] += k, fts[i] += x;
		i |= i + 1;
	}
}
 
long long query(int *ftk, long long *fts, int i, int x) {
	int k;
	long long s;
 
	k = 0, s = 0;
	while (i >= 0) {
		k += ftk[i], s += fts[i];
		i &= i + 1, i--;
	}
	return (long long) x * k - s;
}
 
int main() {
	int t;
 
	srand_();
	scanf("%d", &t);
	while (t--) {
		static int aa[N], bb[N], bb_[N], bb1[N], idx[N], idx_[N], pp[N], pp1[N], qq[N], qq1[N], qu[N], hh[N * 2], ftk[N], ftkl[N], ftkr[N], kk[N + 1];
		static long long fts[N], ftsl[N], ftsr[N];
		static int msk[N];
		int n, m, m_, m1, cnt, h, h_, h1, p, q, i, a, l, l_, r, r_, o, c, k;
		long long ans;
 
#if STRESS
		n = 200;
		generate(aa, n);
		for (a = 0; a < n; a++) {
			eo[a] = a + 1;
			ec[a] = eo[a] == 0 ? NULL : (int *) malloc(eo[a] * sizeof *ec[a]);
			for (o = 0; o < eo[a]; o++)
				ec[a][o] = o + 1;
		}
#else
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &aa[i]), aa[i]--;
		for (a = 0; a < n; a++) {
			scanf("%d", &eo[a]);
			ec[a] = eo[a] == 0 ? NULL : (int *) malloc(eo[a] * sizeof *ec[a]);
			for (o = 0; o < eo[a]; o++)
				scanf("%d", &ec[a][o]);
		}
#endif
		for (l = 0; l < n; l += B) {
			r = min(l + B, n);
			m = 0, m_ = 0;
			for (i = 0; i < n; i++) {
				a = aa[i];
				if (a < l)
					bb[m++] = a, idx_[a] = m_;
				else if (a < r)
					bb_[m_++] = a, idx[a] = m;
			}
			memset(tt, 0x3f, m * 2 * sizeof *tt);
			for (h_ = 0; h_ < m_; h_++) {
				a = bb_[h_], h = idx[a];
				if (h < m)
					tt[h << 1 | 0] = min(tt[h << 1 | 0], a);
				if (h > 0)
					tt[h - 1 << 1 | 1] = min(tt[h - 1 << 1 | 1], a);
			}
			cnt = 0;
			for (h = 0; h < m; h++) {
				while (cnt && bb[p = qu[cnt - 1]] < bb[h])
					tt[h << 1 | 0] = min(tt[h << 1 | 0], tt[p << 1 | 0]), cnt--;
				pp[h] = cnt == 0 ? -INF : qu[cnt - 1], qu[cnt++] = h;
			}
			cnt = 0;
			for (h = m - 1; h >= 0; h--) {
				while (cnt && bb[q = qu[cnt - 1]] < bb[h])
					tt[h << 1 | 1] = min(tt[h << 1 | 1], tt[q << 1 | 1]), cnt--;
				qq[h] = cnt == 0 ? INF : qu[cnt - 1], qu[cnt++] = h;
			}
			for (h = 0; h < m * 2; h++)
				hh[h] = h;
			sort(hh, 0, m * 2);
			memset(msk, 0, m * sizeof *msk);
			memset(ftk, 0, n * sizeof *ftk), memset(fts, 0, n * sizeof *fts);
			memset(ftkl, 0, n * sizeof *ftkl), memset(ftsl, 0, n * sizeof *ftsl);
			memset(ftkr, 0, n * sizeof *ftkr), memset(ftsr, 0, n * sizeof *ftsr);
			memset(kk, 0, (m_ + 1) * sizeof *kk);
			for (h = 0; h < m; h++)
				if (pp[h] != -INF && qq[h] != INF)
					update(ftk, fts, qq[h] - pp[h], n, 1, qq[h] - pp[h]);
			for (a = l, h = 0; a < r; a++) {
				while (h < m * 2 && tt[h_ = hh[h]] <= a) {
					if ((h_ & 1) == 0) {
						h_ >>= 1;
						if (msk[h_] == 0) {
							if (pp[h_] != -INF && qq[h_] != INF)
								update(ftk, fts, qq[h_] - pp[h_], n, -1, -(qq[h_] - pp[h_]));
							if (qq[h_] != INF)
								update(ftkr, ftsr, qq[h_], n, 1, qq[h_]);
						} else {
							if (pp[h_] != -INF)
								update(ftkl, ftsl, n - 1 - pp[h_], n, -1, -(n - 1 - pp[h_]));
							kk[idx_[bb[h_]]]++;
						}
						msk[h_] |= 1;
					} else {
						h_ >>= 1;
						if (msk[h_] == 0) {
							if (pp[h_] != -INF && qq[h_] != INF)
								update(ftk, fts, qq[h_] - pp[h_], n, -1, -(qq[h_] - pp[h_]));
							if (pp[h_] != -INF)
								update(ftkl, ftsl, n - 1 - pp[h_], n, 1, n - 1 - pp[h_]);
						} else {
							if (qq[h_] != INF)
								update(ftkr, ftsr, qq[h_], n, -1, -qq[h_]);
							kk[idx_[bb[h_]]]++;
						}
						msk[h_] |= 2;
					}
					h++;
				}
				for (o = 0; o < eo[a]; o++) {
					c = ec[a][o];
					ans = (long long) (a + 1) * c - query(ftk, fts, c - 1, c);
					m1 = 0;
					for (p = -1, q = 0, k = 0; q <= m_; q++) {
						k += kk[q];
						if (q == m_ || bb_[q] <= a) {
							l_ = p == -1 ? -INF : idx[bb_[p]], r_ = q == m_ ? INF : idx[bb_[q]];
							if (l_ != -INF && r_ != INF)
								ans -= (long long) max(c - (r_ - l_ + 1), 0) * k;
							if (l_ != -INF)
								ans -= query(ftkr, ftsr, min(min(l_ - 1 + c, r_) - 1, n - 1), l_ - 1 + c) - query(ftkr, ftsr, l_ - 1, l_ - 1 + c);
							if (r_ != INF)
								ans -= query(ftkl, ftsl, min(n - 1 - (max(r_ - c, l_ - 1) + 1), n - 1), n - 1 - (r_ - c)) - query(ftkl, ftsl, n - 1 - r_, n - 1 - (r_ - c));
							if (q < m_)
								bb1[m1++] = bb_[q];
							p = q, k = 0;
						}
					}
					cnt = 0;
					for (h1 = 0; h1 < m1; h1++) {
						while (cnt && bb1[qu[cnt - 1]] < bb1[h1])
							cnt--;
						pp1[h1] = cnt == 0 ? -INF : qu[cnt - 1];
						qu[cnt++] = h1;
					}
					cnt = 0;
					for (h1 = m1 - 1; h1 >= 0; h1--) {
						while (cnt && bb1[qu[cnt - 1]] < bb1[h1])
							cnt--;
						qq1[h1] = cnt == 0 ? INF : qu[cnt - 1];
						qu[cnt++] = h1;
					}
					for (h1 = 0; h1 < m1; h1++)
						if (pp1[h1] != -INF && qq1[h1] != INF)
							ans -= max(c - (idx[bb1[qq1[h1]]] - idx[bb1[pp1[h1]]] + qq1[h1] - pp1[h1]), 0);
					printf("%lld\n", ans);
#if STRESS
					if (ans != brute(aa, n, a, c)) {
						printf("WA: expected %lld\n", brute(aa, n, a, c));
						return 0;
					}
#endif
				}
			}
		}
		for (a = 0; a < n; a++)
			free(ec[a]);
	}
	return 0;
} 