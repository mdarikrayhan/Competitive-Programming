#include <bits/stdc++.h>
#define f first
#define s second
#define int long long
using namespace std;
const int N = 2e5 + 69;
struct Line {
  int n, k;
  int val(int x) {
    return x * k + n;
  }
} st[4 * N];
int n, a[N], p[N];
void AddLine(int v, int tl, int tr, Line &t) {
  int mid = (tl + tr) / 2;
  if (st[v].val(mid) < t.val(mid))
    swap(t, st[v]);
  if (tl == tr)
    return;
  if (st[v].val(tl) < t.val(tl)) 
    AddLine(v * 2, tl, mid, t);
  else 
    AddLine(v * 2 + 1, mid + 1, tr, t);
}
int Get(int v, int tl, int tr, int x) {
  if (tl == tr)
    return st[v].val(x);
  else {
    int mid = (tl + tr) / 2;
    if (x <= mid)
      return max(st[v].val(x), Get(v * 2, tl, mid, x));
    else
      return max(st[v].val(x), Get(v * 2 + 1, mid + 1, tr, x));
  }
}
void reset(int v, int tl, int tr, int p) {
  st[v] = {0, 0};
  if (tl == tr)
    return;
  else {
    int mid = (tl + tr) / 2;
    if (p <= mid)
      reset(v * 2, tl, mid, p);
    else
      reset(v * 2 + 1, mid + 1, tr, p);
  }
}
int Solve(int L, int R) {
  if (L == R)
    return max(0ll, a[L]);
  int mid = (L + R) / 2, k = 1, sum = 0;
  int d = R - L + 1;
  for (int i = mid + 1;i <= R;i++) {
    sum += k * a[i];
    k++;
    Line t = {sum, p[i] - p[mid]};
    AddLine(1, 1, n, t);
  } 
  int res = 0;
  sum = 0, k = 1;
  int s = 0;
  for (int i = L;i <= mid;i++) {
    sum += k * a[i];
    k++;
  }
  for (int i = L;i <= mid;i++) {
    res = max(res, sum + Get(1, 1, n, mid - i + 1));
    sum -= p[mid] - p[i - 1];
  }
  for (int i = 1;i <= d;i++)
    reset(1, 1, n, i);
  return max({Solve(L, mid), Solve(mid + 1, R), res});
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  //cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 1;i <= n;i++)
      cin >> a[i];
    for (int i = 1;i <= n;i++)
      p[i] = p[i - 1] + a[i];
    cout << Solve(1, n) << '\n';
  }
  return 0; 
}