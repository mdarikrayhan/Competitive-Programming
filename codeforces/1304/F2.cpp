// LUOGU_RID: 158203233
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 20010, M = N << 2;
int a[100][N], s[100][N];
ll f[100][N];

struct Node {
	ll mx, add;
} tr[M];

void pushup(int u) {
	tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
}

void pushdown(int u) {
	if (tr[u].add) {
		tr[u << 1].add += tr[u].add, tr[u << 1].mx += tr[u].add;
		tr[u << 1 | 1].add += tr[u].add, tr[u << 1 | 1].mx += tr[u].add;
		tr[u].add = 0;
	}
}

void modify(int u, int l, int r, int s, int t, ll v) {
	if (s <= l && r <= t) {
		tr[u].mx += v;
		tr[u].add += v;
		return;
	}
	pushdown(u);
	int mid = l + r >> 1;
	if (s <= mid) modify(u << 1, l, mid, s, t, v);
	if (t > mid) modify(u << 1 | 1, mid + 1, r, s, t, v);
	pushup(u);
}

int cover(int i, int l1, int r1, int l2, int r2) {
	if (r1 < l2 || r2 < l1) return 0;
	return s[i][min(r1, r2)] - s[i][max(l1, l2) - 1];
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i ++ )
    	for (int j = 1; j <= m; j ++ ) {
    		scanf("%d", &a[i][j]);
    		s[i][j] = a[i][j] + s[i][j - 1];
    	}
    for (int j = 1; j + k - 1 <= m; j ++ ) {
    	f[2][j] = (ll)s[2][j + k - 1] - s[2][j - 1] + s[1][j + k - 1] - s[1][j - 1];
	}
    for (int i = 3; i <= n + 1; i ++ ) {
    	for (int j = 0; j < M; j ++ ) tr[j].mx = tr[j].add = 0;
    	int l = 1, r = k;
    	for (int j = 1; j + k - 1 <= m; j ++ ) {
    		modify(1, 1, m, j, j, f[i - 1][j] - cover(i - 1, l, r, j, j + k - 1));
		}
		f[i][l] = tr[1].mx + s[i][r] + s[i - 1][r];
		while (r + 1 <= m) {
			modify(1, 1, m, max(1, l - k + 1), l, a[i - 1][l]);
			modify(1, 1, m, l + 1, r + 1, -a[i - 1][r + 1]);
			l ++ , r ++ ;
			f[i][l] = tr[1].mx + s[i][r] - s[i][l - 1] + s[i - 1][r] - s[i - 1][l - 1];
		}
	}
	long long ans = 0;
	for (int i = 1; i + k - 1 <= m; i ++ ) ans = max(ans, f[n + 1][i]);
	printf("%lld\n", ans);
    return 0;
}