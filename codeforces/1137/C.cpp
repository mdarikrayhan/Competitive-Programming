#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2", "popcnt")
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
#define IO_file freopen("output.txt","w",stdout), freopen("input.txt","r",stdin);
#define ll long long
#define lld long double
const lld pi = 3.14159265358979323846;
#define pb push_back
#define pf push_front
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
constexpr int mod = (int)(998244353);
#define log(x) (31^__builtin_clz(x)) // Easily calculate log2 on GNU G++ compilers
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int x, int y) {
  return uniform_int_distribution<int>(x, y)(rng);
}

struct SCC {
  
  int n, scc_cnt;
  vector<int> scc, order;
  vector<basic_string<int> > adj, radj;
  
  SCC() {}
  SCC(int n) {
    init(n);
  }
  
  void init(int n) {
    this->n = n;
    scc.assign(n + 1, 0);
    adj.assign(n + 1, {});
    radj.assign(n + 1, {});
    scc_cnt = 0;
  }
  
  void add_edge(int u, int v) {
    adj[u].push_back(v);
    radj[v].push_back(u);
  }
 
  void dfs1(int v) {
    scc[v] = 1;
    for(int u : adj[v]){
      if(!scc[u]) dfs1(u);
    }
    order.push_back(v);
  }
 
  void dfs2(int v) {
    scc[v] = scc_cnt;
    for(int u : radj[v]){
      if(!scc[u]) dfs2(u);
    }
  }
 
  void build() {
    for(int v = 1 ; v < n + 1 ; v++){
      if(!scc[v]) dfs1(v);
    }
    scc.assign(n + 1, 0);
    for(int i = n - 1 ; i > -1 ; i--){
      if(scc[order[i]]) continue;
      scc_cnt++;
      dfs2(order[i]);
    }
  }
  
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, m, D; cin>>n>>m>>D;
  SCC t(n);
  pair<int, int> edges[m];
  for(int i = 0 ; i < m ; i++){
    int x, y; cin>>x>>y;
    edges[i] = {x, y};
    t.add_edge(x, y);
  }
  t.build();
  bool mus[D][n + 1];
  for(int i = 1 ; i < n + 1 ; i++){
    string s; cin>>s;
    for(int j = 0 ; j < D ; j++){
      mus[j][i] = s[j] - '0';
    }
  }
  basic_string<int> in_edges[t.scc_cnt + 1];
  for(int i = 0 ; i < m ; i++){
    int x = edges[i].first;
    int y = edges[i].second;
    if(t.scc[x] == t.scc[y]) continue;
    in_edges[t.scc[y]].pb(i);
  }
  basic_string<int> nodes_of[t.scc_cnt + 1];
  int dp[D][n + 1];
  for(int i = 1 ; i < n + 1 ; i++){
    nodes_of[t.scc[i]].pb(i);
    for(int j = 0 ; j < D ; j++){
      dp[j][i] = -1e9;
    }
  }
  int idx[D][n + 1];
  memset(idx, -1, sizeof(idx));
  vector<int> costs;
  bool checked[n + 1] = {};
  for(int i = 1 ; i < n + 1 ; i++){
    for(int j = 0 ; j < D ; j++){
      if(idx[j][i] != -1) continue;
      vector<pair<int, int> > q, to_clear;
      idx[j][i] = costs.size();
      q.pb({j, i});
      while(!q.empty()){
        int dy = q.back().first;
        int x = q.back().second;
        q.pop_back();
        to_clear.pb({dy, x});
        int ndy = dy + 1;
        if(ndy == D) ndy = 0;
        for(int u : t.adj[x]){
          if(t.scc[u] != t.scc[x]) continue;
          if(idx[ndy][u] != -1) continue;
          idx[ndy][u] = idx[dy][x];
          q.pb({ndy, u});
        }
      }
      int sum = 0;
      for(auto &[dy, x] : to_clear){
        if(checked[x]) continue;
        if(mus[dy][x]){
          checked[x] = 1;
          sum++;
        }
      }
      costs.pb(sum);
      for(auto &[dy, x] : to_clear){
        checked[x] = 0;
      }
    }
  }
  for(int i = 1 ; i < n + 1 ; i++){
    for(int j = 0 ; j < D ; j++){
      if(idx[j][i] == idx[0][1]){
        dp[j][i] = costs[idx[j][i]];
      }
    }
  }
  int best[costs.size()];
  for(int i = 0 ; i < costs.size() ; i++){
    best[i] = -1e9;
  }
  for(int sc = t.scc[1] + 1 ; sc < t.scc_cnt + 1 ; sc++){
    for(int e : in_edges[sc]){
      int x = edges[e].first;
      int y = edges[e].second;
      for(int d = 0 ; d < D ; d++){
        int nd = d + 1;
        if(nd == D) nd = 0;
        best[idx[nd][y]] = max(best[idx[nd][y]], dp[d][x]);
      }
    }
    for(int u : nodes_of[sc]){
      for(int d = 0 ; d < D ; d++){
        dp[d][u] = best[idx[d][u]] + costs[idx[d][u]];
      }
    }
  }
  int ans = 0;
  for(int i = 1 ; i < n + 1 ; i++){
    for(int j = 0 ; j < D ; j++){
      ans = max(ans, dp[j][i]);
    }
  }
  cout<<ans<<'\n';
  
  
  
  
  
  
  
  return 0;
}
/*
 
 
 
 
 
 
 
 
 
 
 
*/