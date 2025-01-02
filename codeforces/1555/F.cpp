// LUOGU_RID: 160432259
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
const int N = 5e5 + 5;
int n, q, id, dfn[N], pre[N], fa[N], dis[N], f[N][25], siz[N];
vector<PII> G[N];
int find(int x){return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);}
void merge(int x, int y){int fx = find(x), fy = find(y); if(fx != fy) fa[fx] = fy;}
struct edge{
    int u, v, w;
}e[N];
bool vis[N];
void dfs(int u, int fa){
    pre[u] = fa, dfn[u] = ++id, f[id][0] = fa, siz[u] = 1;
    for(auto &[v, w] : G[u]){
        if(v == fa) continue;
        dis[v] = dis[u] ^ w, dfs(v, u);
        siz[u] += siz[v];
    }
}
int mindfn(int x, int y){return dfn[x] < dfn[y] ? x : y;}
void buildst(){_rep(i, 1, 20) _rep(j, 1, n - (1 << i) + 1) f[j][i] = mindfn(f[j][i - 1], f[j + (1 << i - 1)][i - 1]);}
int lca(int x, int y){
    if(x == y) return x;
    x = dfn[x], y = dfn[y]; if(x > y) swap(x, y); ++x;
    int k = __lg(y - x + 1); return mindfn(f[x][k], f[y - (1 << k) + 1][k]);
}
namespace bit{
    int c[N];
    void modify(int x, int val){for(; x <= n; x += x & -x) c[x] += val;}
    int ask(int x){int res = 0; for(; x; x -= x & -x) res += c[x]; return res;}
}
using namespace bit;
int main(){
	read(n, q);
    _rep(i, 1, n) fa[i] = i;
    _rep(i, 1, q){
        int u, v, w; read(u, v, w);
        int fx = find(u), fy = find(v);
        if(fx != fy){
            // debug("edge (%d,%d,%d)\n", u, v, w);
            fa[fx] = fy, vis[i] = 1;
            G[u].pb({v, w}), G[v].pb({u, w});
        }
        e[i] = {u, v, w};
    }
    _rep(i, 1, n) if(!dfn[i]) dfs(i, 0);
    buildst();
    _rep(i, 1, q){
        int u = e[i].u, v = e[i].v, w = e[i].w;
        int x = lca(u, v);
        // debug("dis:(%d,%d,%d) (%d,%d,%d)\n", u, dis[u], ask(dfn[u]), v, dis[v], ask(dfn[v]));
        if(vis[i] || ask(dfn[u]) == ask(dfn[x]) && ask(dfn[v]) == ask(dfn[x]) && (dis[u] ^ dis[v]) != w){
            puts("YES");
            if(!vis[i]){
                while(u != x) modify(dfn[u], 1), modify(dfn[u] + siz[u], -1), u = pre[u];
                while(v != x) modify(dfn[v], 1), modify(dfn[v] + siz[v], -1), v = pre[v];
            }
        }else{
            puts("NO");
        }
    }
    return 0;
}

