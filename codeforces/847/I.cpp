#include<bits/stdc++.h>
typedef long long ll;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
const int maxn = 255;
int n, m;
ll p, qq;
int a[maxn][maxn], num[maxn][maxn];
ll res[maxn][maxn];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
struct info {
	int x, y;
	ll v;
};
void solve() {
	std::cin >> n >> m >> qq >> p;
	for (int i = 1; i <= n; i++) {
		std::string s;
		std::cin >> s;
		for (int j = 1; j <= m; j++) {
			if (s[j - 1] == '.')
				continue;
			if (s[j - 1] == '*')
				a[i][j] = -1;
			else {
				a[i][j] = s[j - 1] - 'A' + 1;
			}
		}
	}
	int dfn = 0;
	auto bfs = [&](int x, int y, ll val) {
		std::queue<info>q;
		q.push(info{x, y, val});
		num[x][y] = dfn;
		while (!q.empty()) {
			auto [i, j, v] = q.front();
			q.pop();
			res[i][j] += v;
			ll nxt = v / 2LL;
			if (nxt == 0LL)continue;
			for (int k = 0; k < 4; k++) {
				int ni = i + dx[k], nj = j + dy[k];
				if (ni < 1 or ni > n or nj < 1 or nj > m or a[ni][nj] == -1 or num[ni][nj] == dfn)continue;
				q.push({ni, nj, nxt});
				num[ni][nj] = dfn;
			}
		}
	};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] > 0) {
				dfn++;
				bfs(i, j, a[i][j] * qq);
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (res[i][j] > p) {
				ans++;
			}
		}
	}
	std::cout << ans << "\n";
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int t = 1;
	while (t--)solve();
	return 0;
}