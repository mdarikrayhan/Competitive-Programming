#include <bits/stdc++.h>
using namespace std;
struct unionfind{
  vector<int> p;
  unionfind(int N): p(N, -1){
  }
  int root(int x){
    if (p[x] == -1){
      return x;
    } else {
      p[x] = root(p[x]);
      return p[x];
    }
  }
  void unite(int x, int y){
    p[x] = y;
  }
};
struct binary_indexed_tree{
  int N;
  vector<int> BIT;
  binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
  }
  void add(int i, int x){
    i++;
    while (i <= N){
      BIT[i] += x;
      i += i & -i;
    }
  }
  int sum(int i){
    int ans = 0;
    while (i > 0){
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
  int sum(int L, int R){
    return sum(R) - sum(L);
  }
};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  unionfind UF1(n);
  vector<int> p1(n, -1);
  for (int i = 0; i < n; i++){
    for (int j : E[i]){
      if (j < i){
        int v = UF1.root(j);
        p1[v] = i;
        UF1.unite(v, i);
      }
    }
  }
  unionfind UF2(n);
  vector<int> p2(n, -1);
  for (int i = n - 1; i >= 0; i--){
    for (int j : E[i]){
      if (j > i){
        int v = UF2.root(j);
        p2[v] = i;
        UF2.unite(v, i);
      }
    }
  }
  vector<vector<int>> c1(n), c2(n);
  for (int i = 0; i < n - 1; i++){
    c1[p1[i]].push_back(i);
  }
  for (int i = 1; i < n; i++){
    c2[p2[i]].push_back(i);
  }
  vector<int> d2(n, 0);
  for (int i = 1; i < n; i++){
    d2[i] = d2[p2[i]] + 1;
  }
  auto get = [&](vector<int> &in, vector<int> &out, vector<vector<int>> c, int r){
    int t = 0;
    auto dfs = [&](auto dfs, int v) -> void {
      in[v] = t;
      t++;
      for (int w : c[v]){
        dfs(dfs, w);
      }
      out[v] = t;
    };
    dfs(dfs, r);
  };
  vector<int> in1(n), out1(n), in2(n), out2(n);
  get(in1, out1, c1, n - 1);
  get(in2, out2, c2, 0);
  long long ans = 0;
  for (int i = 0; i < n; i++){
    ans += out1[i] - in1[i] - 1;
    ans += out2[i] - in2[i] - 1;
  }
  vector<vector<pair<int, int>>> query(n);
  for (int i = 0; i < n; i++){
    if (!c1[i].empty()){
      query[in2[i]].push_back(make_pair(in1[i] + 1, out1[i]));
    }
  }
  vector<vector<pair<int, int>>> update(n + 1);
  for (int i = 0; i < n; i++){
    if (!c2[i].empty()){
      update[in2[i] + 1].push_back(make_pair(in1[i], 1));
      update[out2[i]].push_back(make_pair(in1[i], -1));
    }
  }
  binary_indexed_tree BIT(n);
  for (int i = 0; i < n; i++){
    for (pair<int, int> P : update[i]){
      BIT.add(P.first, P.second);
    }
    for (pair<int, int> P : query[i]){
      ans -= BIT.sum(P.first, P.second) * 2;
    }
  }
  cout << ans << '\n';
  int m;
  cin >> m;
  vector<int> r(n + m), d(n + m);
  for (int i = 0; i < n; i++){
    r[i] = i;
    d[i] = 0;
  }
  for (int i = 0; i < m; i++){
    int v;
    cin >> v;
    v--;
    d[n + i] = d[v] + 1;
    v = r[v];
    r[n + i] = v;
    ans += n + i - (d2[v] + 1) - (d[n + i] - 1);
    cout << ans << '\n';
  }
}