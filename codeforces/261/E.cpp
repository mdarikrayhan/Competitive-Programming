#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e6 + 9;
int l, r, p, v[N], bel[N], t, f[N], ans;
bool vst[N];
void init() {
  constexpr int prm[]{2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                      43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97},
      C = sizeof(prm) / sizeof(*prm);
  v[++t] = 1, bel[t] = 0;
  for (int i = 1; i <= t; ++i) {
    int w = v[i], z = bel[i];
    while (z < C && prm[z] <= p) {
      auto f = 1ll * w * prm[z];
      if (f > r) break;
      v[++t] = f, bel[t] = z++;
    }
  }
  sort(v + 1, v + t + 1);
}
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> l >> r >> p, init();
  memset(f + 2, 0x3f, (t - 1) * sizeof(int));
  for (int i = 2; i <= p; ++i)
    for (int j = i, g = 1; v[g] * i <= v[t]; ++g) {
      while (j <= t && v[j] != v[g] * i) ++j;
      if ((f[j] = min(f[j], f[g] + 1)) > p - i) continue;
      if (v[j] >= l && !vst[j]) ans += vst[j] = true;
    }
  return cout << ans << endl, 0;
}
