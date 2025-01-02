#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
struct graph {
	vector<vector<int> > edge;
	vector<int> dis;
	vector<pii> E;
	int flag;
	void init(int n) {
		edge.resize(n + 1);
		dis.assign(n + 1, -1);
		flag = 0;
	}
	graph(int n) {
		init(n);
	}
	void addedge(int u, int v) {
		edge[u].emplace_back(v);
		edge[v].emplace_back(u);
		E.push_back({u, v});
	}
	void dfs(int x, int fa) {
		for(auto i : edge[x]) {
			if(i != fa) {
				if(dis[i] == -1) {
					dis[i] = (dis[x] + 1) & 1;
					dfs(i, x);
				} else if(dis[i] == dis[x]) {
					flag = 1;
				}
			}
		}
	}
} ;
void solve() {
	int n, m;
	cin >> n >> m;
	graph G(n);
	while(m--) {
		int u, v;
		cin >> u >> v;
		G.addedge(u, v);
	}
	G.dis[1] = 0;
	G.dfs(1, 0);
	if(G.flag) {
		cout << "NO";
	} else {
		cout << "YES" << '\n';
		for(auto i : G.E) {
			int x = i.first, y = i.second;
			if(G.dis[x] < G.dis[y]) {
				cout << 1;
			} else {
				cout << 0;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}