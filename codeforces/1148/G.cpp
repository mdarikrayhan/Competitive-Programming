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


struct PrimeTable {
  std::vector<int> primes;
  std::vector<int> min_div;

  PrimeTable() = default;
  explicit PrimeTable(int n) { make(n); }

  void make(int n) {
    if (n < 1) return;
    primes.clear();
    min_div.assign(n + 1, 0);
    min_div[1] = 1;
    for (int i = 2; i <= n; ++i) {
      if (!min_div[i]) {
        primes.emplace_back(i);
        min_div[i] = i;
      }
      for (int p : primes) {
        if (i * p > n) break;
        min_div[i * p] = p;
        if (i % p == 0) break;
      }
    }
  }

  template<typename T>
  bool is_prime(T x) const {
    if (x < 2) return false;
    if (x < min_div.size()) return min_div[x] == x;
    for (int p : primes) {
      if (p * 1LL * p > x) break;
      if (x % p == 0) return false;
    }
    for (T w = std::max<T>(2, min_div.size()); w * 1LL * w <= x; ++w) {
      if (x % w == 0) return false;
    }
    return true;
  }

  template<typename T>
  std::vector<typename std::pair<T, T>> get_canonical_representation(T x) const {
    assert(x >= 1);
    std::vector<typename std::pair<T, T>> ret;  // <prime, cnt>
    for (int p : primes) {
      if (p * 1LL * p > x) break;
      if (x < min_div.size()) break;
      if (x % p == 0) {
        T cnt = 0;
        while (x % p == 0) ++cnt, x /= p;
        ret.emplace_back(p, cnt);
      }
    }
    for (T i = min_div.size(); x >= min_div.size() && i * 1LL * i <= x; ++i) if (i > 1 && x % i == 0) {
      T cnt = 0;
      while (x % i == 0) ++cnt, x /= i;
      ret.emplace_back(i, cnt);
    }
    while (1 < x && x < min_div.size()) {
      T p = min_div[x];
      T cnt = 0;
      while (x % p == 0) ++cnt, x /= p;
      ret.emplace_back(p, cnt);
    }
    if (x >= min_div.size() && x > 1) {
      ret.emplace_back(x, 1);
    }
    return ret;
  }

  template<typename T>
  std::vector<T> get_factors(T x) const {  // Note: Not in ascending order.
    assert(x >= 1);
    const std::vector<typename std::pair<T, T>> repr = get_canonical_representation(x);
    std::vector<T> factors;
    auto rec = [&](auto self, int at, T val) -> void {
      factors.emplace_back(val);
      for (int i = at; i < repr.size(); ++i) {
        T tmp = val;
        for (int j = 0; j < repr[i].second; ++j) {
          tmp *= repr[i].first;
          self(self, i + 1, tmp);
        }
      }
    };
    rec(rec, 0, 1);
    return factors;
  }

  template<typename T>
  std::vector<T> get_factors_with_nonzero_mu(T x) const {  // Note: Not in ascending order.
    assert(x >= 1);
    const std::vector<typename std::pair<T, T>> repr = get_canonical_representation(x);
    std::vector<T> factors;
    auto rec = [&](auto self, int at, T val) -> void {
      factors.emplace_back(val);
      for (int i = at; i < repr.size(); ++i) {
        self(self, i + 1, val * repr[i].first);
      }
    };
    rec(rec, 0, 1);
    return factors;
  }

  // Find the minimum k s.t. x^k == 1 mod P.
  template<typename T>
  T get_order(T x, T P) const {
    return get_order(x, P, get_canonical_representation(P - 1));
  }
  template<typename T>
  T get_order(T x, T P, const std::vector<typename std::pair<T, T>>& P_minus_1_repr) const {
    T M = P - 1;
    for (auto [p, b] : P_minus_1_repr) {
      while (M % p == 0 && power(x, M / p, P) == 1) {
        M /= p;
      }
    }
    return M;
  }
};

//-#include "prime_table.hpp"



