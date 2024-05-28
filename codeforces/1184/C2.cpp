#include <bits/stdc++.h>
 
using namespace std;

struct node {
  int s, mx;

  node(int v = 0) : s(v), mx(v) {}

  inline void operator += (int v) {
    s += v;
    mx += v;
  }
};

node operator + (node &a, node &b) {
  node ret;
  ret.s = a.s + b.s;
  ret.mx = max(a.mx, a.s + b.mx);
  return ret;
}

struct SegmentTree {
  vector<node> st;
  int n;

  SegmentTree(int _n) {
    n = 1;
    while (n < _n) {
      n *= 2;
    }
    st.resize(2 * n);
  }

  void Modify(int pos, int val) {
    for (st[pos += n] += val; pos > 1; pos >>= 1) {
      st[pos / 2] = st[pos / 2 * 2] + st[pos / 2 * 2 + 1];
    }
  }

  int Get() {
    return st[1].mx;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, r;
  cin >> n >> r;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  // (x, y) -> (x - y, x + y)
  vector<int> xs, ys;
  for (int i = 0; i < n; i++) {
    xs.push_back(x[i] - y[i] - r);
    xs.push_back(x[i] - y[i] + r);
    ys.push_back(x[i] + y[i] - r);
    ys.push_back(x[i] + y[i] + r);
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());
  int kx = (int) xs.size();
  int ky = (int) ys.size();
  vector<vector<pair<int, int>>> open(kx);
  vector<vector<pair<int, int>>> close(kx);
  for (int i = 0; i < n; i++) {
    int lx = (int) (lower_bound(xs.begin(), xs.end(), x[i] - y[i] - r) - xs.begin());
    int rx = (int) (lower_bound(xs.begin(), xs.end(), x[i] - y[i] + r) - xs.begin());
    int ly = (int) (lower_bound(ys.begin(), ys.end(), x[i] + y[i] - r) - ys.begin());
    int ry = (int) (lower_bound(ys.begin(), ys.end(), x[i] + y[i] + r) - ys.begin());
    open[lx].emplace_back(ly, ry);
    close[rx].emplace_back(ly, ry);
  }
  SegmentTree st(ky);
  vector<int> val(ky);
  int res = 0;
  for (int i = 0; i < kx; i++) {
    for (auto &p : open[i]) {
      st.Modify(p.first, +1);
      if (p.second + 1 < ky) {
        st.Modify(p.second + 1, -1);
      }
    }
    res = max(res, st.Get());
    for (auto &p : close[i]) {
      st.Modify(p.first, -1);
      if (p.second + 1 < ky) {
        st.Modify(p.second + 1, +1);
      }
    }
  }
  cout << res << '\n';
  return 0;
}