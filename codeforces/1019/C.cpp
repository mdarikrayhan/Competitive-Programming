# include <iostream>
# include <cstdio>
# include <cmath>
# include <algorithm>
# include <cstring>
# include <vector>
# include <map>
# include <climits>
# include <unordered_map>
using namespace std;
const int MAXN = 1e6 + 10;
int f[MAXN], g[MAXN], n,m,ans;
vector<int> v[MAXN],w[MAXN];
void dfs(int x) {
	if (x > n) return ;
	if (f[x]) { dfs(x + 1); return ; }
	for (int y : v[x])
		if (!f[y]) f[y] = x;
	dfs(x + 1);
	for (int y : w[x]) if (g[y]) return ;
	g[x] = 1;
	ans++;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		w[b].push_back(a);
	}
	dfs(1);
	cout << ans << endl ;
	for (int i = 1; i <= n; i++)
		if (g[i]) cout << i << " " ;
	cout << endl ;
	return 0;
}

