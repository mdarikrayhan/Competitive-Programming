// clang-format off

#ifdef ONLINE_JUDGE
#define dbg(...)
#define SOLVE solve();
#else
// #define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template <const int T> struct ModInt;
namespace debug { void __print(int x) { std::cerr << x; } void __print(long x) { std::cerr << x; } void __print(long long x) { std::cerr << x; } void __print(unsigned x) { std::cerr << x; } void __print(unsigned long x) { std::cerr << x; } void __print(unsigned long long x) { std::cerr << x; } void __print(float x) { std::cerr << x; } void __print(double x) { std::cerr << x; } void __print(long double x) { std::cerr << x; } void __print(char x) { std::cerr << '\'' << x << '\''; } void __print(const char *x) { std::cerr << '\"' << x << '\"'; } void __print(const std::string x) { std::cerr << '\"' << x << '\"'; } void __print(bool x) { std::cerr << (x ? "true" : "false"); } template <const int T> void __print(ModInt<T> x) { std::cerr << x.x; } template <typename T, typename V> void __print(std::pair<T, V> x) { std::cerr << '{'; __print(x.first); std::cerr << ','; __print(x.second); std::cerr << '}'; } template <typename T> void __print(T x) { int f = 0; std::cerr << '{'; for (auto &i : x) std::cerr << (f++ ? "," : ""), __print(i); std::cerr << "}"; } template <typename T> void __print(std::stack<T> x) { std::vector<T> _x; while (!x.empty()) _x.push_back(x.top()), x.pop(); reverse(_x.begin(), _x.end()); __print(_x); } template <typename T> void __print(std::queue<T> x) { std::vector<T> _x; while (!x.empty()) _x.push_back(x.front()), x.pop(); reverse(_x.begin(), _x.end()); __print(_x); } template <typename T> void __print(std::priority_queue<T> x) { std::vector<T> _x; while (!x.empty()) _x.push_back(x.top()), x.pop(); reverse(_x.begin(), _x.end()); __print(_x); } template <typename T> void __print(std::priority_queue<T, std::vector<T>, std::greater<T>> x) { std::vector<T> _x; while (!x.empty()) _x.push_back(x.top()), x.pop(); reverse(_x.begin(), _x.end()); __print(_x); } void _print() { std::cerr << "]\n\n"; } template <typename T, typename... V> void _print(T t, V... v) { __print(t); if (sizeof...(v)) std::cerr << ", "; _print(v...); } template <typename T> void _print2d(T x) { for (auto &i : x) _print(i); } } // namespace debug

using namespace std;
using namespace __gnu_pbds;
using namespace debug;

