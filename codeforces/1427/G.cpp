#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 210
#define V 40010
#define M V * 4
int n;
int a[N][N];
int id[N][N], idx;
bool s[V], t[V];
int first[V], nxt[M], to[M], f[M], et = 1;
bitset<V> vis;
void add(int u, int v) {
  nxt[++et] = first[u]; first[u] = et; to[et] = v; f[et] = 1;
  nxt[++et] = first[v]; first[v] = et; to[et] = u; f[et] = 1;
}
bool dfs(int u, bool flg) {
  if (flg && s[u]) return 1;
  if (!flg && t[u]) return 1;
  vis[u] = 1;
  for (int i = first[u]; i; i = nxt[i]) {
    if (!vis[to[i]] && f[i] && (!flg || f[i] == 2)) {
      if (dfs(to[i], flg)) {
        --f[i]; ++f[i ^ 1];
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  cin.tie(nullptr) -> sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      id[i][j] = ++idx;
    }
  }
  vector<pair<int, int>> p;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (a[i][j] > 0) t[id[i][j]] = 1, p.emplace_back(a[i][j], id[i][j]);
      if (a[i][j] >= 0) {
        if (j + 1 <= n && a[i][j + 1] >= 0) add(id[i][j], id[i][j + 1]);
        if (i + 1 <= n && a[i + 1][j] >= 0) add(id[i][j], id[i + 1][j]);
      }
    }
  } 
  int flow = 0;
  ll ans = 0;
  sort(p.begin(), p.end());
  for (int i = 0; i < (int)p.size() - 1; ++i) {
    int u = p[i].second;
    vis.reset();
    while (dfs(u, 1)) --flow, vis.reset();
    s[u] = 1, t[u] = 0;
    vis.reset();
    for (int j = 0; j <= i; ++j) {if (!vis[p[j].second]) while (dfs(p[j].second, 0)) ++flow, vis.reset();}
    ans += 1ll * flow * (p[i + 1].first - p[i].first);
  }
  cout << ans;
  return 0;
}
	 		 	      		  		 		 	 			 	