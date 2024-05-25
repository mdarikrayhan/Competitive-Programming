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
#define reverse(x) reverse(all(x))

int query(int a, int b) {
  cout << "? " << a + 1 << " " << b + 1 << "\n";
  fflush(stdout);
  int x;
  cin >> x;
  return x;
}

void submit(int x) {
  cout << "! " << x + 1 << "\n";
  fflush(stdout);
}

int get2(int a, int b) {
  int p0 = query(a, b);
  if (p0 == 1) { // a > b
    return a;
  } else {
    return b;
  }
}

int get4(int a, int b, int c, int d) {
  int p0 = query(a, c), p1;
  if (p0 == 0) { // a = c = 0
    p1 = query(b, d);
    if (p1 == 1) { // b > d
      return b;
    } else {
      return d;
    }
  } else if (p0 == 2) { // a < c
    p1 = query(b, c);
    if (p1 == 2) { // b < c
      return c;
    } else {
      return b;
    }
  } else if (p0 == 1) { // a > c
    p1 = query(a, d);
    if (p1 == 1) { // a > d
      return a;
    } else {
      return d;
    }
  }
}

int solve(vector<int> a) {
  if ((int)a.size() == 1) {
    return a[0];
  }
  if ((int)a.size() == 2) {
    return get2(a[0], a[1]);
  }
  vector<int> b((int)a.size() / 4);
  for (int i = 0; i < a.size(); i += 4) {
    b[i / 4] = get4(a[i], a[i + 1], a[i + 2], a[i + 3]);
  }
  return solve(b);
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;

    vector<int> a(1 << n);
    iota(all(a), 0);

    submit(solve(a));
  }
  return 0;
}