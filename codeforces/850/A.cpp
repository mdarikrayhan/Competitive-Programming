#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "./algo/debug.h"
#endif

struct Point {
  vector<int> a;
  Point() {
    a.resize(5);
  }
  long double operator* (Point b) {
    int ans = 0;
    for (int i = 0; i < 5; i++) {
      ans += a[i] * b.a[i];
    }
    return ans;
  }
  Point operator- (Point b) {
    Point c = *this;
    for (int i = 0; i < 5; i++) {
      c.a[i] -= b.a[i];
    }
    return c;
  }
};

using Vector = Point;
const long double HPI = acosl(0);

long double mag(Vector& v1) {
  return sqrtl(v1 * v1);
}

long double calc(Vector& v1, Vector& v2) {
  return acosl(v1 * v2 / (mag(v1) * mag(v2)));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<Point> a(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a[i].a[j];
    }
  }
  if (n < 3) {
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
      cout << i + 1 << '\n';
    }
    return 0;
  }
  if (n > 15) {
    cout << "0\n";
    return 0;
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    vector<Vector> b;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      b.push_back(a[j] - a[i]);
    }
    Vector ref = b[0];
    sort(b.begin(), b.end(), [&](Vector& v1, Vector& v2) {
      return calc(ref, v1) < calc(ref, v2);
    });
    int m = b.size();
    bool ok = true;
    for (int i = 1; i < m; i++) {
      if (fabs(calc(b[i], b[i - 1])) < HPI) {
        ok = false;
        break;
      }
    }
    if (ok) ans.push_back(i);
  }
  cout << ans.size() << '\n';
  for (int i : ans) {
    cout << i + 1 << '\n';
  }
  return 0;
}