void rd(char &c) { cin >> c; } void rd(string &x) { cin >> x; } template <typename T> void rd_real(T &x) { string s; rd(s); x = stod(s); } void rd(int &x) { cin >> x; } void rd(long long &x) { cin >> x; } void rd(unsigned int &x) { cin >> x; } void rd(unsigned long long &x) { cin >> x; } void rd(double &x) { rd_real(x); } void rd(long double &x) { rd_real(x); } void rd(__float128 &x) { rd_real(x); } template <class T, class U> void rd(pair<T, U> &p) { return rd(p.first), rd(p.second); } template <size_t N = 0, typename T> void rd_tuple(T &t) { if constexpr (N < tuple_size<T>::value) { auto &x = get<N>(t); rd(x); rd_tuple<N + 1>(t); } } template <class... T> void rd(tuple<T...> &tpl) { rd_tuple(tpl); } template <size_t N = 0, typename T> void rd(array<T, N> &x) { for (auto &d : x) rd(d); } template <class T> void rd(vector<T> &x) { for (auto &d : x) rd(d); } void read() {} template <class H, class... T> void read(H &h, T &...t) { rd(h), read(t...); } void wt(const char c) { cout << c; } void wt(const string s) { cout << s; } void wt(const char *s) { size_t len = strlen(s); for (size_t i = 0; i < len; i++) wt(s[i]); } template <typename T> void wt_real(T x) { ostringstream oss; oss << fixed << setprecision(15) << double(x); string s = oss.str(); wt(s); } void wt(int x) { cout << x; } template <const int T> void wt(ModInt<T> x) { cout << x.x; } void wt(long long x) { cout << x; } void wt(unsigned int x) { cout << x; } void wt(unsigned long long x) { cout << x; } void wt(double x) { wt_real(x); } void wt(long double x) { wt_real(x); } void wt(__float128 x) { wt_real(x); } template <class T, class U> void wt(const pair<T, U> val) { wt(val.first); wt(' '); wt(val.second); } template <size_t N = 0, typename T> void wt_tuple(const T t) { if constexpr (N < tuple_size<T>::value) { if constexpr (N > 0) { wt(' '); } const auto x = get<N>(t); wt(x); wt_tuple<N + 1>(t); } } template <class... T> void wt(tuple<T...> tpl) { wt_tuple(tpl); } template <class T, size_t S> void wt(const array<T, S> val) { auto n = val.size(); for (size_t i = 0; i < n; i++) { if (i) wt(' '); wt(val[i]); } } template <class T> void wt(const vector<T> val) { auto n = val.size(); for (size_t i = 0; i < n; i++) { if (i) wt(' '); wt(val[i]); } } void print() { wt('\n'); } template <class Head, class... Tail> void print(Head &&head, Tail &&...tail) { wt(head); if (sizeof...(Tail)) wt(' '); print(forward<Tail>(tail)...); } void println() { wt('\n'); } template <class Head, class... Tail> void println(Head &&head, Tail &&...tail) { wt(head); if (sizeof...(Tail)) wt('\n'); println(forward<Tail>(tail)...); } template <typename T> void print2d(T x) { for (auto &i : x) println(i); }

#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#define dbg2d(x) cerr << "[" << #x << "]\n"; _print2d(x)
#define SOLVE { cerr << (_ > 0 ? "\n####### TestCase " : "####### TestCase ") << _ + 1 << " #######\n\n"; solve(); }
#endif

#define int(...) int __VA_ARGS__; read(__VA_ARGS__);
#define long(...) long long __VA_ARGS__; read(__VA_ARGS__);
#define str(...) string __VA_ARGS__; read(__VA_ARGS__);
#define char(...) char __VA_ARGS__; read(__VA_ARGS__);
#define vec(type, name, size) vc<type> name(size); read(name);
#define vvec(type, name, n, m) vc<vc<type>> name(n, vc<type>(m)); read(name);
#define reif(t, ...) if (t) { __VA_ARGS__; return; }
#define coif(t, ...) if (t) { __VA_ARGS__; continue; }
#define brif(t, ...) if (t) { __VA_ARGS__; break; }

