#include <bits/stdc++.h>
using namespace std;

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
   segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

struct S {
  int in, out1, out2;
  int64_t sum1, sum2;
};

S op(S a, S b) {
  if (a.out1 == -1) return b;
  if (b.out1 == -1) return a;
  S res;
  res.in = b.in;
  res.out1 = (b.out1 == a.in ? a.out2 : a.out1);
  res.sum1 = b.sum1 + (b.out1 == a.in ? a.sum2 : a.sum1);
  res.out2 = (b.out2 == a.in ? a.out2 : a.out1);
  res.sum2 = b.sum2 + (b.out2 == a.in ? a.sum2 : a.sum1);
  return res;
}

S e() {
  return {0, -1, -1, 0, 0};
}

using segtree = atcoder::segtree<S, op, e>;

const int K = 21;
struct mex2tracker {
  array<int, K> freq;

  mex2tracker() {
    freq.fill(0);
  }

  int mex() {
    for (int i = 0; i < K; i++) {
      if (!freq[i]) return i;
    }
    assert(0);
  }

  int mex2() {
    for (int i = mex()+1; i < K; i++) {
      if (!freq[i]) return i;
    }
    assert(0);
  }

  void add(int x) {
    freq[x]++;
  }

  void remove(int x) {
    freq[x]--;
  }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> sz(n+1, 1), par(n+1), son(n+1), dep(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> par[i];
    par[i]--;
    dep[i] = dep[par[i]] + 1;
  }

  for (int i = n; i >= 1; i--) {
    sz[par[i]] += sz[i];
    if (!son[par[i]] || sz[son[par[i]]]  < sz[i]) {
      son[par[i]] = i;
    }
  }

  vector<int> tree_idx(n+1, -1), hld_root(n+1), chain_size(n+1);

  int ptr = 0;
  for (int i = 0; i <= n; i++) {
    if (tree_idx[i] != -1) continue;
    int v = i;
    while (1) {
      tree_idx[v] = ptr++;
      hld_root[v] = i;
      if (!son[v]) break;
      v = son[v];
    }
  }
  vector<mex2tracker> mexes(n+1);

  segtree st(n+1);
  st.set(tree_idx[0], {0, 0, 1, 0, 1});
  chain_size[0]++;

  int64_t cur_ans = 0;
  for (int i = 1; i <= n; i++) {
    int v = i;
    while (1) {
      int mex1 = mexes[v].mex();
      int mex2 = mexes[v].mex2();
      int root = hld_root[v];
      S orig_chain = st.prod(tree_idx[root], tree_idx[root] + chain_size[root]);
      int orig_val = orig_chain.out1;
      cur_ans -= orig_chain.sum1;
      if (v == i) chain_size[hld_root[i]]++;

      st.set(tree_idx[v], {mex1, mex1, mex2, mex1, mex2});
      S new_chain = st.prod(tree_idx[root], tree_idx[root] + chain_size[root]);
      int new_val = new_chain.out1;
      cur_ans += new_chain.sum1;

      if (!root) break;
      if (orig_val == new_val) break;
      int u = par[root];
      if (orig_val != -1) mexes[u].remove(orig_val);
      mexes[u].add(new_val);
      v = u;
    }
    cout << cur_ans << '\n';
  }
}
