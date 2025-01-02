#include <algorithm>
#include <array>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> in(k + 1), vis(k + 1);
    vector<vector<int>> son(k + 1);
    for (int i = 1; i <= n; i++) {
        int c, x, pre;
        cin >> c >> pre;
        for (int j = 2; j <= c; j++) {
            cin >> x;
            son[pre].push_back(x);
            if (!in[x])
                in[x] = pre;
            else if (in[x] != pre)
                in[x] = -1;
            pre = x;
        }
    }
    auto dfs = [&](auto self, int x, int fa) -> int {
        sort(son[x].begin(), son[x].end());
        son[x].erase(unique(son[x].begin(), son[x].end()), son[x].end());
        if (son[x].size() > 1)
            return -1;
        vis[x] = 1;
        int siz = 0;
        for (auto y : son[x]) {
            if (vis[y] || in[y] != x)
                return -1;
            siz = self(self, y, x);
        }
        if (siz == -1)
            return -1;
        return siz + 1;
    };
    vector<int> cnt(k + 1);
    for (int i = 1; i <= k; i++)
        if (in[i] == 0) {
            int siz = dfs(dfs, i, 0);
            if (siz == -1)
                continue;
            cnt[siz]++;
        }
    vector<array<int, 2>> len;
    for (int i = 1; i <= k; i++)
        if (cnt[i])
            len.push_back({i, cnt[i]});
    vector<ll> dp(m + 1);
    dp[0] = 1;
    for (int i = 0; i <= m; i++)
        for (auto [x, y] : len) {
            if (i + x > m)
                continue;
            dp[i + x] = (dp[i + x] + dp[i] * y % mod) % mod;
        }
    cout << dp[m] << "\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}