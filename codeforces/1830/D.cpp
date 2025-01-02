#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define endl '\n'
#define debug(x) cout << __FUNCTION__ << ": " << #x " = " << (x) << endl
using ll = long long;

const int maxn = 2e5 + 10;
const int maxm = 4 * maxn;
const ll INF = 3e18;
const ll mod = 1e9 + 7;
int n, m, k;
int block = 500;
vector<int> g[maxn], dp[maxn][2];
int siz[maxn], tmp[maxn];

void dfs(int u, int fa) {
    vector<int>(2).swap(dp[u][0]);
    vector<int>(2).swap(dp[u][1]);
    siz[u] = 1;
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        for (int x = 0; x <= 1; x++) {
            dp[u][x].resize(min(block, siz[u] + siz[v]) + 1);
            for (int i = 1; i <= min(block, siz[u] + siz[v]); i++) {
                tmp[i] = dp[u][x][i];
                dp[u][x][i] = 2e9;
            }
            for (int y = 0; y <= 1; y++) {
                for (int i = 1; i <= min(block, siz[u]); i++) {
                    for (int j = 1; j <= min(block, siz[v]); j++) {
                        if (x ^ y) dp[u][x][i] = min(dp[u][x][i], tmp[i] + dp[v][y][j] + j * (j + 1) / 2 * (y ? 2 : 1));
                        else if (i + j <= block) dp[u][x][i + j] = min(dp[u][x][i + j], tmp[i] + dp[v][y][j]);
                    }
                }
            }
        }
        siz[u] += siz[v];
        //dp[v][0].clear(), dp[v][1].clear();
        vector<int>().swap(dp[v][0]), vector<int>().swap(dp[v][1]);
    }
}

void kkkyyyhhh() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        vector<int>().swap(g[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    ll ans = INF;
    for (int i = 1; i <= min(siz[1], block); i++) {
        for (int j = 0; j <= 1; j++) {
            ans = min(ans, 1ll * dp[1][j][i] + i * (i + 1) / 2 * (j ? 2 : 1));
        }
    }
    cout << 1ll * n * (n + 1) - ans << endl;
}     

signed main() {
    IOS;
    int w_ = 1;
    cin >> w_;
    while (w_--) kkkyyyhhh();
    return 0;
} 