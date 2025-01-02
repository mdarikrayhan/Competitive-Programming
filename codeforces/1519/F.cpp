// LUOGU_RID: 160423999
#include <bits/stdc++.h>
using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

i64 getclock() { return (i64)1000 * clock() / CLOCKS_PER_SEC; }
mt19937_64 MT(time(nullptr));
i64 MTin(i64 l, i64 r) { return l + (i64)(MT() % (u64)(r - l + 1)); }
double MTreal() { return (double)MT() / (double)MT.max(); }

const u32 rmsk32 = MT() ^ (MT() >> 3) ^ (MT() << 11);
u32 XS32(u32 x) { return x ^= rmsk32, x ^= x << 6, x ^= x >> 1, x ^= x << 11, x ^= rmsk32; }
const u64 rmsk64 = MT() ^ (MT() >> 3) ^ (MT() << 17);
u64 XS64(u64 x) { return x ^= rmsk64, x ^= x << 6, x ^= x >> 1, x ^= x << 17, x ^= rmsk64; }

int n, m;
int a[7], b[7], c[7][7];
int f[7][5 * 5 * 5 * 5 * 5 * 5];
int ok[5 * 5 * 5 * 5 * 5 * 5];

int pw5[15];
int getd(int x, int i) {
  return x / pw5[i] % 5;
}
int setd(int x, int i, int d) {
  return x + (d - getd(x, i)) * pw5[i];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i += 1) {
    cin >> a[i];
  }
  for (int j = 1; j <= m; j += 1) {
    cin >> b[j];
  }
  for (int i = 1; i <= n; i += 1) {
    for (int j = 1; j <= m; j += 1) {
      cin >> c[i][j];
    }
  }
  pw5[0] = 1;
  for (int i = 1; i <= m; i += 1) {
    pw5[i] = pw5[i - 1] * 5;
  }
  
  for (int j = 0; j < pw5[m]; j += 1) {
    ok[j] = 1;
    for (int i = 1; i <= m; i += 1) {
      if (getd(j, i - 1) > b[i]) {
        ok[j] = 0;
      }
    }
  }
  memset(f, 0x3f, sizeof(f));
  f[0][0] = 0;
  
  for (int i = 1; i <= n; i += 1) {
    for (int j = 0; j < pw5[m]; j += 1) {
      if (ok[j]) {
        auto dfs = [&](const auto &self, int pt, int lst, int stat, int use) -> void {
          if (pt > a[i]) {
            int cst = 0;
            for (int p = 1; p <= m; p += 1) {
              if (use >> (p - 1) & 1) {
                cst += c[i][p];
              }
            }
            f[i][j] = min(f[i][j], f[i - 1][stat] + cst);
            return;
          }
          for (int p = lst; p <= m; p += 1) {
            if (getd(stat, p - 1) >= 1) {
              self(self, pt + 1, p, stat - pw5[p - 1], use | (1 << (p - 1)));
            }
          }
        };
        dfs(dfs, 1, 1, j, 0);
      }
    }
  }
  
  int ans = 0x3f3f3f3f;
  for (int j = 0; j < pw5[m]; j += 1) {
    ans = min(ans, f[n][j]);
  }
  if (ans == 0x3f3f3f3f) {
    ans = -1;
  }
  cout << ans << "\n";
  return 0;
}
