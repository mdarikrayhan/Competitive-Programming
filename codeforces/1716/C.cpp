/*
 * temp.cc
 * written by retired_user
 * 2022-08-05 17:30:05
 */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include </algo/debug.h>
#else
#define debug(...) 42
#endif
#define tr(x, v) for (auto &x : v)
#define rp(i, v) for (int i = 0; i < sz(v); i++)
#define rep(i, x, y) for (int i = x; i < y; i++)
#define pr(i, v) for (int i = sz(v) - 1; i >= 0; i--)
#define per(i, x, y) for (int i = x; i > y; i--)
template <typename T> void cmin(T &x, const T &y) {
  if (x > y)
    x = y;
}
template <typename T> void cmax(T &x, const T &y) {
  if (x < y)
    x = y;
}
using ll = long long;
using E = vector<vector<int>>;
using EW = vector<vector<array<int, 2>>>;
mt19937 rng(time(NULL));
const int inf = 1000000000;
const ll lnf = 1000000000000000000;
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define ed(x) end(x)
#define all(x) bg(x), ed(x)
#define lb lower_bound
#define ub upper_bound
#define sort(x) sort(all(x))
#define unique(x) (x).erase(unique(all(x)), x.end())
#define rev(x) reverse(all(x))

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int a[2][n], b[2][n + 1];
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    rep(i, 0, 2) rep(j, 0, n) cin >> a[i][j], a[i][j] += !!(i + j);
    b[0][n] = b[1][n] = 0;
    per(i, n - 1, -1) rep(k, 0, 2) b[k][i] =
        max({a[k ^ 1][i], a[k][i] + 2 * (n - i) - 1, b[k][i + 1] + 1});
    int ans = inf << 1, cur = 0;
    rep(i, 0, n) {
      int k = i & 1;
      ans = min(ans, max(cur, b[k][i]));
      cur = max(cur, a[k][i] + 2 * (n - i) - 1);
      cur = max(cur, a[k ^ 1][i] + 2 * (n - i) - 2);
    }
    cout << ans << "\n";
  }
  return 0;
}