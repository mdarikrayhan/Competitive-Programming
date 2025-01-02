#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#include <tr2/dynamic_bitset>
using namespace tr2;
// dynamic_bitset<typename> : <>, <uint64_t>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2", "popcnt")
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define IO_file freopen("output.txt","w",stdout), freopen("input.txt","r",stdin);
#define ll long long
#define lld long double
const lld pi = 3.14159265358979323846;
#define pb push_back
#define pf push_front
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
constexpr int mod = (int)(1e8);
#define log(x) (31^__builtin_clz(x)) // Easily calculate log2 on GNU G++ compilers
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll x, ll y) {
  return uniform_int_distribution<ll>(x, y)(rng);
}

constexpr int N = 2e5 + 1;
constexpr int M = 35e5 + 7;

basic_string<int> adj[M];
int par[N], sz[N], id[N], tick;
pair<int, int> stk[N];
int n, og_id[N], stk_top;
vector<int> imp_ids; // ids of components node 1 has been in

void init() {
  for(int i = 1 ; i < n + 1 ; i++){
    par[i] = id[i] = i;
    sz[i] = 1;
  }
  tick = n;
}

int find(int x) {
  while(par[x] != x) x = par[x];
  return x;
}

#define left p << 1, L, (L + R) >> 1
#define right p << 1 ^ 1, ((L + R) >> 1) + 1, R

pair<int, int> edges[2 * N];
basic_string<int> seg[3 * N];

void add(int i, int j, int E, int p = 1, int L = 1, int R = N - 1) {
  if(L > j || R < i) return;
  if(i <= L && R <= j){
    seg[p].pb(E); return;
  }
  add(i, j, E, left); add(i, j, E, right);
}

void dfs(int p = 1, int L = 1, int R = N - 1) {
  int p_sz = stk_top;
  for(int e : seg[p]){
    int x = find(edges[e].first);
    int y = find(edges[e].second);
    if(x == y) continue;
    if(sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
    int nd = ++tick;
    adj[nd].pb(id[x]);
    adj[nd].pb(id[y]);
    stk[++stk_top] = {x, y};
    og_id[stk_top] = id[x];
    id[x] = nd;
    if(find(1) == x) imp_ids.pb(nd);
  }
  if(L != R){
    dfs(left); dfs(right);
  }
  while(stk_top != p_sz){
    int x = stk[stk_top].first;
    int y = stk[stk_top].second;
    id[x] = og_id[stk_top];
    sz[x] -= sz[y];
    par[y] = y;
    stk_top--;
  }
}

bool vis[M];

void dfs2(int v) {
  vis[v] = 1;
  for(int u : adj[v]){
    if(!vis[u]) dfs2(u);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int m; cin>>n>>m;
  int l[n + 1], r[n + 1];
  for(int i = 1 ; i < n + 1 ; i++){
    cin>>l[i]>>r[i];
  }
  for(int i = 0 ; i < m ; i++){
    int x, y; cin>>x>>y;
    if(x > y) swap(x, y);
    int lf = max(l[x], l[y]);
    int rg = min(r[x], r[y]);
    if(rg < lf) continue;
    edges[i] = {x, y};
    add(lf, rg, i);
  }
  init();
  imp_ids.pb(1);
  dfs();
  for(int x : imp_ids){
    if(!vis[x]) dfs2(x);
  }
  for(int v = 1 ; v < n + 1 ; v++){
    if(vis[v]) cout<<v<<" ";
  }
  
  
  return 0;
}
/*
 
 
 
 
 
 
 
 
 
 
 
*/