#include "bits/stdc++.h"
#ifndef ALGO
#define DUMP(...)
#endif
using i64 = long long;
template<typename T, typename U>
inline bool enlarge(T& a, U b) {
  return a < b ? (a = b, true) : false;
}
template<typename T, typename U>
inline bool minify(T& a, U b) {
  return a > b ? (a = b, true) : false;
}





namespace power_details {
template<typename T, typename Enable = void>
struct Identity { static constexpr T get() { return T{1}; } };
template<typename T>
struct Identity<T, std::void_t<decltype(T::identity())>> {
  static constexpr T get() { return T::identity(); }
};
}  // namespace power_details

template<typename T,
         typename MulFunc = std::function<T(T,T)>,
         typename SqrFunc = std::function<T(T)>>
constexpr T power(T a, long long b, MulFunc&& mul, SqrFunc&& sqr) {
  T ret = sqr(power_details::Identity<T>::get());
  for (; b; b >>= 1, a = sqr(a)) if (b & 1) ret = mul(ret, a);
  return ret;
}
template<typename T, typename MulFunc = std::function<T(T,T)>>
constexpr T power(T a, long long b, MulFunc&& mul) {
  return power(a, b, std::forward<MulFunc>(mul), [&](T x) { return mul(x, x); });
}
template<typename T, typename IT = T>
constexpr T power(T a, long long b, T mod) {
  return power(a, b, [&mod](T x, T y) { return static_cast<IT>(x) * y % mod; });
}
template<typename T>
constexpr T power(T a, long long b) {
  return power(a, b, [](T x, T y) { return x * y; });
}

template<typename T>
struct PowerTable final : public std::vector<T> {
  PowerTable() = default;
  PowerTable(int n, const T& g)
    : PowerTable(n, g, [](const T& lhs, const T& rhs) -> T { return lhs * rhs; }) {}
  template<typename MulFunc = std::function<T(T,T)>>
  PowerTable(int n, const T& g, MulFunc&& mul) {
    static_assert(sizeof(PowerTable) == sizeof(std::vector<T>), "");
    this->resize(n + 1);
    this->at(0) = power_details::Identity<T>::get();
    for (int i = 1; i < this->size(); ++i) this->at(i) = mul(this->at(i - 1), g);
  }
};

//-#include "power.hpp"


namespace mod_wrapper_details {
template<typename T, typename U, typename Enable = void>
struct HasWrap : std::false_type {};
template<typename T, typename U>
struct HasWrap<T, U, std::void_t<decltype(T::wrap(std::declval<U>()))>> : std::true_type {};
}  // namespace mod_wrapper_details

template<typename Kernel>
class ModWrapper {
 public:
  static constexpr int get_mod() { return Kernel::get_mod(); }
  static void set_mod(int m) { Kernel::set_mod(m); }

  // Implicit conversion is allowed.
  ModWrapper(int v) : v_(wrap(norm(v))) {}
  ModWrapper(long long v) : v_(wrap(norm(v))) {}
  ModWrapper(unsigned int v) : v_(wrap(norm(v))) {}
  ModWrapper(unsigned long long v) : v_(wrap(norm(v))) {}

  ModWrapper() = default;
  ~ModWrapper() = default;

  // Explicit conversion to other type.
  template<typename T>
  explicit operator T() const {
    if constexpr(std::is_same<T, bool>::value) {
      return static_cast<T>(v_);
    } else {
      return static_cast<T>(unwrap(v_));
    }
  }

  int val() const { return unwrap(v_); }
  ModWrapper& operator+=(const ModWrapper& rhs) { Kernel::add(v_, rhs.v_); return *this; }
  ModWrapper& operator-=(const ModWrapper& rhs) { Kernel::sub(v_, rhs.v_); return *this; }
  ModWrapper& operator*=(const ModWrapper& rhs) { Kernel::mul(v_, rhs.v_); return *this; }
  ModWrapper& operator/=(const ModWrapper& rhs) { Kernel::mul(v_, rhs.inv().v_); return *this; }
  ModWrapper operator+(const ModWrapper& rhs) const { ModWrapper ret = *this; return ret += rhs; }
  ModWrapper operator-(const ModWrapper& rhs) const { ModWrapper ret = *this; return ret -= rhs; }
  ModWrapper operator*(const ModWrapper& rhs) const { ModWrapper ret = *this; return ret *= rhs; }
  ModWrapper operator/(const ModWrapper& rhs) const { ModWrapper ret = *this; return ret /= rhs; }
  bool operator==(const ModWrapper& rhs) const { return val() == rhs.val(); }
  bool operator!=(const ModWrapper& rhs) const { return !(*this == rhs); }
  const ModWrapper operator-() const { ModWrapper ret{0}; Kernel::sub(ret.v_, v_); return ret; }
  const ModWrapper& operator++() { Kernel::add(v_, ModWrapper{1}.v_); return *this; }
  const ModWrapper operator++(int) { ModWrapper ret = *this; ++(*this); return ret; }
  const ModWrapper& operator--() { Kernel::sub(v_, ModWrapper{1}.v_); return *this; }
  const ModWrapper operator--(int) { ModWrapper ret = *this; --(*this); return ret; }

