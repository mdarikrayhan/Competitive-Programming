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
typedef long long ll;
const int MAXN = 1e5 + 5;
const int lg = 20;
const ll inf = 1e18;
int n, L;
ll S;
int w[MAXN];
vector<int> down[MAXN];
ll sum[MAXN];
int up[MAXN];
int h[MAXN];
int p[MAXN][lg];
int path[MAXN];
inline ll get_sum(int v) {
	return v == -1 ? 0 : sum[v];
}
void preprocess(int v, int pr = -1) {
	sum[v] = get_sum(pr) + w[v];
	p[v][0] = pr;
	h[v] = pr == -1 ? 0 : (1 + h[pr]);
	up[v] = v;
	for (int i = 1; i < lg; i++)
		p[v][i] = p[v][i - 1] == -1 ? -1 : p[p[v][i - 1]][i - 1];
	int dist = L - 1;
	for (int i = lg - 1; i >= 0; i--) {
		if (p[up[v]][i] == -1 || (1<<i) > dist)continue;
		if (get_sum(v) - get_sum(p[up[v]][i]) + w[p[up[v]][i]] <= S) {
			dist -= 1<<i;
			up[v] = p[up[v]][i];
		}
	}
	for (int u : down[v]) {
		preprocess(u, v);
	}
}
int solve(int v) {
	int ans = 0;
	int best = -1;
	for (int u : down[v]) {
		ans += solve(u);
		if (path[u] == u)continue;
		if (best == -1 || h[best] > h[path[u]])
			best = path[u];
	}
	if (best == -1) {
		best = up[v];
		++ans;
	}
	path[v] = best;
	return ans;
}
int main() {
	cin >> n >> L >> S;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		if (w[i] > S) return cout << -1 << endl, 0;
	}
	for (int i = 1; i < n; i++) {
		int j;
		cin >> j;
		down[--j].push_back(i);
	}
	preprocess(0);
	cout << solve(0) ; return 0;
}