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

const ll  INF = 1e9 + 23;
const ll  MOD = 1e9 + 7;
const int MXN = 1e6 + 23;
const int LOG = 23;

int n, q, mn[MXN], MN=INF;
vector<int> g[MXN];

void dfs(int v, int p=0) {
    mn[v] = p ? min(mn[p], v) : v;
    for(int u : g[v])
        if(u^p)
            dfs(u, v);
}

void Main() {
    cin >> n >> q;
    for(int i=1, u,v; i<n; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int t, x;
    cin >> t >> x; q--;
    MN = x = x%n + 1;
    dfs(x);
    int last=0;
    while(q--) {
        cin >> t >> x;
        x = (x+last)%n + 1;
        if(t == 1) mins(MN, mn[x]);
        if(t == 2) cout << (last=min(MN, mn[x])) << '\n';
    }
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--) Main();
    return 0;
}