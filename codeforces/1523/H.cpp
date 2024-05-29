// learned from https://www.luogu.com.cn/article/hevvfurc
#include <bits/stdc++.h>
using namespace std;

const int maxn = 20005, logn = 16, maxk = 31;

int n, q, a[maxn];

struct Node {
	int w, i;
	Node() {}
	Node(int i) : w(a[i] + i), i(i) {}
	Node(int w, int i) : w(min(w, n)), i(i) {}
	Node operator+ (const Node &other) const {
		return w < other.w ? other : *this;
	}
} f[maxn][logn][maxk];

#define lc (i << 1)
#define rc (i << 1 | 1)
Node t[maxn << 2];
void build(int i, int l, int r) {
	if (l == r) {
		t[i] = (Node){a[l] + l, l};
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	t[i] = t[lc] + t[rc];
}

Node query(int i, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return t[i];
	int mid = l + r >> 1;
	if (qr <= mid) return query(lc, l, mid, ql, qr);
	if (ql > mid) return query(rc, mid + 1, r, ql, qr);
	return query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];

	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		f[i][0][0] = query(1, 1, n, i, i + a[i]);
		for (int k = 1; k < maxk; k++) {
			f[i][0][k] = Node(f[i][0][k - 1].w + 1, f[i][0][k - 1].i) + Node(min(a[i] + i + k, n));
		}
	}

	for (int j = 1; j < logn; j++) {
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k < maxk; k++) {
				for (int kk = 0; kk <= k; kk++) {
					f[i][j][k] = f[i][j][k] + f[f[i][j - 1][kk].i][j - 1][k - kk];
				}
			}
		}
	}

	int l, r, k, cur[maxk];
	while (q--) {
		cin >> l >> r >> k;
		if (l == r) {
			cout << "0\n";
			continue;
		}

		if (l + a[l] + k >= r) {
			cout << "1\n";
			continue;
		}

		fill(cur, cur + k + 1, l);
		int res = 2;
		for (int j = logn - 1; j >= 0; j--) {
			bool flag = 1;
			for (int i = 0; i <= k; i++) {
				if (f[cur[i]][j][k - i].w >= r) {
					flag = 0;
					break;
				}
			}
			if (!flag) continue;;
			res += 1 << j;
			for (int i = k; i >= 0; i--) {
				Node mx = {0, 0};
				for (int kk = 0; kk <= i; kk++) {
					mx = mx + f[cur[kk]][j][i - kk];
				}
				cur[i] = mx.i;
			}
		}
		cout << res << '\n';
	}
}