#define all(x) x.begin(), x.end()
#define rev(x) reverse(all(x))
#define s0rt(x) sort(all(x))
#define s0rtd(x) sort(all(x)), rev(x);
#define s0rtx(x, ...) sort(all(x), __VA_ARGS__);
#define sum(x) accumulate(all(x), 0ll)
#define len(x) (long long)(x.size())
#define mine(v) *min_element(all(v))
#define maxe(v) *max_element(all(v))
#define unq(x) s0rt(x), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()
#define FOR1(a) for (int _ = 0; _ < (a); ++_)
#define FOR2(i, a) for (int i = 0; i < (a); ++i)
#define FOR3(i, a, b) for (int i = a; i < (b); ++i)
#define FOR4(i, a, b, c) for (int i = a; i < (b); i += (c))
#define FOR5(i, a, condn, b, add) for (int i = a; condn < b; i += add)
#define FOR1_R(a) for (int _ = (a); _ >= (0); --i)
#define FOR2_R(i, a) for (int i = (a); i >= (0); --i)
#define FOR3_R(i, a, b) for (int i = (a); i >= (b); --i)
#define FOR4_R(i, a, b, c) for (int i = (a); i >= (b); i -= c)
#define FOR5_R(i, a, condn, b, add) for (int i = (a); condn >= (b); i -= add)
#define TRAV1(i, a) for (auto &i : a)
#define TRAV2(i, j, a) for (auto &[i, j] : a)
#define LB1(x, y) lower_bound(all(x), y)
#define UB1(x, y) upper_bound(all(x), y)
#define LB2(x) lower_bound(x)
#define UB2(x) upper_bound(x)
#define CNT1(x, y) count(all(x), y)
#define cnt2(x) count(x)
#define overload5(a, b, c, d, e, f, ...) f
#define overload2(a, b, c, d, ...) d
#define overload1(a, b, c, ...) c
#define f0r(...) overload5(__VA_ARGS__, FOR5, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define f0rd(...) overload5(__VA_ARGS__, FOR5_R, FOR4_R, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)
#define trav(...) overload2(__VA_ARGS__, TRAV2, TRAV1)(__VA_ARGS__)
#define lb(...) overload1(__VA_ARGS__, LB1, LB2)(__VA_ARGS__)
#define ub(...) overload1(__VA_ARGS__, UB1, UB2)(__VA_ARGS__)
#define c0unt(...) overload1(__VA_ARGS__, CNT1, CNT2)(__VA_ARGS__)
#define pb push_back
#define eb emplace_back
#define ep emplace
#define ins insert
#define ers erase
#define beg begin()
#define ed end()
#define back back()
#define mkp make_pair
#define f first
#define s second
#define yes "YES"
#define no "NO"
#define printw(x) print(#x)
#define fun(type, name, ...) auto name = [&](__VA_ARGS__) -> type
#define recfun(type, name, ...) auto name = [&](auto &&name, __VA_ARGS__) -> type

