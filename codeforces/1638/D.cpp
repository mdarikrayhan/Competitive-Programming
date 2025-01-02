#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 1e6 + 5, mod = 998244353, maxp = 25, inf = 1e9;
const ll INF = 1e18;

int a[1005][1005], b[1005][1005];

struct node {
	int x, y, c;
};

int n, m;

queue<pii> q;
vector<node> ans;

void work(int x, int y) {
	if (x == 0 || y == 0) return;
	umap<int, int> mp;
	int c = -1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			int fx = x + i, fy = y + j;
			if (fx > n || fy > m) return;
			if (b[fx][fy]) continue;
			if (c != -1 && c != a[fx][fy]) return;
			c = a[fx][fy];
		}
	}
	if (c == -1) return;
	q.push({x, y});
	ans.push_back({x, y, c});
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			b[x + i][y + j] = 1;
		}
	}
}

void work2(int x, int y, int c) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			b[x + i][y + j] = c;
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			work(i, j);
		}
	}
	while (q.size()) {
		auto [x, y] = q.front();
		q.pop();
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				work(x + i, y + j);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b[i][j] == 0) {
				cout << -1 << endl;
				return;
			}
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (auto [x, y, c] : ans) {
		cout << x << " " << y << " " << c << endl;
		work2(x, y, c);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt = 1;
	// cin >> tt;
	while (tt--) solve();
	return 0;
}