// LUOGU_RID: 159727693
#include <bits/stdc++.h>
#define db double
#define il inline
#define re register
#define ll long long
#define ui unsigned
#define ull ui ll
#define i128 __int128
#define pii pair<int, int>
#define fi first
#define se second
#define eb emplace_back
#define SZ(v) (int)v.size()
#define ALL(v) v.begin(), v.end()
#define mems(v, x) memset(v, x, sizeof(v))
#define memc(a, b) memcpy(a, b, sizeof(a))
#define FOR(i, L, R) for(re int i = (L); i <= (R); ++i)
#define ROF(i, R, L) for(re int i = (R); i >= (L); --i)
#define LS i << 1, l, mid
#define RS i << 1 | 1, mid + 1, r
#define popc(x) __builtin_popcount(x)
#define popcll(x) __builtin_popcountll(x)
using namespace std;
#define N 55
#define P 998244353
il int add(int x, int y) {return x + y < P ? x + y : x + y - P;}
il void addr(int &x, int y) {(x += y) >= P && (x -= P);}
il int qpow(int p, int n = P - 2) {
  int s = 1;
  while(n) {
    if(n & 1) s = 1ll * s * p % P;
    p = 1ll * p * p % P, n >>= 1;
  }
  return s;
}
il void chkmin(int &x, int y) {(x > y) && (x = y);}
il void chkmax(int &x, int y) {(x < y) && (x = y);}
int n;
il int query(int a, int b, int c, int d) {
  cout << "? " << a << " " << b << " " << c << " " << d << endl;
  int v; cin >> v; return v;
}
int a[N][N], v[N][N];
il void work(int x, int y) {
  while(y < n) a[x + 1][y + 1] = a[x][y] ^ !v[x][y], ++x, ++y;
  int X = x, Y = y - 2;
  a[X][Y] = a[x][y] ^ !query(X, Y, x, y);
  while(x > 1) --x, --y, a[x][y] = a[x + 1][y + 1] ^ !v[x][y];
  while(Y > 1) --X, --Y, a[X][Y] = a[X + 1][Y + 1] ^ !v[X][Y];
}
int main() {
  // freopen("test.in", "r", stdin);
  // freopen("test.out", "w", stdout);
  // ios::sync_with_stdio(0);
  // cin.tie(0), cout.tie(0);
  cin >> n;
  a[1][1] = 1;
  FOR(i, 1, n - 1) FOR(j, 1, n - 1) {
    if(i == n - 1 && j == n - 1) continue;
    v[i][j] = query(i, j, i + 1, j + 1);
  }
  FOR(i, 1, n - 1) FOR(j, 1, n - 1) {
    if(i == n - 1 && j == n - 1) continue;
    if(i + j & 1) continue; a[i + 1][j + 1] = a[i][j] ^ !v[i][j];
  }
  FOR(i, 1, n - 2) a[i + 1][i + 1] = a[i][i] ^ !v[i][i];
  FOR(i, 1, n - 2) if(a[i][i] != a[i + 2][i + 2]) {
    if(v[i][i] == v[i][i + 1]) {
      int k = query(i, i, i + 1, i + 2);
      // cerr << "Find = " << i + 1 << " " << i + 2 << " " << k << "\n";
      a[i + 1][i + 2] = a[i][i] ^ !k, work(i + 1, i + 2); break;
    }
    int k = query(i, i + 1, i + 2, i + 2);
    a[i][i + 1] = a[i + 2][i + 2] ^ !k, work(i, i + 1); break;
  }
  FOR(i, 3, n) a[1][i] = a[1][i - 2] ^ !query(1, i - 2, 1, i);
  FOR(i, 3, n) a[i][1] = a[i - 2][1] ^ !query(i - 2, 1, i, 1);
  FOR(i, 1, n - 1) FOR(j, 1, n - 1) {
    if(i == n - 1 && j == n - 1) continue;
    a[i + 1][j + 1] = a[i][j] ^ !v[i][j];
  }
  cout << "!" << endl;
  FOR(i, 1, n) {FOR(j, 1, n) cout << a[i][j]; cout << endl;}
  cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
  return 0;
}