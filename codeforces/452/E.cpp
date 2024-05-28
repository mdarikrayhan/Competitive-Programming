// LUOGU_RID: 159903170
/*
 * _|_|_|_|_|  _|_|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|      _|_|
 *       _|    _|        _|                _|        _|  _|    _|
 *     _|      _|_|_|      _|_|          _|      _|_|        _|
 *   _|        _|              _|      _|            _|    _|
 * _|_|_|_|_|  _|        _|_|_|      _|        _|_|_|    _|_|_|_|
 */

#include <bits/stdc++.h>

const int maxC = 27;
const int maxV = 3;
const int maxN = 1e5 + 1;
const int pMod = 1e9 + 7;

template<class Tp>
Tp Add(Tp x) { return x; }

template<class Tp>
Tp Mul(Tp x) { return x; }

template<class Tp, class ...Tps>
int Add(Tp x, Tps ...y) { return (x + Add(y...)) % pMod; }

template<class Tp, class ...Tps>
int Mul(Tp x, Tps ...y) { return int(1LL * x * Mul(y...) % pMod); }

template<class Tp, class ...Tps>
void AddC(Tp &x, Tps ...y) { x = Add(x, y...); }

template<class Tp, class ...Tps>
void MulC(Tp &x, Tps ...y) { x = Mul(x, y...); }

int ans[maxN];

struct SAM {
  struct Node {
    int len, link, sum[maxV], trans[maxC];

    Node() {
      len = 0, link = -1, std::fill(sum, sum + maxV, 0);
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
        std::fill(tree[cl].sum, tree[cl].sum + maxV, 0);
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
      int u = id[i], p = tree[u].link, mul = 1;

      for (int i = 0; i < maxV; i++) {
        tree[p].sum[i] += tree[u].sum[i];
        MulC(mul, tree[u].sum[i]);
      }

      if (mul) {
        AddC(ans[tree[u].len], +mul);
        AddC(ans[tree[p].len], -mul);
      }
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

  int n = INT_MAX;

  for (int i = 0, lst = 0; i < maxV; i++) {
    std::string str;
    std::cin >> str;
    n = std::min(n, (int)str.length());

    for (auto v : str)
      lst = sam.Extend(lst, int(v - 'a'), i);

    lst = sam.Extend(lst, maxC - 1, -1);
  }

  sam.Solve();

  for (int i = n - 1; i; i--)
    AddC(ans[i], ans[i + 1]);

  for (int i = 1; i <= n; i++)
    std::cout << Add(pMod, ans[i]) << " \n"[i == n];

  return 0;
}