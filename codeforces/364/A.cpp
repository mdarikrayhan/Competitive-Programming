#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...) 42
#endif

constexpr void scan(auto&&... args) noexcept { (std::cin >> ... >> args); }
constexpr void print(auto&&... args) noexcept { ((std::cout << args << ' '), ...); }
constexpr void println(auto&&... args) noexcept { print(std::forward<decltype(args)>(args)...); std::cout << '\n'; }

using u64 = uint64_t;

void solve() {
  u64 a;
  std::string s;
  scan(a, s);

  const auto n = s.size();
  std::vector<u64> xs(n);
  for (std::size_t i{}; i < n; ++i) {
    xs[i] = s[i] - '0';
  }

  if (a == 0) {
    u64 cnt0{};
    for (std::size_t l{}; l < n; ++l) {
      u64 sum = 0;
      for (std::size_t r = l; r < n; ++r) {
        sum += xs[r];
        cnt0 += sum == 0u;
      }
    }
    u64 tot{};
    for (std::size_t l{}; l < n; ++l) {
      u64 sum = 0;
      for (std::size_t r = l; r < n; ++r) {
        sum += xs[r];
        if (sum == 0u) {
          tot += n * (n + 1) / 2;
        } else {
          tot += cnt0;
        }
      }
    }
    println(tot);
    return;
  }

  std::set<u64> ds;
  for (u64 d{1}; d * d <= a; ++d) {
    const auto [q, r] = std::lldiv(a, d);
    if (r != 0) {
      continue;
    }
    ds.emplace(d);
    ds.emplace(q);
  }
  std::map<u64, u64> cnt{};
  for (std::size_t l{}; l < n; ++l) {
    u64 sum = 0;
    for (std::size_t r = l; r < n; ++r) {
      sum += xs[r];
      if (ds.contains(sum)) {
        ++cnt[sum];
      }
    }
  }
  u64 tot{};
  for (std::size_t l{}; l < n; ++l) {
    u64 sum = 0;
    for (std::size_t r = l; r < n; ++r) {
      sum += xs[r];
      if (ds.contains(sum) && sum <= a) {
        const auto [quot, rem] = std::lldiv(a, sum);
        if (rem == 0) {
          tot += cnt[quot];
        }
      }
    }
  }
  println(tot);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();
}