struct MuTable final : public std::vector<int8_t> {
  MuTable() = default;
  explicit MuTable(int n) : MuTable(PrimeTable(n)) {}
  explicit MuTable(const PrimeTable& pt) {
    int n = (int)pt.min_div.size() - 1;
    if (n < 1) return;
    this->assign(n + 1, 0);
    (*this)[1] = 1;
    for (int i = 2; i <= n; ++i) {
      int md = pt.min_div[i];
      if (i / md % md != 0) {
        (*this)[i] = -(*this)[i / md];
      }
    }
  }
};

//-#include "mu_table.hpp"


PrimeTable pt(10'000'000);
MuTable mu(pt);

std::mt19937 rng(clock());

struct Solver {

  void solve(int ca, std::istream& reader) {
    int N, K;
    reader >> N >> K;
    std::vector<std::vector<int>> B(N);
    for (int i = 0; i < N; ++i) {
      int a;
      reader >> a;
      B[i] = pt.get_factors_with_nonzero_mu(a);
    }

    using Table = std::unordered_map<int, int>;
    auto calc = [&](const Table& table, int id) -> int {
      int ret = 0;
      for (int d : B[id]) {
        if (auto iter = table.find(d); iter != table.end()) {
          ret += iter->second * mu[d];
        }
      }
      return ret;
    };
    auto add = [&](Table& table, int id) -> void {
      for (int d : B[id]) {
        table[d]++;
      }
    };

    std::vector<int> ind, other;
    {
      Table table;
      for (int i = 0; i < N; ++i) {
        if (calc(table, i) == 0) {
          ind.emplace_back(i);
          add(table, i);
        } else {
          other.emplace_back(i);
        }
      }
    }
    if (ind.size() >= K) {
      ind.resize(K);
      for (int i = 0; i < ind.size(); ++i) {
        printf("%d%c", ind[i] + 1, " \n"[i + 1 == ind.size()]);
      }
      return;
    }

    while (true) {
      std::shuffle(ind.begin(), ind.end(), rng);
      std::shuffle(other.begin(), other.end(), rng);
      std::vector<std::vector<int>> groups;
      auto dc = [&](auto&& self, std::vector<int> P, std::vector<int> Q) {
        if (P.empty() || Q.empty()) return;
        if (P.size() == 1) {
          P.insert(P.end(), Q.begin(), Q.end());
          groups.emplace_back(std::move(P));
          return;
        }
        std::vector<int> PP;
        while (P.size() > PP.size()) {
          int x = P.back(); P.pop_back();
          PP.emplace_back(x);
        }
        std::vector<int> Q0, Q1;
        {
          Table table;
          for (int id : P) {
            add(table, id);
          }
          for (int id : Q) {
            if (calc(table, id)) Q0.emplace_back(id);
            else Q1.emplace_back(id);
          }
        }
        self(self, P, Q0);
        self(self, PP, Q1);
      };
      dc(dc, ind, other);
      std::sort(groups.begin(), groups.end(), [](const auto& lhs, const auto& rhs) -> bool {
        return lhs.size() > rhs.size();
      });
      int rest = 0;
      for (const auto& g : groups) {
        rest += g.size();
      }
      std::vector<int> last;
      while (rest > K) {
        last = groups.back(); groups.pop_back();
        rest -= last.size();
      }
      if (rest < K) {
        if (rest == K - 1) {
          if (groups[0].size() != 2) {
            groups[0].pop_back();
            --rest;
            rest += last.size();
            while (rest > K) {
              --rest;
              last.pop_back();
            }
            groups.emplace_back(last);
            std::vector<int>{}.swap(last);
          }
        } else {
          rest += last.size();
          while (rest > K) {
            --rest;
            last.pop_back();
          }
          groups.emplace_back(last);
          std::vector<int>{}.swap(last);
        }
      }
      if (rest == K) {
        std::vector<int> result;
        for (const auto& g : groups) {
          for (int x : g) {
            result.emplace_back(x);
          }
        }
        assert(result.size() == K);
        for (int i = 0; i < result.size(); ++i) {
          printf("%d%c", result[i] + 1, " \n"[i + 1 == result.size()]);
        }
        return;
      }
    }
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

