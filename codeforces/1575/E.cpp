// LUOGU_RID: 160560772
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
int n, k, a[N];
vector<PII> G[N];
int rt, tot, maxn[N], siz[N];
bool vis[N];
void findrt(int u, int fa){
    siz[u] = 1, maxn[u] = 0;
    for(auto &[v, w] : G[u]){
        if(vis[v] || v == fa) continue;
        findrt(v, u), siz[u] += siz[v];
        maxn[u] = max(maxn[u], siz[v]);
    }
    maxn[u] = max(maxn[u], tot - siz[u]);
    if(maxn[u] < maxn[rt]) rt = u;
}
int cnt;
struct node{
    ll num, sum, op;
}p[N];
void dfs(int u, int fa, ll sum, int num, int lst, int op){
    p[++cnt] = {num, sum % mod, op};
    for(auto &[v, w] : G[u]){
        if(vis[v] || v == fa) continue;
        dfs(v, u, sum + a[v], num + (w != lst), w, op == -1 ? w : op);
    }
}
ll ans, pre[N], t[N][2], q[N][2];
ll calc(int u, int fa, ll sum, int num, int lst, ll del, int op){
    dfs(u, fa, sum, num, lst, op);
    // debug("calc %d: \n", u);
    sort(p + 1, p + 1 + cnt, [](node x, node y){return x.num < y.num;});
    // _rep(i, 1, cnt) debug("(%d,%d,%d) ", p[i].num, p[i].sum, p[i].op); debug("\n");
    _rep(i, 1, cnt) pre[i] = (pre[i - 1] + p[i].sum) % mod;
    lst = 0;
    ll cur = 0;
    _rep(i, 1, cnt){
        if(p[i].num > k) break;
        while(lst && p[lst].num + p[i].num > k) lst--;
        if(lst + 1 < i && p[lst + 1].num + p[i].num <= k) lst++;
        add(cur, (p[i].sum - del) * lst + pre[lst]);
        add(cur, t[k - p[i].num + 1][p[i].op] + (p[i].sum - del) * q[k - p[i].num + 1][p[i].op] % mod);
        if(p[i].op != -1) add(t[p[i].num][p[i].op], p[i].sum), q[p[i].num][p[i].op]++;
    }
    _rep(i, 1, cnt) t[p[i].num][p[i].op] = q[p[i].num][p[i].op] = 0;
    //  debug("cur:%d\n--------\n", cur);
    cnt = 0;
    return cur;
}
void solve(int u){
    int sum = tot, lst = siz[u];
    vis[u] = 1, siz[u] = tot;
    // debug("solve %d\n", u);
    for(auto &[v, w] : G[u]) if(!vis[v]) dec(ans, calc(v, u, a[u] + a[v], 1, w, a[u], w));
    add(ans, calc(u, 0, a[u], 0, -1, a[u], -1));
    for(auto &[v, w] : G[u]){
        if(vis[v]) continue;
        maxn[rt = 0] = 2e9, tot = (siz[v] > lst) ? sum - lst : siz[v];
        findrt(v, u), solve(rt);
    }
    // debug("===========\n");
}
int main(){
	read(n, k), k++;
    _rep(i, 1, n) read(a[i]);
    _rep(i, 2, n){
        int u, v, w; read(u, v, w);
        G[u].pb({v, w}), G[v].pb({u, w});
    }
    tot = n, maxn[rt = 0] = 2e9, findrt(1, 0);
    solve(rt);
    _rep(i, 1, n) add(ans, a[i]);
    writeln(ans);
    return 0;
}

