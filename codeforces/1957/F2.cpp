#include <bits/stdc++.h>
using namespace std;
 
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
using ll = long long;
using dbl = long double;
//#define int ll
 
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vvii = vector<vii>;
using vll = vector<ll>;
 
#define ff first
#define ss second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tc int t; cin>>t; while(t--)
#define fightFight cin.tie(0) -> sync_with_stdio(0)
template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a <= b); // tie(a, b) = minimax(a, b)
        int dep = 31 - __builtin_clz(b-a+1);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep) + 1]);
    }
};
struct LCA {
    int T = 0;
    vi st, path, ret; vi en, d;
    RMQ<int> rmq;
    LCA(vector<vi>& C) : st(sz(C)), en(sz(C)), d(sz(C)), rmq((dfs(C,1,-1), ret)) {}
    void dfs(vvi &adj, int v, int par) {
        st[v] = T++;
        for (auto to : adj[v]) if (to != par) {
            path.pb(v), ret.pb(st[v]);
            d[to] = d[v] + 1;
            dfs(adj, to, v);
        }
        en[v] = T-1;
    }
    bool anc(int p, int c) { return st[p] <= st[c] and en[p] >= en[c]; }
    int lca(int a, int b) {
        if (a == b) return a;
        tie(a, b) = minmax(st[a], st[b]);
        return path[rmq.query(a, b-1)];
    }
    int dist(int a, int b) { return d[a] + d[b] - 2*d[lca(a,b)]; }
};
template<const int mod>
struct mint {
    constexpr mint(int x = 0) : val((x % mod + mod) % mod) {}
    mint& operator+=(const mint &b) { val += b.val; val -= mod * (val >= mod); return *this; }
    mint& operator-=(const mint &b) { val -= b.val; val += mod * (val < 0); return *this; }
    mint& operator*=(const mint &b) { val = 1ll * val * b.val % mod; return *this; }
    mint& operator/=(const mint &b) { return *this *= b.inv(); }
    mint inv() const {
        int x = 1, y = 0, t;
        for(int a=val, b=mod; b; swap(a, b), swap(x, y))
            t = a/b, a -= t * b, x -= t * y;
        return mint(x);
    }
    mint pow(int b) const {
        mint a = *this, res(1);
        for(; b; a *= a, b /= 2)  if(b&1) res *= a;
        return res;
    }
    friend mint operator+(const mint &a, const mint &b) { return mint(a) += b; }
    friend mint operator-(const mint &a, const mint &b) { return mint(a) -= b; }
    friend mint operator*(const mint &a, const mint &b) { return mint(a) *= b; }
    friend mint operator/(const mint &a, const mint &b) { return mint(a) /= b; }
    friend bool operator==(const mint &a, const mint &b) { return a.val == b.val; }
    friend bool operator!=(const mint &a, const mint &b) { return a.val != b.val; }
    friend bool operator<(const mint &a, const mint &b) { return a.val < b.val; }
    friend ostream& operator<<(ostream &os, const mint &a) { return os << a.val; }
    int val;
};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> rnd(20,10000);
using Mint1 = mint<MOD1>;
using Mint2 = mint<MOD2>;
using Mint = pair<Mint1,Mint2>;
const int N = 3e5 + 10, LOGN = 20;
int p1, p2;
int blen = 0;
int L[N * LOGN], R[N * LOGN];
Mint ST[N * LOGN], p_pow[N];
void prec() {
    p1 = rnd(rng);
    p2 = p1; 
    while (p2 == p1) p2 = rnd(rng);
    p_pow[0].ff = 1;
    p_pow[0].ss = 1;
    for (int i = 1; i < N; i++) {
        p_pow[i].ff = p_pow[i - 1].ff * p1;
        p_pow[i].ss = p_pow[i - 1].ss * p2;
    }
}
int update(int pos, int l, int r, int id) {
    if (pos < l || pos > r) return id;
    int ID = ++blen, m = (l + r) / 2;
    if (l == r) return (ST[ID] = {ST[id].ff + 1, ST[id].ss + 1}, ID);
    L[ID] = update(pos, l, m, L[id]);
    R[ID] = update(pos, m + 1, r, R[id]);
    return (ST[ID] = {ST[L[ID]].ff + p_pow[m - l + 1].ff * ST[R[ID]].ff, ST[L[ID]].ss + p_pow[m - l + 1].ss * ST[R[ID]].ss}, ID);
}
vi vals;
using a4 = array<int,4>;
void descent(int l, int r, const array<int, 4>& a, const array<int, 4>& b, int k) {
    if (l == r) return void(vals.push_back(l));
    int m = (l + r) / 2;
#define stm(X, y) {ST[X[y[0]]].ff + ST[X[y[1]]].ff - ST[X[y[2]]].ff - ST[X[y[3]]].ff, ST[X[y[0]]].ss + ST[X[y[1]]].ss - ST[X[y[2]]].ss - ST[X[y[3]]].ss}
#define arr(X, y) (a4{X[y[0]], X[y[1]], X[y[2]], X[y[3]]})
    Mint l1 = stm(L, a), l2 = stm(L, b), r1 = stm(R, a), r2 = stm(R, b);
    if (sz(vals) < k && l1 != l2) descent(l, m, arr(L, a), arr(L, b), k);
    if (sz(vals) < k && r1 != r2) descent(m + 1, r, arr(R, a), arr(R, b), k);
}
 
vvi adj;
vi a, roots, par; 
void dfs(int x, int p) {
    par[x] = p;
    roots[x] = update(a[x], 0, N, roots[par[x]]);
    for (auto& s : adj[x]) if (s != p) {
        dfs(s, x);
    }
}
void solve(){
    int n; cin >> n;        
    adj = vvi(n + 1);
    a = roots = par = vi(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    dfs(1, 0);
    LCA lca(adj);
    int q; cin >> q;
    while (q--) {
        vals.clear();
        int u1, v1, u2, v2, k; cin >> u1 >> v1 >> u2 >> v2 >> k;
        int l1 = lca.lca(u1, v1), l2 = lca.lca(u2, v2);
        a4 a{roots[u1], roots[v1], roots[l1], roots[par[l1]]};
        a4 b{roots[u2], roots[v2], roots[l2], roots[par[l2]]};
        descent(0, N, a, b, k);
        cout << sz(vals) << " ";
        for (auto& s : vals) cout << s << " ";
        cout << "\n";
    }
}
signed main(){ 
    fightFight; 
    prec();
    solve(); 
}