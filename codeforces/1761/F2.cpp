// learned from huzhaoyang's code: https://codeforces.com/contest/1761/submission/196148211
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1000005, mod = 1000000007;
int n, m, res;
int a[maxn], pos[maxn];
int fac[maxn], ifac[maxn];
int l1[maxn], r1[maxn], l2[maxn], r2[maxn], f1[maxn], f2[maxn], sum[maxn];
int add(int x, int y) {
  x += y;
  return (x < mod ? x : x - mod);
}

int C(int n, int m) {
  if ((m < 0) || (m > n)) return 0;
  return (ll)fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int get_sum(int l, int r) {
  l = max(l, 0);
	r = min(r, n - 2);
  if (l > r) return 0;
  return add(sum[r], (l ? mod - sum[l - 1] : 0));
}

bool check(int l, int r) {
  if (l <= r) return l + r <= n + 1;
  return l + r > n + 1;
}

int calc(int l, int r, int x, int y) {
  return add(add(C(l + r, l), mod - C(l + r, x - 1 + r)), mod - C(l + r, y + 1 + r));
}

int move(int l1, int r1, int l2, int r2) {
  int l = (l1 - l2 + n) % n, r = (r2 - r1 + n) % n;
  if ((l + r >= n) || (!check(l2, r2))) return 0;
  if (l1 <= r1) return calc(l, r, l1 + r1 - n - 1, l1 + r1 - 2);
  return calc(l, r, -n, l1 + r1 - n - 2);
}

int work() {
  m = 0;
  for (int i = 1; i <= n; i++) pos[i] = 0;
  for (int i = 1; i <= n; i++) {	
    if (a[i] > 0) pos[a[i]] = ((i & 1) ? (i + 1 >> 1) : n - (i >> 1) + 1);
	}
	
  for (int i = 1; i <= n; i++) {
    if (pos[i]) {
      if (i == 1) {
				m++;
        l1[m] = r1[m] = l2[m] = r2[m] = pos[i];
				f1[m] = 1;
				f2[m] = 0;
			} else {
        l1[++m] = pos[i] % n + 1;
				r1[m] = (pos[i] + i - 2) % n + 1;
        l2[m] = (pos[i] + n - i) % n + 1;
				r2[m] = (pos[i] + n - 2) % n + 1;
        f1[m] = f2[m] = 0;
        if (m == 1) {
          for (int j = 1; j <= (n + 1 >> 1); j++) {
            f1[m] = add(f1[m], move(j, j, l1[m], r1[m]));
            f2[m] = add(f2[m], move(j, j, l2[m], r2[m]));
          }
        } else {
          f1[m] = (ll)f1[m - 1] * move(l1[m - 1], r1[m - 1], l1[m], r1[m]) % mod;
          f1[m] = (f1[m] + (ll)f2[m - 1] * move(l2[m - 1], r2[m - 1], l1[m], r1[m])) % mod;
          f2[m] = (ll)f1[m - 1] * move(l1[m - 1], r1[m - 1], l2[m], r2[m]) % mod;
          f2[m] = (f2[m] + (ll)f2[m - 1] * move(l2[m - 1], r2[m - 1], l2[m], r2[m])) % mod;
        }
        l1[m] = r2[m] = pos[i];
      }
			
      if (i < n) {
        if (!check(l1[m], r1[m])) f1[m] = 0;
        if (!check(l2[m], r2[m])) f2[m] = 0;
      }
    }
	}
	
  if (pos[n]) return f1[m];
  if (m) {
    int res = 0;
    for (int i = (n + 1 >> 1) + 1; i <= n; i++) {
      res = (res + (ll)f1[m] * move(l1[m], r1[m], i % n + 1, (i + n - 2) % n + 1)) % mod;
      res = (res + (ll)f2[m] * move(l2[m], r2[m], i % n + 1, (i + n - 2) % n + 1)) % mod;
    }
    return res;
  }
	
  int res = 0;
  sum[0] = 1;
  for (int i = 1; i <= n - 2; i++) sum[i] = add(sum[i - 1], C(n - 2, i));
  for (int i = 1; i <= (n + 1 >> 1); i++) {
    res = add(res, get_sum((n + 1 >> 1) - i, n - i - 1));
    res = add(res, mod - get_sum(i - (n >> 1) - 2, i - 3));
    res = add(res, mod - get_sum(i + (n + 1 >> 1) - 1, i + n - 2));
  }
  return res;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	res = work();
	for (int i = 1; i <= n; i++) {	
		if (a[i] > 0) a[i] = n - a[i] + 1;
	}
	cout << add(res, work()) << '\n';
}

int main() {
  fac[0] = ifac[0] = ifac[1] = 1;
  for (int i = 1; i < maxn; i++) fac[i] = (ll)fac[i - 1] * i % mod;
  for (int i = 2; i < maxn; i++) ifac[i] = (ll)(mod - mod / i) * ifac[mod % i] % mod;
  for (int i = 1; i < maxn; i++) ifac[i] = (ll)ifac[i - 1] * ifac[i] % mod;

	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
  while (t--) solve();
}