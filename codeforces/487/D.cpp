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
  int n, m, qn; cin >> n >> m >> qn;
  vs g(n+1);
  g[0] = std::string(m+2, ' ');
  FOR(i, 1, n) {
    cin >> g[i];
    g[i].insert(g[i].begin(), ' ');
    g[i].push_back(' ');
  }
  
  const auto n_sqrt = std::max(1, CI(std::sqrt(n)));
  const auto max_bn = n/n_sqrt;
  std::vector<vii> p_out(n+1, vii(m+2));
  
  const std::function<ii(int,int,int)> dfs = [&](int i, int j, int bn) {
    if (i/n_sqrt != bn || i==0 || j==0 || j==m+1) return ii{i,j};
    if (p_out[i][j] != ii{-1,-1}) return p_out[i][j];
    if (g[i][j]=='^') {
      p_out[i][j] = dfs(i-1, j, bn);
    } else if (g[i][j]=='<' && g[i][j-1]!='>') {
      p_out[i][j] = dfs(i, j-1, bn);
    } else if (g[i][j]=='>' && g[i][j+1]!='<') {
      p_out[i][j] = dfs(i, j+1, bn);
    } else {
      p_out[i][j] = {-1,-1};
    }
    return p_out[i][j];
  };
  
  const auto refresh_block = [&](int bn) {
    const auto min_i = bn*n_sqrt;
    const auto max_i = std::min(n, (bn+1)*n_sqrt-1);
    FOR(i, min_i, max_i) {
      std::fill(RNG(p_out[i]), ii{-1,-1});
    }
    FOR(i, min_i, max_i) {
      FOR(j, 1, m) {
        dfs(i, j, bn);
      }
    }
  };

  FOR(bn, 0, max_bn) {
    refresh_block(bn);
  }

  FOR(qi, 0, qn-1) {
    char op; int i, j;
    cin >> op >> i >> j;
    if (op == 'A') {
      auto p = p_out[i][j];
      while (p.F != -1 && p.F != 0 && p.S != 0 && p.S != m+1) {
        p = p_out[p.F][p.S];
      }
      cout << p.F << ' ' << p.S << '\n';
    } else {
      char ch; cin >> ch;
      if (ch != g[i][j]) {
        g[i][j] = ch;
        refresh_block(i/n_sqrt);
      }
    }
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
