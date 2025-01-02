// LUOGU_RID: 160182643
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 1e6 + 5;

class SAM {
	static const int SN = N << 1;
	int tot{}, last{};
	struct Node {
		int fa, len, trans[26];
	} s[SN]{};
	ll siz[SN]{}, vis[SN]{};
	vector<int> e[SN];
public:

	void init() {
		tot = last = 0, s[0].fa = -1;
	}

	void insert(int c) {
		int x = ++tot, p = last;
		s[x].len = s[last].len + 1;
		for (; ~p && !s[p].trans[c]; p = s[p].fa) s[p].trans[c] = x;
		if (p == -1) {
			s[x].fa = 0;
		} else {
			int q = s[p].trans[c];
			if (s[q].len == s[p].len + 1) {
				s[x].fa = q;
			} else {
				int tmp = ++tot;
				s[tmp] = s[q], s[tmp].len = s[p].len + 1;
				for (; ~p && s[p].trans[c] == q; p = s[p].fa) s[p].trans[c] = tmp;
				s[x].fa = s[q].fa = tmp;
			}
		}
		last = x;
	}

	void dfs(int u) {
		for (auto v : e[u]) dfs(v), siz[u] += siz[v];
	}

	void prepare(string &str) {
		for (int i = 1; i <= tot; i++) e[s[i].fa].emplace_back(i);
		int p = 0;
		for (auto i : str) {
			int c = i - 'a';
			p = s[p].trans[c];
			siz[p] = 1;
		}
		dfs(0);
	}

	ll query(string &str, int id) {
		int cur = 0, p = 0;
		for (auto i : str) {
			int c = i - 'a';
			if (!s[p].trans[c]) {
				while (p && !s[p].trans[c]) p = s[p].fa;
				cur = s[p].len;
			}
			if (s[p].trans[c]) {
				p = s[p].trans[c];
				cur++;
			}
		}
		ll res = 0;
		for (auto i : str) {
			int c = i - 'a';
			if (cur == str.length()) {
				if (vis[p] != id) res += siz[p], vis[p] = id;
				cur--;
				if (cur == s[s[p].fa].len) p = s[p].fa;
			}
			if (!s[p].trans[c]) {
				while (p && !s[p].trans[c]) p = s[p].fa;
				cur = s[p].len;
			}
			if (s[p].trans[c]) {
				p = s[p].trans[c];
				cur++;
			}
		}
		return res;
	}
} sam;

signed main() {

#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	string str;
	cin >> str;

	sam.init();
	for (auto i : str) sam.insert(i - 'a');
	sam.prepare(str);

	int m, idx = 0;
	cin >> m;
	while (m--) {
		cin >> str;
		cout << sam.query(str, ++idx) << "\n";
	}

	return 0;
}