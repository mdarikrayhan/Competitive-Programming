// LUOGU_RID: 159886896
/*
 * _|_|_|_|_|  _|_|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|      _|_|
 *       _|    _|        _|                _|        _|  _|    _|
 *     _|      _|_|_|      _|_|          _|      _|_|        _|
 *   _|        _|              _|      _|            _|    _|
 * _|_|_|_|_|  _|        _|_|_|      _|        _|_|_|    _|_|_|_|
 */

#include <bits/stdc++.h>

const int maxC = 26;

struct SAM {
  struct Node {
    int len, link, siz, trans[maxC]{};

    Node() {
      len = siz = 0, link = -1;
      std::fill(trans, trans + maxC, -1);
    }
  };

  int tot, lst;
  std::vector<Node> tree;

  SAM() {
    tot = 1, lst = 0;
    tree.emplace_back();
  }

  void Extend(int c) {
    int cur = tot++, p = lst;
    tree.emplace_back(), lst = cur, tree[cur].siz = 1;
    tree[cur].len = tree[p].len + 1;
    while (~p && !~tree[p].trans[c])
      tree[p].trans[c] = cur, p = tree[p].link;
    if (~p) {
      int q = tree[p].trans[c];
      if (tree[q].len == tree[p].len + 1)
        tree[cur].link = q;
      else {
        int cl = tot++;
        tree.emplace_back(tree[q]), tree[cl].siz = 0;
        tree[cl].len = tree[p].len + 1;
        while (~p && tree[p].trans[c] == q)
          tree[p].trans[c] = cl, p = tree[p].link;
        tree[q].link = tree[cur].link = cl;
      }
    } else
      tree[cur].link = 0;
  }

  long long Solve() {
    std::vector<int> cnt(tot + 1), id(tot);
    for (auto v: tree)
      cnt[v.len]++;
    for (int i = 1; i <= tot; i++)
      cnt[i] += cnt[i - 1];
    for (int i = 0; i < tot; i++)
      id[--cnt[tree[i].len]] = i;
    long long ans = 0;
    for (int i = tot - 1; i; i--) {
      int u = id[i];
      tree[tree[u].link].siz += tree[u].siz;
      ans += 1LL * (tree[u].len - tree[tree[u].link].len)
             * tree[u].siz * tree[u].siz;
    }
    return ans;
  }
};

int main() {
#ifdef LOCAL
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  freopen("task.err", "w", stderr);
#endif
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int test;
  std::cin >> test;
  while (test--) {
    SAM sam;
    std::string str;
    std::cin >> str;
    for (auto v: str)
      sam.Extend(int(v - 'a'));
    std::cout << sam.Solve() << '\n';
  }

  return 0;
}