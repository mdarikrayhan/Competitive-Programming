// LUOGU_RID: 160012129
#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const LL kMaxN = 2e4 + 5, kMaxM = 5, kM = 1e9 + 7;

LL n, m, cnt, sum[kMaxM], pty[kMaxN], l[kMaxN], r[kMaxN], ty[kMaxN], d[kMaxM][kMaxN];
struct M {
  LL a[kMaxM][kMaxM] = {0};
};

M Mul(M a, M b) {
  M c;
  for (LL i = 1; i <= 3; i++) {
    for (LL j = 1; j <= 3; j++) {
      for (LL k = 1; k <= 3; k++) {
        c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % kM;
      }
    }
  }
  return c;
}
M qpow(M a, LL n) {
  M b; b.a[1][1] = b.a[2][2] = b.a[3][3] = 1;
  for (LL i = 1; i <= n; a = Mul(a, a), i <<= 1) {
    n & i && (b = Mul(b, a), 0);
  }  
  return b;
}

signed main() {
  cin >> n >> m, pty[++cnt] = 1, pty[++cnt] = m;
  for (LL i = 1; i <= n; i++) {
    cin >> ty[i] >> l[i] >> r[i];
    pty[++cnt] = l[i] - 1, pty[++cnt] = r[i];
  }
  sort(pty + 1, pty + cnt + 1), cnt = unique(pty + 1, pty + cnt + 1) - pty - 1;
  for (LL i = 1; i <= n; i++) {
    l[i] = lower_bound(pty + 1, pty + cnt + 1, l[i]) - pty;
    r[i] = lower_bound(pty + 1, pty + cnt + 1, r[i]) - pty, d[ty[i]][l[i]]++, d[ty[i]][r[i] + 1]--;
  }
  M ans; ans.a[1][2] = 1;
  for (LL i = 2; i <= cnt; i++) {
    M ma; ma.a[1][1] = ma.a[1][2] = ma.a[2][1] = ma.a[2][2] = ma.a[2][3] = ma.a[3][2] = ma.a[3][3] = 1;
    for (LL j = 1; j <= 3; j++) {
      sum[j] += d[j][i];
      if (sum[j]) {
        ma.a[1][j] = ma.a[2][j] = ma.a[3][j] = 0;
      }
    }
    ans = Mul(ans, qpow(ma, pty[i] - pty[i - 1]));
  }
  cout << ans.a[1][2];
}