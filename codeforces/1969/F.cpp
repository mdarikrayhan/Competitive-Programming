// Problem: F. Card Pairing
// Contest: Codeforces - Educational Codeforces Round 165 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1969/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define pb emplace_back
#define fst first
#define scd second
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef long double ldb;
typedef pair<int, int> pii;

const int maxn = 1010;

int n, m, a[maxn], b[maxn], cnt, stk[maxn], top, f[maxn];
bool vis[maxn][maxn];

inline void add(int i) {
	for (int j = i * 2 - 1; j <= i * 2; ++j) {
		int x = a[j];
		if (b[x] & 1) {
			--cnt;
		} else {
			++cnt;
			stk[++top] = x;
		}
		++b[x];
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	mems(f, -0x3f);
	for (int i = 1; i <= n / 2; ++i) {
		add(i);
		if (i == n / 2 || cnt == m) {
			f[i] = (i * 2 - cnt) / 2;
			break;
		}
	}
	for (int i = 1; i < n / 2; ++i) {
		if (f[i] < 0) {
			continue;
		}
		top = cnt = 0;
		mems(b, 0);
		vector<pii> vc;
		for (int j = i + 1; j <= n / 2; ++j) {
			add(j);
			if (cnt != 2) {
				continue;
			}
			int x = 0, y = 0;
			while (top) {
				int z = stk[top--];
				if (b[z] & 1) {
					if (x && z != x) {
						y = z;
					} else {
						x = z;
					}
				}
			}
			stk[++top] = x;
			stk[++top] = y;
			if (x > y) {
				swap(x, y);
			}
			if (!vis[x][y]) {
				vis[x][y] = 1;
				vc.pb(x, y);
				f[j] = max(f[j], f[i] + ((j - i) * 2 + cnt) / 2 - 2);
			}
		}
		vector<int> va, vb;
		for (int j = 1; j <= m; ++j) {
			((b[j] & 1) ? vb : va).pb(j);
		}
		for (int x = 0; x < (int)va.size(); ++x) {
			for (int y = x + 1; y < (int)va.size(); ++y) {
				if (!vis[va[x]][va[y]]) {
					f[n / 2] = max(f[n / 2], f[i] + (n - i * 2 + cnt) / 2);
					break;
				}
			}
		}
		for (int x : va) {
			for (int y : vb) {
				if (!vis[min(x, y)][max(x, y)]) {
					f[n / 2] = max(f[n / 2], f[i] + (n - i * 2 + cnt) / 2 - 1);
					break;
				}
			}
		}
		for (int x = 0; x < (int)vb.size(); ++x) {
			for (int y = x + 1; y < (int)vb.size(); ++y) {
				if (!vis[vb[x]][vb[y]]) {
					f[n / 2] = max(f[n / 2], f[i] + (n - i * 2 + cnt) / 2 - 2);
					break;
				}
			}
		}
		for (pii p : vc) {
			vis[p.fst][p.scd] = 0;
		}
	}
	printf("%d\n", f[n / 2]);
}
/////////////////
int main() {
	int T = 1;
	// scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}

   			     	  	  		  		 	 		 		