int popcnt(int x) { return __builtin_popcount(x); }
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int popcnt(long long x) { return __builtin_popcountll(x); }
int topbit(long long x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int lowbit(long long x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

template <typename T> int sgn(const T &x) { return (x > 0 ? 1 : x < 0 ? -1 : 0); };
template <typename T, typename U> T ceil(T x, U y) { return (x > 0 ? (x + y - 1) / y : x / y); }
template <typename T, typename U> T floor(T x, U y) { return (x > 0 ? x / y : (x - y + 1) / y); }
template <class T, class S> bool chmx(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> bool chmn(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }

template <typename U> long long binser(U&& check, long long lo, long long hi, bool min) { long long ret = (min ? hi + 1 : lo - 1); for (long long mid = lo + (hi - lo) / 2; lo <= hi; mid = lo + (hi - lo) / 2) { bool chk = check(mid); (min == chk) ? (hi = mid - 1) : (lo = mid + 1); if (chk) ret = mid; } return ret; } template <typename T> void prfxsum(vector<T> &a) { int _n = a.size(); for (int i = 1; i < _n; i++) a[i] += a[i - 1]; }; template <typename T, typename U> vector<T> getorder(T start, T size, U comp) { vector<T> ord(size); iota(ord.begin(), ord.end(), start); sort(ord.begin(), ord.end(), comp); return ord; } template <typename T = int, typename U = int> map<T, U> mappos(const vector<T> &data, U offset) { map<T, U> ps; for (int i = 0; i < data.size(); i++) ps[data[i]] = i + offset; return ps; } template <typename T> map<T, int> counter(const vector<T> &data) { map<T, int> x; for (auto &i : data) x[i]++; return x; }; template <typename T, typename U> T toset(const vector<U> &data) { T x; for (auto &i : data) x.insert(i); return x; }; template <typename T, typename U> U safeErase(T &setik, U target) { auto iterator = setik.find(target); assert(iterator != setik.end()); U a = *iterator; setik.erase(iterator); return a; } template <typename T, typename U> pair<U, bool> Erase(T &setik, U target) { auto iterator = setik.find(target); pair<U, bool> a = {0, false}; if (iterator != setik.end()) { a.first = *iterator; setik.erase(iterator); } return a; } template <typename T> T pop(multiset<T> &que, bool front) { assert(que.empty() == false); auto iterator = front ? que.begin() : prev(que.end()); T a = *iterator; que.erase(iterator); return a; } template <typename T> T pop(set<T> &que, bool front = 1) { assert(que.empty() == false); auto iterator = front ? que.begin() : prev(que.end()); T a = *iterator; que.erase(iterator); return a; } template <typename T> T pop(stack<T> &que) { T a = que.top(); que.pop(); return a; } template <typename T> T pop(queue<T> &que) { T a = que.front(); que.pop(); return a; } template <typename T> T pop(deque<T> &que, bool front) { T a = (front ? que.front() : que.back()); (front ? que.pop_front() : que.pop_back()); return a; } template <typename T> T pop(priority_queue<T> &que) { T a = que.top(); que.pop(); return a; } template <typename T> T pop(priority_queue<T, vector<T>, greater<T>> &que) { T a = que.top(); que.pop(); return a; } template <typename T> T pop(vector<T> &que) { T a = que.back; que.pop_back(); return a; } template <typename T, typename U> constexpr T fpow(T x, U n) { T result = 1; while (n > 0) { if (n & 1ll) result *= x; x *= x; n >>= 1ll; } return result; } template <typename T> vector<T> divisors(T V) { vector<T> ret; for (int i = 1; (long long)i * i < V + 1; ++i) { if (V % i == 0) { ret.push_back(i); if (V / i != i) ret.push_back(V / i); } } return ret; }
vector<int> z_function(string s) {int n = s.size(); vector<int> z(n); int l = 0, r = 0; for(int i = 1; i < n; i++) {if(i < r) {z[i] = min(r - i, z[i - l]); } while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {z[i]++; } if(i + z[i] > r) {l = i; r = i + z[i]; } } return z; }

template <const int T> struct ModInt { const static int mod = T; int x; ModInt(int x = 0) : x(x % mod) {} ModInt(long long x) : x((int)x % mod) {} int val() { return x; } ModInt operator+(const ModInt &a) const { int x0 = x + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); } ModInt operator-(const ModInt &a) const { int x0 = x - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); } ModInt operator*(const ModInt &a) const { return ModInt(1ll * x * a.x % mod); } ModInt operator/(const ModInt &a) const { return *this * a.inv(); } void operator+=(const ModInt &a) { x += a.x; if (x >= mod) x -= mod; } void operator-=(const ModInt &a) { x -= a.x; if (x < 0) x += mod; } void operator*=(const ModInt &a) { x = 1LL * x * a.x % mod; } void operator/=(const ModInt &a) { *this = *this / a; } ModInt pow(int64_t n) const { ModInt res(1), mul(x); while (n) { if (n & 1) res *= mul; mul *= mul; n >>= 1; } return res; } ModInt inv() const { int a = x, b = mod, u = 1, v = 0; while (b) { int t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); } if (u < 0) u += mod; return u; } };
template <const int SZ> struct numb { static constexpr int M = SZ; int pc = 0; array<int, M> primes, lpf; bitset<M> isPrime; constexpr numb() { for (int i = 2; i < M; ++i) { if (!lpf[i]) { primes[pc++] = i; lpf[i] = i; isPrime[i] = 1; } for (int j = 0; j < pc && 1LL * i * primes[j] < M && primes[j] <= lpf[i]; j++) lpf[i * primes[j]] = primes[j]; } } pair<int, array<pair<int, int>, 30>> pfact(int V) { array<pair<int, int>, 30> ret; int sz = 0; for (int p = lpf[V], cnt = 0; V > 1; p = lpf[V], cnt = 0) { while (V % p == 0) V /= p, ++cnt; ret[sz++] = {p, cnt}; } return {sz, ret}; } };
template <typename MI, const int SZ> struct combi { static constexpr int M = SZ; array<MI, M> fact, invfact; constexpr combi() { fact[0] = invfact[0] = 1; for (int i = 1; i < M; i++) fact[i] = fact[i - 1] * i; invfact[M - 1] = fact[M - 1].inv(); for (int i = M - 2; i; i--) invfact[i] = invfact[i + 1] * (i + 1); } inline MI C(int a, int b) { if (a < 0 || b < 0 || a < b) return 0; return fact[a] * invfact[b] * invfact[a - b]; } };

