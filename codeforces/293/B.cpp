#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<int> vis(k + 1), cnt(k + 1);
    vector<int> popcount(1 << k + 1);
    for (int i = 1; i < (1 << k); i++)
        popcount[i] = popcount[i / 2] + (i & 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            vis[a[i][j]] = 1;
        }
    vector<vector<int>> sta(n + 1, vector<int>(m + 1));
    auto dfs = [&](auto self, int x, int y) -> ll {
        if (y == m + 1) {
            x = x + 1;
            y = 1;
        }
        if (x == n + 1)
            return 1;
        int s = sta[x - 1][y] | sta[x][y - 1];
        if (n + m - x - y > k - popcount[s])
            return 0;
        ll ans = 0, res = -1;
        for (int i = 1; i <= k; i++) {
            if ((s >> (i - 1)) & 1)
                continue;
            if (a[x][y] == 0 || a[x][y] == i) {
                cnt[i]++;
                sta[x][y] = s | (1 << (i - 1));
                if (cnt[i] == 1 && vis[i] == 0) {
                    if (res == -1)
                        res = self(self, x, y + 1);
                    ans = (ans + res) % mod;
                } else
                    ans = (ans + self(self, x, y + 1)) % mod;
                cnt[i]--;
            }
        }
        return ans;
    };
    ll ans = dfs(dfs, 1, 1);
    cout << ans << "\n";
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