#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[505][505];

void solve() {
	vector<int> cand;
	for (int i = 1; i <= n; ++i) cand.push_back(i);
	while (true) {
		int ver = 0;
		int sum = 1e9;
		for (int u : cand) {
			int now = 0;
			for (int v : cand) {
				now += d[u][v];
			}
			if (now < sum) {
				sum = now;
				ver = u;
			}
		}
		cout << ver << '\n'; cout.flush();
		string res; cin >> res;
		if (res == "FOUND") return;
		int nxt; cin >> nxt;
		vector<int> ncand;
		for (int u : cand) {
			if (d[u][ver] > d[u][nxt]) {
				ncand.push_back(u);
			}
		}
		cand.swap(ncand);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			d[i][j] = (i == j ? 0 : n + 5);
		}
	}
	for (int i = 1; i <= m; ++i) {
		int len; cin >> len;
		int v = 0;
		while (len--) {
			int u; cin >> u;
			if (v) d[u][v] = d[v][u] = 1;
			v = u;
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		solve();
	}
}