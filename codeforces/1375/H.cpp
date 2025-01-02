#include <bits/stdc++.h>

#define For(i, a, b) for (int i = a; i <= b; ++i)
#define rFor(i, b, a) for (int i = b; i >= a; --i)
#define eFor(i, u, v) for (int i = head[u], v = e[i].to; i; i = e[i].next, v = e[i].to)

typedef long long ll;
typedef std::pair<int, int> pii;
#define fi first
#define se second

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T myrand(T l, T r) {
	return std::uniform_int_distribution<T>(l, r)(rnd);
}

const int kN = (1 << 12) + 5;
const int kB = (1 << 8) + 6;
const int kM = (1 << 16) + 5;

int n, bs, q, a[kN], pos[kN], ql[kM], qr[kM], ans[kM];

const int kS = 2.2e6 + 5;

int tot, lc[kS], rc[kS];
int lb, rb, pb[kN], idb[kN], stb[kB][kB], nstb[kB][kB], nxt[kN], pre[kN];

void solve(int L, int R) {
	if (L == R) {
		stb[L - lb][R - lb] = pos[L];
		return;
	}
	int mid = (L + R) >> 1;
	solve(L, mid), solve(mid + 1, R);
	std::inplace_merge(pb + L, pb + mid + 1, pb + R + 1, [](int i, int j) {
		return pos[i] < pos[j];
	});
	For(l, L, R) for (int i = l, l1 = R + 1, l2 = R + 1, r1 = -1, r2 = -1; i <= R; ++i) {
		if (pb[i] <= mid) {
			r1 = i;
			if (l1 == R + 1) l1 = i;
		}
		else {
			r2 = i;
			if (l2 == R + 1) l2 = i;
		}
		if (r1 != -1 && r2 != -1) {
			nstb[pb[l] - lb][pb[i] - lb] = ++tot;
			lc[tot] = stb[pb[l1] - lb][pb[r1] - lb], rc[tot] = stb[pb[l2] - lb][pb[r2] - lb];
		}
		else nstb[pb[l] - lb][pb[i] - lb] = 0;
	}
	For(i, L, R) For(j, i, R) if (nstb[pb[i] - lb][pb[j] - lb])
		stb[pb[i] - lb][pb[j] - lb] = nstb[pb[i] - lb][pb[j] - lb];
}

const int _Buf_ = 1e7 + 5;

char obuf[_Buf_], *o = obuf;

inline void pc(char c) {
	if (o - obuf == _Buf_) fwrite(o = obuf, 1, _Buf_, stdout);
	*o++ = c;
}

void write(int x) {
	if (x < 10) {
		pc(x + '0');
		return;
	}
	write(x / 10), pc(x % 10 + '0');
}

int main() {
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	scanf("%d%d", &n, &q);
	For(i, 1, n) scanf("%d", &a[i]), pos[a[i]] = i;
	bs = sqrt(q);
	tot = n;
	For(i, 1, q) scanf("%d%d", &ql[i], &qr[i]);
	For(i, 1, n) pb[i] = i;
	for (lb = 1, rb = bs; lb <= n; lb += bs, rb += bs) {
		rb = std::min(rb, n);
		solve(lb, rb);
		For(i, 1, n) {
			if (a[i] >= lb && a[i] <= rb) pre[i] = i;
			else pre[i] = pre[i - 1];
		}
		nxt[n + 1] = n + 1;
		rFor(i, n, 1) {
			if (a[i] >= lb && a[i] <= rb) nxt[i] = i;
			else nxt[i] = nxt[i + 1];
		}
		For(i, 1, q) if (nxt[ql[i]] <= qr[i] && pre[qr[i]] >= ql[i]) {
			int l = a[nxt[ql[i]]], r = a[pre[qr[i]]];
			if (!ans[i]) ans[i] = stb[l - lb][r - lb];
			else {
				++tot;
				lc[tot] = ans[i], rc[tot] = stb[l - lb][r - lb];
				ans[i] = tot;
			}
		}
	}
	write(tot), pc('\n');
	For(i, n + 1, tot) write(lc[i]), pc(' '), write(rc[i]), pc('\n');
	For(i, 1, q) write(ans[i]), pc(' ');
	fwrite(obuf, 1, o - obuf, stdout);
	return 0;
}