template <typename T> struct prfx { vector<T> _a; int _n; prfx(const vector<T> &a) { _n = a.size() + 1; _a.resize(_n); for (int i = 0; i < _n - 1; i++) _a[i + 1] = _a[i] + a[i]; } T get(int x, int y) { if (y < x) return 0; return _a[y + 1] - _a[x]; } };
template <typename T, typename F> struct segt {vector<T> t; int N; T DF; F combine; segt(int n, T df, F fn) : N(n), DF(df), t(2 * n + 10), combine(fn) {for (auto &i : t) i = DF; } segt(const vector<T> &array, T df, F fn) : segt(array.size(), df, fn) {for (int i = 0; i < N; i++) t[i + N] = array[i]; for (int i = N - 1; i > 0; --i) t[i] = combine(t[i << 1], t[i << 1 | 1]); } void set(int p, T v) {for (t[p += N] = v; p >>= 1;) t[p] = combine(t[p << 1], t[p << 1 | 1]); } T get(int l, int r) {++r; T resl = DF, resr = DF; for (l += N, r += N; l < r; l >>= 1, r >>= 1) {if (l & 1) resl = combine(resl, t[l++]); if (r & 1) resr = combine(t[--r], resr); } return combine(resl, resr); } };
namespace atcoder { namespace internal { unsigned int bit_ceil(unsigned int n) { unsigned int x = 1; while (x < (unsigned int)(n)) x *= 2; return x; } int countr_zero(unsigned int n) { return __builtin_ctz(n); } constexpr int countr_zero_constexpr(unsigned int n) { int x = 0; while (!(n & (1 << x))) x++; return x; } } } namespace atcoder { template <class S, auto op, auto e, class F, auto mapping, auto composition, auto id> struct lazy_segtree { static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>, "op must work as S(S, S)"); static_assert(std::is_convertible_v<decltype(e), std::function<S()>>, "e must work as S()"); static_assert(std::is_convertible_v<decltype(mapping), std::function<S(F, S)>>, "mapping must work as F(F, S)"); static_assert(std::is_convertible_v<decltype(composition), std::function<F(F, F)>>, "compostiion must work as F(F, F)"); static_assert(std::is_convertible_v<decltype(id), std::function<F()>>, "id must work as F()"); public: lazy_segtree() : lazy_segtree(0) {} explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {} explicit lazy_segtree(const std::vector<S> &v) : _n(int32_t(v.size())) { size = (int)internal::bit_ceil((unsigned int)(_n)); log = internal::countr_zero((unsigned int)size); d = std::vector<S>(2 * size, e()); lz = std::vector<F>(size, id()); for (int i = 0; i < _n; i++) d[size + i] = v[i]; for (int i = size - 1; i >= 1; i--) { update(i); } } void set(int p, S x) { assert(0 <= p && p < _n); p += size; for (int i = log; i >= 1; i--) push(p >> i); d[p] = x; for (int i = 1; i <= log; i++) update(p >> i); } S get(int p) { assert(0 <= p && p < _n); p += size; for (int i = log; i >= 1; i--) push(p >> i); return d[p]; } S prod(int l, int r) { assert(0 <= l && l <= r && r <= _n); if (l == r) return e(); l += size; r += size; for (int i = log; i >= 1; i--) { if (((l >> i) << i) != l) push(l >> i); if (((r >> i) << i) != r) push((r - 1) >> i); } S sml = e(), smr = e(); while (l < r) { if (l & 1) sml = op(sml, d[l++]); if (r & 1) smr = op(d[--r], smr); l >>= 1; r >>= 1; } return op(sml, smr); } S all_prod() { return d[1]; } void apply(int p, F f) { assert(0 <= p && p < _n); p += size; for (int i = log; i >= 1; i--) push(p >> i); d[p] = mapping(f, d[p]); for (int i = 1; i <= log; i++) update(p >> i); } void apply(int l, int r, F f) { assert(0 <= l && l <= r && r <= _n); if (l == r) return; l += size; r += size; for (int i = log; i >= 1; i--) { if (((l >> i) << i) != l) push(l >> i); if (((r >> i) << i) != r) push((r - 1) >> i); } { int l2 = l, r2 = r; while (l < r) { if (l & 1) all_apply(l++, f); if (r & 1) all_apply(--r, f); l >>= 1; r >>= 1; } l = l2; r = r2; } for (int i = 1; i <= log; i++) { if (((l >> i) << i) != l) update(l >> i); if (((r >> i) << i) != r) update((r - 1) >> i); } } template <bool (*g)(S)> int max_right(int l) { return max_right(l, [](S x) { return g(x); }); } template <class G> int max_right(int l, G g) { assert(0 <= l && l <= _n); assert(g(e())); if (l == _n) return _n; l += size; for (int i = log; i >= 1; i--) push(l >> i); S sm = e(); do { while (l % 2 == 0) l >>= 1; if (!g(op(sm, d[l]))) { while (l < size) { push(l); l = (2 * l); if (g(op(sm, d[l]))) { sm = op(sm, d[l]); l++; } } return l - size; } sm = op(sm, d[l]); l++; } while ((l & -l) != l); return _n; } template <bool (*g)(S)> int min_left(int r) { return min_left(r, [](S x) { return g(x); }); } template <class G> int min_left(int r, G g) { assert(0 <= r && r <= _n); assert(g(e())); if (r == 0) return 0; r += size; for (int i = log; i >= 1; i--) push((r - 1) >> i); S sm = e(); do { r--; while (r > 1 && (r % 2)) r >>= 1; if (!g(op(d[r], sm))) { while (r < size) { push(r); r = (2 * r + 1); if (g(op(d[r], sm))) { sm = op(d[r], sm); r--; } } return r + 1 - size; } sm = op(d[r], sm); } while ((r & -r) != r); return 0; } private: int _n, size, log; std::vector<S> d; std::vector<F> lz; void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); } void all_apply(int k, F f) { d[k] = mapping(f, d[k]); if (k < size) lz[k] = composition(f, lz[k]); } void push(int k) { all_apply(2 * k, lz[k]); all_apply(2 * k + 1, lz[k]); lz[k] = id(); } }; }
template <typename T> struct fenwt { vector<T> bit; int n; fenwt(int n) { this->n = n; bit.resize(n, 0); } fenwt(vector<T> const &a) : fenwt(a.size()) { for (size_t i = 0; i < a.size(); i++) add(i, a[i]); } T query(int r) { T ret = 0; for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r]; return ret; } T query(int l, int r) { return query(r) - query(l - 1); } void add(int idx, T delta) { for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta; } };
struct dsu { vector<int> parent, size; dsu(int n) { parent.resize(n); size.resize(n); } void makeset(int v) { parent[v] = v; size[v] = 1; } bool combine(int a, int b) { a = find(a), b = find(b); if (a == b) return false; if (size[a] < size[b]) swap(a, b); parent[b] = a, size[a] += size[b]; return true; }; int find(int v) { if (v == parent[v]) return v; return parent[v] = find(parent[v]); } };
struct lowca { int n, l, timer; vector<vector<int>> adj; vector<int> tin, tout; vector<vector<int>> up; vector<int> depth; lowca(int n_, const vector<vector<int>> &g, int root_ = 0) : n(n_), tin(n), tout(n), up(n), depth(n) { adj = g; preprocess(root_); }; private: void dfs(int v, int p, int dpt) { depth[v] = dpt; tin[v] = ++timer; up[v][0] = p; for (int i = 1; i <= l; ++i) up[v][i] = up[up[v][i - 1]][i - 1]; for (int u : adj[v]) { if (u != p) dfs(u, v, dpt + 1); } tout[v] = ++timer; } void preprocess(int root) { tin.resize(n); tout.resize(n); timer = 0; l = ceil(log2(n)); up.assign(n, vector<int>(l + 1)); dfs(root, root, 0); } public: bool is_ancestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; } int lca(int u, int v) { if (is_ancestor(u, v)) return u; if (is_ancestor(v, u)) return v; for (int i = l; i >= 0; --i) { if (!is_ancestor(up[u][i], v)) u = up[u][i]; } return up[u][0]; } int kth_ancestor(int u, int k) { while (k) { int t = __builtin_ctz(k); u = up[u][t], k ^= 1 << t; } return u; } int kth_node_on_path(int u, int v, int k) { int lc = lca(u, v); int tn = depth[u] + depth[v] - 2 * depth[lc] + 1; if (depth[u] - depth[lc] + 1 >= k) return kth_ancestor(u, k - 1); return kth_ancestor(v, tn - k); } int total_nodes_on_path(int u, int v) { int lc = lca(u, v); return depth[u] + depth[v] - 2 * depth[lc] + 1; } int distance(int u, int v) { return total_nodes_on_path(u, v) - 1; } };

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<long long>(a, b)(rng)

