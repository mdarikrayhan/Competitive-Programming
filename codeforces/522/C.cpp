#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std::literals;

using ll = long long;
using ii [[maybe_unused]] = std::pair<int, int>;
using vi [[maybe_unused]] = std::vector<int>;
using vl [[maybe_unused]] = std::vector<ll>;
using vvi [[maybe_unused]] = std::vector<vi>;
using vii [[maybe_unused]] = std::vector<ii>;
using vb [[maybe_unused]] = std::vector<bool>;
using vd [[maybe_unused]] = std::vector<double>;
using vs [[maybe_unused]] = std::vector<std::string>;

#define FOR(_i, _a, _b) for (int _i = (_a); _i <= (_b); ++(_i))
#define FORD(_i, _a, _b) for (int _i = (_a); _i >= (_b); --(_i))
#define RNG(_l) (_l).begin(), (_l).end()
#define SORT(_l) std::sort((_l).begin(), (_l).end())
#define CI(_v) static_cast<int>(_v)
#define CL(_v) static_cast<ll>(_v)
#define CD(_v) static_cast<double>(_v)
#define F first
#define S second
#define PB push_back

void Solution([[maybe_unused]] std::istream& cin, [[maybe_unused]] std::ostream& cout) {
  int tn;
  cin >> tn;
  FOR(ti, 1, tn) {
    int m, k; cin >> m >> k;
    vi a(k+1);
    FOR(i, 1, k) {
      cin >> a[i];
    }
    
    auto a_end = a;
    vi t_max_pass(k+1);
    auto t0 = 0;
    auto t0_upset = 0;
    auto i_upset = 0;
    FOR(i, 1, m-1) {
      int t, r; cin >> t >> r;
      if (t != 0) t_max_pass[t] = i;
      if (r == 1 && i_upset == 0) {
        t0_upset = t0;
        i_upset = i;
      }
      if (t == 0) ++t0;
      else --a_end[t];
    }
    
    vb res(k+1);
    if (i_upset == 0) { // no upset passengers
      FOR(i, 1, k) {
        res[i] = (a_end[i] <= t0);
      }
    } else {
      auto min_a_end = INT_MAX;
      FOR(i, 1, k) {
        if (t_max_pass[i] < i_upset && a_end[i] <= t0_upset) {
          res[i] = true;
          min_a_end = std::min(min_a_end, a_end[i]);
        }
      }
      const auto t0_end = t0 - min_a_end;
      FOR(i, 1, k) {
        if (a_end[i] <= t0_end) {
          res[i] = true;
        }
      }
    }

    FOR(i, 1, k) {
      cout << (res[i] ? 'Y':'N');
    }
    cout << '\n';
  }
}

#ifndef NDEBUG
[[maybe_unused]] std::stringstream ReadFile(const std::string& path) {
  std::ifstream file(path);
  assert(file);
  std::stringstream ss;
  ss << file.rdbuf();
  file.close();
  return ss;
}

[[maybe_unused]] void RunTest(const std::string& in_path, const std::string& out_path) {
  std::stringstream cin = ReadFile(in_path);
  std::stringstream cout;
  const auto e_out = ReadFile(out_path).str();
  const auto start_t = std::chrono::high_resolution_clock::now();
  Solution(cin, cout);
  const auto end_t = std::chrono::high_resolution_clock::now();
  const auto total_t = std::chrono::duration_cast<std::chrono::milliseconds>(end_t - start_t).count();
  std::cerr << in_path << ", "sv << total_t << " ms"sv << std::endl;
  const auto a_out = cout.str();
  assert(a_out == e_out);
}

[[maybe_unused]] void TestSolution() {
  const std::string dir("../"s);
  RunTest(dir + "input1.txt"s, dir + "output1.txt"s);
  RunTest(dir + "input2.txt"s, dir + "output2.txt"s);
  RunTest(dir + "input3.txt"s, dir + "output3.txt"s);
  std::cerr << "TestSolution OK"sv << std::endl;
}
#endif

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
// #ifndef NDEBUG
//   TestSolution();
// #endif
  Solution(std::cin, std::cout);
  return 0;
}
