// LUOGU_RID: 159797367
#include<bits/stdc++.h>
#define rep(i,L,R) for (int i(L), i##end(R); i <= i##end; ++i)
#define per(i,R,L) for (int i(R), i##end(L); i >= i##end; --i)
#define LL long long
#define eb emplace_back
using namespace std;
typedef pair <int, int> PII;
#define mp make_pair
#define fi first
#define se second

template <typename T>
void read(T &x) {
	x = 0; bool f = 0; char ch = getchar();
	while (ch < '0' || ch > '9') f ^= ch == '-', ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	if (f) x = -x;
}

template <typename Tx, typename ...Ty>
void read(Tx &x, Ty &...y) {read(x);read(y...);}

template <typename T>
void write(T x, char ch = '\0') {
	if (x < 0) return putchar('-'), write(-x, ch);
	if (x > 9) write(x / 10);
	putchar('0' + x % 10);
	if (ch != '\0') putchar(ch);
}

template <typename T>
void cmax(T &x, T y) {if (x < y) x = y; }
template <typename T>
void cmin(T &x, T y) {if (x > y) x = y; }

const int N = 1e3 + 9;

int n, p0, p1;
int ans0[N][4], ans1[N][4];
// 0, 1 -> 2, 3
set <int> S0[N], S1[N];

void solve0() {
	rep (i, 2, n) {
		while (!S0[i].empty()) {
			int x = *(--S0[i].end());
			S0[i].erase(--S0[i].end());
			if (x == 1) continue;
			++p0;
			ans0[p0][0] = i;
			ans0[p0][1] = x;
			ans0[p0][2] = 1;
			S0[x].erase(S0[x].find(i));
			int t;
			if (S0[i].empty()) t = i + 1;
			else t = *(--S0[i].end());
			ans0[p0][3] = t;
			S0[1].insert(t);
		}
	}
}

void solve1() {
	rep (i, 2, n) {
		while (!S1[i].empty()) {
			int x = *(--S1[i].end());
			S1[i].erase(--S1[i].end());
			if (x == 1) continue;
			++p1;
			ans1[p1][0] = i;
			ans1[p1][1] = x;
			ans1[p1][2] = 1;
			S1[x].erase(S1[x].find(i));
			int t;
			if (S1[i].empty()) t = i + 1;
			else t = *(--S1[i].end());
			if (t == 1) cerr << "i !" << i << endl;
			ans1[p1][3] = t;
			S1[1].insert(t);
		}
	}
}

int main() {
	read(n);
	rep (i, 1, n - 3) {
		int x, y;
		read(x, y);
		if (y != 1) S0[x].insert(y);
		if (x != 1) S0[y].insert(x);
	}
	rep (i, 1, n - 3) {
		int x, y;
		read(x, y);
		if (y != 1) S1[x].insert(y);
		if (x != 1) S1[y].insert(x);
	}
	solve0();
	solve1();
	printf("%d\n", p0 + p1);
	rep (i, 1, p0) printf("%d %d\n", ans0[i][0], ans0[i][1]);
	per (i, p1, 1) {
		// printf("%d %d ", ans1[i][0], ans1[i][1]);
		printf("%d %d\n", ans1[i][2], ans1[i][3]);
	}
	return 0;
}