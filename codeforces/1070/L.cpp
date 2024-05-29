#include <bits/stdc++.h>
#define endl " --- in " << __LINE__ << endl
using namespace std;
int n, m, deg[2010];
bitset<2010> t[2010];
void Solve(int test) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		deg[i] = 0, t[i].reset();
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y, deg[x]++, deg[y]++;
		t[x][y] = t[y][x] = 1;
	}
	bool flag = 1;
	for (int i = 1; i <= n; i++)
		if (deg[i] % 2)
			t[i][n + 1] = t[i][i] = 1, flag = 0;
	if (flag) {
		cout << 1 << "\n";
		for (int i = 1; i <= n; i++)
			cout << 1 << " \n"[i == n];
		return;
	}
	cout << 2 << "\n";
	int now = 1;
	for (int i = 1; i <= n; i++) {
		int p = 0;
		for (int j = now; j <= n; j++)
			if (t[j][i]) {p = j; break;}
		if (!p) continue;
		swap(t[now], t[p]);
		for (int j = 1; j <= n; j++) {
			if (j == now || !t[j][i]) continue;
			t[j] ^= t[now];
		}
		now++;
	}
	now = 1;
	for (int i = 1; i <= n; i++) {
		if (t[now][i]) cout << t[now++][n + 1] + 1 << " \n"[i == n];
		else cout << 1 << " \n"[i == n];
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) Solve(i);
	return 0;
}