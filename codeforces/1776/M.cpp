#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
const int N = 1e6 + 1e3;
int n, mx;
vector<int> g[N];
pair<int, int> dfs(int x, int fa, int dep) {
  if (dep || g[x].size() == 1) mx = max(mx, x);
  vector<int> vt;
  pii res = mp(0, 0);
  for (auto y : g[x])
    if (y != fa) {
      auto v = dfs(y, x, dep ^ 1);
      swap(v.fi, v.se);
      res.fi = max(res.fi, v.fi);
      res.se = max(res.se, v.se);
      vt.push_back(v.se);
    }
  if (!dep && vt.size() >= 2)
    std::sort(vt.begin(), vt.end()),
        mx = max(mx, vt[vt.size() - 2]);
  if (dep)
    res.fi = max(res.fi, x);
  else
    res.se = max(res.se, x);
  return res;
}
signed main() {
  scanf("%d", &n);
  for (int i = 1, x, y; i < n; i++)
    scanf("%d%d", &x, &y), g[x].push_back(y), g[y].push_back(x);
  if (n % 2 == 0 || g[n].size() == 1) mx = n;
  vector<int> vt;
  for (auto y : g[n]) {
    int v = dfs(y, n, 1).fi;
    vt.push_back(v);
  }
  if (vt.size() >= 3)
    std::sort(vt.begin(), vt.end()),
        mx = max(mx, vt.end()[-3]);
  printf("%d\n", mx);
  return 0;
}