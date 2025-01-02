#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 100005;
int a[maxn], res[maxn];

int f(int x, int y, int k) {
	return (x - 1) * k + y;
}

void get(int n, int k) {
  if (!(k & 1)) {
    for (int i = 1; i <= n >> 1; i++) {
      a[(i << 1) - 1] = i, a[i << 1] = n + 1 - i;
    }
    return;
  }

  int m = n / k, cur = 3 * m;
  for (int j = 4; j <= k; j++) {
    if (j & 1) {
      for (int i = m; i >= 1; i -= 1) a[f(i, j, k)] = ++cur;
    } else {
      for (int i = 1; i <= m; i++) a[f(i, j, k)] = ++cur;
    }
  }

  for (int i = 1; i <= (m + 1 >> 1); i++) {
    a[f(i, 1, k)] = (i << 1) - 1;
    a[f(i, 2, k)] = ((3 * m + 3) >> 1) - i;
    a[f(i, 3, k)] = 3 * m - i + 1;
  }

  for (int i = (m + 3 >> 1); i <= m; i++) {
    int delta = i - (m + 3 >> 1);
    a[f(i, 1, k)] = ((3 * m + 3) >> 1) + delta;
    a[f(i, 2, k)] = (m << 1) + 1 + delta;
    a[f(i, 3, k)] = m - (m & 1) - (delta << 1);
  }
}

int n, k;
void answer() {
  ll sum = 0;
  for (int i = 1; i <= k; i++) sum += res[i];
  ll mn = sum;
  for (int i = k + 1; i <= n; i++) {
    sum += res[i] - res[i - k];
    mn = min(mn, sum);
  }
  cout << mn << '\n';
  for (int i = 1; i <= n; i++) cout << res[i] << ' ';
  cout << '\n';
}

void solve() {
	cin >> n >> k;
    if (!(n % k)) {
      get(n, k);
      for (int i = 1; i <= n; i++) res[i] = a[i];
      answer();
      return;
    }

    int q = n / k, r = n % k;
    if (r == 1) {
      int cur = 0, delta = (q << 1) + 1;
      for (int i = 1; i <= n; i += k) res[i] = ++cur;
      for (int i = n - k + 1; i >= 2; i -= k) res[i] = ++cur;
      get(q * (k - 2), k - 2);
  cur = 0;
      for (int i = 3; i <= n; i += k)
        for (int j = i; j <= i + k - 3; j++) res[j] = a[++cur] + delta;
      answer();
      return;
    }

    if (k - r == 1) {
      if (q == 1) {
        int cur = 0;
        res[k] = n;
        get(n - 1, k - 1);
        for (int i = 1; i < k; i++) res[i] = a[++cur];
        for (int i = k + 1; i <= n; i++) res[i] = a[++cur];
        answer();
        return;
      }

      int cur = n + 1, delta = q + 1;
      for (int i = k; i <= n; i += k) res[i] = --cur;
      cur = 0;
      for (int i = 1; i <= n; i += k) res[i] = ++cur;
      get((q + 1) * (r - 1), r - 1);
  cur = 0;
      for (int i = 2; i <= n; i += k) {
        for (int j = i; j <= i + r - 2; j++) res[j] = a[++cur] + delta;
      }
      answer();
      return;
    }

    int cur = 0, delta = (q + 1) * r;
    get((q + 1) * r, r);
    for (int i = 1; i <= n; i += k) {
      for (int j = i; j <= i + r - 1; j++) res[j] = a[++cur];
    }
    get(q * (k - r), k - r), cur = 0;
    for (int i = r + 1; i <= n; i += k) {
      for (int j = i; j <= i + (k - r) - 1; j++) res[j] = a[++cur] + delta;
    }
    answer();
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}