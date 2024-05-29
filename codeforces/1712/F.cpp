// LUOGU_RID: 158884398
#include<bits/stdc++.h>
#define il inline
#define re register
#define pii pair<int, int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
#define N 1000005
#define M 20
int n, m, f[N]; vector<int> G[N];
int DFN, dep[N], dfn[N], lg[N], ST[M][N];
il int dmin(int x, int y) {return dep[x] < dep[y] ? x : y;}
il int LCA(int x, int y) {
  if(x == y) return x; if((x = dfn[x]) > (y = dfn[y])) swap(x, y);
  int t = lg[y - x++]; return dmin(ST[t][x], ST[t][y - (1 << t) + 1]);
}
il int dis(int x, int y) {return dep[x] + dep[y] - dep[LCA(x, y)] * 2;}
il void DFS(int x, int fat) {
  dep[x] = dep[fat] + 1, ST[0][dfn[x] = ++DFN] = fat;
  for(auto y : G[x]) if(y != fat) DFS(y, x);
}
vector<int> pos[N]; pii D[N];
il void upd(pii &T, int x) {
  if(T.fi == -1) {T.fi = x; return ;} if(T.se == -1) {T.se = x; return ;}
  int p = T.fi, q = T.se, w = dis(p, q), P = dis(p, x), Q = dis(q, x);
  if(P > w) w = P, T = pii {p, x}; if(Q > w) w = Q, T = pii {q, x};
}
il int calc(pii T, int x) {return ~T.se ? max(dis(T.fi, x), dis(T.se, x)) : dis(T.fi, x);}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for(re int x = 2, y; x <= n; ++x)
    cin >> y, G[x].eb(y), G[y].eb(x);
  DFS(1, 0);
  for(re int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
  for(re int i = 1; i < M; ++i)
    for(re int j = 1; j + (1 << i) - 1 <= n; ++j)
      ST[i][j] = dmin(ST[i - 1][j], ST[i - 1][j + (1 << i - 1)]);
  queue<int> Q;
  for(re int i = 1; i <= n; ++i)
    if(G[i].size() == 1) Q.emplace(i), f[i] = 0; else f[i] = 1e9;
  while(!Q.empty()) {
    int x = Q.front(); Q.pop(), pos[f[x]].eb(x), m = f[x];
    for(auto y : G[x]) if(f[y] > f[x] + 1) f[y] = f[x] + 1, Q.emplace(y);
  }
  D[m + 1] = pii {-1, -1};
  for(re int i = m; i >= 0; --i) {D[i] = D[i + 1]; for(auto x : pos[i]) upd(D[i], x);}
  int q; cin >> q; while(q--) {
    int X, ans = 0; cin >> X;
    for(re int i = 0; i <= m; ++i)
      for(auto x : pos[i])
        for(; ; ) {
          int j = max(0, ans - i - X + 1); if(j > m) break;
          if(calc(D[j], x) > ans) ++ans; else break;
        }
    cout << ans << " ";
  }
}