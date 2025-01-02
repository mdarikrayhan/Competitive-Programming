/**
  * created     : 14.05.2024 13:56:55
  * author      : wzj33300
  */

#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include <algo/debug.h>
#else
#define debug(...) 42
#define assert(...) 42
#endif

using ll = long long;
using db = long double;  // or double, if TL is tight
using str = string;      // yay python!

// pairs
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define mp make_pair
#define fi first
#define se second

// ^ lol this makes everything look weird but I'll try it
template <class T>
using V = vector<T>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
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

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)

#define lb lower_bound
#define ub upper_bound
template <class T>
int lwb(V<T> &a, const T &b) {
  return int(lb(all(a), b) - bg(a));
}
template <class T>
int upb(V<T> &a, const T &b) {
  return int(ub(all(a), b) - bg(a));
}
// const int MOD = 998244353;  // 1e9+7;
const int Big = 1e9;  // not too close to INT_MAX
const ll BIG = 1e18;  // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); }  // # of bits set
constexpr ll pct(ll x) { return __builtin_popcountll(x); }  // # of bits set
constexpr int bits(int x) {  // assert(x >= 0); // make C++11 compatible until
                             // USACO updates ...
  return x == 0 ? 0 : 31 - __builtin_clz(x);
}  // floor(log2(x))
constexpr ll bits(ll x) {  // assert(x >= 0); // make C++11 compatible until
                           // USACO updates ...
  return x == 0 ? 0 : 63 - __builtin_clzll(x);
}  // floor(log2(x))
constexpr int p2(int x) { return 1 << x; }
constexpr ll p2L(int x) { return 1ll << x; }
constexpr int msk2(int x) { return p2(x) - 1; }
constexpr ll msk2L(int x) { return p2L(x) - 1; }

ll cdiv(ll a, ll b) {
  return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
  return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}  // set a = min(a,b)
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}  // set a = max(a,b)

template <class T, class U>
T fstTrue(T lo, T hi, U f) {
  ++hi;
  assert(lo <= hi);  // assuming f is increasing
  while (lo < hi) {  // find first index such that f is true
    T mid = lo + (hi - lo) / 2;
    f(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}
template <class T, class U>
T lstTrue(T lo, T hi, U f) {
  --lo;
  assert(lo <= hi);  // assuming f is decreasing
  while (lo < hi) {  // find first index such that f is true
    T mid = lo + (hi - lo + 1) / 2;
    f(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}

void _sol() {
  int n, x;
  cin >> n >> x;
  vi a(n), b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  sort(all(a)), sort(all(b), greater());
  int ok = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] + b[i] > x) ok = 0;
  }
  cout << (ok ? "Yes" : "No") << endl;
}

// signed main() {
int main() {
  // freopen(".in", "r",stdin);
  // freopen(".out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    _sol();
  }
  return 0;
}