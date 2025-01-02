#include <bits/stdc++.h>
using namespace std;

#define int long long
#define str string
using db = long double;
using i128 = __int128;

using pi = pair<int, int>;
using pd = pair<db, db>;
#define mp make_pair
#define f first
#define s second

#define tcT template <class T
#define tcTU tcT, class U
tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using ll = long long;
using vi = V<int>;
using vb = V<bool>;
using vd = V<db>;
using vs = V<string>;
using vpi = V<pi>;
using vpd = V<pd>;

#define sz(x) (int)((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
tcT > int lwb(V<T>& a, const T& b) { return (int)(lb(all(a), b) - bg(a)); }
tcT > int upb(V<T>& a, const T& b) { return (int)(ub(all(a), b) - bg(a)); }

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep1(a) F0R(_, a)
#define each(a, x) for (auto& a : x)

#define rep2(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep3(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep4(i, a, b, c) for (ll i = (ll)(a); i < (ll)(b); i += (c))
#define cut4(a, b, c, d, e, ...) e
#define rep(...) cut4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define per1(n) for (ll i = ((ll)n) - 1; i >= 0; --i)
#define per2(i, n) for (ll i = ((ll)n) - 1; i >= 0; --i)
#define per3(i, a, b) for (ll i = ((ll)b) - 1; i >= (ll)(a); --i)
#define per4(i, a, b, c) for (ll i = ((ll)b) - 1; i >= (ll)(a); i -= (c))
#define per(...) cut4(__VA_ARGS__, per4, per3, per2, per1)(__VA_ARGS__)
#define rep_subset(i, s) \
    for (ll i = (s); i >= 0; i = (i == 0 ? -1 : (i - 1) & (s)))

const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(
    (uint64_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int topbit(int x) { return x == 0 ? 0 : 63 - __builtin_clzll(x); }
constexpr int pow2(int x) { return 1 << x; }
constexpr int isp2(int x) { return x && (x & -x) == x; }
constexpr int mask(int x) { return pow2(x) - 1; }
template <typename T> inline int gbit(const T& a, int i) {
    return (a >> i) & 1;
}
template <typename T> inline void sbit(T& a, int i, bool b) {
    if (gbit(a, i) != b) a ^= T(1) << i;
}

int cdiv(int a, int b) { return a / b + ((a ^ b) > 0 && a % b); }

int fdiv(int a, int b) { return a / b - ((a ^ b) < 0 && a % b); }

int root2(int x) {
    int res = sqrtl(x) + 2;
    while (res * res > x) --res;
    return res;
}

tcT > bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }

tcT > bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

tcTU > T fstTrue(T lo, T hi, U f) {
    ++hi;
    assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}

tcTU > T lstTrue(T lo, T hi, U f) {
    --lo;
    assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}

tcT > void remDup(vector<T>& v) {
    sort(all(v));
    v.erase(unique(all(v)), end(v));
}

tcTU > void safeErase(T& t, const U& u) {
    auto it = t.find(u);
    assert(it != end(t));
    t.erase(it);
}

tcT > V<T> prefSum(const V<T>& a) {
    V<T> ret = a;
    FOR(i, 1, sz(ret)) ret[i] += ret[i - 1];
    return ret;
}

tcT > V<T> sufSum(const V<T>& a) {
    V<T> ret = a;
    R0F(i, sz(ret) - 1) ret[i] += ret[i + 1];
    return ret;
}

// sorted[i] = v[idx[i]]
tcT > vi sortedIdx(const V<T>& v) {
    vi ret(sz(v));
    iota(all(ret), 0);
    sort(all(ret), [&](int i, int j) { return v[i] < v[j]; });
    return ret;
}

tcT > vi rearrange(const V<T>& v, const vi& idx) {
    vi ret(sz(v));
    rep(i, sz(v)) ret[i] = v[idx[i]];
    return ret;
}

// ? = -1
tcT> vi s_to_vi(const str& S, T first_char) {
    vi A(sz(S));
    rep(i, sz(S)) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }
    return A;
}

tcT > T Sum(const V<T>& v) {
    T ret = 0;
    each(x, v) ret += x;
    return ret;
}

tcT > T Max(const V<T>& v) { return *max_element(all(v)); }

tcT > T Min(const V<T>& v) { return *min_element(all(v)); }

tcT > int MaxIdx(const V<T>& v) { return max_element(all(v)) - bg(v); }

tcT > int MinIdx(const V<T>& v) { return min_element(all(v)) - bg(v); }

inline namespace IO {
#define SFINAE(x, ...)                                            \
    template <class, class = void> struct x : std::false_type {}; \
    template <class T> struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}

SFINAE(DefaultI, decltype(std::cin >> std::declval<T&>()));
SFINAE(DefaultO, decltype(std::cout << std::declval<T&>()));
SFINAE(IsTuple, typename std::tuple_size<T>::type);
SFINAE(Iterable, decltype(std::begin(std::declval<T>())));

