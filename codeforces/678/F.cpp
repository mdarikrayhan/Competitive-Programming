#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

struct line {
  mutable long long k, m, p;

  bool operator < (const line &o) const {
    return k < o.k;
  }

  bool operator < (long long x) const {
    return p < x;
  }
};

struct line_container : multiset<line, less<>> {
  static const long long INF = LLONG_MAX;

  long long div(long long a, long long b) {
    return a / b - ((a ^ b) < 0 && a % b);
  }

  bool isect(iterator x, iterator y) {
    if (y == end()) {
      x->p = INF;
      return false;
    }
    if (x->k == y->k) {
      x->p = x->m > y->m ? INF : -INF;
    } else {
      x->p = div(y->m - x->m, x->k - y->k);
    }
    return x->p >= y->p;
  }

  void add(long long k, long long m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) {
      z = erase(z);
    }
    if (x != begin() && isect(--x, y)) {
      isect(x, y = erase(y));
    }
    while ((y = x) != begin() && (--x)->p >= y->p) {
      isect(x, erase(y));
    }
  }

  long long query(long long x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};

struct segment_tree {
  line_container t[4 * N];
  long long res = LLONG_MIN;

  void upd(int id, int tl, int tr, int l, int r, int a, int b) {
    if (l <= tl && tr <= r) {
      t[id].add(a, b);
      return;
    }
    int tm = (tl + tr) >> 1;
    if (r <= tm) {
      upd(id << 1, tl, tm, l, r, a, b);
    } else if (tm + 1 <= l) {
      upd(id << 1 | 1, tm + 1, tr, l, r, a, b);
    } else {
      upd(id << 1, tl, tm, l, r, a, b);
      upd(id << 1 | 1, tm + 1, tr, l, r, a, b);
    }
  }

  void get(int id, int tl, int tr, int pos, int q) {
    if (tl <= pos && pos <= tr) {
      if (!t[id].empty()) {
        res = max(res, t[id].query(q));
      }
    }
    if (tl == tr) {
      return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
      get(id << 1, tl, tm, pos, q);
    } else {
      get(id << 1 | 1, tm + 1, tr, pos, q);
    }
  }
};

int n;
int t[N];
int a[N], b[N];
int q[N];
segment_tree st;
bool rmv[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    if (t[i] == 1) {
      cin >> a[i] >> b[i];
      rmv[i] = true;
    } else if (t[i] == 2) {
      int id;
      cin >> id;
      st.upd(1, 1, n, id, i - 1, a[id], b[id]);
      rmv[id] = false;
    } else if (t[i] == 3) {
      cin >> q[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (rmv[i]) {
      st.upd(1, 1, n, i, n, a[i], b[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (t[i] == 3) {
      st.res = LLONG_MIN;
      st.get(1, 1, n, i, q[i]);
      if (st.res == LLONG_MIN) {
        cout << "EMPTY SET" << '\n';
      } else {
        cout << st.res << '\n';
      }
    }
  }
  return 0;
}