  ModWrapper power(long long b) const { return ::power(*this, b); }
  ModWrapper inv() const {
    return power(Kernel::get_mod() - 2);
  }

  std::string to_string() const { return std::string("{") + std::to_string(val()) + "}"; }

 private:
  using StorageType = typename Kernel::StorageType;

  template<typename T>
  static T norm(T v) {
    const int MOD = Kernel::get_mod();
    if constexpr(sizeof(T) > sizeof(MOD)) {
      v %= MOD;
      if (v < 0) v += MOD;
    } else {
      if (v >= MOD) v -= MOD;
      if (v < 0) v += MOD;
      if (v >= MOD || v < 0) {
        v %= MOD;
        if (v < 0) v += MOD;
      }
    }
    return v;
  }

  static constexpr StorageType wrap(int x) {
    if constexpr(mod_wrapper_details::HasWrap<Kernel, StorageType>()) {
      return Kernel::wrap(x);
    } else {
      return static_cast<StorageType>(x);
    }
  }

  static constexpr int unwrap(StorageType x) {
    if constexpr(mod_wrapper_details::HasWrap<Kernel, StorageType>()) {
      return Kernel::unwrap(x);
    } else {
      return static_cast<int>(x);
    }
  }

  StorageType v_{};
};

template<typename Kernel>
std::string to_string(const ModWrapper<Kernel>& v) {
  return v.to_string();
}

//-#include "mod_wrapper.hpp"


namespace integral_details {

template<int MOD>
struct IntegralKernel {
  using StorageType = int;
  static constexpr void add(int& x, int y) { if ((x += y) >= MOD) x -= MOD; }
  static constexpr void sub(int& x, int y) { if ((x += MOD - y) >= MOD) x -= MOD; }
  static constexpr void mul(int& x, int y) { x = static_cast<int64_t>(x) * y % MOD; }
  static constexpr int get_mod() { return MOD; }
};

}  // namespace integral_details

template<int MOD>
using Integral = ModWrapper<integral_details::IntegralKernel<MOD>>;

// const int MOD = 998244353;
// using Mint = Integral<MOD>;

//-#include "mod.hpp"




template<typename T>
struct InvTable final : std::vector<T> {
  explicit InvTable(int n = 0) : InvTable(n, [](int i) { return T{i}; }) {}
  explicit InvTable(const std::vector<T>& arr) { make(arr); }
  template<typename GetTerm>
  InvTable(int n, GetTerm&& get_term) {
    std::vector<T> arr(n);
    for (int i = 0; i < n; ++i) arr[i] = get_term(i);
    make(arr);
  }
  void make(const std::vector<T>& arr) {
    int n = arr.size();
    std::vector<T>::assign(arr.begin(), arr.end());
    for (int i = 0, j = 1; i < n; i = j++) if (arr[i]) {
      for (; j < n && arr[j]; ++j) (*this)[j] *= (*this)[j - 1];
      T w = T{1} / (*this)[j - 1];
      for (int t = j - 1; t > i; w *= arr[t--]) (*this)[t] = w * (*this)[t - 1];
      (*this)[i] = w;
    }
  }
};

//-#include "inv_table.hpp"


template<typename T>
struct Binomial final {
  std::vector<T> fact;
  InvTable<T> inv_fact;

  explicit Binomial(int n = 0) : fact(n + 1) {
    assert(0 <= n && n < T::get_mod());
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
    inv_fact = InvTable<T>(fact);
  }
  ~Binomial() = default;

