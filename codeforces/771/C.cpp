// LUOGU_RID: 160208652
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 3e5 + 10, K = 11;

int n, k;
vector<int> e[N];
ll f[N][K], g[N][K], x[K], y[K];
ll ans = 0;
// f[i][j] number of ways
// g[i][j] sum of ways

void dfs(int now, int fa) {
    f[now][0] = 1;
    for (int i : e[now]) {
        if (i == fa) continue;
        dfs(i, now);
        for (int j = 0; j < k; j++) x[(j + 1) % k] = f[i][j];
        for (int j = 0; j < k; j++) y[(j + 1) % k] = g[i][j] + (j == 0) * f[i][j];

        for (int a = 0; a < k; a++) {
            for (int b = 0; b < k; b++) {
                ans = (ans + f[now][a] * y[b] + g[now][a] * x[b] - (a && b && a + b <= k) * f[now][a] * x[b]);
            }
        }
        for (int j = 0; j < k; j++) f[now][j] += x[j];
        for (int j = 0; j < k; j++) g[now][j] += y[j];
    }
    // cout << ans << '\n';
}

int main() {

    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}