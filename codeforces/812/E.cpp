#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 100'010;
int n;
int a[maxn];
int p[maxn];
vector<int> g[maxn];
int d[maxn];
int prt;

void dfs(int u, int dist) {
    d[u] = dist;
    for (auto v : g[u]) dfs(v, dist + 1);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        g[p[i]].push_back(i);
    }
    dfs(1, 0);

    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 0) prt = d[i] % 2;
    }

    map<int, int> c;
    vector<int> v;
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        if (d[i] % 2 == prt) {
            v.push_back(a[i]);
            s ^= a[i];
        } else {
            ++c[a[i]];
        }
    }

    int ans = 0;
    for (auto x : v) ans += c[s ^ x];

    if (s == 0) {
        int x = v.size();
        ans += x * (x - 1) / 2;
        x = n - x;
        ans += x * (x - 1) / 2;
    }

    cout << ans << '\n';

    return 0;
}
