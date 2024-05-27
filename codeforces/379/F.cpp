#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
int q;
int n;
int x;
int u, v, ans;
int dep[MAXN];
int fa[MAXN][25];
void update (int id) {
	for (int i = 1; i <= 21; ++i) {
		fa[id][i] = fa[fa[id][i - 1]][i - 1];
	}
}
int lca (int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	while (dep[x] > dep[y]) {
		int t = dep[x] - dep[y];
		x = fa[x][int(log2(t))];
	}
	if (x == y) {
		return x;
	}
	for (int i = 21; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) {
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	u = 2, v = 3, ans = 2, n = 4;
	dep[2] = dep[3] = dep[4] = 1;
	fa[2][0] = fa[3][0] = fa[4][0] = 1;
	cin >> q;
	while (q--) {
		cin >> x;
		dep[n + 1] = dep[x] + 1;
		dep[n + 2] = dep[x] + 1;
		fa[n + 1][0] = x;
		fa[n + 2][0] = x;
		update(n + 1);
		update(n + 2);
		int la = lca(n + 1, u);
		int lb = lca(n + 1, v);
		int val1 = dep[u] + dep[n + 1] - dep[la] * 2;
		int val2 = dep[v] + dep[n + 1] - dep[lb] * 2;
		if (val1 > val2) {
			if (val1 > ans) {
				ans = val1;
				v = n + 1;
			}
		} else {
			if (val2 > ans) {
				ans = val2;
				u = n + 1;
			}
		}
		n += 2;
		cout << ans << endl;
	}
	return 0;
}
  		  	 	 	 	  		 		 					 	 	