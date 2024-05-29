// LUOGU_RID: 159906041
#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; ++i)
#define _req(i, x, y) for(int i = x; i >= y; --i)
#define _rev(i, u) for(int i = head[u]; i; i = e[i].nxt)
#define pb push_back
#define fi first
#define se second
#define mst(f, i) memset(f, i, sizeof f)
using namespace std;
#ifdef ONLINE_JUDGE
#define debug(...) 0
#else
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#endif
typedef long long ll;
typedef pair<int, int> PII;
namespace fastio{
    char ibuf[50007],*p1 = ibuf, *p2 = ibuf;
    #ifdef ONLINE_JUDGE
    #define get() p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 50007, stdin), p1 == p2) ? EOF : *p1++
    #else
    #define get() getchar()
    #endif
    template<typename T> inline void read(T &t){
        T x = 0, f = 1;
        char c = getchar();
        while(!isdigit(c)){
            if(c == '-') f = -f;
            c = getchar();
        }
        while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
        t = x * f;
    }
    template<typename T, typename ... Args> inline void read(T &t, Args&... args){
        read(t);
        read(args...);
    }
    template<typename T> void write(T t){
        if(t < 0) putchar('-'), t = -t;
        if(t >= 10) write(t / 10);
        putchar(t % 10 + '0');
    }
    template<typename T, typename ... Args> void write(T t, Args... args){
        write(t), putchar(' '), write(args...);
    }
    template<typename T> void writeln(T t){
        write(t);
        puts("");
    }
    template<typename T> void writes(T t){
        write(t), putchar(' ');
    }
    #undef get
};
using namespace fastio;
#define multitest() int T; read(T); _rep(tCase, 1, T)
namespace Calculation{
    const ll mod = 998244353;
    ll ksm(ll p, ll h){ll base = p % mod, res = 1; while(h){if(h & 1ll) res = res * base % mod; base = base * base % mod, h >>= 1ll;} return res;}
    void dec(ll &x, ll y){x = ((x - y) % mod + mod) % mod;}
    void add(ll &x, ll y){x = (x + y) % mod;}
    void mul(ll &x, ll y){x = x * y % mod;}
    ll sub(ll x, ll y){return ((x - y) % mod + mod) % mod;}
    ll pls(ll x, ll y){return ((x + y) % mod + mod) % mod;}
    ll mult(ll x, ll y){return x * y % mod;}
}
using namespace Calculation;
const int N = 5e5 + 5, M = 1e6 + 5;
int n, rt, id, dfn[N], dep[N], f[N][25];
vector<int> G[N], v[N];
void dfs(int u, int fa){
    dep[u] = dep[fa] + 1, v[dep[u]].pb(u), f[dfn[u] = ++id][0] = fa;
    for(auto &v : G[u]){
        if(v == fa) continue;
        dfs(v, u);
    }
}
int mindfn(int u, int v){return dfn[u] < dfn[v] ? u : v;}
void buildst(){
    _rep(i, 1, 20) _rep(j, 1, n - (1 << i) + 1) f[j][i] = mindfn(f[j][i - 1], f[j + (1 << i - 1)][i - 1]);
}
int lca(int u, int v){
    if(u == v) return u;
    u = dfn[u], v = dfn[v]; if(u > v) swap(u, v); u++;
    int k = __lg(v - u + 1);
    return mindfn(f[u][k], f[v - (1 << k) + 1][k]);
}
ll dp[N];
int len, h[M], sum[N];
bool vis[N];
vector<int> e[N];
void build(int d){
    len = 0;
    sort(v[d].begin(), v[d].end(), [](int x, int y){return dfn[x] < dfn[y];});
    _rep(i, 0, v[d].size() - 2) h[++len] = v[d][i], h[++len] = lca(v[d][i], v[d][i + 1]), vis[v[d][i]] = 1;
    h[++len] = v[d].back(), h[++len] = rt, vis[v[d].back()] = 1;
    sort(h + 1, h + 1 + len, [](int x, int y){return dfn[x] < dfn[y];});
    len = unique(h + 1, h + 1 + len) - h - 1;
    _rep(i, 2, len) e[lca(h[i - 1], h[i])].pb(h[i]);
    // debug("%d -> %d\n", lca(h[i - 1], h[i]), h[i]);
}
void dfs2(int u){
    sum[u] = vis[u];
    for(auto &v : e[u]) dfs2(v), sum[u] += sum[v];
}
void solve(int u, ll cur){
    if(vis[u]) dp[u] += cur;
    for(auto &v : e[u]){
        ll t = sum[u] - sum[v] - vis[u];
        solve(v, cur + t * dep[u]);
    }
}
void dfs3(int u, int fa){
    dp[u] += dep[u] - 1;
    for(auto &v : G[u]){
        if(v == fa) continue;
        dp[v] += dp[u], dfs3(v, u);
    }
}
int main(){
    read(n);
    _rep(i, 1, n){
        int u; read(u);
        if(!u) rt = i;
        else G[u].pb(i);
    }
    dfs(rt, 0), buildst();
    _rep(i, 1, n){
        if(v[i].size() < 2) continue;
        // debug("work %d\n", i);
        build(i);
        dfs2(rt), solve(rt, 0);
        _rep(i, 1, len) e[h[i]].clear(), sum[h[i]] = vis[h[i]] = 0;
        len = 0;
    }
    dfs3(rt, 0);
    _rep(i, 1, n) writes(dp[i]); puts("");
    return 0;
}

