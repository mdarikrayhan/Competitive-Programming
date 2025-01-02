// LUOGU_RID: 159610377
// just for a test
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
const int MAXN = 100;
int n, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 1;
template <typename T>
bool chkmin(T& x, const T& y) {
  return y < x ? x = y, true : false;
}
template <typename T>
bool chkmax(T& x, const T& y) {
  return x < y ? x = y, true : false;
}

void adde(int u, int v) {
  to[++ec] = v;
  nxt[ec] = hd[u];
  hd[u] = ec;
}
struct lnum {
  bitset<MAXN + 5> a;
  lnum() { a.reset(); }
  friend bool operator<(const lnum& X, const lnum& Y) {
    int pos = (X.a ^ Y.a)._Find_first();
    if (pos == X.a.size() || X.a[pos]) return 0;
    return 1;
  }
} f[MAXN + 5], af[MAXN + 5], g[MAXN + 5];
int val[MAXN + 5], tmp[MAXN + 5], len;
bool check(lnum v) {
  priority_queue<pair<lnum, int> > q;
  for (int i = 1; i <= len; i++) q.push(mp(af[i], i)), g[i].a.reset();
  for (int i = 0; i < n; i++) {
    if (!v.a[i]) {
      if (!q.empty() && q.top().fi.a[i]) return 0;
    } else {
      auto t = q.top();
      q.pop();
      if (t.fi.a[i]) {
        if (!q.empty() && q.top().fi.a[i]) return 0;
        t.fi.a[i] = 0;
        g[t.se].a[i] = 1;
        q.push(t);
      } else
        g[t.se].a[i] = 1;
    }
    if (q.empty()) return 1;
  }
  return 0;
}
void dfs(int x, int fa) {
  for (int e = hd[x]; e; e = nxt[e])
    if (to[e] != fa) dfs(to[e], x);
  len = 0;
  for (int e = hd[x]; e; e = nxt[e])
    if (to[e] != fa) af[++len] = f[to[e]];
  for (int i = 0; i < n; i++) f[x].a[i] = 1;
  for (int i = 0; i < n; i++) {
    f[x].a[i] = 0;
    if (!check(f[x])) f[x].a[i] = 1;
  }
  check(f[x]);
  int cur = 0;
  for (int e = hd[x]; e; e = nxt[e])
    if (to[e] != fa) {
      ++cur;
      for (int j = 0; j < n; j++)
        if (g[cur].a[j] && !af[cur].a[j]) {
          val[e >> 1] = n - 1 - j;
          break;
        }
    }
}
bool ban[MAXN + 5], has[MAXN + 5];
pair<int, int> mx = mp(0, 0);
void dfs_cmp(int x) {
  if (has[x]) return;
  has[x] = 1;
  for (int e = hd[x]; e; e = nxt[e])
    if (!ban[e >> 1]) chkmax(mx, mp(val[e >> 1], e >> 1)), dfs_cmp(to[e]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; i++)
    scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
  dfs(1, 0);
  int pre = 1, res = 0;
  for (int i = 1; i < n; i++) chkmax(res, val[i] + 1);
  //	printf("res=%d\n",res);
  while (1) {
    memset(has, 0, sizeof(has));
    mx = mp(0, 0);
    dfs_cmp(pre);
    if (!mx.se) {
      cout << "! " << pre << endl;
      break;
    }
    cout << "? " << to[mx.se << 1] << " " << to[mx.se << 1 | 1] << endl;
    int x;
    cin >> x;
    pre = x;
    ban[mx.se] = 1;
  }
  return 0;
}
