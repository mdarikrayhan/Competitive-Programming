#include <bits/stdc++.h>
using namespace std;
int p[2005], s[2005];
int find(int x) {
    if (p[x] == x) {
        return x;
    }
    p[x] = find(p[x]);
    return p[x];
}
void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (s[b] > s[a]) {
        swap(a, b);
    }
    p[b] = a;
    s[a] += s[b];
}
void solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> edges, ch;
    vector<vector<int>> d(n+1, vector<int>(n+1)), dist(n+1, vector<int>(n+1, -1));
    vector<vector<pair<int, int>>> adj(n+1);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        s[i] = 1;
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (d[i][i] != 0) {
            cout << "NO" << endl;
            return;
        }
        for (int j = i+1; j <= n; j++) {
            if (d[i][j] != d[j][i] || d[i][j] <= 0) {
                cout << "NO" << endl;
                return;
            }
            edges.push_back({d[i][j], i, j});
        }
    }
    sort(edges.begin(), edges.end());
    for (auto x : edges) {
        if (find(get<1>(x)) != find(get<2>(x))) {
            adj[get<1>(x)].push_back({get<2>(x), get<0>(x)});
            adj[get<2>(x)].push_back({get<1>(x), get<0>(x)});
            merge(get<1>(x), get<2>(x));
        } else {
            ch.push_back(x);
        }
    }
    for (auto [di, i, j] : ch) {
        if (dist[i][j] == di) {
            continue;
        }
        if (dist[i][j] != -1 && dist[i][j] != di) {
            cout << "NO" << endl;
            return;
        }
        queue<pair<int, int>> q;
        dist[i][i] = 0;
        q.push({i, -1});
        while(!q.empty()) {
            auto [a, p] = q.front();
            q.pop();
            for (auto [b, w] : adj[a]) {
                if (b == p) {
                    continue;
                }
                dist[i][b] = dist[i][a]+w;
                q.push({b, a});
            }
        }
        if (dist[i][j] != di) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while(t--) {
        solve();
    }
}