#include <bits/stdc++.h>
 
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int q;
  cin >> q;
  vector<int> l(q), r(q);
  for (int i = 0; i < q; i++) {
    cin >> l[i] >> r[i];
    --l[i]; --r[i];
  }
  vector<int> xs;
  for (int i = 0; i < n; i++) {
    xs.push_back(a[i]);
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  for (int i = 0; i < n; i++) {
    a[i] = (int) (lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin());
  }
  vector<int> order(q);
  iota(order.begin(), order.end(), 0);
  const int B = 350;
  sort(order.begin(), order.end(), [&](int i, int j) {
    if (l[i] / B != l[j] / B) {
      return l[i] < l[j];
    } else {
      return r[i] < r[j];
    }
  });
  int cur = 0;
  int good = 0;
  int ll = 0, rr = -1;
  vector<int> cnt(n);
  vector<deque<int>> dq(n);
  vector<deque<int>> v(n);
  vector<int> f(n);
  auto Add = [&](int i) {
    int x = a[i];
    cnt[x] += 1;
    if (cnt[x] == 1) {
      cur += 1;
      dq[x].push_back(i);
      good += 1;
      return;
    }
    if (f[x] == 0) {
      good -= 1;
    }
    if (i < dq[x].front()) {
      int d = dq[x].front() - i;
      if (!v[x].empty() && v[x].front() != d) {
        f[x] += 1;
      }
      v[x].push_front(d);
      dq[x].push_front(i);
    } else {
      int d = i - dq[x].back();
      if (!v[x].empty() && v[x].back() != d) {
        f[x] += 1;
      }
      v[x].push_back(d);
      dq[x].push_back(i);
    }
    if (f[x] == 0) {
      good += 1;
    }
  };
  auto Remove = [&](int i) {
    int x = a[i];
    cnt[x] -= 1;
    if (cnt[x] == 0) {
      cur -= 1;
      dq[x].pop_back();
      good -= 1;
      return;
    }
    if (f[x] == 0) {
      good -= 1;
    }
    if (i == dq[x].front()) {
      int d = v[x].front();
      v[x].pop_front();
      dq[x].pop_front();
      if (!v[x].empty() && v[x].front() != d) {
        f[x] -= 1;
      }
    } else {
      assert(i == dq[x].back());
      int d = v[x].back();
      v[x].pop_back();
      dq[x].pop_back();
      if (!v[x].empty() && v[x].back() != d) {
        f[x] -= 1;
      }
    }
    if (f[x] == 0) {
      good += 1;
    }
  };
  vector<int> ans(q);
  for (int i : order) {
    while (rr < r[i]) {
      Add(++rr);
    }
    while (ll > l[i]) {
      Add(--ll);
    }
    while (rr > r[i]) {
      Remove(rr--);
    }
    while (ll < l[i]) {
      Remove(ll++);
    }
    ans[i] = cur + (good == 0 ? 1 : 0);
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}