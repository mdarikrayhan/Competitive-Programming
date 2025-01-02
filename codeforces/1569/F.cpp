// LUOGU_RID: 160014026
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define db double
const int maxn = 1e4 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;

namespace IO {
void openfile() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
}
void Min(int& x, int y) {
	x = (x < y) ? x : y;
}
void Max(int& x, int y) {
	x = (x > y) ? x : y;
}
int add(int x, int y) {
	return (x + y) >= mod ? (x + y - mod) : (x + y);
}
int sub(int x, int y) {
	return (x < y) ? (x + mod - y) : (x - y);
}
void Add(int& x, int y) {
	x = (x + y) >= mod ? (x + y - mod) : (x + y);
}
void Sub(int& x, int y) {
	x = (x < y) ? (x - y + mod) : (x - y);
}
int mul(int x, int y) {
	return 1ll * x * y % mod;
}
void Mul(int& x, int y) {
	x = 1ll * x * y % mod;
}
int qpow(int x, int y = mod - 2) {
	int ans = 1;
	while (y) {
		if (y & 1)
			ans = 1ll * x * ans % mod;
		x = 1ll * x * x % mod, y >>= 1;
	}
	return ans;
}
inline int read() {
	int x = 0, f = 0;
	char c = getchar();
	while (!isdigit(c))
		f |= c == '-', c = getchar();
	while (isdigit(c))
		x = x * 10 + c - '0', c = getchar();
	if (f)
		x = -x;
	return x;
}
}  // namespace IO
using namespace IO;

int n, m, k, u[maxn], v[maxn];
int e[1010][1010], A[1010][1010];
int totb, b[maxn][110], a[maxn], vis[maxn];
int x[maxn], y[maxn], col[maxn];
bool f[maxn][20][20];
set<vector<int>> q;

void dfs(int stp, int col) {
	if (col > min(k, (n / 2)))
		return;
	if (stp == n / 2) {
		++totb;
		for (int i = 1; i <= n / 2; i++)
			b[totb][i] = a[i];
		return;
	}
	for (int i = 1; i <= col + 1; i++)
		a[stp + 1] = i, dfs(stp + 1, max(col, i));
}

bool is(int S, int x) {
	return (S >> (x - 1) & 1);
}

int ji(int x) {
	return (1 << (x - 1));
}

bool pan() {
	for (int s = 0; s < (1 << n); s++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[s][i][j] = 0;
	for (int i = 1; i <= (n / 2); i++)
		if (e[x[i]][y[i]])
			f[ji(x[i]) | ji(y[i])][x[i]][y[i]] = f[ji(x[i]) | ji(y[i])][y[i]][x[i]] = 1;
	for (int i, j, k, l, s = 1; s < (1 << n); s++) {
		for (int I = 1; I <= (n / 2); I++) {
			i = x[I], j = y[I];
			if (f[s][i][j] || f[s][j][i])
				for (int J = 1; J <= (n / 2); J++) {
					k = x[J], l = y[J];
					if (!is(s, k) && !is(s, l) && ((e[i][k] && e[j][l]) || (e[i][l] && e[j][k])))
						f[s | ji(l) | ji(k)][l][k] = f[s | ji(l) | ji(k)][k][l] = 1;
				}
		}
	}
	for (int i = 1; i <= (n / 2); i++)
		if (f[(1 << n) - 1][x[i]][y[i]])
			return 1;
	return 0;
}
vector<int> p;
void dfs1(int stp) {
	if (stp == n / 2) {
		for (int i = 1; i <= stp; i++)
			col[x[i]] = col[y[i]] = i;
		// cout << pan() << ":\n";
		// for (int i = 1; i <= stp; i++)
		// 	printf("%d %d\n", x[i], y[i]);
		if (!pan())
			return;
		for (int i = 1; i <= totb; i++) {
			for (int j = 1; j <= stp; j++)
				col[x[j]] = col[y[j]] = b[i][j];
			p.clear();
			for (int i = 1; i <= n; i++)
				p.push_back(col[i]);
			q.insert(p);
		}
		return;
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			vis[i] = 1;
			x[stp + 1] = i;
			for (int j = i + 1; j <= n; j++)
				if (!vis[j])
					vis[j] = 1, y[stp + 1] = j, dfs1(stp + 1), vis[j] = 0;
			vis[i] = 0;
			break;
		}
}

signed main() {
	openfile();
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++) {
		u[i] = read(), v[i] = read();
		e[u[i]][v[i]] = e[v[i]][u[i]] = 1;
	}
	for (int i = 0; i <= k; i++) {
		A[i][0] = 1;
		for (int j = 1; j <= i; j++)
			A[i][j] = A[i][j - 1] * (i - j + 1);
	}
	dfs(0, 0), dfs1(0);
	ll ans = 0;
	for (auto p : q) {
		int mx = 0;
		for (int v : p)
			mx = max(mx, v);
		ans += A[k][mx];
	}
	cout << ans << endl;
	return 0;
}
