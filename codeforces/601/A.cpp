#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()


class Shadow {
public:
    static void Files() {
#ifndef ONLINE_JUDGE
        freopen("../INPUT.txt", "r", stdin);
        freopen("../OUTPUT.txt", "w", stdout);
        freopen("../BacKDooR.txt", "w", stderr);
#endif
    }

    static void Fast() {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    }
};


//-----------------------------------------------------`|||`-----------------------------------------------------\\
\\-----------------------------------------------------`\|/`-----------------------------------------------------//
const int N = 4e2 + 3, F = 1e6 + 3, mod = 998244353, inf = 1e8;
int n, m;
bool mat[N][N], vis[N];

int dfs(int node, int parent, int time, vector<vector<int>> &adj, vector<int> &dist, set<int> &path) {
    if (node == n) return 0;
    vis[node] = true;
    if (node != 1 && path.count(node) && dist[node] == time) return inf;

    int ans = inf;
    for (const auto &u: adj[node]) {
        if (vis[u]) continue;
        ans = min(ans, 1 + dfs(u, node, time + 1, adj, dist, path));
    }
    return ans;
}

set<int> bfs(vector<vector<int>> &adj, vector<int> &dist) {
    vector<int> p(n + 1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const auto &v: adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                p[v] = u;
            }
        }
    }
    int c = n;
    set<int> path;
    while (c != -1) {
        c = p[c];
        if (~c)
            path.insert(c);
    }
    return path;
}

void solve() {
    cin >> n >> m;
    vector<vector<int>> railway(n + 1), roads(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        mat[a][b] = mat[b][a] = true;
        railway[a].push_back(b);
        railway[b].push_back(a);
    }
    if (m == (n * n - n) / 2) return void(cout << "-1\n");
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j || mat[i][j]) continue;
            mat[i][j] = mat[j][i] = true;
            roads[i].push_back(j);
            roads[j].push_back(i);
        }
    }
    int ans = inf;
    vector<int> dist(n + 1, inf);
    auto path = bfs(roads, dist);
    if (!path.empty()) {
        int mn = dfs(1, -1, 0, railway, dist, path);
        ans = min(ans, max(mn, (int) path.size()));
    }

    dist.assign(n + 1, inf);
    path = bfs(railway, dist);
    if (!path.empty()) {
        int mn = dfs(1, -1, 0, roads, dist, path);
        ans = min(ans, max(mn, (int) path.size()));
    }
    if (ans >= inf) cout << "-1\n";
    else cout << ans << '\n';
}


int main() {
    Shadow::Fast();
    Shadow::Files();
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}