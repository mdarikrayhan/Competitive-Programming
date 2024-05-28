// LUOGU_RID: 159750556
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(tar) tar.begin(),tar.end()
#define pii pair<int,int>
#define AC return 0;
int n, m, t;
const int INF = 0x3f3f3f3f;
const int maxx = 5e3 + 5;
const int mod = 1e9 + 7;
struct data {
	int v;
	int nxt;
	int val, c;
} edge[50000 * 2 + 5];
int alist[maxx];
int cnt = 1, S, T;
int dep[maxx];
inline void add(int u, int v, int val, int c) {
	edge[++cnt].v = v;
	edge[cnt].val = val;
	edge[cnt].c = c;
	edge[cnt].nxt = alist[u];
	alist[u] = cnt;
	return;
}
bool vis[maxx];
bool spfa() {
	memset(dep, 0x3f, sizeof dep);
	memset(vis, 0, sizeof vis);
	dep[S] = 0;
	queue<int>q;
	q.push(S);
	vis[S] = 1;
	while (!q.empty()) {
		int u = q.front();
		vis[u] = 0;
		q.pop();
		int nxt = alist[u];
		while (nxt) {
			int v = edge[nxt].v;
			int val = edge[nxt].val;
			int c = edge[nxt].c;
			if (dep[v] > dep[u] + c && val) {
				dep[v] = dep[u] + c;
				if (!vis[v])q.push(v), vis[v] = 1;
			}
			nxt = edge[nxt].nxt;
		}
	}
	//	cout << dep[T] << " " << INF << '\n';
	return dep[T] != INF;
}
int ans = 0;
int dfs(int u, int lim) {
	if (u == T)return lim;
	int nxt = alist[u];
	vis[u] = 1;
	int f = 0;
	while (nxt) {
		int v = edge[nxt].v;
		int val = edge[nxt].val;
		int c = edge[nxt].c;
		if (!vis[v] && dep[v] == dep[u] + c  && val) {
			int delta = dfs(v, min(lim - f, val));
			f += delta;
			ans += c * delta;
			edge[nxt].val -= delta;
			edge[nxt ^ 1].val += delta;
			if (f == lim) {
				return f;
			}
		}
		nxt = edge[nxt].nxt;
	}
	return f;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a;
	cin >> n >> a >> m;
	a = " " + a;
	S = n + 2, T = S + 1;
	for (int i = 1; i <= m; i++) {
		string s;
		int val;
		cin >> s >> val;
		for (int j = 1; j <= (int)n - (int) s.size() + 1; j++) {
			string q = a.substr(j, s.size());
			if (q == s) {
				add(j, j + s.size(), 1, -val);
				add(j + s.size(), j, 0, val);
			}
		}
	}

	int x;
	cin >> x;
	for (int i = 1; i <= n; i++) {
		add(i, i + 1, x, 0);
		add(i + 1, i, 0, 0);
	}
	add(S, 1, x, 0);
	add(1, S, 0, 0);
	add(n + 1, T, x, 0);
	add(T, n + 1, 0, 0);
	int sum = 0;
	while (spfa()) {
		sum += dfs(S, INF);
	}
	cout << -ans << '\n';
	AC
}