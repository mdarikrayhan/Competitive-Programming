#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
typedef long double     ld;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pll;

#define deb(x)          cout << x
#define X               first
#define Y               second
#define SZ(x)           int(x.size())
#define all(x)          x.begin(), x.end()
#define mins(a,b)       (a = min(a,b))
#define maxs(a,b)       (a = max(a,b))
#define pb              push_back
#define Mp              make_pair
#define kill(x)         {cout << (x) << '\n'; exit(0);}
#define killt(x)        {cout << (x) << '\n'; return;}
#define md(x)           ((((x)%MOD)+MOD)%MOD)
#define lc              id<<1
#define rc              lc|1
#define mid             ((l+r)/2)
mt19937_64              rng(chrono::steady_clock::now().time_since_epoch().count());

const ll  INF = 2e18 + 23;
const ll  MOD = 1e9 + 7;
const int MXN = 3e3 + 23;
const int LOG = 23;

int n, m, w[MXN], sz[MXN];
pll dp[MXN][MXN], DP[MXN];
vector<int> g[MXN];

void dfs(int v, int p=0) {
    sz[v] = 1;
    dp[v][1] = {0, w[v]};
    for(int u : g[v])
        if(u != p) {
            dfs(u, v);
            for(int i=0; i<=sz[v]+sz[u]; i++) DP[i] = {0, -INF};
            for(int i=1; i<=sz[v]; i++)
                for(int j=1; j<=sz[u]; j++) {
                    maxs(DP[i+j], Mp(dp[v][i].X+dp[u][j].X+(dp[u][j].Y>0), dp[v][i].Y));
                    maxs(DP[i+j-1], Mp(dp[v][i].X+dp[u][j].X, dp[v][i].Y+dp[u][j].Y));
                }
            sz[v] += sz[u];
            for(int i=1; i<=sz[v]; i++) dp[v][i] = DP[i];
        }
}

void Main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        g[i].clear();
        cin >> w[i];
        w[i] = -w[i];
    }
    for(int i=1, x; i<=n; i++) {
        cin >> x;
        w[i] += x;
    }
    for(int i=1, u,v; i<n; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    cout << (dp[1][m].X + (dp[1][m].Y>0)) << '\n';
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while(T--) Main();
    return 0;
}