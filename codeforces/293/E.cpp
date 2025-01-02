// LUOGU_RID: 159843979
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
typedef pair<ll, ll> PII;
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
const int N = 1e5 + 5, M = 1e9;
int n, l, w;
vector<PII> G[N];
int rt, tot, siz[N], maxn[N];
bool vis[N];
void findrt(int u, int fa){
    siz[u] = 1, maxn[u] = 0;
    for(auto &[v, w] : G[u]){
        if(vis[v] || v == fa) continue;
        findrt(v, u), maxn[u] = max(maxn[u], siz[v]);
        siz[u] += siz[v];
    }
    maxn[u] = max(maxn[u], tot - siz[u]);
    if(maxn[u] < maxn[rt]) rt = u;
}
namespace sgt{
    int r, num, tr[N * 35], ls[N * 35], rs[N * 35];
    void modify(int &x, int l, int r, int p, int v){
        if(!x) x = ++num;
        if(l == r) return tr[x] += v, void();
        int mid = l + r >> 1;
        if(p <= mid) modify(ls[x], l, mid, p, v);
        else modify(rs[x], mid + 1, r, p, v);
        tr[x] = tr[ls[x]] + tr[rs[x]];
    }
    int query(int x, int l, int r, int L, int R){
        if(!x) return 0;
        if(l >= L && r <= R) return tr[x];
        int mid = l + r >> 1; ll res = 0;
        if(L <= mid) res += query(ls[x], l, mid, L, R);
        if(R > mid) res += query(rs[x], mid + 1, r, L, R);
        return res;
    }
    void clr(){
        _rep(i, 1, num) tr[i] = ls[i] = rs[i] = 0;
        num = r = 0;
    }
}
using namespace sgt;
ll calc(PII *a, int len){
    sort(a + 1, a + 1 + len);
    // debug("calc:");
    // _rep(i, 1, len) debug("(%d,%d) ", a[i].fi, a[i].se);
    // debug("\n");
    int lst = 0;
    ll ans = 0;
    _rep(i, 1, len){
        if(lst + 1 < i && a[lst + 1].fi + a[i].fi <= l) modify(r, 0, M, a[++lst].se, 1);
        while(lst && a[lst].fi + a[i].fi > l) modify(r, 0, M, a[lst--].se, -1);
        // debug("i:%d lst:%d\n", i, lst);
        if(w >= a[i].se) ans += query(r, 0, M, 0, w - a[i].se);
        // debug("ans:%d\n", query(r, 0, M, 0, w - a[i].se));
    }
    clr();
    // debug("ans:%d\n-----------\n", ans);
    return ans;
}
int cnt;
PII cur[N], in[N];
void dfs(int u, int fa, ll dep, ll dis){
    in[++cnt] = {dep, dis};
    for(auto &[v, w] : G[u]){
        if(v == fa || vis[v]) continue;
        dfs(v, u, dep + 1, dis + w);
    }
}
ll ans;
void solve(int u){
    int sum = tot, lst = siz[u], len = 0;
    siz[u] = tot, vis[u] = 1;
    for(auto &[v, w] : G[u]){
        if(vis[v]) continue;
        cnt = 0; dfs(v, u, 1, w);
        _rep(i, 1, cnt) cur[++len] = in[i];
        ans -= calc(in, cnt);
    }
    cur[++len] = {0, 0};
    // debug("solve %d\n", u);
    // _rep(i, 1, len) debug("(%d,%d) ", cur[i].fi, cur[i].se);
    ll res = calc(cur, len);
    ans += res;
    // debug("\nres:%d ===============\n", res);
    for(auto &[v, w] : G[u]){
        if(vis[v]) continue;
        tot = (siz[v] > lst) ? (sum - lst) : siz[v];
        maxn[rt = 0] = 2e9, findrt(v, u);
        solve(rt);
    }
}
int main(){
    read(n, l, w);
    _rep(i, 2, n){
        int p, v; read(p, v);
        G[p].pb({i, v}), G[i].pb({p, v});
    }
    tot = n, maxn[rt = 0] = 2e9, findrt(1, 0);
    solve(rt);
    writeln(ans);
    return 0;
}