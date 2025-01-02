// LUOGU_RID: 160553052
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
const int N = 1e6 + 5;
ll n, a[N];
vector<int> pos[65];
namespace sgt{
    int tr[N << 2], tag[N << 2], cnt[N << 2];
    #define ls x << 1
    #define rs x << 1 | 1
    void update(int x){
        tr[x] = max(tr[ls], tr[rs]), cnt[x] = 0;
        if(tr[x] == tr[ls]) cnt[x] += cnt[ls];
        if(tr[x] == tr[rs]) cnt[x] += cnt[rs];
    }
    void pushdown(int x){
        if(!tag[x]) return;
        tr[ls] += tag[x], tr[rs] += tag[x], tag[ls] += tag[x], tag[rs] += tag[x];
        tag[x] = 0;
    }
    void modify(int x, int l, int r, int L, int R, int v){
        if(l >= L && r <= R) return tr[x] += v, tag[x] += v, void();
        int mid = l + r >> 1;
        pushdown(x);
        if(L <= mid) modify(ls, l, mid, L, R, v);
        if(R > mid) modify(rs, mid + 1, r, L, R, v);
        update(x);
    }
    void clr(int x, int l, int r){
        tag[x] = tr[x] = 0, cnt[x] = r - l + 1;
        if(l == r) return;
        int mid = l + r >> 1;
        clr(ls, l, mid), clr(rs, mid + 1, r);    
    }
}
using namespace sgt;
int top1, top2, st1[N], st2[N], col[N];
struct node{
    int p, l, r, v;
    node(int _p = 0, int _l = 0, int _r = 0, int _v = 0){p = _p, l = _l, r = _r, v = _v;}
};
vector<node> v[65];
int main(){
    // freopen("in.in", "r", stdin);
    int tt = clock();
    read(n);
    _rep(i, 1, n) read(a[i]), pos[__builtin_popcountll(a[i])].pb(i), col[i] = __builtin_popcountll(a[i]);
    clr(1, 1, n);

    ll ans = 0, tot = 0;
    st1[top1 = 1] = st2[top2 = 1] = 0;
    _rep(j, 1, n){
        int lst = j - 1;
        while(top1 > 1 && a[st1[top1]] > a[j]){
            int l = st1[top1 - 1] + 1, r = lst;
            v[col[st1[top1]]].pb(node(j, l, r, -1));
            lst = l - 1;
            top1--;
        }
        st1[++top1] = j;
        v[col[j]].pb(node(j, st1[top1 - 1] + 1, j, 1));
        lst = j - 1;
        while(top2 > 1 && a[st2[top2]] < a[j]){
            int l = st2[top2 - 1] + 1, r = lst;
            v[col[st2[top2]]].pb(node(j, l, r, -1));
            top2--;
            lst = l - 1;
        }
        st2[++top2] = j;
        v[col[j]].pb(node(j, st2[top2 - 1] + 1, j, 1));
    }
    debug("use %d ms\n", clock() - tt);
    _rep(i, 0, 59){
        ll cur = 0;
        int len = v[i].size();
        _rep(j, 0, len - 1){
            int k = j;
            while(k < len && v[i][k].p == v[i][j].p){
                modify(1, 1, n, v[i][k].l, v[i][k].r, v[i][k].v);
                k++;
            }
            k--;
            if(tr[1] == 2){
                if(k == len - 1) cur += 1ll * (n - v[i][k].p + 1) * cnt[1];
                else cur += 1ll * (v[i][k + 1].p - v[i][k].p) * cnt[1];
            }
            j = k;
        }
        tot += cur;
        clr(1, 1, n);
    }
    writeln(tot);
    debug("%d ms\n", clock() - tt);
    return 0;
}

