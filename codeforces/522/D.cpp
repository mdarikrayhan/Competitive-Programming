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

struct [[maybe_unused]] CustomHash { // https://codeforces.com/blog/entry/62393
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

template<typename T>
class SegTree {
public:
  struct Node {
    T val = std::numeric_limits<T>::max();
  };

  explicit SegTree(const std::vector<T>& a) {
    while (size_ < CI(a.size())) size_ *= 2;
    t_.resize(size_ * 2 - 1);
    Init(a, 0, 0, size_);
  }

  T GetMin(int l, int r) const {
    return GetMin(l, r, 0, 0, size_).val;
  }

  void Set(int i, T v) {
    Set(i, v, 0, 0, size_);
  }

private:
  std::vector<Node> t_;
  int size_ = 1;

  static Node Combine(const Node& l, const Node& r) {
    return {std::min(l.val, r.val)};
  }

  void Init(const std::vector<T>& a, int x, int lx, int rx) {
    if (lx + 1 == rx) {
      if (lx < CI(a.size())) {
        t_[x].val = a[lx];
      }
    } else {
      const auto m = (lx + rx) / 2;
      Init(a, 2*x+1, lx, m);
      Init(a, 2*x+2, m, rx);
      t_[x] = Combine(t_[2*x+1], t_[2*x+2]);
    }
  }

  Node GetMin(int l, int r, int x, int lx, int rx) const {
    if (rx <= l || lx >= r) return Node{};
    if (rx <= r && lx >= l) return t_[x];
    const auto m = (lx + rx) / 2;
    return Combine(GetMin(l, r, 2*x+1, lx, m), GetMin(l, r, 2*x+2, m, rx));
  }

  void Set(int i, T v, int x, int lx, int rx) {
    if (lx + 1 == rx) {
      t_[x].val = v;
      return;
    }
    const auto m = (lx + rx) / 2;
    if (i < m) Set(i, v, 2*x+1, lx, m);
    else Set(i, v, 2*x+2, m, rx);
    t_[x] = Combine(t_[2*x+1], t_[2*x+2]);
  }
};

struct Query {
  int i=0, l=0, r=0;
};

void Solution(std::istream& cin, std::ostream& cout) {
  int n, qn; cin >> n >> qn;
  vi a(n);
  FOR(i, 0, n-1) {
    cin >> a[i];
  }
  std::vector<Query> qs(qn);
  FOR(i, 0, qn-1) {
    int l, r; cin >> l >> r; --l; --r;
    qs[i] = {i, l, r};
  }
  std::sort(RNG(qs), [&](const Query& q1, const Query& q2) {
    return std::tie(q1.l, q1.r, q1.i) < std::tie(q2.l, q2.r, q2.i);
  });

  vi r_id(n, INT_MAX), l_dist(n, INT_MAX);
  {
    std::unordered_map<int, int, CustomHash> max_id;
    FOR(i, 0, n-1) {
      if (max_id.contains(a[i])) {
        const auto li = max_id.at(a[i]);
        r_id[li] = i;
        l_dist[i] = i - li;
      }
      max_id[a[i]] = i;
    }
  }
  SegTree tree(l_dist);

  vi res(qn);
  int tree_l = 0;
  
  FOR(qi, 0, qn-1) {
    while (tree_l < qs[qi].l) {
      if (r_id[tree_l] < n) 
        tree.Set(r_id[tree_l], INT_MAX);
      ++tree_l;
    }
    const auto tree_min = tree.GetMin(tree_l, qs[qi].r+1);
    res[qs[qi].i] = tree_min==INT_MAX ? -1 : tree_min;
  }

  for (const auto x : res) {
    cout << x << '\n';
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
  RunTest(dir + "input3.txt"s, dir + "output3.txt"s); // n=5*1e5, qn=5*1e5, -1e9 <= a <= 1e9
  RunTest(dir + "input5.txt"s, dir + "output5.txt"s); // n=  1e5, qn=  1e5, -1e3 <= a <= 1e3
  RunTest(dir + "input4.txt"s, dir + "output4.txt"s); // n=5*1e5, qn=5*1e5, -1e3 <= a <= 1e3
  std::cerr << "TestSolution OK"sv << std::endl;
}
#endif

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
// #ifndef NDEBUG
//    TestSolution();
// #endif
  Solution(std::cin, std::cout);
  return 0;
}
