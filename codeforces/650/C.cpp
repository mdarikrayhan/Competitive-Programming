#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
typedef vector<int> vi;
#define f first
#define s second
#define derr if(0) cerr
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define debug(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << flush;
// END NO SAD

template<class Fun>
class y_combinator_result {
  Fun fun_;
public:
  template<class T>
  explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

  template<class ...Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template<class T>
bool updmin(T& a, T b) {
  if(b < a) {
    a = b;
    return true;
  }
  return false;
}
template<class T>
bool updmax(T& a, T b) {
  if(b > a) {
    a = b;
    return true;
  }
  return false;
}
typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef array<array<int, 2>, 2> matrix;

struct disjoint_set {
  vector<int> par, sz;
  disjoint_set(int n) {
    par.assign(n, -1);
    sz.assign(n, 1);
  }
  int find(int x) {
    return par[x] < 0 ? x : (par[x] = find(par[x]));
  }
  bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return false;
    par[x] = y;
    sz[y] += sz[x];
    return true;
  }
  int getsz(int x) {
    return sz[find(x)];
  }
};

int dx[4]{-1,0,1,0};
int dy[4]{0,1,0,-1};
void solve() {
  int r, c;
  cin >> r >> c;
  vector<vector<int>> g(r);
  for(auto& x: g) {
    x.resize(c);
    for(auto& y: x) cin >> y;
  }
  vector<vector<int>> edges(r*c);
  disjoint_set dsu(r*c);
  for(int i = 0; i < r; i++) {
    vector<array<int, 2>> vals;
    for(int j = 0; j < c; j++) {
      vals.pb({g[i][j], j});
    }
    sort(all(vals));
    for(int j = 1; j < sz(vals); j++) {
      if(vals[j][0] == vals[j-1][0]) dsu.merge(i*c+vals[j-1][1], i*c+vals[j][1]);
    }
  }
  for(int j = 0; j < c; j++) {
    vector<array<int, 2>> vals;
    for(int i = 0; i < r; i++) {
      vals.pb({g[i][j], i});
    }
    sort(all(vals));
    for(int i = 1; i < sz(vals); i++) {
      if(vals[i][0] == vals[i-1][0]) dsu.merge(vals[i-1][1]*c+j, vals[i][1]*c+j);
    }
  }
  vector<int> par(r*c);
  for(int i = 0; i < r; i++) {
    vector<array<int, 2>> vals;
    for(int j = 0; j < c; j++) {
      vals.pb({g[i][j], j});
    }
    sort(all(vals));
    for(int j = 1; j < sz(vals); j++) {
      if(vals[j][0] > vals[j-1][0]) {
        par[dsu.find(i*c+vals[j][1])]++;
        edges[dsu.find(i*c+vals[j-1][1])].pb(dsu.find(i*c+vals[j][1]));
      }
    }
  }
  for(int j = 0; j < c; j++) {
    vector<array<int, 2>> vals;
    for(int i = 0; i < r; i++) {
      vals.pb({g[i][j], i});
    }
    sort(all(vals));
    for(int i = 1; i < sz(vals); i++) {
      if(vals[i][0] > vals[i-1][0]) {
        par[dsu.find(vals[i][1]*c+j)]++;
        edges[dsu.find(vals[i-1][1]*c+j)].pb(dsu.find(vals[i][1]*c+j));
      }
    }
  }
  queue<int> q;
  vector<int> dp(r*c, 1);
  for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) {
    if(dsu.find(i*c+j) != i*c+j) continue;
    if(par[i*c+j] == 0) q.push(dsu.find(i*c+j));
  }
  while(sz(q)) {
    auto x = q.front(); q.pop();
    for(auto y: edges[x]) {
      updmax(dp[y], dp[x]+1);
      if(--par[y] == 0) q.push(y);
    }
  }
  for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cout << dp[dsu.find(i*c+j)] << " \n"[j == c-1];
}

// what would chika do
// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points
// are you not using modint when you should

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
