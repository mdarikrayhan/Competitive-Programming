// LUOGU_RID: 157610755
#include <bits/stdc++.h>
#define LL long long
#define pii pair<int, int>
#define fi first
#define se second
#define mkp make_pair
#define pb push_back
using namespace std;

LL read() {
	LL s = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
		f = (ch == '-' ? -1 : 1), ch = getchar();
	while (ch >= '0' && ch <= '9')
		s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
	return s * f;
}

const int MAXN = 25005, MAXM = 100005;

int n, m;
int a[MAXN], l[MAXM], r[MAXM];
int L[MAXN], R[MAXN];
int sl[MAXN], sr[MAXN], bl[MAXN], br[MAXN];
int ans = 0;

void updmx(int &x, int y) {
	if (!x || a[x] < a[y])
		x = y;
}

void updmn(int &x, int y) {
	if (!x || a[x] > a[y])
		x = y;
}

void updr(int x, int r) {
	ans -= sl[br[x]] == x, ans -= bl[sr[x]] == x;
	for (int i = R[x] + 1; i <= r; i++) {
		if (a[i] > a[x])
			updmn(br[x], i);
		else
			updmx(sr[x], i);
	}
	ans += sl[br[x]] == x, ans += bl[sr[x]] == x;
	R[x] = r;
}

void updl(int x, int l) {
	ans -= sr[bl[x]] == x, ans -= br[sl[x]] == x;
	for (int i = L[x] - 1; i >= l; i--) {
		if (a[i] > a[x])
			updmn(bl[x], i);
		else
			updmx(sl[x], i);
	}
	ans += sr[bl[x]] == x, ans += br[sl[x]] == x;
	L[x] = l;
}

signed main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read(), L[i] = R[i] = i;
	for (int i = 1; i <= m; i++) {
		int l = read(), r = read();
		for (int j = l; j <= r && R[j] < r; j++)
			updr(j, r);
		for (int j = r; j >= l && L[j] > l; j--)
			updl(j, l);
		printf("%d\n", ans);
	}
	return 0;
}