#include <bits/stdc++.h>
using namespace std;
#define debug(fmt, ...) \
  fprintf(stderr, "[%d] : " fmt "\n", __LINE__, ##__VA_ARGS__)
template <class _Tx, class _Ty>
inline void chkmin(_Tx& x, const _Ty& y) { if (y < x) x = y; }
template <class _Tx, class _Ty>
inline void chkmax(_Tx& x, const _Ty& y) { if (x < y) x = y; }
bool Mbe;
using ll = long long;
constexpr int N = 3e5 + 10, B = 1500, K = 19;
int n, k, q, typ, a[N], fa[N], pos[N], nxt[N], ans[N];
int dsu[N], las[N], jmp[N], jcnt[N], cur[N], ncur[N], mx[K][N], dp[B][B];
vector<tuple<int, int, int>> qry[N];
int find(int x) { return dsu[x] == x ? x : dsu[x] = find(dsu[x]); }
int askmax(int l, int r) {
  int k = __lg(r - l + 1);
  return max(mx[k][l], mx[k][r - (1 << k) + 1]);
}
void solve(int l, int r) {
  int len = r - l + 1;
  vector<int> key;
  for (int i = l; i <= r; ++i) key.push_back(pos[i]);
  sort(key.begin(), key.end());
  int ptr = 0;
  for (int i = 1; i <= n; ++i) {
    while (ptr < len && key[ptr] <= i) ++ptr;
    las[i] = ptr;
  }
  for (int i = 0; i < len; ++i) {
    dp[i][i] = a[key[i]];
    for (int j = i + 1; j < len; ++j)
      dp[i][j] = max(dp[i][j - 1], a[key[j]]);
  }
  copy(cur + 1, cur + n + 1, ncur + 1);
  for (int i = 1; i <= n; ++i) {
    int x = las[i - 1], y = las[nxt[i]] - 1;
    if (x <= y) chkmax(ncur[i], dp[x][y]);
  }
  for (int i = n; i >= 1; --i) {
    fa[i] = pos[ncur[i]];
    if (!fa[i]) continue;
    if (a[fa[i]] >= l) {
      jmp[i] = i, jcnt[i] = 0;
    } else {
      jmp[i] = jmp[fa[i]], jcnt[i] = jcnt[fa[i]] + 1;
    }
  }
  for (int i = l; i <= r; ++i) {
    int y = pos[i];
    for (auto it : qry[y]) {
      int op, x, id;
      tie(op, x, id) = it;
      if (a[x] > a[y]) x = 0;
      int ptr = 0, cnt = 0;
      while (x && x != y) {
        cnt += jcnt[x];
        x = jmp[x];
        int mxp = cur[x];
        while (ptr < len && key[ptr] <= nxt[x]) {
          if (key[ptr] > x && a[key[ptr]] <= a[y])
            chkmax(mxp, a[key[ptr]]);
          ++ptr;
        }
        if (pos[mxp] == x) {
          x = 0;
          break;
        }
        ++cnt;
        x = pos[mxp];
      }
      ans[id] = x ? (op == 1 ? 1 : cnt) : 0;
    }
  }
  copy(ncur + 1, ncur + n + 1, cur + 1);
}
bool Med;
int main() {
  // debug("Mem: %.4lfMB.", fabs(&Med - &Mbe) / 1048576);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k >> typ;
  for (int i = 1; i <= n; ++i) cin >> a[i], pos[a[i]] = i;
  cin >> q;
  for (int i = 1, op, x, y; i <= q; ++i)
    cin >> op >> x >> y, qry[y].push_back({op, x, i});
  int blk = sqrt(n) * 2 + 1;
  iota(dsu + 1, dsu + n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    int p = pos[i];
    for (int j = find(p); j < n && j < p + k; j = find(j))
      dsu[j] = j + 1;
    nxt[p] = find(p);
  }
  for (int i = 1; i <= n; ++i) mx[0][i] = a[i];
  for (int i = 1; i < K; ++i) {
    for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
      mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
    }
  }
  
  for (int i = 1; i <= n; ++i) fa[i] = pos[askmax(i, nxt[i])];
  for (int i = 1; i <= n; i += blk) solve(i, min(n, i + blk - 1));
  for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
  return 0;
}