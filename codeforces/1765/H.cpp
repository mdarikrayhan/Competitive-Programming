#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 25;
int p[MAXN], n, m;
vector <int> adj[MAXN];
int deg[MAXN], c[MAXN];
void solve () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		adj[b].push_back(a);
		deg[a]++;
	}
	for (int z = 1; z <= n; z++) {
		for (int i = 1; i <= n; i++) {
			c[i] = deg[i];
		}
		deque <int> e; set <pair <int, int>> dd;
		for (int i = 1; i <= n; i++) {
			if (c[i] == 0) {
				if (p[i] == n) {
					e.push_back(i);
				} else {
					dd.insert({p[i], i});
				}
			}
		}
		for (int y = n; y >= 1; y--) {
			while (!dd.empty() && (*(--dd.end())).first >= y) {
				e.push_back((*(--dd.end())).second);
				dd.erase(--dd.end());
			}
			int x = e.back();
			if (e.size() == 1 && x == z) {
				cout << y << " ";
				break;
			}
			if (x == z) {
				x = e.front();
				e.pop_front();
			} else {
				e.pop_back();
			}
			for (auto i : adj[x]) {
				c[i]--;
				if (c[i] == 0) {
					if (p[i] >= y) {
						e.push_back(i);
					} else {
						dd.insert({p[i], i});
					}
				}
			}
		}
	}
}
signed main () {
	 #ifndef ONLINE_JUDGE 
		freopen("input_file", "r", stdin);
		freopen("output_file", "w", stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; //cin >> tc;
	while (tc--) solve();
}