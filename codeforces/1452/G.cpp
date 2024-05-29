// LUOGU_RID: 160392568
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
const int N = 2e5 + 5, inf = 0x3f3f3f3f;
int n, k, a[N], f[N], dp[N][2];
bool key[N];
vector<int> G[N];
void dfs1(int u, int fa){
    dp[u][0] = dp[u][1] = inf;
    if(key[u]) dp[u][0] = 0;
    for(auto &v : G[u]){
        if(v == fa) continue;
        dfs1(v, u); int cur = dp[v][0] + 1;
        if(cur < dp[u][0]) dp[u][1] = dp[u][0], dp[u][0] = cur;
        else if(cur < dp[u][1]) dp[u][1] = cur;
    }
}
void dfs2(int u, int fa, int t){
    f[u] = min(dp[u][0], t);
    for(auto &v : G[u]){
        if(v == fa) continue;
        int nc = min(t + 1, ((dp[u][0] == dp[v][0] + 1) ? dp[u][1] : dp[u][0]) + 1);
        dfs2(v, u, nc);
    }
}
int rt, tot, maxn[N], siz[N];
bool vis[N];
void findrt(int u, int fa){
    siz[u] = 1, maxn[u] = 0;
    for(auto &v : G[u]){
        if(v == fa || vis[v]) continue;
        findrt(v, u), siz[u] += siz[v];
        maxn[u] = max(maxn[u], siz[v]);
    }
    maxn[u] = max(maxn[u], tot - siz[u]);
    if(maxn[u] < maxn[rt]) rt = u;
}
int cnt, c[N], dis[N], suf[N], ans[N];
void dfs(int u, int fa){
    c[++cnt] = u;
    for(auto &v : G[u]) if(v != fa && !vis[v]) dis[v] = dis[u] + 1, dfs(v, u);
}
void solve(int u){
    int lst = siz[u], sum = tot;
    siz[u] = tot, vis[u] = 1;
    dfs(u, 0);
    _rep(i, 1, cnt){
        if(f[c[i]] - dis[c[i]] > 0){
            int cur = f[c[i]] - dis[c[i]] - 1;
            cur = min(cur, cnt);
            suf[cur] = max(suf[cur], f[c[i]]);
        }
    }
    _req(i, cnt - 1, 0) suf[i] = max(suf[i], suf[i + 1]);
    _rep(i, 1, cnt) ans[c[i]] = max(ans[c[i]], suf[dis[c[i]]]);
    _rep(i, 0, cnt) dis[c[i]] = suf[i] = 0;
    cnt = 0;
    for(auto &v : G[u]){
        if(vis[v]) continue;
        tot = (siz[v] > lst) ? sum - lst : siz[v];
        maxn[rt = 0] = 2e9, findrt(v, u);
        solve(rt);
    }
}
int main(){
	read(n);
    _rep(i, 2, n){
        int u, v; read(u, v);
        G[u].pb(v), G[v].pb(u);
    }
    read(k);
    _rep(i, 1, k) read(a[i]), key[a[i]] = 1;
    dfs1(1, 0), dfs2(1, 0, inf);
    _rep(i, 1, n) debug("%d ", f[i]); debug("\n");
    tot = n, maxn[rt = 0] = 2e9, findrt(1, 0);
    solve(rt);
    _rep(i, 1, n) writes(ans[i]); puts("");
    return 0;
}

