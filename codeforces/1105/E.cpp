// LUOGU_RID: 160452206
#include <bits/stdc++.h>
#define int long long
using namespace std;
int bit(int S, int i) { return S >> i & 1; }
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, n;
	cin >> N >> n;
	map<string, int> id;
	int cur = 0;
	vector<set<int>> se(n);
	for (int i = 1, tot = 0; i <= N; i++) {
		int op;
		cin >> op;
		if (op == 1) {
			tot++;
		} else {
			string str;
			cin >> str;
			if (!id.count(str)) {
				id[str] = cur++;
			}
			se[id[str]].insert(tot);
		}
	}
	vector<int> e(n);
	int m = n / 2;
	vector<int> eo(n);
	auto add = [&](int u, int v) {
		if (u > v) swap(u, v);
		e[u] |= 1ll << v;
		e[v] |= 1ll << u;
		if (u < m && v >= m) {
			eo[v] |= 1ll << u;
		}
	};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				add(i, j);
			} else {
				bool ok = 1;
				for (int x : se[i]) {
					ok &= !se[j].count(x);
				}
				if (ok) add(i, j);
			}
		}
	}
	vector<int> f(1 << m, -1e9);
	for (int S = 0; S < (1 << m); S++) {
		bool ok = 1;
		for (int i = 0; i < m; i++) {
			if (!bit(S, i)) continue;
			if ((e[i] & S) != S) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			f[S] = __builtin_popcountll(S);
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < (1 << m); i++) {
			if (bit(i, j)) {
				f[i] = max(f[i], f[i ^ (1 << j)]);
			}
		}
	}
	int ans = 0;
	for (int S = 0; S < (1 << (n - m)); S++) {
		bool ok = 1;
		for (int i = m; i < n; i++) {
			if (!bit(S, i - m)) continue;
			if ((e[i] & (S << m)) != (S << m)) {
				ok = 0;
				break;
			}
		}
		if (!ok) continue;
		int T = (1 << m) - 1;
		for (int i = m; i < n; i++) {
			if (!bit(S, i - m)) continue;
			T &= eo[i];
		}
		ans = max<int>(ans, __builtin_popcountll(S) + f[T]);
	}
	cout << ans << "\n";
	return 0;
}