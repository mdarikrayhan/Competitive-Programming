// LUOGU_RID: 159196174
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using std::max; using std::min;
#define INF 1e18
#define rd() read<ll>()
#define lowbit(x) -x & x
#define E(i, l, r) for (ull i = l; i <= r; ++ i)
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
  const int N = 2e5 + 5;
  ull t[N];
  ull n, m, in[N];
  ull a, b, c, ans;
  ull ax[N], ay[N];
  std::vector<ull> E[N], G[N];
  void Main() {
    n = rd(); m = rd();
    a = rd(); b = rd(); c = rd();
    E(i, 1, m) {
      ull x, y;
      x = rd() + 1; y = rd() + 1;
      ax[i] = x; ay[i] = y;
      ++ in[x]; ++ in[y];
      E[x].push_back(y); E[y].push_back(x);
    }
    E(i, 1, m) {
      ull x = ax[i], y = ay[i];
      if (in[x] > in[y] || (in[x] == in[y] && x > y)) std::swap(x, y);
      G[x].push_back(y);
    }
    E(i, 1, n) {
      ans += a * (n - i) * (n - i - 1) / 2 * (i - 1);
      ans += b * (i - 1) * (n - i) * (i - 1);
      ans += c * (i - 1) * (i - 2) / 2 * (i - 1);
    }
    E(i, 1, n)
      for (auto j : G[i]) {
        ull x = min(i, j);
        ull y = max(i, j);
        ans -= a * (x - 1) * (n - x - 1) + b * (x - 1) * (x - 1) + c * (y - 1) * (y - 2);
        ans -= b * (y - 1) * (n - y) + a * (x - 1) * (x - 2) / 2 + b * (y + x - 2) * (y - x - 1) / 2;
        ans -= c * (n + y - 1) * (n - y) / 2;
      }
    E(i, 1, n) {
      E[i].push_back(i);
      std::sort(E[i].begin(), E[i].end());
      ull len = E[i].size() - 1;
      E(k, 0, len) {
        ull j = E[i][k];
        if (i != j) {
          if (j < i) {
            ans += a * (j - 1) * (len - k - 1);
            ans += b * (j - 1) * k;
          }
          else {
            ans += b * (j - 1) * (len - k);
            ans += c * (j - 1) * (k - 1);
          }
        }
        else {
          ans += a * (len - k) * (len - k - 1) / 2 * (i - 1);
          ans += b * k * (len - k) * (i - 1);
          ans += c * k * (k - 1) / 2 * (i - 1);
        }
      }
    }
    E(i, 1, n) {
      for (auto j : G[i]) t[j] = i;
      for (auto j : G[i])
        for (auto k : G[j]) {
          if (t[k] != i) continue;
          ull aa[] = {i, j, k};
          std::sort(aa, aa + 3);
          ans -= (aa[0] - 1) * a + (aa[1] - 1) * b + (aa[2] - 1) * c;
        }
    } write(ans);
  }
}
int main() {
  int T = 1;
  while (T --) pigeon::Main();
  return 0;
}