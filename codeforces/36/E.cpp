#include <bits/stdc++.h>
#define y1 yy1
#define int long long
using namespace std;
int n, m, x, y, w, i, j, sum, cnt, deg[100001], BAN[100001], col[100001];
bool u[100001], ex[100001];
pair<int, int> a[100001];
multiset<pair<int, int>> g[100001];
vector<int> ans1, ans2;
stack<pair<int, int>> st;
vector<int> gg[100001];
map<pair<int, int>, int> mp;

void dfs(int x, int i, bool c2) {
	//cout << "!!!" << x << " " << i << "\n";
	if (!ex[x]) return;
	for (auto y : g[x]) {
		if (BAN[y.second]) continue;
		BAN[y.second] = 1;
		dfs(y.first, y.second, c2);
	}
	if (c2 && i) ans2.push_back(i);
	else if (i) ans1.push_back(i);
}

void dfscomp(int x) {
	if (!ex[x]) return;
	u[x] = 1;
	gg[cnt].push_back(x);
	col[x] = cnt;
	for (auto y : g[x]) {
		if (!u[y.first]) dfscomp(y.first);
	}
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	#ifndef LOCAL
	freopen("output.txt", "w", stdout);
	#endif
	cin >> m;
	for (i = 1; i <= m; i++) {
		cin >> x >> y;
		mp[{x, y}] = mp[{y, x}] = 1;
		g[x].insert({y, i});
		g[y].insert({x, i});
		n = max({n, x, y});
		deg[x]++;
		deg[y]++;
		ex[x] = ex[y] = 1;
	}
	for (i = 1; i <= n; i++) {
		if (!u[i] && ex[i]) {
			cnt++;
			dfscomp(i);
		}
	}
	if (cnt > 2) {
		cout << -1;
		return 0;
	}
	if (cnt == 2) {
		int degg1 = 0, degg2 = 0;
		for (auto i : gg[1]) if (deg[i] % 2 && ex[i]) degg1++;
		for (auto i : gg[2]) if (deg[i] % 2 && ex[i]) degg2++;
		if (degg1 % 2 == 0 && degg2 % 2 == 0 && max(degg1, degg2) <= 2) {
			for (i = 1; i <= n; i++) u[i] = 0;
			bool cyc1 = 1, cyc2 = 1;
			for (i = 1; i <= n; i++) {
				if (col[i] == 1 && deg[i] % 2 && ex[i]) {
					dfs(i, 0, 0);
					cyc1 = 0;
					break;
				}
			}
			if (cyc1) dfs(gg[1].back(), 0, 0);
			for (i = 1; i <= n; i++) {
				if (col[i] == 2 && deg[i] % 2 && ex[i]) {
					dfs(i, 0, 1);
					cyc2 = 0;
					break;
				}
			}
			if (cyc2) dfs(gg[2].back(), 0, 1);
			cout << ans1.size() << "\n";
			for (int i : ans1) cout << i << " ";
			cout << "\n" << ans2.size() << "\n";
			for (int i : ans2) cout << i << " ";
		}
		else cout << -1;
		return 0;
	}
	if (cnt == 1) {
		vector<int> v;
		for (i = 1; i <= n; i++) {
			if (deg[i] % 2 && ex[i]) {
				v.push_back(i);
			}
		}
		if (v.size() % 2 || v.size() > 4) {
			cout << -1;
			return 0;
		}
		for (i = 1; i <= n; i++) u[i] = 0;
		if (!v.size()) {
			dfs(gg[1].back(), 0, 0);
			if (ans1.size() < 2) {
				cout << -1;
				return 0;
			}
			ans2.push_back(ans1.back());
			ans1.pop_back();
			cout << ans1.size() << "\n";
			for (int i : ans1) cout << i << " ";
			cout << "\n" << ans2.size() << "\n";
			for (int i : ans2) cout << i << " ";
			return 0;
		}
		if (v.size() == 2) {
			for (i = 1; i <= n; i++) {
				if (deg[i] % 2 && ex[i]) {
					dfs(i, 0, 0);
					break;
				}
			}
			if (ans1.size() < 2) {
				cout << -1;
				return 0;
			}
			ans2.push_back(ans1.back());
			ans1.pop_back();
			cout << ans1.size() << "\n";
			for (int i : ans1) cout << i << " ";
			cout << "\n" << ans2.size() << "\n";
			for (int i : ans2) cout << i << " ";
			return 0;
		}
		if (v.size() == 4) {
			int st = -1;
			for (int i = 0; i < 4; i++) {
				for (int j = i + 1; j < 4; j++) {
					if (!mp.count({v[i], v[j]})) {
						g[v[i]].insert({v[j], 2 * m});
						g[v[j]].insert({v[i], 2 * m});
						st = 0;
						while (st == i || st == j) st++;
						//cout << st << " " << i << " " << j << "\n";
						break;
					}
				}
				if (st > -1) break;
			}
			dfs(v[st], 0, 0);
			if (ans1.size() < 3) {
				cout << -1;
				return 0;
			}
			int pos01 = -1;
			for (i = 0; i < ans1.size(); i++) {
				if (ans1[i] == 2 * m) pos01 = i;
			}
			vector<int> anss1 = ans1;
			ans1.clear();
			for (i = pos01 + 1; i < anss1.size(); i++) ans1.push_back(anss1[i]);
			for (i = 0; i < pos01; i++) ans2.push_back(anss1[i]);
			cout << ans1.size() << "\n";
			for (int i : ans1) cout << i << " ";
			cout << "\n" << ans2.size() << "\n";
			for (int i : ans2) cout << i << " ";
			return 0;
		}
	}
}