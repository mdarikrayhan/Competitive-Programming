#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;


struct LazyContext {
  int x;
  bool is_empty;
  LazyContext() : x(0), is_empty(true) {} // neutral element
  LazyContext(int x) : x(x), is_empty(false) {}
  void compose(const LazyContext& rhs) {
    x = rhs.x;
    is_empty &= rhs.is_empty;
  }
  bool empty() const { return is_empty; }
  void reset() { *this = LazyContext(); }
};
struct Node {
  int mx, mn;
  long long sum;
  Node() : mx(-INF), mn(INF), sum(0) {} // neutral element
  Node(int s) : mx(s), mn(s), sum(s) {}
  Node(int mx, int mn, long long sum) : mx(mx), mn(mn), sum(sum) {}
  Node& operator+=(const Node& rhs) {
    mx = max(mx, rhs.mx);
    mn = min(mn, rhs.mn);
    sum += rhs.sum;
    return *this;
  }
  friend Node operator+(Node lhs, const Node& rhs) {
    return lhs += rhs;
  }
  void apply(int l, int r, const LazyContext& lazy) {
    mn = mx = lazy.x;
    sum = 1ll * lazy.x * (r - l);
  }
};

struct SegmentTree {
public:
  SegmentTree(int n = 0) : n(n), st(4 * n, Node()), lazy(4 * n) {}
  template<typename Iterator>
  SegmentTree(Iterator first, Iterator last) : SegmentTree(int(last - first)) {
    build(1, 0, n, first);
  }
  void update(int x, const Node& val) {
    update(1, 0, n, x, val);
  }
  void update_mod(int l, int r, int x) {
    update_mod(1, 0, n, l, r, x);
  }
  Node query(int l, int r) {
    Node cur{}; 
    query(1, 0, n, l, r, cur);
    return cur;
  }
private:
  int n;
  vector<Node> st;
  vector<LazyContext> lazy;
  static int left (int p) { return 2 * p; }
  static int right (int p) { return 2 * p + 1; }
  template<typename Iterator>
  void build(int p, int tl, int tr, Iterator first) {
    if(tl + 1 == tr) {
      st[p] = first[tl];
    } else {
      int mid = (tl + tr) / 2;
      build(left(p), tl, mid, first);
      build(right(p), mid, tr, first);
      st[p] = st[left(p)] + st[right(p)];
    }
  }
  void update(int p, int tl, int tr, int x, const Node& val) {
    if(tl + 1 == tr) {
      st[p] = val;
    } else {
      push(tl, tr, p);
      int mid = (tl + tr) / 2;
      if(x < mid) {
        update(left(p), tl, mid, x, val);
      } else {
        update(right(p), mid, tr, x, val);
      }
      st[p] = st[left(p)] + st[right(p)];
    }
  }
  void update_mod(int p, int tl, int tr, int l, int r, const int x) {
    if(tl >= r || tr <= l || st[p].mx < x) return; // break_condition
    if(tl >= l && tr <= r && st[p].mn == st[p].mx) { // tag_condition
      int r = st[p].mx % x;
      st[p].apply(tl, tr, r);
      lazy[p].compose(r);
    } else {
      push(tl, tr, p);
      int mid = (tl + tr) / 2;
      update_mod(left(p), tl, mid, l, r, x);
      update_mod(right(p), mid, tr, l, r, x);
      st[p] = st[left(p)] + st[right(p)];
    }
  }
  void query(int p, int tl, int tr, int l, int r, Node& cur) {
    if(tl >= r || tr <= l) {
      return;
    } else if(tl >= l && tr <= r) {
      cur += st[p];
    } else {
      push(tl, tr, p);
      int mid = (tl + tr) / 2;
      query(left(p), tl, mid, l, r, cur);
      query(right(p), mid, tr, l, r, cur);
    }
  }
  void push(int tl, int tr, int p) {
    if(lazy[p].empty()) {
      return;
    }
    int mid = (tl + tr) / 2;
    st[left(p)].apply(tl, mid, lazy[p]);
    lazy[left(p)].compose(lazy[p]);

    st[right(p)].apply(mid, tr, lazy[p]);
    lazy[right(p)].compose(lazy[p]);
    lazy[p].reset();
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for(auto& x : a) cin >> x;
  SegmentTree seg(begin(a), end(a));
  while(m--) {
    int op;
    cin >> op;
    if(op == 1) {
      int l, r;
      cin >> l >> r;
      cout << seg.query(l - 1, r).sum << '\n';
    } else if(op == 2) {
      int l, r, x;
      cin >> l >> r >> x;
      seg.update_mod(l - 1, r, x);
    } else {
      int k, x;
      cin >> k >> x;
      seg.update(k - 1, x);
    }
  }
  return 0;
}