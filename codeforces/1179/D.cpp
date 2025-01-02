// LUOGU_RID: 160030840
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
ll n, ans, f[N], siz[N], a[N], x[N], y[N];
ll top, q[N];
vector<int> G[N];
void dfs(int u, int fa){
    siz[u] = 1;
    for(auto &v : G[u]){
        if(v == fa) continue;
        dfs(v, u), siz[u] += siz[v];
    }
    f[u] = siz[u] * siz[u];
    int cnt = 0;
    for(auto &v : G[u]){
        if(v == fa) continue;
        a[++cnt] = v;
        f[u] = min(f[u], f[v] + (siz[u] - siz[v]) * (siz[u] - siz[v]));
        ans = max(ans, n * n - (f[v] + (n - siz[v]) * (n - siz[v])));
    }
    sort(a + 1, a + 1 + cnt, [](ll x, ll y){return siz[x] < siz[y];});
    _rep(i, 1, cnt) y[a[i]] = f[a[i]] + siz[a[i]] * siz[a[i]], x[a[i]] = 2ll * siz[a[i]];
    q[top = 1] = a[1];
    ll cur = 1e18;
    _rep(i, 2, cnt){
        ll k = n - siz[a[i]];
        while(top > 1 && (y[q[top]] - y[q[top - 1]]) >= (x[q[top]] - x[q[top - 1]]) * k) top--;
        cur = min(cur, f[a[i]] + f[q[top]] + (n - siz[a[i]] - siz[q[top]]) * (n - siz[a[i]] - siz[q[top]]));
        while(top > 1 && (y[q[top]] - y[q[top - 1]]) * (x[a[i]] - x[q[top]]) >= (y[a[i]] - y[q[top]]) * (x[q[top]] - x[q[top - 1]])) top--;
        q[++top] = a[i];
    }
    ans = max(ans, n * n - cur);
}

int main(){
	read(n);
    _rep(i, 2, n){
        int u, v; read(u, v);
        G[u].pb(v), G[v].pb(u);
    }
    dfs(1, 0);
    writeln(n * (n - 1) / 2ll + ans / 2ll);
    return 0;
}

