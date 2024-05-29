// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt")
// #pragma GCC target("avx,avx2")
// #pragma GCC optimize("Ofast,unroll-loops")

// #define FAST_ALLOCATOR_MEMORY 2e8

// #include "optimization.h"
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define forn(i, n) for (int i = 0; i < (ll)(n); i++)

std::random_device dev;
std::mt19937 rng(dev());
ll mod = 1e9 + 7;
std::uniform_int_distribution<std::int64_t> uid(0, 10);

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);
    return h1 ^ h2;
  }
};

class DSU {
public:
  DSU(std::size_t n) {
    parent_.resize(n);
    std::iota(all(parent_), 0);
  }

  bool is_in_same_set(std::size_t a, std::size_t b) const {
    return get(a) == get(b);
  }

  void join(std::size_t set_of, std::size_t to) {
    auto lhs_parent = get(set_of);
    auto rhs_parent = get(to);
    if (lhs_parent != rhs_parent) {
      parent_[lhs_parent] = rhs_parent;
    }
  }

  std::size_t get(std::size_t node) const {
    return parent_[node] == node ? node : (parent_[node] = get(parent_[node]));
  }

  void add() const { parent_.push_back(parent_.size()); }

private:
  mutable std::vector<std::size_t> parent_;
};

struct Edge {
  std::size_t id;
  std::size_t from, to;
  std::int64_t weight;

  bool operator<(const Edge &other) const { return weight < other.weight; }
};

struct SkewHeap {
private:
  struct Node {
    Node *left, *right;
    Edge value_;
    std::int64_t pending_add_ = 0;

    void add_pending_add(std::int64_t value) { pending_add_ += value; }

    void push_pending_add() {
      value_.weight += pending_add_;

      if (left != nullptr) {
        left->add_pending_add(pending_add_);
      }
      if (right != nullptr) {
        right->add_pending_add(pending_add_);
      }

      pending_add_ = 0;
    }

    Edge value() {
      push_pending_add();
      return value_;
    }

    ~Node() {
      if (left != nullptr) {
        delete left;
      }
      if (right != nullptr) {
        delete right;
      }
    }
  };

public:
  SkewHeap() = default;
  SkewHeap(const SkewHeap &other) = delete;
  SkewHeap &operator=(const SkewHeap &other) = delete;
  SkewHeap(SkewHeap &&other) : size_(other.size_), root(other.root) {
    other.root = nullptr;
  }
  SkewHeap &operator=(SkewHeap &&other) {
    if (!empty()) {
      delete root;
    }

    root = std::exchange(other.root, nullptr);
    size_ = other.size_;
    return *this;
  }

  ~SkewHeap() {
    if (!empty()) {
      delete root;
    }
  }

  void merge(SkewHeap &&right) {
    if (empty() && right.empty()) {
      return;
    }

    assert(root != right.root);
    root = inner_merge(root, right.root);
    right.root = nullptr;

    size_ += right.size();
  }

  void add(const Edge &value) {
    Node *node = new Node{nullptr, nullptr, value};
    merge(SkewHeap(node));
  }

  Edge extract_min() {
    assert(!empty());

    auto result = root->value();

    auto old_root = root;
    auto old_size = size();

    root = old_root->left;
    merge(SkewHeap(old_root->right));

    size_ = old_size - 1;

    old_root->left = old_root->right = nullptr;
    delete old_root;

    return result;
  }

  void per_element_add(std::int64_t value) {
    if (!empty()) {
      root->pending_add_ += value;
    }
  }

  bool empty() const { return root == nullptr; }

  std::size_t size() { return size_; }

private:
  static Node *inner_merge(Node *lhs, Node *rhs) {
    if (lhs == nullptr || rhs == nullptr) {
      return lhs != nullptr ? lhs : rhs;
    }

    if (rhs->value() < lhs->value()) {
      std::swap(lhs, rhs);
    }

    lhs->right = inner_merge(lhs->right, rhs);
    std::swap(lhs->left, lhs->right);

    return lhs;
  }

  std::size_t size_ = 0;

  explicit SkewHeap(Node *new_root) : size_(1), root(new_root) {}
  Node *root = nullptr;
};

