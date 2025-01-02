// LUOGU_RID: 159207758
#include <bits/stdc++.h>

#define FOR(i, l, r) for (int i = l; i <= (r); ++i)
#define ROF(i, l, r) for (int i = r; i >= (l); --i)
#define rep(n) FOR (_, 1, n)
#define each(i, x) for (auto& i : x)

using namespace std;

using ll = long long;
using db = long double;
using str = string;

#define mp make_pair
#define f first
#define s second

#define il inline
#define ttt template <typename T
ttt > using V = vector<T>;
ttt, size_t n > using A = array<T, n>;

#define sz(x) int((x).size())
#define bg begin
#define all(x) bg(x), end(x)
#define rsz resize
#define pb push_back
#define eb emplace_back

constexpr int mod = 1e9 + 7;

constexpr int N = 1e6 + 5;
int n;
ll ans = 1;
V<int> pri;
A<int, N> b, f, lp, quo, in, out, cnt;
A<bool, N> is;

void sieve() {
  is.fill(true), f[1] = lp[1] = quo[1] = 1;
  FOR (i, 2, n) {
    if (is[i]) pri.pb(i), b[i] = 1, f[i] = lp[i] = i, quo[i] = n / i;
    each (p, pri) {
      int j = i * p;
      if (j > n) break;
      is[j] = false, lp[j] = p;
      if (p != lp[i])
        f[j] = f[i] * p, b[j] = i;
      else {
        f[j] = f[i], b[j] = b[i];
        break;
      }
    }
  }
}
bool mk_map(int n, int m) {
  if (n == 1 && m == 1) return in[1] = out[1] = 1;
  while (n > 1 || m > 1) {
    int p = lp[n], q = lp[m];
    if (quo[p] != quo[q] || (out[p] && out[p] != q) || (in[q] && in[q] != p))
      return false;
    out[p] = q, in[q] = p;
    n = b[n], m = b[m];
  }
  return n <= 1 && m <= 1;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false), cin.exceptions(cin.failbit);

  cin >> n, sieve();
  FOR (i, 1, n) {
    int a;
    cin >> a;
    if (a == 0)
      ans = ans * ++cnt[f[i]] % mod;
    else if (!mk_map(i, a))
      return cout << "0\n", 0;
  }
  cnt.fill(0);
  FOR (i, 1, n)
    if (is[i] && !out[i]) ans = ans * ++cnt[quo[i]] % mod;
  cout << ans << "\n";
}