template <auto& is> struct Reader {
    template <class T> void Impl(T& t) {
        if constexpr (DefaultI<T>::value)
            is >> t;
        else if constexpr (Iterable<T>::value) {
            for (auto& x : t) Impl(x);
        } else if constexpr (IsTuple<T>::value) {
            std::apply([this](auto&... args) { (Impl(args), ...); }, t);
        } else
            static_assert(IsTuple<T>::value, "No matching type for read");
    }
    template <class... Ts> void read(Ts&... ts) { ((Impl(ts)), ...); }
};

template <class... Ts> void re(Ts&... ts) { Reader<cin>{}.read(ts...); }
#define def(t, args...) \
    t args;             \
    re(args);

#define defi(args...) def(int, args)
#define defs(args...) def(str, args)
#define defd(args...) def(db, args)
#define defv(t, name, size) \
    V<t> name(size);        \
    re(name);

#define defvi(name, size, offset) \
    vi name(size + offset);       \
    rep(i, offset, size + offset) re(name[i]);

#define re2(s, t)                     \
    for (int i = 0; i < sz(s); i++) { \
        re(s[i], t[i]);               \
    }

#define re3(s, t, u)                  \
    for (int i = 0; i < sz(s); i++) { \
        re(s[i], t[i], u[i]);         \
    }

#define re4(s, t, u, v)               \
    for (int i = 0; i < sz(s); i++) { \
        re(s[i], t[i], u[i], v[i]);   \
    }

template <auto& os, bool debug, bool print_nd> struct Writer {
    string comma() const { return debug ? "," : ""; }
    template <class T> constexpr char Space(const T&) const {
        return print_nd && (Iterable<T>::value or IsTuple<T>::value) ? '\n'
                                                                     : ' ';
    }
    template <class T> void Impl(T const& t) const {
        if constexpr (DefaultO<T>::value)
            os << t;
        else if constexpr (Iterable<T>::value) {
            if (debug) os << '{';
            int i = 0;
            for (auto&& x : t)
                ((i++) ? (os << comma() << Space(x), Impl(x)) : Impl(x));
            if (debug) os << '}';
        } else if constexpr (IsTuple<T>::value) {
            if (debug) os << '(';
            std::apply(
                [this](auto const&... args) {
                    int i = 0;
                    (((i++) ? (os << comma() << " ", Impl(args)) : Impl(args)),
                     ...);
                },
                t);
            if (debug) os << ')';
        } else
            static_assert(IsTuple<T>::value, "No matching type for print");
    }
    template <class T> void ImplWrapper(T const& t) const { Impl(t); }
    template <class... Ts> void print(Ts const&... ts) const {
        ((Impl(ts)), ...);
    }
    template <class F, class... Ts>
    void print_with_sep(const std::string& sep,
                        F const& f,
                        Ts const&... ts) const {
        ImplWrapper(f), ((os << sep, ImplWrapper(ts)), ...), os << '\n';
    }
    void print_with_sep(const std::string&) const { os << '\n'; }
};

template <class... Ts> void pr(Ts const&... ts) {
    Writer<cout, false, true>{}.print(ts...);
}
template <class... Ts> void ps(Ts const&... ts) {
    Writer<cout, false, true>{}.print_with_sep(" ", ts...);
}
}  // namespace IO

inline namespace Debug {
template <typename... Args> void err(Args... args) {
    Writer<cerr, true, false>{}.print_with_sep(" | ", args...);
}

void err_prefix(string func, int line, string args) {
    cerr << func << ":" << line << " - " << "[" << args << "] = ";
}

#ifdef LOCAL
#define dbg(args...) err_prefix(__FUNCTION__, __LINE__, #args), err(args)
#else
#define dbg(...)
#endif

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(12);
}
}  // namespace Debug

void YES(bool t = 1) { ps(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { ps(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { ps(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }

namespace std {

template <class Fun> class y_combinator_result {
    Fun fun_;

  public:
    template <class T>
    explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

    template <class... Args> decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <class Fun> decltype(auto) fun(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}  // usage : fun([&](auto dfs, int u, int p) -> void ...

}  // namespace std

/* start */

void solve(int tc) {
    defi(n);
    defs(s);
    auto v = s_to_vi(s, '0');
    int ans = 0;
    rep(i, 0, n, 2) if (v[i] != v[i + 1]) ans++;

    const int inf = 1e18;
    vi dp(2, inf);
    dp[v[0]] = 1;
    dp[v[1]] = 1;

    rep(i, 2, n, 2) {
        vi dp2(2, inf);
        int a = v[i], b = v[i + 1];
        ckmin(dp2[a], dp[a]);
        ckmin(dp2[a], dp[a ^ 1] +  1);
        ckmin(dp2[b], dp[b]);
        ckmin(dp2[b], dp[b ^ 1] + 1);
        dp = dp2;
    }

    ps(ans, Min(dp));
}

signed main() {
    setIO();
    int TC = 1;
    re(TC);
    rep(i, 1, TC + 1) solve(i);
}

  	 		 			 	 			 		 	     					