std::int64_t brute_force(int n, int m, std::vector<Edge> edges) {
  std::int64_t global_ans = std::numeric_limits<std::int64_t>::max();

  for (std::size_t i = 0; i < (1ull << m); ++i) {
    std::vector<std::vector<std::size_t>> g(n);

    forn(j, m) {
      if ((1 << j) & i) {
        auto edge = edges[j];
        g[edge.from].push_back(edge.id);
      }
    }

    std::vector<std::size_t> visited(n);
    std::int64_t local_ans = 0;

    std::function<bool(int)> dfs = [&](int v) -> bool {
      visited[v] = 1;
      for (auto e_idx : g[v]) {
        auto to = edges[e_idx];
        if (visited[to.to]) {
          return false;
        }
        if (!dfs(to.to)) {
          return false;
        }
        local_ans += to.weight;
      }
      return true;
    };

    if (!dfs(0)) {
      continue;
    }

    bool is_mst = true;
    for (auto v : visited) {
      if (!v) {
        is_mst = false;
        break;
      }
    }

    if (is_mst) {
      global_ans = std::min(global_ans, local_ans);
    }
  }

  return global_ans;
}

bool check_reachability(int n, int m, std::vector<Edge> edges) {
  std::vector<std::vector<std::size_t>> g(n);

  forn(j, m) {
    auto edge = edges[j];
    g[edge.from].push_back(edge.id);
  }

  std::vector<std::size_t> visited(n);
  std::function<void(int)> dfs = [&](int v) {
    visited[v] = 1;
    for (auto e_idx : g[v]) {
      auto to = edges[e_idx];
      if (!visited[to.to]) {
        dfs(to.to);
      }
    }
  };
  dfs(0);

  for (auto v : visited) {
    if (!v) {
      return false;
    }
  }
  return true;
}