constexpr int mod0 = 998244353;
constexpr int mod1 = 1e9 + 7;
constexpr int imx = INT_MAX;
constexpr int imn = INT_MIN;
constexpr long long lmx = LLONG_MAX;
constexpr long long lmn = LLONG_MIN;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
constexpr char nl = '\n';

using mint0 = ModInt<mod0>;
using mint1 = ModInt<mod1>;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<long long>;
using vvl = vector<vector<long long>>;
using vpi = vector<pair<int, int>>;
using vpl = vector<pair<long long, long long>>;
using pi = pair<int, int>;
using pl = pair<long long, long long>;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T> using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using vc = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using qu = queue<T>;
template <typename T> using dq = deque<T>;
template <typename T> using stk = stack<T>;
template <typename T1, typename T2> using pr = pair<T1, T2>;
template <typename T> using mst = multiset<T>;
template <typename Key, typename T> using ump = unordered_map<Key, T>;
template <typename T> using ust = unordered_set<T>;
template <typename T> using mpq = priority_queue<T, vector<T>, greater<T>>;
template <typename T, int N> using ar = array<T, N>;

int tt = 1; void solve(); void presolve(); int main() { cin.tie(0)->ios_base::sync_with_stdio(false); presolve(); f0r(tt) SOLVE; };

