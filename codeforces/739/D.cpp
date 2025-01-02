#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fir first
#define sec second
#define eb emplace_back
#define ep emplace

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return x * f;
}

const int N = 310;

int n, m, x[N], y[N];
int fa[N], match[N], mxd[N], cnt[N];
bool vis[N], va[N], vb[N], g[N][N];
vector<int> ring[N];
char s1[N], s2[N];

struct Node { int p, c; } a[N];

bool dfs(int u) {
	for (int v = 1; v <= m; v ++ ) {
		if (g[u][v] && !vis[v]) {
			vis[v] = true;
			if (!match[v] || dfs(match[v])) {
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}

bool check(int k) {
	m = 0; // 需求的个数 
	memset(g, 0, sizeof g);
	memset(va, 0, sizeof va);
	memset(vb, 0, sizeof vb);
	memset(match, 0, sizeof match);
	for (int i = 1; i <= n; i ++ ) { // 枚举环长 
		if (~mxd[i] || i == k) {
			int c = cnt[i], p = mxd[i];
			if (i == k) p = max(p, mxd[0]);
			if (m + c + p > n) return 0;
			for (int j = 1; j <= c; j ++ ) x[ ++ m] = i, y[m] = 0;
			for (int j = 1; j <= p; j ++ ) x[ ++ m] = i, y[m] = j;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= m; j ++ ) {
			if ((a[i].c == x[j] || a[i].c == -1) && (a[i].p == y[j] || a[i].p == -1)) g[i][j] = true;
			if (a[i].c == x[j] && a[i].p == y[j] && !va[i] && !vb[j]) va[i] = vb[j] = true, match[j] = i, ans ++ ;
		}
	}
	for (int i = 1; i <= n; i ++ ) {
		if (!va[i]) {
			memset(vis, 0, sizeof vis);
			ans += dfs(i);
		}
	}
	return ans == m;
}

int main() {
	n = read();
	memset(mxd, -1, sizeof mxd);
	for (int i = 1; i <= n; i ++ ) {
		scanf("%s%s", s1, s2);
		a[i].p = (*s1 ^ '?') ? atoi(s1) : -1;
		a[i].c = (*s2 ^ '?') ? atoi(s2) : -1;
		if (~a[i].c) {
			if (~a[i].p) mxd[a[i].c] = max(mxd[a[i].c], a[i].p);
			else mxd[a[i].c] = max(mxd[a[i].c], 0);
			if (!a[i].p) cnt[a[i].c] ++ ;
		}
		else mxd[0] = max(mxd[0], a[i].p);
	}
	for (int i = 1; i <= n; i ++ ) cnt[i] = max(i, (cnt[i] + i - 1) / i * i);
	for (int k = 1; k <= n; k ++ ) {
		if (check(k)) {
			for (int i = 1; i <= m; i ++ ) a[match[i]] = {y[i], x[i]};
			for (int i = 1; i <= n; i ++ ) {
				if (a[i].c == -1) {
					if (a[i].p <= 0) a[i] = {0, 1};
					else a[i].c = k;
				}
				else if (a[i].p == -1) a[i].p = 1;
			}
			for (int i = 1; i <= n; i ++ ) { // 在一条链上 
				for (int j = 1; j <= n; j ++ ) {
					if (a[i].p == a[j].p + 1 && a[i].c == a[j].c) {
						fa[i] = j;
						break;
					}
				}
			}
			for (int i = 1; i <= n; i ++ ) { // 分配点到环上 
				if (!a[i].p) {
					ring[a[i].c].eb(i);
					if ((int)ring[a[i].c].size() == a[i].c) {
						for (int j = 0; j + 1 < a[i].c; j ++ ) {
							int u = ring[a[i].c][j];
							int v = ring[a[i].c][j + 1];
							fa[u] = v;
						}
						fa[ring[a[i].c].back()] = ring[a[i].c][0];
						ring[a[i].c].clear();
					}
				}
			}
			for (int i = 1; i <= n; i ++ ) printf("%d ", fa[i]);
			return puts(""), 0;
		}
	}
	puts("-1");
	return 0;
}