void solve() {
  std::ifstream fin("input.txt");
  std::ofstream fout("output.txt");

#ifdef DEBUG
  std::size_t n = uid(rng) + 1, m = n + uid(rng);
  cout << n << " " << m << endl;
#else
  // std::size_t n = readInt(), m = readInt();
  std::size_t n, m;
  fin >> n >> m;
#endif

  std::vector<std::vector<std::size_t>> i_g(n);

  std::vector<Edge> edges(m);
  std::vector<Edge> i_edges(m);

  for (std::size_t i = 0; i < m; ++i) {
#ifdef DEBUG
    std::size_t a = uid(rng) % n + 1, b = uid(rng) % n + 1;
    cout << a << " " << b << " ";
#else
    // std::size_t a = readInt(), b = readInt();
    std::size_t a, b;
    fin >> a >> b;

#endif
    --a, --b;

#ifdef DEBUG
    std::int64_t weight = uid(rng);
    cout << weight << endl;
#else
    // std::int64_t weight = readInt();
    std::int64_t weight;
    fin >> weight;
#endif

    edges[i] = {i, a, b, weight};

    i_edges[i] = {i, b, a, weight};
    if (a == b) {
      continue;
    }

    i_g[b].push_back(i);
  }

  // #ifdef DEBUG
  if (!check_reachability(n, m, edges)) {
    fout << -1 << "\n";
    return;
  }
  // #endif

  std::vector<SkewHeap> heaps(n);

  std::vector<std::size_t> q;
  q.reserve(n);
  for (std::size_t i = 1; i < n; ++i) {
    q.push_back(i);
  }

  DSU dsu(n);
  DSU dsu_reachability(n);

  forn(v, n) {
    for (auto idx_edge : i_g[v]) {
      const auto &edge = i_edges[idx_edge];
      heaps[v].add(edge);
    }
  }

  // edge id -> epoch
  std::unordered_map<std::size_t, std::size_t> peeked_edges;
  peeked_edges.reserve(2 * m);
  std::size_t epoch_counter = 1;

  std::unordered_map<std::size_t, std::size_t> parent;
  parent.reserve(2 * m);
  std::unordered_map<std::size_t, std::size_t> parent_edge;
  parent_edge.reserve(2 * m);

  /// All structures initialized. Go search

  std::vector<std::size_t> cycle;
  cycle.reserve(2 * n);

  std::int64_t ans = 0;
  while (!q.empty()) {
    auto v = dsu.get(q.back());
    q.pop_back();

    Edge edge;
    do {
      edge = heaps[v].extract_min();
    } while (dsu.get(edge.to) == v);

    auto u = dsu.get(edge.to);

#ifdef REL_DEBUG
    std::cout << "Chosen " << edge.id + 1 << " " << edge.weight << std::endl;
#endif

    ans += edge.weight;
    heaps[v].per_element_add(-edge.weight);

    // Probably found the path to the root
    if (!dsu_reachability.is_in_same_set(v, u)) {
#ifdef REL_DEBUG
      std::cout << "Not in same set " << v + 1 << " and " << u + 1 << std::endl;
#endif
      peeked_edges[edge.id] = 0;

      dsu_reachability.join(v, u);
      parent[v] = u;
      parent_edge[v] = edge.id;

#ifdef REL_DEBUG
      std::cout << u + 1 << " : " << parent[u] + 1 << std::endl;
#endif
      continue;
    }
#ifdef REL_DEBUG
    std::cout << "In same set " << v + 1 << " and " << u + 1 << std::endl;
#endif
    cycle.clear();
    cycle.push_back(v);

    peeked_edges[edge.id] = epoch_counter;
    while (v != u) {
#ifdef REL_DEBUG
      std::cout << v + 1 << " " << u + 1 << std::endl;
#endif
      assert(dsu_reachability.is_in_same_set(v, u));
      cycle.push_back(u);

      peeked_edges[parent_edge[u]] = epoch_counter;
      u = dsu.get(parent[u]);
    }
    ++epoch_counter;

    assert(v == u);
    parent[parent[v]] = heaps.size();

    // Prepared the cycle. Merge heaps
    dsu_reachability.add();
    dsu_reachability.join(v, heaps.size());

    dsu.add();
    dsu.join(v, heaps.size());
#ifdef REL_DEBUG
    std::cout << "Unioned " << v + 1 << " and " << heaps.size() + 1
              << std::endl;
#endif
    q.push_back(heaps.size());

    heaps.emplace_back();

#ifdef REL_DEBUG
    std::cout << "Union: ";
#endif
    for (auto node : cycle) {
#ifdef REL_DEBUG
      std::cout << node + 1 << " ";
#endif
      dsu.join(node, v);
      heaps.back().merge(std::move(heaps[node]));
    }
#ifdef REL_DEBUG
    std::cout << std::endl;
#endif
  }
  // writeInt(ans, '\n');
  fout << ans << "\n";

  // vertex -> <idx in peeked_edges>
  std::vector<std::size_t> visited(n);
  std::vector<std::vector<std::pair<std::size_t, std::size_t>>> ans_g(n);

  for (auto [edge_id, weight] : peeked_edges) {
    auto &edge = edges[edge_id];
    ans_g[edge.from].emplace_back(weight, edge_id);
  }

  // weight, edge id
  std::priority_queue<std::pair<std::size_t, std::size_t>,
                      std::vector<std::pair<std::size_t, std::size_t>>,
                      std::greater<std::pair<std::size_t, std::size_t>>>
      pq;
  for (auto it : ans_g[0]) {
    pq.emplace(it);
  }

  visited[0] = 1;
  std::int64_t check_ans = 0;

  while (!pq.empty()) {
    auto edge_id = pq.top().second;
    pq.pop();

    auto &edge = edges[edge_id];
    if (visited[edge.to]) {
      continue;
    }
    // writeInt(edge_id + 1, ' ');
    if (edge.weight == 1) {
      fout << edge_id + 1 << " ";
    }

    check_ans += edge.weight;

    visited[edge.to] = 1;

    for (auto to : ans_g[edge.to]) {
      if (!visited[edges[to.second].to]) {
        pq.emplace(to);
      }
    }
  }
  // writeChar('\n');
  fout << "\n";
  assert(check_ans == ans);

#ifdef REL_DEBUG
  writeInt(brute_force(n, m, edges), '\n');
  flush();
  assert(ans == brute_force(n, m, edges));
#endif
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int t = 1;
  // cin >> t;
  // t = readInt();
  while (t--) {
    solve();
  }
  return 0;
}