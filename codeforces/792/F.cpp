#line 1 "library-cpp/other/template.hpp"
// clang-format off
#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
template <class T> using maxheap = priority_queue<T>;
template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vector<T>>;
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP0(n) for (auto minato = decay_t<decltype(n)>{}; minato < (n); ++minato)
#define REP1(i, n) for (auto i = decay_t<decltype(n)>{}; (i) < (n); (i)++)
#define REP2(i, l, r) for (auto i = (l); (i) < (r); (i)++)
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1, REP0)(__VA_ARGS__)
#define OVERLOAD_RREP(_1, _2, _3, name, ...) name
#define RREP1(i, n) for (auto i = (n) - 1; (i) >= decay_t<decltype(n)>{}; (i)--)
#define RREP2(i, l, r) for (auto i = (r) - 1; (i) >= (l); (i)--)
#define rrep(...) OVERLOAD_RREP(__VA_ARGS__, RREP2, RREP1)(__VA_ARGS__)
#define ALL(x) begin(x), end(x)
template <class Container> int SZ(const Container& v) { return int(v.size()); }
template <class T> void UNIQUE(vector<T>& v) { v.erase(unique(v.begin(), v.end()), v.end()); }
template <class T> T MAX(const vector<T>& v) { return *max_element(v.begin(), v.end()); }
template <class T> T MIN(const vector<T>& v) { return *min_element(v.begin(), v.end()); }
template <class T> T SUM(const vector<T>& v) { return accumulate(v.begin(), v.end(), T(0)); }
template <class T> T ABS(T x) { return max(x, -x); }
template <class T> constexpr T POW(T x, ull n) { T ret = 1; while (n > 0) { if (n & 1) ret *= x; x *= x; n >>= 1; } return ret; }
template <class T> constexpr T POW(T x, ull n, T mod) { T ret = 1; while (n > 0) { if (n & 1) ret = ret * x % mod; x = x * x % mod; n >>= 1; } return ret; }
constexpr long long floor_div(long long n, long long d) { return n / d - ((n ^ d) < 0 && n % d); }
template <class T1, class T2> bool chmax(T1& a, T2 b) { if (a < b) { a = b; return true; } return false; }
template <class T1, class T2> bool chmin(T1& a, T2 b) { if (a > b) { a = b; return true; } return false; }
constexpr int topbit(ull x) { return 63 - std::countl_zero(x); }
constexpr int botbit(ull x) { return std::countr_zero(x); }
constexpr int popcnt(ull x) { return std::popcount(x); }
constexpr int kthbit(ull x, int k) { return (x >> k) & 1; }
constexpr int popparity(ull x) { return __builtin_parityll(x); }
constexpr int parity_sign(ull x) { return (x & 1) ? -1 : 1; }
constexpr long long TEN(int x) { return x == 0 ? 1 : TEN(x - 1) * 10; }
template <typename S> void rearrange(const vector<S>& id) { (void)id; }
template <typename S, typename T> void rearrange_exec(const vector<S>& id, vector<T>& v) { vector<T> w(v.size()); for (size_t i = 0; i < id.size(); i++) { w[i] = v[id[i]]; } v.swap(w); }
template <typename S, typename Head, typename... Tail> void rearrange(const vector<S>& id, Head& a, Tail& ...tail) { rearrange_exec(id, a); rearrange(id, tail...); }
istream& operator>>(istream& is, __int128_t& x) {
    x = 0;
    string s;
    is >> s;
    int n = int(s.size()), it = 0;
    if (s[0] == '-') it++;
    for (; it < n; it++) x = (x * 10 + s[it] - '0');
    if (s[0] == '-') x = -x;
    return is;
}
ostream& operator<<(ostream& os, __int128_t x) {
    if (x == 0) return os << 0;
    if (x < 0) os << '-', x = -x;
    deque<int> deq;
    while (x) deq.emplace_front(x % 10), x /= 10;
    for (int e : deq) os << e;
    return os;
}
template <class T> vector<T> &operator++(vector<T>& v) { for (auto& e : v) { e++; } return v;} 
template <class T> vector<T> operator++(vector<T>& v, int) { auto res = v; for (auto& e : v) { e++; } return res; }
template <class T> vector<T> &operator--(vector<T>& v) { for (auto& e : v) { e--; } return v; }
template <class T> vector<T> operator--(vector<T>& v, int) { auto res = v; for (auto& e : v) { e--; } return res; }
template <class T1, class T2> pair<T1, T2> operator-(const pair<T1, T2>& x) { return pair<T1, T2>(-x.first, -x.second); }
template <class T1, class T2> pair<T1, T2> operator-(const pair<T1, T2>& x, const pair<T1, T2>& y) { return pair<T1, T2>(x.first - y.first, x.second - y.second); }
template <class T1, class T2> pair<T1, T2> operator+(const pair<T1, T2>& x, const pair<T1, T2>& y) { return pair<T1, T2>(x.first + y.first, x.second + y.second); }
template <class T1, class T2> pair<T1, T2> operator+=(pair<T1, T2>& l, const pair<T1, T2>& r) { return l = l + r; }
template <class T1, class T2> pair<T1, T2> operator-=(pair<T1, T2>& l, const pair<T1, T2>& r) { return l = l - r; }
constexpr char ln = '\n';
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
void YES(bool t = true) { cout << YESNO[t] << "\n"; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = true) { cout << YesNo[t] << "\n"; }
void No(bool t = 1) { Yes(!t); }
template <class T> void drop(T x) { cout << x << "\n"; exit(0); }
#define INT(...)     \
    int __VA_ARGS__; \
    IN(__VA_ARGS__)
