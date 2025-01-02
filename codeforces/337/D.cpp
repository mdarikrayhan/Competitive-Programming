#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...) 42
#endif

constexpr void scan(auto&&... args) noexcept { (std::cin >> ... >> args); }
constexpr void print(auto&&... args) noexcept { ((std::cout << args << ' '), ...); }
constexpr void println(auto&&... args) noexcept { print(std::forward<decltype(args)>(args)...); std::cout << '\n'; }

template <typename Node, typename Tag>
struct LazySegmentTree {
  std::size_t n{};
  std::vector<Node> nodes;
  std::vector<Tag> tags;

  static constexpr auto npos = static_cast<size_t>(-1);

  LazySegmentTree() = default;

  explicit LazySegmentTree(std::size_t n_) { init(std::vector(n_, Node())); }

  LazySegmentTree(std::size_t n_, Node&& node) {
    init(std::vector(n_, std::forward<Node>(node)));
  }

  template <typename T>
  explicit LazySegmentTree(const std::vector<T>& init_) { init(init_); }

  template <typename T>
  void init(const std::vector<T>& init_) {
    n = 1u << std::__lg(2 * init_.size() - 1);
    nodes.assign(2 * n - 1, Node());
    tags.assign(2 * n - 1, Tag());
    auto build = [&](auto&& self, std::size_t x, std::size_t lx, std::size_t rx) -> void {
      if (rx - lx == 1u) {
        if (lx < init_.size()) {
          nodes[x] = Node{init_[lx]};
        }
        return;
      }
      const auto mid = lx + (rx - lx) / 2;
      self(self, 2 * x + 1, lx, mid);
      self(self, 2 * x + 2, mid, rx);
      nodes[x] = Node::unite(std::forward<Node>(nodes[2 * x + 1]),
                             std::forward<Node>(nodes[2 * x + 2]));
    };
    build(build, 0u, 0u, n);
  }

  void apply(std::size_t x, Tag&& tag) {
    nodes[x].apply(std::forward<Tag>(tag));
    tags[x].apply(std::forward<Tag>(tag));
  }

  void push(std::size_t x) {
    apply(2 * x + 1, std::forward<Tag>(tags[x]));
    apply(2 * x + 2, std::forward<Tag>(tags[x]));
    tags[x] = Tag();
  }

  void pull(std::size_t x) {
    nodes[x] = Node::unite(std::forward<Node>(nodes[2 * x + 1]),
                           std::forward<Node>(nodes[2 * x + 2]));
  }

  void modify(std::size_t pos, Node&& node,
              std::size_t x, std::size_t lx, std::size_t rx) {
    if (rx - lx == 1u) {
      nodes[x] = node;
      return;
    }
    push(x);
    const auto mid = lx + (rx - lx) / 2;
    if (pos < mid) {
      modify(pos, std::forward<Node>(node), 2 * x + 1, lx, mid);
    } else {
      modify(pos, std::forward<Node>(node), 2 * x + 2, mid, rx);
    }
    pull(x);
  }

  void modify(std::size_t pos, Node&& node) {
    modify(pos, std::forward<Node>(node), 0u, 0u, n);
  }

  void modify(std::size_t ql, std::size_t qr, Tag&& tag,
              std::size_t x, std::size_t lx, std::size_t rx) {
    if (ql >= rx || qr <= lx) {
      return;
    }
    if (ql <= lx && rx <= qr) {
      apply(x, std::forward<Tag>(tag));
      return;
    }
    push(x);
    const auto mid = lx + (rx - lx) / 2;
    modify(ql, qr, std::forward<Tag>(tag), 2 * x + 1, lx, mid);
    modify(ql, qr, std::forward<Tag>(tag), 2 * x + 2, mid, rx);
    pull(x);
  }

  void modify(std::size_t ql, std::size_t qr, Tag&& tag) {
    modify(ql, qr, std::forward<Tag>(tag), 0u, 0u, n);
  }

