#include <bits/stdc++.h>
using namespace std;

int n, k, d;
vector<vector<pair<int, int>>> g;
vector<bool> visited;
set<int> path;
queue<int> q;

void bfs() {
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto x : g[u]) {
            if (!visited[x.first]) {
                visited[x.first] = true;
                path.erase(x.second);
                q.push(x.first);
            }
        }
    }
} 

int main() {
    cin >> n >> k >> d;
    visited.resize(n + 1, false);
    g.resize(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        visited[x] = true;
        q.push(x);
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        path.insert(i);
    }
    bfs();
    cout << path.size() << "\n";
    for (auto x : path) cout << x << " ";
	return 0; 
}