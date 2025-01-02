// LUOGU_RID: 159595473
#include <bits/stdc++.h>
#define REP(i, l, r) for (int i = (l); i <= (r); ++ i)
#define DEP(i, r, l) for (int i = (r); i >= (l); -- i)
#define fi first
#define se second
#define pb emplace_back
#define mems(x, v) memset((x), (v), sizeof(x))
using namespace std;
namespace Milkcat {
	typedef long long LL;
	typedef pair<LL, LL> pii;
	const int N = 1e6 + 5;
	int n, u, v, rt, rs, d[N];
	vector<int> s, G[N];
	void dfs1(int u, int fa) {
		for (int v : G[u])
			if (v != fa) d[v] = d[u] + 1, dfs1(v, u);
	}
	int dfs2(int u, int fa) {
		vector<int> t;
		for (int v : G[u])
			if (v != fa) t.pb(dfs2(v, u) + 1);
		sort(t.begin(), t.end(), greater<int>());
		for (int i = 1; i < t.size(); i ++) s.pb(t[i]);
		return (t.size() ? t[0] : 0);
	}
	int main() {
		cin >> n;
		REP(i, 2, n) cin >> u >> v, G[u].pb(v), G[v].pb(u);
		dfs1(1, 0);
		REP(i, 1, n)
			if (d[i] > d[rt]) rt = i;
		s.pb(dfs2(rt, 0)), rs = 1;
		sort(s.begin(), s.end(), greater<int>());
		REP(i, 1, n) {
			if (i > 1 && i - 2 < s.size()) rs += s[i - 2];
			cout << rs << ' ';
		}
		cout << '\n';
		return 0;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	while (T --) Milkcat::main();
	return 0;
}
