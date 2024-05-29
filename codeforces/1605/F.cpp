// LUOGU_RID: 159963067
#include <bits/stdc++.h>
typedef long long ll;
using std::max; using std::min;
#define INF 1e18
#define rd() read<ll>()
#define lowbit(x) -x & x
#define E(i, l, r) for (int i = l; i <= r; ++ i)
#define FILE(filename) { \
  freopen(#filename ".in", "r", stdin); \
  freopen(#filename ".out", "w", stdout); \
}
template <typename T> inline T read() {
  T x = 0; char c = getchar(); bool f = 0;
  while (c < '0' || c > '9') {if (c == '-') f = 1; c = getchar();}
  while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return f ? -x : x;
}
template <typename T> void write(T x) {
  if (x < 0) {putchar('-'); x = -x;}
  if (x / 10) write(x / 10);
  putchar((x % 10) ^ 48);
}
namespace pigeon {
  const int N = 105;
  int n, m, mod, ans;
  int f[N][N], g[N][N], h[N][N];
  int fact[N], finv[N], ba[N * N], mv[2];
  int qpow(int x, int y = mod - 2) {
    int res = 1;
    while (y) {
      if (y & 1) res = 1ll * res * x % mod;
      x = 1ll * x * x % mod; y >>= 1;
    } return res;
  }
  int mto(int x, int y) {int res = 1; E(i, x - y + 1, x) res = 1ll * res * i % mod; return res;}
  int C(int x, int y) {return x < y || x < 0 || y < 0 ? 0 : 1ll * fact[x] * finv[y] % mod * finv[x - y] % mod;}
  void Main() {
    n = rd(); m = rd(); mod = rd();
    mv[1] = mod - 1;
    fact[0] = finv[0] = ba[0] = mv[0] = 1;
    E(i, 1, 10000) ba[i] = ba[i - 1] * 2 % mod;
    E(i, 1, 100) fact[i] = 1ll * fact[i - 1] * i % mod;
    finv[100] = qpow(fact[100]);
    for (int i = 99; i; -- i)
      finv[i] = 1ll * finv[i + 1] * (i + 1) % mod;
    E(i, 0, n) E(j, 0, m) E(k, 0, j) {
      f[i][j] = (f[i][j] + 1ll * C(j, k) * mv[(j - k) & 1] % mod * ba[i * k] % mod) % mod;
      h[i][j] = (h[i][j] + 1ll * C(j, k) * mv[(j - k) & 1] % mod * mto(ba[k] - 1, i)) % mod;
    }
    E(i, 0, n) E(j, 0, m) E(x, 0, i - 1) E(y, 0, j - 1)
      if (!(n & 1) || i != n || x != n - 1)
        g[i][j] = (g[i][j] + 1ll * C(i, x) * C(j, y) % mod * ba[(i - x) * y] % mod * h[i - x][j - y] % mod * (f[x][y] - g[x][y] + mod) % mod) % mod;
    E(i, 0, m) ans = (ans + 1ll * C(m, i) * (f[n][i] - g[n][i] + mod) % mod) % mod;
    write(ans);
  }
}
int main() {
  int T = 1;
  while (T --) pigeon::Main();
  return 0;
}