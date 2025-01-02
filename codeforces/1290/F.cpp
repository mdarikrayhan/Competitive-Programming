#include <bits/stdc++.h>

using namespace std;

const int md = (int) 998244353;

inline void add(int& a, int b) {
  a += b;
  if (a >= md) a -= md;
}

int n, m;
int x[5], y[5];
int dp[30][20][20][20][20][2][2];

int sol(int j, int px, int nx, int py, int ny, int ex, int ey) {
  if ((1 << j) > m) {
    return (!px && !nx && !py && !ny && !ex && !ey);
  }
  int& ret = dp[j][px][nx][py][ny][ex][ey];
  if (ret != -1) {
    return ret;
  }
  ret = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    int npx = px, nnx = nx, npy = py, nny = ny;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        npx += max(x[i], 0); nnx += abs(min(x[i], 0));
        npy += max(y[i], 0); nny += abs(min(y[i], 0));
      }
    }
    if ((npx & 1) != (nnx & 1)) {
      continue;
    }
    if ((npy & 1) != (nny & 1)) {
      continue;
    }
    int b = ((m >> j) & 1);
    int nex = ((npx & 1) > b ? 1 : ((npx & 1) < b ? 0 : ex));
    int ney = ((npy & 1) > b ? 1 : ((npy & 1) < b ? 0 : ey));
    add(ret, sol(j + 1, npx >> 1, nnx >> 1, npy >> 1, nny >> 1, nex, ney));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  memset(dp, -1, sizeof dp);
  int ans = sol(0, 0, 0, 0, 0, 0, 0) - 1;
  if (ans < 0) ans += md;
  cout << ans << '\n';
  return 0;
}
