// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int INF = 1e18; // 1e9
const int P = 1e9+7; // 998244353;
const double PI = acos(-1.0);

using pi = pair<int,int>;

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;
using vpi = V<pi>;

#define sz(x) ((int)(x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define rep(a) F0R(_,a)

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; } // set a = max(a,b)

template<class T, class U> T fstFalse(T lo, T hi, U f) {
    while (lo < hi) {
        T m = (lo+hi)/2;
        f(m) ? lo = m+1 : hi = m;
    }
    return hi;
}

template<class, class=void> struct is_iterable : false_type {};
template<class T> struct is_iterable<T, void_t<decltype(begin(declval<T&>())), decltype(end(declval<T&>()))>> : true_type {};
template<class T> constexpr bool is_iterable_v = is_iterable<T>::value;

template<class, class = void> struct is_readable : false_type {};
template<class T> struct is_readable<T, typename std::enable_if_t<is_same_v<decltype(cin >> declval<T&>()), istream&>>> : true_type {};
template<class T> constexpr bool is_readable_v = is_readable<T>::value;

template<class, class = void> struct is_printable : false_type {};
template<class T> struct is_printable<T, typename std::enable_if_t<is_same_v<decltype(cout << declval<T>()), ostream&>>> : true_type {};
template<class T> constexpr bool is_printable_v = is_printable<T>::value;

#define def(t, args...) \
    t args;             \
    re(args);

// Input
template<class T> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
template<class T> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } 
template<class T, class... U> void re(T& t, U&... u);
template<class T> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 
template<class T, class U> void re(pair<T,U>& p) { re(p.f,p.s); }
template<class T> typename enable_if<needs_input_v<T>,void>::type re(T& i) { for(auto&x:i)re(x); }
template<class T, class... U> void re(T& t, U&... u) { re(t); re(u...); }

// String representation for printing
template<class T> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;
template<class T> typename enable_if<is_printable_v<T>,string>::type ts(T v) {
    stringstream ss; ss << fixed << setprecision(15) << v;
    return ss.str(); 
}
template<class T> string bit_vec(T t) { // bit vector to string
    string res = "{"; for (const auto& x : t) res += ts(x);
    res += "}"; return res; 
}
string ts(V<bool> v) { return bit_vec(v); }
template<size_t SZ> string ts(bitset<SZ> b) { return bit_vec(b); }

template<class T, class U> string ts(pair<T, U> p);
template<class T> typename enable_if<needs_output_v<T>,string>::type ts(T v);

template<class T, class U> string ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
template<class T> typename enable_if<is_iterable_v<T>,string>::type ts_sep(T v, string sep) {
    bool fst = 1; string res = "";
    for (const auto& x: v) {
        if (!fst) res += sep;
        fst = 0; res += ts(x);
    }
    return res;
}
template<class T> typename enable_if<needs_output_v<T>,string>::type ts(T v) { return "{"+ts_sep(v,", ")+"}"; }

// Printing functions
template<class T> void pr_sep(ostream& os, string, const T& t) { os << ts(t); }
template<class T, class... U> void pr_sep(ostream& os, string sep, const T& t, const U&... u) {
    pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }

template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
void ps() { cout << "\n"; }
template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 

template<class ...T> void dbg_out(const T&... t) {
    pr_sep(cerr," | ",t...); cerr << endl; }
    void loc_info(int line, string names) {
        cerr << "Line(" << line << ") -> [" << names << "]: "; }
#ifdef I_AM_NOOB
#define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// Fast IO
void setIn(string s)  { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(s) && fopen((s+".in").c_str(), "r")) setIn(s+".in"), setOut(s+".out"); // for old USACO
}

template<class F> struct y_combinator_result {
    F f;
    template<class T> explicit y_combinator_result(T &&f): f(std::forward<T>(f)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return f(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) yy(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

void add(int& x, int y) {
    x += y;
    if (x >= P) x -= P;
}
int mod(int x) {
    if (x >= P) x -= P;
    return x;
}
int binexp(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2) res = res*a%P;
        a = a*a%P;
        b /= 2;
    }
    return res;
}

int n, q;
vi a;
const int max_n = 1e5;

int C[6][6];
int pre[6][max_n+1];
void precalc() {
    for (int j = 0; j < 6; j++) {
        for (int i = 1; i <= max_n; i++)
            pre[j][i] = mod(pre[j][i-1] + binexp(i, j));
    }
    C[0][0] = 1;
    for (int i = 1; i < 6; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i-1][j-1]+C[i-1][j];
        }
    }
    assert(C[5][3] == 10);
    assert(binexp(2, 10) == 1024);
}

struct segtree {
    int j;
    vi t, buf;
    void build(int v, int l, int r) {
        if (l == r-1) {
            t[v] = a[l]*binexp(l+1, j) % P;
            return;
        }
        int m = (l+r)/2;
        build(2*v+1, l, m);
        build(2*v+2, m, r);
        t[v] = mod(t[2*v+1]+t[2*v+2]);
    }
    void pd(int v, int l, int r) {
        if (buf[v] != -1) {
            t[v] = buf[v]*(pre[j][r] + P - pre[j][l])%P;
            if (l < r-1) {
                buf[2*v+1] = buf[v];
                buf[2*v+2] = buf[v];
            }
            buf[v] = -1;
        }
    }
    int range_sum(int v, int l, int r, int L, int R) {
        pd(v, l, r);
        if (r <= L || R <= l) return 0;
        if (L <= l && r <= R) return t[v];
        int m = (l+r)/2;
        return mod(range_sum(2*v+1, l, m, L, R) + range_sum(2*v+2, m, r, L, R));
    }
    void range_set(int v, int l, int r, int L, int R, int x) {
        pd(v, l, r);
        if (r <= L || R <= l) return;
        if (L <= l && r <= R) {
            buf[v] = x;
            pd(v, l, r);
            return;
        }
        int m = (l+r)/2;
        range_set(2*v+1, l, m, L, R, x);
        range_set(2*v+2, m, r, L, R, x);
        t[v] = mod(t[2*v+1] + t[2*v+2]);
    }
    segtree(int j) {
        this->j = j;
        int size = 1;
        while (size < 2*n) size *= 2;
        t.resize(size);
        buf.assign(size, -1);
        build(0, 0, n);
    }
    segtree() {}
};
segtree trees[6];

void solve() {
    precalc();

    cin >> n >> q;
    // for (int i = 0; i < n; i++) cerr << pre[0][i] << " \n"[i==n-1];
    a.resize(n); for (auto& x : a) cin >> x;
    for (int j = 0; j < 6; j++) trees[j] = segtree(j);

    for (int i = 0; i < q; i++) {
        char tp; cin >> tp;
        if (tp == '=') {
            int l, r, x; cin >> l >> r >> x; l--;
            for (int j = 0; j < 6; j++) {
                trees[j].range_set(0, 0, n, l, r, x);
            }
        } else {
            int l, r, k; cin >> l >> r >> k; l--;
            int res = 0;
            for (int j = 0; j <= k; j++) {
                int cont = trees[j].range_sum(0, 0, n, l, r) * binexp(P-l, k-j) % P * C[k][j] % P;
                cont = (cont + P) % P;
                add(res, cont);
            }
            cout << res << '\n';
        }
    }
}

signed main() {
    setIO();
    
    solve();

    return 0;
}