// clang-format on

void presolve() {}

void solve() {
    int(n) vec(int, a, n);
    vvi x(3);
    {
        vi idx;
        f0r(i, n) if (a[i] && (idx.empty() || a[idx.back] != a[i])) idx.pb(i);
        int sz = len(idx);
        f0r(i, 1, sz) {
            if (a[idx[i]] != 3 && a[idx[i - 1]] != 3)
                x[0].pb(idx[i]);
            if (i > 1 && a[idx[i - 2]] == 3 && a[idx[i]] != 3)
                x[1 + (a[idx[i - 1]] == 2)].pb(idx[i]);
        }
        f0r(i, 3) x[i].pb(n);
    }
    vl pfz(n);
    {
        int cnt = 0;
        f0r(i, n) {
            cnt += (!a[i]);
            pfz[i] = cnt;
        }
    }
    vi nxt(n, n);
    {
        stk<int> st;
        f0r(i, n) {
            st.push(i);
            while (!st.empty() && a[i])
                nxt[pop(st)] = i;
        }
    }
    ll ans = 0, sm = sum(pfz);
    f0r(_, n) {
        ans += sm - (n - _) * 1ll * (_ > 0 ? pfz[_ - 1] : 0ll);
        sm -= pfz[_];
        int i = nxt[_];
        coif(i == n);
        int r1 = *ub(x[0], i);
        ans += (r1 - i) + 2ll * (n - r1);
        if (r1 < n) {
            int r2 = *ub(x[1 + (a[r1] == 2)], r1);
            ans += (n - r2);
        }
    }
    print(ans);
}