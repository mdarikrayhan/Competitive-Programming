// LUOGU_RID: 159903042
/*
 * _|_|_|_|_|  _|_|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|      _|_|
 *       _|    _|        _|                _|        _|  _|    _|
 *     _|      _|_|_|      _|_|          _|      _|_|        _|
 *   _|        _|              _|      _|            _|    _|
 * _|_|_|_|_|  _|        _|_|_|      _|        _|_|_|    _|_|_|_|
 */

#include <bits/stdc++.h>

const int maxC = 27;

int ans = INT_MAX;

struct SAM {
  struct Node {
    int len, link, sum[2], trans[maxC];

    Node() {
      len = 0, link = -1, sum[0] = sum[1] = 0;
      std::fill(trans, trans + maxC, -1);
    }
  };

  int tot;
  std::vector<Node> tree;

  int New(Node val = Node()) {
    tree.emplace_back(val);
    return tot++;
  }

  SAM() { New(); }

  int Extend(int p, int c, int ty) {
    int cur = New();
    tree[cur].len = tree[p].len + 1;
    if (~ty)
      tree[cur].sum[ty] = 1;
    while (~p && !~tree[p].trans[c])
      tree[p].trans[c] = cur, p = tree[p].link;
    if (~p) {
      int q = tree[p].trans[c];
      if (tree[q].len == tree[p].len + 1)
        tree[cur].link = q;
      else {
        int cl = New(tree[q]);
        tree[cl].len = tree[p].len + 1;
        tree[cl].sum[0] = tree[cl].sum[1] = 0;
        while (~p && tree[p].trans[c] == q)
          tree[p].trans[c] = cl, p = tree[p].link;
        tree[q].link = tree[cur].link = cl;
      }
    } else
      tree[cur].link = 0;
    return cur;
  }

  void Solve() {
    std::vector<int> cnt(tot + 1), id(tot);

    for (const auto &v : tree)
      cnt[v.len]++;

    for (int i = 1; i <= tot; i++)
      cnt[i] += cnt[i - 1];

    for (int i = 0; i < tot; i++)
      id[--cnt[tree[i].len]] = i;
    
    for (int i = tot - 1; i; i--) {
      int u = id[i], p = tree[u].link;

      tree[p].sum[0] += tree[u].sum[0];
      tree[p].sum[1] += tree[u].sum[1];

      if (tree[u].sum[0] == 1 && tree[u].sum[1] == 1)
        ans = std::min(ans, tree[p].len + 1);
    }
  }
} sam;

int main() {
#ifdef LOCAL
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  freopen("task.err", "w", stderr);
#endif
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int lst = 0;

  for (int i = 0; i < 2; i++) {
    std::string str;
    std::cin >> str;

    for (auto v : str)
      lst = sam.Extend(lst, int(v - 'a'), i);

    lst = sam.Extend(lst, maxC - 1, -1);  
  }

  sam.Solve();

  std::cout << (ans == INT_MAX ? -1 : ans) << '\n';

  return 0;
}