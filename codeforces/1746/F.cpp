#pragma GCC optimize "tree-vectorize,unroll-loops"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <bitset>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() const { T t; cin >> t; return t; } operator X() const { return operator()(); } template <typename T> operator T() const { return operator()<T>(); } template <auto=0> string operator~() const { return *this; } char operator!() const { return *this; } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
auto operator>>(istream& in, auto&& p) -> decltype(p.first, p.second, in) { return in >> p.first >> p.second; }
auto operator<<(ostream& out, const auto& p) -> decltype(p.first, p.second, out) { return out << p.first << ' ' << p.second; }
template <typename It> struct range { It first, last; constexpr range() {} constexpr range(It first, It last) : first{first}, last{last} {} constexpr range(It first, auto n) : range{first, first + n} {} constexpr range(auto&& c) : range{c.begin(), c.end()} {} constexpr It begin() const { return first; } constexpr It end() const { return last; } constexpr int size() const { return last - first; } constexpr const auto& operator[](int i) const { return first[i]; } constexpr auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
template <int from, int which> auto getfield(const auto& a) -> const auto& { static_assert(1 <= which && which <= from && from <= 5); auto fix = [](auto& x) -> auto& { return x; }; if constexpr (from == 1) { if constexpr (is_scalar_v<decay_t<decltype(a)>>) { if constexpr (which == 1) return fix(a); } else { auto& [a1] = a; if constexpr (which == 1) return fix(a1); } } else if constexpr (from == 2) { auto& [a1, a2] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); } else if constexpr (from == 3) { auto& [a1, a2, a3] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); } else if constexpr (from == 4) { auto& [a1, a2, a3, a4] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); if constexpr (which == 4) return fix(a4); } else if constexpr (from == 5) { auto& [a1, a2, a3, a4, a5] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); if constexpr (which == 4) return fix(a4); if constexpr (which == 5) return fix(a5); } }
template <int from, int which> struct GetField { decltype(auto) operator()(const auto& a) { return getfield<from, which>(a); } };
template <int from, int which, typename Cmp = equal_to<>> struct CompareField { bool operator()(const auto& a, const auto& b) const { return Cmp{}(getfield<from, which>(a), getfield<from, which>(b)); } };
template <int from, int which, int... whichs> struct Ordering { bool operator()(const auto& a, const auto& b) const { auto& aa = getfield<from, labs(which)>(a), & bb = getfield<from, labs(which)>(b); if (aa < bb) { return which > 0; } else if (bb < aa) { return which < 0; } else if constexpr (sizeof...(whichs)) { return Ordering<from, whichs...>{}(a, b); } return 0; } };
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (0 < a) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }
void lshift(auto& first, auto& second, auto&... args) { first = second; if constexpr (sizeof...(args)) lshift(second, args...); } void rshift(auto& first, auto& second, auto&... args) { if constexpr (sizeof...(args)) rshift(second, args...); second = first; }
void lrotate(auto& arg, auto&... args) { auto t = arg; lshift(arg, args...); ([](auto&t)->auto&{return t;}(args), ...) = t; } void rrotate(auto& arg, auto&... args) { auto t = ([](auto&t)->auto&{return t;}(args), ...); rshift(arg, args...); arg = t; }
template <typename T, typename Cmp = greater<>> using PQ = priority_queue<T, vector<T>, Cmp>;

#include <chrono>
struct Hash {
  static uint64_t& global_seed() { static uint64_t global_seed = chrono::steady_clock::now().time_since_epoch().count(); return global_seed; }

  Hash(uint64_t seed = 0) : seed{seed += global_seed() += 0x9e3779b97f4a7c15} {
  }

  size_t operator()(uint64_t x) const {
    x += seed;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  const uint64_t seed;
} hsh;

constexpr int R = 20, N = 3e5;
using Trace = array<uint32_t, R + 1>;

Trace& operator+=(Trace& __restrict val, const Trace& arg) {
  for (int i = 0; i < R; ++i) {
    val[i] += arg[i];
  }
  val[R] ^= arg[R];
  return val;
}

Trace& operator-=(Trace& __restrict val, const Trace& arg) {
  for (int i = 0; i < R; ++i) {
    val[i] -= arg[i];
  }
  val[R] ^= arg[R];
  return val;
}

struct FT {
  using T = Trace;
  static constexpr int N = ::N;

  T& op(T& val, const T& arg) {
    return val += arg;
  }

  void build() {
    for (int i = 0; i < N; ++i) if ((i | i + 1) < N) {
      op(ft[i | i + 1], ft[i]);
    }
  }

  void update(int i, T val) {
    for (; i < N; i |= i + 1) {
      op(ft[i], val);
    }
  }

  T query(int l, int r) {
    T res{};
    for (; r != l; ) {
      if (r > l) res += ft[r - 1], r &= r - 1;
      else       res -= ft[l - 1], l &= l - 1;
    }
    return res;
  }

//private:
  T ft[N];
} ft;

Trace gentrace(int x) {
  Trace res{};
  auto t = hsh(x * 2);
  for (int i = 0; i < R; ++i) {
    res[i] = t & 3;
    t /= 4;
  }
  res[R] = hsh(x * 2 + 1);
  return res;
}

int a[N];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int n = $, q = $;
  for (int i = 0; i < n; ++i) {
    ft.ft[i] = gentrace(a[i] = $);
  }
  ft.build();
  while (q--) {
    if ($ == 1) {
      int i = $ - 1, x = $;
      auto upd = gentrace(x);
      upd -= gentrace(a[i]);
      ft.update(i, upd);
      a[i] = x;
    } else {
      int l = $ - 1, r = $, k = $;
      bool ok = 1;
      Trace t = ft.query(l, r);
      uint64_t ik = -1u / k;
      for (int i = 0; i < R; ++i) {
        auto d = t[i] * ik + -1u >> 32;
        ok &= d * k == t[i];
      }
      if (k % 2 == 0) ok &= t[R] == 0;
      print(ok? "YES": "NO");
    }
  }
}
