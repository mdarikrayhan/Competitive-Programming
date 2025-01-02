#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
bool be;
constexpr int N = 5e5 + 5, L = 1e6 + 5, T = 5e6 + 5;
int n, m, f[T], g[T];
string t, s[N];
ll sf[T];
vector<int>C[N];
struct AC {
	int ch[L][26], tot, fail[L], cnt[L], ed[L];
	vector<int>e[L];
	void insert(int id)
	{
		int u = 0;
		for (char c : s[id]) {
			int &v = ch[u][c - 'a'];
			if (!v) v = ++tot;
			u = v;
		}
		++cnt[u];
		ed[u] = id;
	}
	void build()
	{
		queue<int>q;
		for (int i = 0; i < 26; ++i) {
			if (ch[0][i]) {
				q.emplace(ch[0][i]);
				e[0].emplace_back(ch[0][i]);
			}
		}
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int i = 0; i < 26; ++i) {
				if (ch[u][i]) {
					fail[ch[u][i]] = ch[fail[u]][i];
					e[fail[ch[u][i]]].emplace_back(ch[u][i]);
					q.emplace(ch[u][i]);
				} else {
					ch[u][i] = ch[fail[u]][i];
				}
			}
		}
	}
	void dfs(int u)
	{
		for (int v : e[u]) {
			if (!ed[v]) ed[v] = ed[u];
			cnt[v] += cnt[u];
			dfs(v);
		}
	}
}t1, t2;
struct Seg {
	#define ls k << 1
	#define rs k << 1 | 1
	#define push_up(k) mn[k] = min(mn[ls], mn[rs])
	int mn[T << 2];
	void build(int k = 1, int l = 1, int r = t.size())
	{
		if (l == r) {
			mn[k] = l - s[g[l]].size() + 1;
			return;
		}
		int mid = l + r >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
		push_up(k);
	}
	int query(int L, int R, int x, int k = 1, int l = 1, int r = t.size())
	{
		if (mn[k] >= x) return -1;
		if (l == r) return l;
		int mid = l + r >> 1;
		if (R > mid) {
			int t = query(L, R, x, rs, mid + 1, r);
			if (t != -1) return t;
		}
		if (L <= mid) return query(L, R, x, ls, l, mid);
		return -1;
	}
}tr;
void getfg()
{
	int u = 0;
	for (int i = 1; i <= t.size(); ++i) {
		u = t1.ch[u][t[i - 1] - 'a'];
		f[i] = t1.cnt[u];
		sf[i] = sf[i - 1] + f[i];
		g[i] = t1.ed[u];
	}
}
void getc(int id)
{
	int u = 0, tot = 0;
	for (char c : s[id]) {
		u = t2.ch[u][c - 'a'];
		tot += t2.cnt[u];
		C[id].emplace_back(tot);
	}
}
bool en;
int main() {
	cerr << (&be - &en) / 1024.0 / 1024 << " MB\n--------------------------------" << endl;
#ifdef IAKIOI
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> t;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		t1.insert(i);
		reverse(all(s[i]));
		t2.insert(i);
	}
	t1.build(), t2.build();
	t1.dfs(0);
	getfg();
	tr.build();
	t2.dfs(0);
	for (int i = 1; i <= n; ++i) {
		getc(i);
	}
	while (m--) {
		int l, r;
		cin >> l >> r;
		int q = tr.query(l, r, l);
		if (q == -1) {
			cout << sf[r] - sf[l - 1] << ' ';
		} else {
			cout << sf[r] - sf[q] + C[g[q]][q - l] << ' ';
		}
	}
	return 0;
}
   	 					      	  	  	 			 			