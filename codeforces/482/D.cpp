// LUOGU_RID: 154747720
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
const int N = 1e5 + 5;
ll n, dp[N][2];
vector<int> G[N];
void dfs(int u){
    sort(G[u].begin(), G[u].end());
    ll cur[2] = {1, 0}, tot = 1, f[2] = {1, 0}, g[2] = {1, 0};
    for(auto &v : G[u]){
        dfs(v);
        ll nc[2] = {(cur[1] * dp[v][0] + cur[0]) % mod, (cur[0] * dp[v][0] + cur[1]) % mod};
        tot = tot * dp[v][1] % mod, cur[0] = nc[0], cur[1] = nc[1];
        ll nf[2] = {(f[0] * dp[v][1] + f[1] * dp[v][0]) % mod, (f[0] * dp[v][0] + f[1] * dp[v][1]) % mod};
        f[0] = nf[0], f[1] = nf[1];
    }
    sort(G[u].begin(), G[u].end(), greater<int>());
    for(auto &v : G[u]){
        ll ng[2] = {(g[0] * dp[v][1] + g[1] * dp[v][0]) % mod, (g[0] * dp[v][0] + g[1] * dp[v][1]) % mod};
        g[0] = ng[0], g[1] = ng[1];
    }
    dp[u][0] = (f[0] + g[0] - tot + mod) % mod, dp[u][1] = (f[1] + g[1] - cur[1] + 1 + mod) % mod;
}
int main(){
    read(n);
    _rep(i, 2, n){int u; read(u); G[u].pb(i);}
    dfs(1);
    writeln((dp[1][0] + dp[1][1] - 1 + mod) % mod);
    return 0;
}