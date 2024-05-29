// LUOGU_RID: 159859252
#include <bits/stdc++.h>
#define int long long
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
typedef pair<int, ll> PII;
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
    const ll mod = 1e9 + 7;
    ll ksm(ll p, ll h){ll base = p % mod, res = 1; while(h){if(h & 1ll) res = res * base % mod; base = base * base % mod, h >>= 1ll;} return res;}
    void dec(ll &x, ll y){x = ((x - y) % mod + mod) % mod;}
    void add(ll &x, ll y){x = (x + y) % mod;}
    void mul(ll &x, ll y){x = x * y % mod;}
    ll sub(ll x, ll y){return ((x - y) % mod + mod) % mod;}
    ll pls(ll x, ll y){return ((x + y) % mod + mod) % mod;}
    ll mult(ll x, ll y){return x * y % mod;}
}
using namespace Calculation;
const int N = 2e5 + 5;
int n, q, id, dfn[N], siz[N];
vector<PII> G[N];
vector<PII> Q[N];
ll ans[N];
namespace sgt{
    ll s2[N << 2], s[N << 2], tag[N << 2];
    #define ls x << 1
    #define rs x << 1 | 1
    void pushtag(int x, int l, int r, ll val){
        ll len = r - l + 1;
        add(s2[x], len * val % mod * val % mod + s[x] * val % mod * 2ll % mod);
        add(s[x], val * len % mod);
        add(tag[x], val);
    }
    void pushdown(int x, int l, int r){
        if(!tag[x]) return;
        int mid = l + r >> 1;
        pushtag(ls, l, mid, tag[x]), pushtag(rs, mid + 1, r, tag[x]);
        tag[x] = 0;
    }
    void update(int x){
        s2[x] = pls(s2[ls], s2[rs]);
        s[x] = pls(s[ls], s[rs]);
    }
    void modify(int x, int l, int r, int L, int R, ll val){
        if(l >= L && r <= R) return pushtag(x, l, r, val);
        int mid = l + r >> 1;
        pushdown(x, l, r);
        if(L <= mid) modify(ls, l, mid, L, R, val);
        if(R > mid) modify(rs, mid + 1, r, L, R, val);
        update(x);
    }
    ll query(int x, int l, int r, int L, int R){
        if(l >= L && r <= R) return s2[x];
        int mid = l + r >> 1; ll res = 0;
        pushdown(x, l, r);
        if(L <= mid) add(res, query(ls, l, mid, L, R));
        if(R > mid) add(res, query(rs, mid + 1, r, L, R));
        return res;
    }
}
using namespace sgt;
ll dis[N];
void dfs(int u, int fa){
    dfn[u] = ++id, siz[u] = 1;
    modify(1, 1, n, dfn[u], dfn[u], dis[u]);
    for(auto &[v, w] : G[u]){
        if(v == fa) continue;
        dis[v] = pls(dis[u], w);
        dfs(v, u), siz[u] += siz[v];
    }
}
void solve(int u, int fa){
    for(auto &[v, id] : Q[u]){
        int l = dfn[v], r = dfn[v] + siz[v] - 1;
        ll cur = query(1, 1, n, l, r);
        if(l > 1) dec(cur, query(1, 1, n, 1, l - 1));
        if(r < n) dec(cur, query(1, 1, n, r + 1, n));
        ans[id] = cur;
    }
    for(auto &[v, w] : G[u]){
        if(v == fa) continue;
        int l = dfn[v], r = dfn[v] + siz[v] - 1;
        if(l > 1) modify(1, 1, n, 1, l - 1, w);
        if(r < n) modify(1, 1, n, r + 1, n, w);
        modify(1, 1, n, l, r, mod - w); 
        solve(v, u);
        modify(1, 1, n, l, r, w);
        if(l > 1) modify(1, 1, n, 1, l - 1, mod - w);
        if(r < n) modify(1, 1, n, r + 1, n, mod - w);
    }
}
signed main(){
    read(n);
    _rep(i, 2, n){
        int u, v, w; read(u, v, w);
        G[u].pb({v, w}), G[v].pb({u, w});
    }
    read(q);
    _rep(i, 1, q){
        int u, v; read(u, v);
        Q[u].pb({v, i});
    }
    dfs(1, 0);
    solve(1, 0);
    _rep(i, 1, q) writeln(ans[i]);
    return 0;
}

