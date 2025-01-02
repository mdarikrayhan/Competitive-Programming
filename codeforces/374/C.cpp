// LUOGU_RID: 159879966
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1E3 + 5;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
int n, m;
vector<int> adj[N * N];
int d[N * N];
bitset<N * N> inq;
inline int flatten(int x, int y) {
	return x * 1000 + y;
}
inline void link(int u, int v) {
	adj[u].emplace_back(v);
}
char grid[N][N];
bool bad;
void dfs(int u) {
	if (d[u]) return;
	inq[u] = true;
	d[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int &v = adj[u][i];
		if (inq[v]) {
			bad = true;
			inq[u] = false;
			return;
		}
		dfs(v);
		if (bad) {
			inq[u] = false;
			return;
		}
		d[u] = max(d[u], d[v] + 1);
	}
	inq[u] = false;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
				if (grid[i][j] == 'D' && grid[nx][ny] == 'I'
					|| grid[i][j] == 'I' && grid[nx][ny] == 'M'
					|| grid[i][j] == 'M' && grid[nx][ny] == 'A'
					|| grid[i][j] == 'A' && grid[nx][ny] == 'D') {
					link(flatten(i, j), flatten(nx, ny));
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (grid[i][j] == 'D') {
				dfs(flatten(i, j));
				if (bad) {
					cout << "Poor Inna!\n";
					return 0;
				}
				ans = max(ans, d[flatten(i, j)]);
			}
		}
	}
	ans /= 4;
	if (!ans) cout << "Poor Dima!\n";
	else cout << ans << '\n';
	return 0;
}