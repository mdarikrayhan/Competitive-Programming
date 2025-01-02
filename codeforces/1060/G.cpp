// LUOGU_RID: 160586915
#include <bits/stdc++.h>
using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__)

using LL = long long;

struct BIT {
  int n;
  vector<int> a;
  BIT(int n) : n(n), a(n + 1) {}
  void mdf(int x, int v) {
    for (int i = x + 1; i <= n; i += i & -i) {
      a[i] += v;
    }
  }
  int qry(int x) {
    int res = 0;
    for (int i = x + 1; i > 0; i -= i & -i) {
      res += a[i];
    }
    return res;
  }
  int find(int x) {
    int cur = 0, s = 0;
    for (int i = __lg(n); i >= 0; --i) {
      if (cur + (1 << i) > n) {
        continue;
      }
      if (s + a[cur + (1 << i)] < x) {
        cur += 1 << i;
        s += a[cur];
      }
    }
    return cur;
  }
  void clear() {
    fill(a.begin(), a.end(), 0);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int m, n;
  cin >> n >> m;
  vector<LL> a(n), c(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<LL> b(m), k(m), ans(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i] >> k[i];
    if (b[i] < a[0]) {
      ans[i] = b[i];
    }
  }
  vector<int> o(m);
  iota(o.begin(), o.end(), 0);
  sort(o.begin(), o.end(), [&](auto i, auto j) {
    return b[i] < b[j];
  });
  BIT bit(n);
  for (int i = 0; i < n; ++i) {
    bit.mdf(i, 1);
  }
  int cur = m - 1;
  LL l = 1e18, r = l + n - 1, t = 0;
  for (int i = n - 1; i >= 0; --i) {
    while (cur >= 0) {
      int u = o[cur];
      LL v = (l - b[u] + i) / (i + 1);
      LL nl = l - v * (i + 1), nr = r - v * (i + 1);
      if (nr < a[i]) break;
      k[u] = t + v - k[u];
      b[u] = bit.find(b[u] - nl + 1);
      cur--;
    }
    LL v = (l - a[i] + i) / (i + 1);
    LL nl = l - v * (i + 1), nr = r - v * (i + 1);
    bit.mdf(c[i] = bit.find(a[i] - nl + 1), -1);
    while (i - 1 >= 0 && a[i - 1] >= nl) {
      --i;
      bit.mdf(c[i] = bit.find(a[i] - nl + 1), -1);
    }
    t += v + 1;
    r = nl - 1;
    l = r - i + 1;
  }
  for (int i = cur; i >= 0; --i) {
    k[o[i]] = -1;
  }
  sort(o.begin(), o.end(), [&](auto i, auto j) {
    return k[i] > k[j];
  });
  bit.clear();
  for (int i = 0; i < n; ++i) {
    bit.mdf(i, 1);
  }
  cur = m - 1;
  l = 1e18, r = l + n - 1, t = 0;
  for (int i = n - 1; i >= 0; --i) {
    while (cur >= 0) {
      int u = o[cur];
      if (k[u] == -1) {
        cur--;
        continue;
      }
      LL v = k[u] - t;
      LL nl = l - v * (i + 1), nr = r - v * (i + 1);
      if (nr < a[i]) break;
      ans[u] = nl + bit.qry(b[u]) - 1;
      cur--;
    }
    LL v = (l - a[i] + i) / (i + 1);
    LL nl = l - v * (i + 1), nr = r - v * (i + 1);
    bit.mdf(c[i], -1);
    while (i - 1 >= 0 && a[i - 1] >= nl) {
      --i;
      bit.mdf(c[i], -1);
    }
    t += v + 1;
    r = nl - 1;
    l = r - i + 1;
  }
  for (int i = 0; i < m; ++i) {
    cout << ans[i] << "\n";
  }
  return 0;
}