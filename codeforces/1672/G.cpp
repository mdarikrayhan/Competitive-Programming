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

const int MOD = 998244353;
using Mint = Integral<MOD>;

//-#include "mod.hpp"



struct Dsu {
  int n = 0;
  std::vector<int> dsu;
  std::vector<int> P, Q;

  Dsu() = default;

  explicit Dsu(int n) : n(n), dsu(n), P(n), Q(n) {
    std::iota(dsu.begin(), dsu.end(), 0);
  }
  int size() const { return n; }
  int find(int x) { return dsu[x] == x ? x : dsu[x] = find(dsu[x]); }
  bool same(int x, int y) { x = find(x); y = find(y); return x == y; }

  bool merge(int x, int y) { return merge_from(x, y); }

  bool merge_from(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    dsu[y] = x;
    P[x] ^= P[y];
    Q[x] += Q[y];
    return true;
  }
};

//-#include "dsu.hpp"


struct Solver {

  void solve(int ca, std::istream& reader) {
    auto calc = [](auto&& self, int N, int M, std::vector<std::string> B) -> Mint {
      if ((~N & 1) && (~M & 1)) {
        int z = 0;
        for (int i = 0; i < N; ++i) {
          for (int j = 0; j < M; ++j) {
            z += B[i][j] == '?';
          }
        }
        return power<Mint>(2, z);
      }
      if ((~N & 1) && (M & 1)) {
        Mint ret = 1;
        for (int i = 0; i < N; ++i) {
          int z = 0, w = 0;
          for (int j = 0; j < M; ++j) {
            if (B[i][j] == '?') {
              ++z;
            } else if (B[i][j] == '1') {
              w ^= 1;
            }
          }
          if (z == 0) {
            if (w) return 0;
          } else {
            ret *= power<Mint>(2, z - 1);
          }
        }
        return ret;
      }
      if ((N & 1) && (~M & 1)) {
        std::vector<std::string> C(M, std::string(N, 0));
        for (int i = 0; i < N; ++i) {
          for (int j = 0; j < M; ++j) {
            C[j][i] = B[i][j];
          }
        }
        return self(self, M, N, C);
      }

      Dsu dsu(N + M);
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
          if (B[i][j] == '1') {
            int u = dsu.find(i);
            dsu.P[u] ^= 1;
            int v = dsu.find(N + j);
            dsu.P[v] ^= 1;
          } else if (B[i][j] == '?') {
            int u = dsu.find(i);
            int v = dsu.find(N + j);
            if (u != v) {
              dsu.merge(u, v);
            } else {
              dsu.Q[u]++;
            }
          }
        }
      }
      Mint ret = 1;
      for (int u = 0; u < dsu.size(); ++u) if (dsu.find(u) == u) {
        if (dsu.P[u]) return 0;
        ret *= power<Mint>(2, dsu.Q[u]);
      }
      return ret;
    };
    int N, M;
    reader >> N >> M;
    std::vector<std::string> B(N);
    for (int i = 0; i < N; ++i) {
      reader >> B[i];
    }
    Mint result = calc(calc, N, M, B);
    if ((N & 1) || (M & 1)) {
      for (int j = 0; j < M; ++j) if (B[0][j] != '?') {
        B[0][j] = ((B[0][j] - '0') ^ 1) + '0';
      }
      for (int i = 1; i < N; ++i) if (B[i][0] != '?') {
        B[i][0] = ((B[i][0] - '0') ^ 1) + '0';
      }
      result += calc(calc, N, M, B);
    }
    printf("%d\n", result.val());

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

