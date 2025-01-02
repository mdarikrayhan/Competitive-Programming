#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
using namespace std;
typedef long long ll;

const int Inf = 1e9;

const int K = 18;

int go[K][K];
int init[3];

tuple<int, int, int> num_to_triple(int x) {
  int have_b = x % 2;
  x /= 2;
  int st = x % 3;
  x /= 3;
  int fn = x;
  return make_tuple(st, fn, have_b);
}

int triple_to_num(int st, int fn, int have_b) {
  return fn * 6 + st * 2 + have_b;
}

void prec() {
  for (int lf = 0; lf < K; ++lf) {
    for (int rg = 0; rg < K; ++rg) {
      auto [sl, fl, bl] = num_to_triple(lf);
      auto [sr, fr, br] = num_to_triple(rg);
      if (sl + fr >= 3) {
        go[lf][rg] = -1;
        continue;
      }
      int ns;
      if (sl == 0) ns = sr;
      else if (sl == 1) ns = sl + br;
      else if (sl == 2) ns = sl;

      int nf;
      if (fr == 0) nf = fl;
      else if (fr == 1) nf = fr + bl;
      else if (fr == 2) nf = fr;

      int nb = max(bl, br);

      go[lf][rg] = triple_to_num(ns, nf, nb);
    }
  }
  auto [s, f, b] = num_to_triple(go[triple_to_num(1, 0, 0)][triple_to_num(0, 1, 0)]);
  // cout << s << ' ' << f << ' ' << b << endl;
  for (int lt = 0; lt < 3; ++lt) {
    int s = 0, f = 0, b = 0;
    if (lt == 0) s = 1;
    else if (lt == 1) b = 1;
    else if (lt == 2) f = 1;
    init[lt] = triple_to_num(s, f, b);
  }
}
 
class segtree {
 public:
  struct node {
    // don't forget to set default value (used for leaves)
    // not necessarily neutral element!
    array<int, 18> have;

    void apply(int l, int r, int v) {
      fill(have.begin(), have.end(), Inf);
      for (int go = 0; go < 3; ++go) {
        have[init[go]] = go != v;
      }
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    fill(res.have.begin(), res.have.end(), Inf);
    for (int l = 0; l < K; ++l) {
      for (int r = 0; r < K; ++r) {
        int g = go[l][r];
        if (g != -1) {
          res.have[g] = min(res.have[g], a.have[l] + b.have[r]);
        }
      }
    }
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    // push from x into (x + 1) and z
/*
    if (tree[x].add != 0) {
      tree[x + 1].apply(l, y, tree[x].add);
      tree[z].apply(y + 1, r, tree[x].add);
      tree[x].add = 0;
    }
*/
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  int n;
  vector<node> tree;

  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }

  template <typename M>
  void build(int x, int l, int r, const vector<M> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }

  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }

  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }

  int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }

  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }

  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  template <typename M>
  segtree(const vector<M> &v) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }

  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }

  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }

  template <typename... M>
  void modify(int ll, int rr, const M&... v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }

  // find_first and find_last call all FALSE elements
  // to the left (right) of the sought position exactly once

  int find_first(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }

  int find_last(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  prec();
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    a[i] = c - 'a';
  }
  segtree tree(a);
  for (int i = 0; i < q; ++i) {
    int pos; char c;
    cin >> pos >> c;
    --pos;
    tree.modify(pos, pos, (int)(c - 'a'));
    int res = Inf;
    auto res_node = tree.get(0, n - 1);
    for (int i = 0; i < K; ++i) {
      // cout << i << ' ' << res_node.have[i] << endl;
      res = min(res, res_node.have[i]);
    }
    // exit(0);
    cout << res << '\n';
  }
}
			  	   				  	 	  	 	    	