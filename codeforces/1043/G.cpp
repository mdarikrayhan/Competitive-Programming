// LUOGU_RID: 160591646
#include<bits/stdc++.h>

#pragma GCC optimize(2)

#define ll long long
#define ull unsigned long long
#define REP(i, l, r) for (int i = l; i <= r; ++i)
#define PER(i, l, r) for (int i = l; i >= r; --i)

using namespace std;

const int N = 2e5 + 7;
const int inf = 1e9 + 7;

namespace cplus_ {
	int n, q;
	string S, T;
	/**
	 * check answer = -1
	 */
	int char_sum[N][26];
	inline bool check_no_answer(int l, int r) {
		REP(i, 0, 25)
			if (char_sum[r][i] - char_sum[l - 1][i] > 1) return false;
		return true;
	}
/**
 * check answer = 1
 */
    struct SA_ {
        int n; string S;
        int sa[N], rnk[N], oldrk[N], st[N][22], cnt[N], id[N];
        inline void GetSA(int _n_, string _S_) {
            n = _n_, S = _S_; int m = 130, p = 0;
            for (int i = 1; i <= n; i++) cnt[rnk[i] = S[i]]++;
            for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
            for (int i = n; i >= 1; i--) sa[cnt[rnk[i]]--] = i;

            for (int w = 1;; w <<= 1, m = p) {  // m = p 即为值域优化
                int cur = 0;
                for (int i = n - w + 1; i <= n; i++) id[++cur] = i;
                for (int i = 1; i <= n; i++)
                    if (sa[i] > w) id[++cur] = sa[i] - w;

                memset(cnt, 0, sizeof(cnt));
                for (int i = 1; i <= n; i++) cnt[rnk[i]]++;
                for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
                for (int i = n; i >= 1; i--) sa[cnt[rnk[id[i]]]--] = id[i];

                p = 0;
                memcpy(oldrk, rnk, sizeof(oldrk));
                for (int i = 1; i <= n; i++) {
                    if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&
                        oldrk[sa[i] + w] == oldrk[sa[i - 1] + w])
                        rnk[sa[i]] = p;
                    else
                        rnk[sa[i]] = ++p;
                }

                if (p == n) break;  // p = n 时无需再排序
            }
            REP(i, 1, n) sa[rnk[i]] = i;
            int tot = 0;
            REP(i, 1, n) {
                if (rnk[i] == 1) continue; tot = tot ? tot - 1 : 0;
                while (i + tot <= n && sa[rnk[i] - 1] + tot <= n && S[i + tot] == S[sa[rnk[i] - 1] + tot]) ++tot;
                st[rnk[i]][0] = tot;
            }
            REP(j, 1, 20)
                REP(i, 1, n) {
                    if (i + (1 << (j - 1)) > n) break;
                    st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
                }
        }
        inline int LCP(int x, int y){
            x = rnk[x], y = rnk[y];
            if (x == y) return n - x + 1;
            if (x > y) swap(x, y);
            ++x;
            int _ = __lg(y - x + 1);
            return min(st[x][_], st[y - (1 << _) + 1][_]);
        }
    } A, B;
    vector<int> gcc[N];
	inline bool check_one_answer(int l, int r) {
		int len = r - l + 1;
		for (auto i : gcc[len])
            if (A.LCP(l, l + i) >= r - l + 1 - i) return true;
        return false;
	}
    /**
     * check answer = 2
     */

    struct seg_tree {
        int mi[N << 2], plus[N];
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
        seg_tree() {memset(mi, 0x3f, sizeof(mi));}
        void update(int x, int l, int r, int L, int R, int c) {
            if (mi[x] <= c) return;
            if (L <= l && r <= R) {
                mi[x] = min(mi[x], c);
                return;
            } int mid = (l + r) >> 1;
            mi[ls(x)] = min(mi[ls(x)], mi[x]), mi[rs(x)] = min(mi[rs(x)], mi[x]);
            if (L <= mid) update(ls(x), l, mid, L, R, c);
            if (mid < R) update(rs(x), mid + 1, r, L, R, c);
        }
        void in(int x, int l, int r) {
            if (l == r) {
                plus[l] = mi[x];
                return;
            } int mid = (l + r) >> 1;
            mi[ls(x)] = min(mi[ls(x)], mi[x]), mi[rs(x)] = min(mi[rs(x)], mi[x]);
            in(ls(x), l, mid), in(rs(x), mid + 1, r);
        }
    } f, g;
	inline bool check_two_answer(int l, int r) {
		/// AAB or BAA
		if (l + f.plus[l] - 1 < r) return true; //AAB
		if (r - g.plus[r] + 1 > l) return true; //BAA
		/// ABA
		int limit = sqrt(n), max_LCP = ((r - l + 1) >> 1) - 1 + ((r - l + 1) & 1);
		REP(i, 1, min(limit, max_LCP))
			if (A.LCP(l, r - i + 1) >= i) return true;
		REP(i, max(1, A.rnk[l] - limit + 1), min(n, A.rnk[l] + limit - 1)) {
            if (i == A.rnk[l]) continue;
			int pos = A.sa[i];
			if (pos < l || r < pos) continue;
			int LCP_ = A.LCP(l, pos);
			if (r - pos + 1 <= LCP_ && min(r - pos + 1, LCP_) <= max_LCP) return true;
		} return false;
	}
	/**
	 * check answer = 3
	 */
	int flow[N][22];
	inline int rmq_(int x, int y) {
		int _ = __lg(y - x + 1);
		return min(flow[x][_], flow[y - (1 << _) + 1][_]);
	}
	inline bool check_three_answer(int l, int r) {
		if (char_sum[r][S[l] - 'a'] - char_sum[l - 1][S[l] - 'a'] > 1) return true;
		if (char_sum[r][S[r] - 'a'] - char_sum[l - 1][S[r] - 'a'] > 1) return true;
		if (rmq_(l + 1, r) < r) return true;
		return false;
	}
	inline void init() {
		/**
		 * if answer = -1
		 * init the char_sum
		 */
		REP(i, 1, n) {
			REP(j, 0, 25) char_sum[i][j] = char_sum[i - 1][j];
			++char_sum[i][S[i] - 'a'];
		}
		/**
		 * if answer = 1
		 * We can find a string T, |S| === 0 (mod |T|) and k * T = S
		 * init the hash & the prime_number
		*/
        REP(i, 2, n) {
            gcc[i].emplace_back(1);
            for (int j = 2; j * j <= i; ++j) {
                if (i % j) continue;
                gcc[i].emplace_back(j);
                if (j * j != i) gcc[i].emplace_back(i / j);
            }
        }
		/**
		 * if answer = 2
		 * AAB or BAA : like the problem Great Cut String: we can init the shortest AA in pre / suf
		 * ABA : the shortest border, use SA and Hash we can solve it in O(sqrt(n))
		 * very easy
		*/
		A.GetSA(n, S);
		B.GetSA(n, T);
		REP(i, 1, n) {
			for (int j = 1, k = 0, a = 0, b = 0, num = 0; j + i <= n; j += i) {
				k = j + i, a = A.LCP(j, k), b = B.LCP(n - j + 2, n - k + 2);
				a = min(i, a), b = min(i - 1, b);
				if (a + b < i) continue;
				num = a + b + 1 - i; //重复的区间，这里都合法
				f.update(1, 1, n, j - b, j - b + num - 1, i << 1);
				g.update(1, 1, n, k + a - num, k + a - 1, i << 1);
			}
		}
		/**
		 * if answer = 3
		 * ABBC init the st to ask the query
		*/
		f.in(1, 1, n), g.in(1, 1, n);
		REP(i, 1, n) flow[i][0] = i + f.plus[i] - 1;
		REP(j, 1, 20)
			REP(i, 1, n) {
				if (i + (1 << (j - 1)) > n) break;
				flow[i][j] = min(flow[i][j - 1], flow[i + (1 << (j - 1))][j - 1]);
			}
	}

	inline int check(int l, int r) {
		if (l == r) return -1;
		if (check_no_answer(l, r)) return -1;
		if (check_one_answer(l, r)) return 1;
		if (check_two_answer(l, r)) return 2;
		if (check_three_answer(l, r)) return 3;
		return 4;
	}

	signed main() {
		cin >> n >> S, S = " " + S, T = " ";
		PER(i, n, 1) T += S[i];
		init();
		cin >> q; int l = 0, r = 0;
		REP(i, 1, q) {
			cin >> l >> r;
			cout << check(l, r) << '\n';
		}
		return 0;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	//	freopen("data.txt", "r", stdin);
	//	freopen("user.out", "w", stdout);
	cplus_::main();
	return 0;
}