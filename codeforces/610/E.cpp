// LUOGU_RID: 160485192
#include<bits/stdc++.h>

#define REP(i, l, r) for (int i = l; i <= r; ++i)

#define ll long long

using namespace std;

namespace charstream {
	inline void read(int &x) {
		int w = 1; char ch = getchar(); x = 0;
		while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
		if (ch == '-') w = -1, ch = getchar();
		while ('0' <= ch && ch <= '9') x = ((x << 3) + (x << 1) + (ch - '0')), ch = getchar();
	}
	inline void read(char &ch) {
		ch = getchar();
		while (isspace(ch)) ch = getchar();
	}
}

const int N = 2e5 + 7;

int n, q, K, arr[N];

struct Matrix {
	int p[10][10];
	Matrix() {memset(p, 0, sizeof(p));}
	Matrix(int i, int j, int w) {
		memset(p, 0, sizeof(p));
		p[i][j] = w;
	}
	friend Matrix operator + (const Matrix &a, const Matrix &b) {
		Matrix c;
		REP(i, 0, 9)
			REP(j, 0, 9)
				c.p[i][j] = a.p[i][j] + b.p[i][j];
		return c;
	}
};

struct Node {
	Matrix v;
	int tg, l_, r_;
	Node() {tg = l_ = r_ = 11, v = Matrix();}
} tr[N << 2];
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define pushup(x) (\
	tr[x].l_ = tr[ls(x)].l_, tr[x].r_ = tr[rs(x)].r_, \
	tr[x].v = Matrix(tr[ls(x)].r_, tr[rs(x)].l_, 1) + tr[ls(x)].v + tr[rs(x)].v)
#define pdd(x, tg_, len) (tr[x].v = Matrix(tg_, tg_, len - 1), tr[x].l_ = tr[x].r_ = tg_, tr[x].tg = tg_)
inline void pushdown(int x, int l, int r) {
	if (tr[x].tg ^ 11) {
		int mid = (l + r) >> 1;
		pdd(ls(x), tr[x].tg, (mid - l + 1)), pdd(rs(x), tr[x].tg, (r - mid));
		tr[x].tg = 11;
	}
}
inline void Build(int x, int l, int r) {
	if (l == r) {
		tr[x].l_ = tr[x].r_ = arr[l];
		return;
	} int mid = (l + r) >> 1;
	Build(ls(x), l, mid), Build(rs(x), mid + 1, r);
	pushup(x);
}
inline void update(int x, int l, int r, int L, int R, int c) {
	if (L <= l && r <= R) {
		pdd(x, c, (r - l + 1));
		return;
	} int mid = (l + r) >> 1; pushdown(x, l, r);
	if (L <= mid) update(ls(x), l, mid, L, R, c);
	if (mid < R) update(rs(x), mid + 1, r, L, R, c);
	pushup(x);
}

signed main() {
//	freopen("asdasdasd.in", "r", stdin);
	charstream::read(n), charstream::read(q), charstream::read(K);
	int op, l, r; char ch;
	REP(i, 1, n)
		charstream::read(ch),
		arr[i] = ch - 'a';
	
	Build(1, 1, n);
	REP(T, 1, q) {
		charstream::read(op);
		if (op == 1) {
			charstream::read(l), charstream::read(r);
			charstream::read(ch);
			update(1, 1, n, l, r, ch - 'a');
//			REP(i, 0, K - 1) {
//				REP(j, 0, K - 1) 
//					cout << tr[1].v.p[i][j] << ' ';
//				cout << '\n';
//			}
		} else {
			REP(i, 1, K)
				charstream::read(ch),
				arr[i] = ch - 'a';
			int Res = 1;
			REP(i, 1, K)
				REP(j, 1, i) 
					Res += tr[1].v.p[arr[i]][arr[j]];
			cout << Res << '\n'; 
		}
	}
	return 0;
} 