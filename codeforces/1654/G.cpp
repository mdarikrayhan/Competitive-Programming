/*
	闲敲棋子落灯花
*/
#pragma GCC optimize("O3, Ofast")

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define L(i, j, k) for (int i = (j); i <= (k); ++i)
#define R(i, j, k) for (int i = (j); i >= (k); --i)
#define all(x) x.begin(), x.end()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;

	vector<int> is_lodge(N + 1), dis(N + 1, -1), lowest(N + 1);
	vector<vector<int>> G(N + 1), P(N + 1), similar(N + 1);
	queue<int> q;

	L(i, 1, N) cin >> is_lodge[i];
	L(i, 1, N - 1) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	L(i, 1, N) {
		if (is_lodge[i]) {
			dis[i] = 0;
			q.push(i);
		}
	}
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (auto v : G[u]) {
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	vector<int> cost(N + 1);
	const int inf = 1E9;
	auto work = [&](int h) {
		L(i, 1, N) cost[i] = inf;
		for (auto v : similar[h]) {
			q.push(v);
			cost[v] = 0;
		}
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (auto y : G[x]) {
				if (dis[x] != dis[y]) continue;
				if (cost[x] + 1 <= cost[y]) {
					cost[y] = cost[x] + 1;
					q.push(y);
				}
			}
			for (auto y : G[x]) {
				if (dis[x] < dis[y] && cost[x] - 1 <= cost[y]) {
					cost[y] = max(cost[x] - 1, 0);
					q.push(y);
				}
			}
		}
		
		L(x, 1, N) {
			if (cost[x] == 0) {
				lowest[x] = min(lowest[x], h);
			}
		}
	};
	L(i, 1, N) {
		P[dis[i]].push_back(i);
		bool same = false;
		for (auto v : G[i]) {
			if (dis[i] == dis[v]) {
				same = true;
				break;
			}
		}
		if (same) similar[dis[i]].push_back(i);
	}
	L(i, 1, N) lowest[i] = dis[i];
	L(i, 0, N) 
		if (similar[i].size()) 
			work(i);
	L(i, 1, N) cout << 2 * dis[i] - lowest[i] << " \n"[i == N];
}