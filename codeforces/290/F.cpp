#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, c[23][23], d[23], u[23];
main() {
  scanf("%d%d", &n, &m);
  for (int xt, yt, i = 1; i <= m; ++i) {
    scanf("%d%d", &xt, &yt);
    if (c[xt][yt] || xt == yt) continue;
    ++d[xt], ++d[yt];
    c[xt][yt] = c[yt][xt] = 1;
  }
  for (int j, co, p, mint, i = 1; i <= n; ++i) {
    fill(u, u + n + 1, 0);
    co = 0;
    for (j = i; !u[j]; j = p) {
      mint = n + n;
      p = j;
      u[j] = 1;
      ++co;
      for (int k = 1; k <= n; ++k)
        if (!u[k] && c[j][k] && (d[k] < mint || d[k] == mint && k < p))
          p = k, mint = d[k];
    }
    if (co == n) {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
}