  Node query(std::size_t ql, std::size_t qr,
             std::size_t x, std::size_t lx, std::size_t rx) {
    if (ql >= rx || qr <= lx) {
      return Node();
    }
    if (ql <= lx && rx <= qr) {
      return nodes[x];
    }
    push(x);
    const auto mid = lx + (rx - lx) / 2;
    return Node::unite(std::forward<Node>(query(ql, qr, 2 * x + 1, lx, mid)),
                       std::forward<Node>(query(ql, qr, 2 * x + 2, mid, rx)));
  }

  Node query(std::size_t ql, std::size_t qr) {
    return query(ql, qr, 0u, 0u, n);
  }

  Node query(std::size_t pos) {
    return query(pos, pos + 1, 0u, 0u, n);
  }

  template <typename F>
  std::size_t findFirst(std::size_t ql, std::size_t qr, F&& pred,
                        std::size_t x, std::size_t lx, std::size_t rx) {
    if (lx >= qr || rx <= ql || !pred(nodes[x])) {
      return npos;
    }
    if (rx - lx == 1u) {
      return lx;
    }
    push(x);
    const auto mid = lx + (rx - lx) / 2;
    auto res = findFirst(ql, qr, std::forward<F>(pred), 2 * x + 1, lx, mid);
    if (res == npos) {
      res = findFirst(ql, qr, std::forward<F>(pred), 2 * x + 2, mid, rx);
    }
    return res;
  }

  template <typename F>
  std::size_t findFirst(std::size_t ql, std::size_t qr, F&& pred) {
    return findFirst(ql, qr, std::forward<F>(pred), 0u, 0u, n);
  }

  template <typename F>
  std::size_t findLast(std::size_t ql, std::size_t qr, F&& pred,
                       std::size_t x, std::size_t lx, std::size_t rx) {
    if (lx >= qr || rx <= ql || !pred(nodes[x])) {
      return npos;
    }
    if (rx - lx == 1u) {
      return lx;
    }
    push(x);
    const auto mid = lx + (rx - lx) / 2;
    auto res = findLast(ql, qr, std::forward<F>(pred), 2 * x + 2, mid, rx);
    if (res == npos) {
      res = findLast(ql, qr, std::forward<F>(pred), 2 * x + 1, lx, mid);
    }
    return res;
  }

  template <typename F>
  std::size_t findLast(std::size_t ql, std::size_t qr, F&& pred) {
    return findLast(ql, qr, std::forward<F>(pred), 0u, 0u, n);
  }
};

struct Tag {
  int val = 0;
  void apply(auto&& tag) {
    val += tag.val;
  }
};

constexpr auto inf = std::numeric_limits<int>::max() / 2;
struct Node {
  int max = -inf;
  void apply(auto&& tag) {
    max += tag.val;
  }
  static Node unite(auto&& a, auto&& b) {
    return {std::max(a.max, b.max)};
  }
};

void solve() {
  int n, m, d;
  scan(n, m, d);
  std::vector<bool> ps(n, false);
  for (int i = 0; i < m; ++i) {
    int v;
    scan(v);
    ps[--v] = true;
  }
  std::vector<std::vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scan(u, v);
    --u, --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  std::vector<int> tin(n), tout(n), depth(n);
  int timer = 0;
  auto dfs_init = [&](auto&& self, int v, int p) -> void {
    tin[v] = timer++;
    for (auto&& u : g[v]) {
      if (u != p) {
        depth[u] = depth[v] + 1;
        self(self, u, v);
      }
    }
    tout[v] = timer;
  };
  dfs_init(dfs_init, 0, -1);

  LazySegmentTree<Node, Tag> st(n);
  for (int v = 0; v < n; ++v) {
    if (ps[v]) {
      st.modify(tin[v], {depth[v]});
    }
  }

  int ret = 0;
  auto dfs = [&](auto&& self, int v, int p) -> void {
    ret += st.query(0, n).max <= d;
    for (auto&& u : g[v]) {
      if (u == p) {
        continue;
      }
      st.modify(0, n, {+1});
      st.modify(tin[u], tout[u], {-2});
      self(self, u, v);
      st.modify(tin[u], tout[u], {+2});
      st.modify(0, n, {-1});
    }
  };
  dfs(dfs, 0, -1);
  println(ret);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();
}