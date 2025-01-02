#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>; 

constexpr int N = 310;
int n, m, c;
vector<int> adj[N];

struct DSU
{
    int n;
    vector<int> fa,sz;
    DSU(int n): n(n) {
        init(n);
    }
    void init(int n) {
        fa.resize(n + 1), sz.resize(n + 1);
        for (int i = 1; i <= n; i ++)
            fa[i] = i, sz[i] = 1;
    }
    int find(int x) {
        if (fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
    }
    bool same(int u, int v) {
        return find(u) == find(v);
    }
    void merge(int u, int v) {
        int x = find(u);
        int y = find(v);
        if (x == y) return;
        sz[x] = sz[x] + sz[y];
        fa[y] = x;
    }
};


void sol() {
    cin >> n >> m >> c;
    for (int i = 1;i <= n;i ++ ) 
        adj[i].clear();
    int mx = 0;
    vector<pii> edges;
    for (int i = 0;i < m;i ++ ) {
        int x, y;cin >> x >> y, edges.emplace_back(x, y);
    }
    // not add
    DSU dsu(n); 
    for (auto [x, y] : edges) {
        dsu.merge(x, y);
    }

    auto wk = [&](vector<int>& a, int V, int add) {
        int sum = 0;
        for (auto x : a) sum += x;
        vector<bool> dp(sum + 1);

        sum = 0;
        dp[0] = true;
        for (int i = 1;i < a.size();i ++ ) {
            sum += a[i];
            for (int j = sum;j >= 0;j -- ) {
                if (j >= a[i] and dp[j - a[i]]) 
                    dp[j] = true; 
            }
        }

        int ans = 0;
        for (int i = 0;i <= sum;i ++ )
            if (dp[i]) {
                int y = i + add;
                int x = ans + add;
                if (x * x + (n - x) * (n - x) > y * y + (n - y) * (n - y))
                    ans = i;
            }
    
        return (ans + add) * (ans + add) + (n - ans - add) * (n - ans - add);
    };

    int conn = 0;
    vector<int> sz = {0};
    for (int i = 1;i <= n;i ++ ) {
        if (dsu.find(i) == i) {
            sz.push_back(dsu.sz[i]), conn ++;
        }
    }

    int ans = wk(sz, n / 2, 0), bridge = 0;
    for (int i = 0;i < m;i ++ ) {
        DSU dsu(n);
        auto [x, y] = edges[i];
        for (int j = 0;j < m;j ++ ) {
            if (i != j) {
                auto [x, y] = edges[j];
                dsu.merge(x, y);
            }
        }
        sz = {0};int add = 0;
        for (int i = 1;i <= n;i ++ ) {
            if (dsu.find(i) == i) {
                if (!dsu.same(x, i))
                    sz.push_back(dsu.sz[i]);
                else add = dsu.sz[i];
            }
        }

        // check bridge
        if (!dsu.same(x, y)) {
            bridge ++;
            ans = min(ans, wk(sz, n / 2, add));
        }
    }
    if (conn == 1 and bridge == 0)
        cout << -1 << '\n';
    else cout << ans + 1ll * (conn - 1) * c << '\n';
}       

signed main() {
    cin.tie(0) -> sync_with_stdio(0), cout.tie(0);
    int T;cin >> T;
    while (T -- ) {
        sol();
    }
}