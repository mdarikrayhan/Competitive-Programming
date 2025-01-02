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
const int MXN = 5e5 + 23;
const int LOG = 21;

int n, par[LOG][MXN];
vector<int> g[MXN];

int h[MXN], stt[MXN], fnt[MXN], timer;
void dfs(int v) {
    stt[v] = ++timer;
    for(int u : g[v]) h[u]=h[v]+1, dfs(u);
    fnt[v] = timer;
}

bool is_anc(int u, int v) {
    return stt[u] <= stt[v] && fnt[v] <= fnt[u];
}

int jump(int v, int d) {
    for(int i=0; i<LOG; i++)
        if(d>>i & 1)
            v = par[i][v];
    return v;
}

int fen[MXN];

void Upd(int p, int x) {
    for(p+=5; p<MXN; p+=p&-p) fen[p]+=x;
}

int sz(int v) {
    int p=fnt[v], res=0;
    for(p+=5; p; p-=p&-p) res += fen[p];
    for(p=stt[v]+4; p; p-=p&-p) res -= fen[p];
    return res;
}

void clear() {
    for(int i=1; i<=n; i++) g[i].clear(), Upd(stt[i], -1);
    timer=0;
}

void Main() {
    cin >> n;
    for(int i=2; i<=n; i++) cin >> par[0][i], g[par[0][i]].pb(i);
    for(int i=1; i<LOG; i++)
        for(int v=1; v<=n; v++)
            par[i][v] = par[i-1][par[i-1][v]];
    dfs(1);
    Upd(stt[1], 1);
    int cent=1, mx=0;
    for(int v=2; v<=n; v++) {
        Upd(stt[v], 1);
        if(is_anc(cent, v)) {
            int u = jump(v, h[v]-h[cent]-1);
            maxs(mx, sz(u));
            if(mx*2 > v) cent=u, mx=v-mx;
        }
        else {
            maxs(mx, v-sz(cent));
            if(mx*2 > v) cent=par[0][cent], mx=v-mx;
        }
        cout << v-2*mx << ' ';
    }
    cout << '\n';
    clear();
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while(T--) Main();
    return 0;
}