#define LL(...)     \
    ll __VA_ARGS__; \
    IN(__VA_ARGS__)
#define STR(...)        \
    string __VA_ARGS__; \
    IN(__VA_ARGS__)
#define CHR(...)      \
    char __VA_ARGS__; \
    IN(__VA_ARGS__)
#define LDB(...)             \
    long double __VA_ARGS__; \
    IN(__VA_ARGS__)
#define VEC(type, name, size) \
    vector<type> name(size);  \
    IN(name)
#define VEC2(type, name1, name2, size)     \
    vector<type> name1(size), name2(size); \
    for (int i = 0; i < size; i++) IN(name1[i], name2[i])
#define VEC3(type, name1, name2, name3, size)           \
    vector<type> name1(size), name2(size), name3(size); \
    for (int i = 0; i < size; i++) IN(name1[i], name2[i], name3[i])
#define VEC4(type, name1, name2, name3, name4, size)                 \
    vector<type> name1(size), name2(size), name3(size), name4(size); \
    for (int i = 0; i < size; i++) IN(name1[i], name2[i], name3[i], name4[i]);
#define VV(type, name, N, M)                       \
    vector<vector<type>> name(N, vector<type>(M)); \
    IN(name)
template <class T> void scan(T& a) { cin >> a; }
template <class T> void scan(vector<T>& a) { for (auto& i : a) scan(i); }
void IN() {}
template <class Head, class... Tail> void IN(Head& head, Tail&... tail) { scan(head); IN(tail...); }
std::vector<std::vector<int>> read_graph(int N, int M) {
    std::vector<std::vector<int>> g(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    return g;
}
std::vector<std::vector<int>> read_tree(int N) { return read_graph(N, N - 1); }
void print() { cout << "\n"; }
template <class T> void print(const vector<T>& v) { for (auto it = v.begin(); it != v.end(); ++it) { if (it != v.begin()) { cout << " "; } cout << *it; } print(); }
template <class T, class... Args> void print(const T& x, const Args& ... args) { cout << x; if (sizeof...(Args)) cout << " "; print(args...); }
#ifdef MINATO_LOCAL
template <class T1, class T2> ostream& operator<<(ostream& os, pair<T1, T2> p);
template <class ...Args> ostream& operator<<(ostream& os, tuple<Args...> t);
template <class T> ostream& operator<<(ostream& os, vector<T> v);
template <class T, size_t N> ostream& operator<<(ostream& os, array<T, N> a);
template <class T, size_t N> enable_if_t<!is_same_v<char, remove_cv_t<T>>, ostream>& operator<<(ostream& os, T(&a)[N]);
template <class Key> ostream& operator<<(ostream& os, set<Key> s);
template <class Key, class T> ostream& operator<<(ostream& os, map<Key, T> mp);
template <class Key> ostream& operator<<(ostream& os, multiset<Key> s);
template <class T> ostream& operator<<(ostream& os, queue<T> q);
template <class T> ostream& operator<<(ostream& os, deque<T> q);
template <class T> ostream& operator<<(ostream& os, priority_queue<T> q);
template <class T> ostream& operator<<(ostream& os, priority_queue<T, vector<T>, greater<T>> q);
template <class T1, class T2> ostream& operator<<(ostream& os, pair<T1, T2> p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <size_t N, class TUPLE> void debug_tuple(ostream& os, TUPLE _) { (void)os; (void)_; }
template <size_t N, class TUPLE, class T, class ...Args> void debug_tuple(ostream &os, TUPLE t) { os << (N == 0 ? "" : ", ") << get<N>(t); debug_tuple<N + 1, TUPLE, Args...>(os, t); }
template <class ...Args> ostream& operator<<(ostream& os, tuple<Args...> t) { os << "("; debug_tuple<0, tuple<Args...>, Args...>(os, t); return os << ")"; }
string debug_delim(int& i) { return i++ == 0 ? "" : ", "; }
#define debug_embrace(x) { int i = 0; os << "{";  { x } return os << "}"; }
template <class T> ostream& operator<<(ostream& os, vector<T> v) { debug_embrace( for (T e : v) { os << debug_delim(i) << e; } ) }
template <class T, size_t N> ostream& operator<<(ostream& os, array<T, N> a) { debug_embrace( for (T e : a) { os << debug_delim(i) << e; } ) }
template <class T, size_t N> enable_if_t<!is_same_v<char, remove_cv_t<T>>, ostream>& operator<<(ostream& os, T(&a)[N]) { debug_embrace( for (T e : a) { os << debug_delim(i) << e; } ) }
template <class Key> ostream& operator<<(ostream& os, set<Key> s) { debug_embrace( for (Key e : s) { os << debug_delim(i) << e; }) }
template <class Key, class T> ostream& operator<<(ostream& os, map<Key, T> mp) { debug_embrace( for (auto e : mp) { os << debug_delim(i) << e; }) }
template <class Key> ostream& operator<<(ostream& os, multiset<Key> s) { debug_embrace( for (Key e : s) { os << debug_delim(i) << e; }) }
template <class T> ostream& operator<<(ostream& os, queue<T> q) { debug_embrace( for (; !q.empty(); q.pop()) { os << debug_delim(i) << q.front(); } ) }
template <class T> ostream& operator<<(ostream& os, deque<T> q) { debug_embrace( for (T e : q) { os << debug_delim(i) << e; } ) }
template <class T> ostream& operator<<(ostream& os, priority_queue<T> q) { debug_embrace( for (; !q.empty(); q.pop()) { os << debug_delim(i) << q.top(); } ) }
template <class T> ostream& operator<<(ostream& os, priority_queue<T, vector<T>, greater<T>> q) { debug_embrace( for (; !q.empty(); q.pop()) { os << debug_delim(i) << q.top(); } ) }
void debug_out() { cerr << endl; }
template <class T, class... Args> void debug_out(const T& x, const Args& ... args) { cerr << " " << x; debug_out(args...); }
#define debug(...) cerr << __LINE__ << " : [" << #__VA_ARGS__ << "] =", debug_out(__VA_ARGS__)
#else
#define debug(...) (void(0))
#endif
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
#line 2 "A.cpp"

/**
 * Author: Simon Lindholm
 * Date: 2017-04-20
 * License: CC0
 * Source: own work
 * Description: Container where you can add lines of the form kx+m, and query
 * maximum values at points x. Useful for dynamic programming (``convex hull
 * trick''). Time: O(\log N) Status: stress-tested
 */

// k : 傾き, m : y切片, p : 最大値となる最大の x {(l,r] の r}
struct Line {
    mutable long long k, m, p;
    bool operator<(const Line& o) const {
        return k < o.k;
    }
    bool operator<(long long x) const {
        return p < x;
    }
};

template <bool Minimize = false> struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const long long inf = LLONG_MAX;
    long long div(long long a, long long b) {  // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k)
            x->p = x->m > y->m ? inf : -inf;
        else
            x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(long long k, long long m) {
        if (Minimize) k *= -1, m *= -1;
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
    }
    long long query(long long x) {
        assert(!empty());
        auto l = *lower_bound(x);
        if (Minimize) return -l.k * x - l.m;
        return l.k * x + l.m;
    }
};

void solve() {
    LL(Q, M);

    constexpr ll mod = TEN(6);

    ll hoge = 0;

    LineContainer<false> CHT;
    auto get = [&](ll x, ll t) {
        auto y = CHT.query(x);
        return M * x + t * y;
    };

    ll Amax = 0, Bmax = 1;
    rep(q, Q) {
        INT(T);
        if (T == 1) {
            LL(a, b);
            a = (a + hoge) % mod + 1;
            b = (b + hoge) % mod + 1;
            CHT.add(-b, a);
            if (a * Bmax > Amax * b) {
                Amax = a;
                Bmax = b;
            }
            debug(CHT.query(0));
        } else {
            LL(t, h);
            t = (t + hoge) % mod + 1;
            h = (h + hoge) % mod + 1;
            if (Amax == 0) {
                NO();
                continue;
            }
            ll l = 0, r = mod * 2;
            while (r - l > 1) {
                int m = (l + r) / 2;
                if (CHT.query(m) < 0) {
                    r = m;
                } else if (get(m - 1, t) < get(m, t)) {
                    r = m;
                } else {
                    l = m;
                }
            }
            ll val = get(l, t);
            debug(l, val, CHT.query(l));
            if (val < h or Amax * M < h * Bmax) {
                NO();
            } else {
                YES();
                hoge = q + 1;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(7);

    int T = 1;
    // cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        // debug(test_case);
        solve();
    }
}