  // binom(0,0) == 1,
  // binom(*,b) == 0 if b < 0.
  template<typename U, typename V>
  T operator()(U a, V b) const {
    if (a < 0 && b >= 0) {
      if (a == -1) return T{b & 1 ? -1 : 1};
      return T{b & 1 ? -1 : 1} * (*this)(-a + b - 1, b);
    }
    if (a < b || b < 0) return 0;
    if (a >= fact.size()) throw std::out_of_range("Binomial");
    return fact[a] * inv_fact[b] * inv_fact[a - b];
  }

  template<typename U, typename V>
  T brute(U a, V b) const {
    if (a < 0 && b >= 0) {
      return T{b & 1 ? -1 : 1} * brute(-a + b - 1, b);
    }
    if (a < b || b < 0) return 0;
    b = std::min(b, a - b);
    T ret = 1;
    for (U i = 1; i <= b; ++i) ret = ret * (a + 1 - i) * inv(i);
    return ret;
  }

  template<typename U, typename V>
  T lucas(U a, V b) const {
    if (a < 0 && b >= 0) {
      if (a == -1) return T{b & 1 ? -1 : 1};
      return T{b & 1 ? -1 : 1} * lucas(-a + b - 1, b);
    }
    if (a < b || b < 0) return 0;
    const int MOD = T::get_mod();
    if (a < MOD) return (*this)(a, b);
    return (*this)(a % MOD, b % MOD) * lucas(a / MOD, b / MOD);
  }

  template<typename U>
  T inv(U x) const {
    assert(x > 0);
    if (x < fact.size()) return inv_fact[x] * fact[x - 1];
    return T{1} / x;
  }
};

//-#include "binomial.hpp"

using Mint = Integral<1'000'000'007>;

struct Solver {

  void solve(int ca, std::istream& reader) {
    int N, M;
    reader >> N >> M;
    std::vector<bool> vis(M);
    for (int i = 0; i < N; ++i) {
      int x;
      reader >> x;
      vis[x] = true;
    }
    printf("%d\n", (solve(M, std::count(vis.begin(), vis.end(), true)) + N).val());
  }

  Mint solve(int M, int P) {
    int Q = M - P;
    std::vector<std::vector<Mint>> f(P + 1, std::vector<Mint>(M + 1));
    std::vector<std::vector<Mint>> g(P + 1, std::vector<Mint>(M + 1));
    std::vector<std::vector<Mint>> h(P + 1, std::vector<Mint>(M + 1));
    Binomial<Mint> binom(M + 10);
    for (int p = 1; p <= P; ++p) {
      for (int r = p + Q; r >= 0; --r) {
        if (p + Q - r - 1 > 0) {
          h[p][r] += (h[p][r + 1] + 2) * (p + Q - r - 1) * binom.inv(p + Q - r);
        }
        if (p + Q - r > 0) {
          h[p][r] += f[p - 1][r] * binom.inv(p + Q - r);
        }
        if (r - 1 > 0 && p + Q - 1 > 0) {
          g[p][r] += f[p - 1][r - 1] * (r - 1) * binom.inv(p + Q - 1);
        }
        if (p + Q - r > 0 && p + Q - 1 > 0) {
          g[p][r] += h[p][r] * (p + Q - r) * binom.inv(p + Q - 1);
        }
        if (p + Q > 0 && r > 0) {
          f[p][r] += f[p - 1][r - 1] * r * binom.inv(p + Q);
        }
        if (p + Q > 0 && p + Q - r > 0) {
          f[p][r] += h[p][r] * (p + Q - r) * binom.inv(p + Q);
        }
      }
    }
    DUMP(f);
    DUMP(g);
    DUMP(h);
    Mint ret = 0;
    for (int i = 0; i < P; ++i) {
      ret += (f[P - i][0] + 1 + (i != 0)) * binom.inv_fact[M + 1] * binom.fact[M - i];
    }
    DUMP(ret);
    for (int i = 0; i < P; ++i) {
      for (int j = 1; i + j <= M; ++j) {
        ret += (g[P - i][j] + j * 2) * (M - i - 1) *\
               binom.fact[M - i - 1] * binom.inv_fact[M - i - j] *\
               binom.inv_fact[M + 1] * binom.fact[M - i - j];
      }
    }
    DUMP(ret);
    return ret;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::istream& reader = std::cin;

  int cas = 1;
  // reader >> cas;
  for (int ca = 1; ca <= cas; ++ca) {
    auto solver = std::make_unique<Solver>();
    solver->solve(ca, reader);
  }
}

