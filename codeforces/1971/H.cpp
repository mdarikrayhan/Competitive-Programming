#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define FOR(i, to) for (int i = 0; i < (to); ++i)
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pair<int, int> > vpi;
typedef pair<ll,ll> pll;
typedef vector<string> vs;
#define Nmax 1010
#define inf 101010000
int N, T;
int a[3][550];

class TwoSAT {
public:
  int N; // number of literals

  int s[2*Nmax], curr, c[2*Nmax];
  int sol[2*Nmax]; //if solution exists, value of literal i = sol[2*i]
  vi g[2*Nmax], gt[2*Nmax]; // graph and reverse graph
  vi v[2*Nmax]; // elements in component
  int viz[2*Nmax], vz[2*Nmax];
  
  TwoSAT() {}

  TwoSAT(int sz) { // number of literals
    N = sz;
  }

  void dfs(int x) {
    viz[x] = 1; for(auto y: g[x]) if(!viz[y]) dfs(y); s[++curr] = x;
  }
  
  void dfs2(int x, int comp) {
    viz[x] = 0; c[x] = comp; v[comp].push_back(x);
    for(auto y: gt[x]) if(viz[y]) dfs2(y,comp);
  }
  
  // negation
  inline int ng(int x) { if(x%2) return x-1; return x+1;}
  
  // assign val to node x
  bool f(int x, int val) {
    vz[x] = 1;
    for(auto y: v[x]) {
      if(sol[y] && sol[y]!=val) return false; sol[y] = val;
    }
    for(auto y: v[x]) {
      y = ng(y); if(sol[y] && sol[y]!=3-val) return false;
      if(!sol[y]) return f(c[y],3-val);
    }
    return true;
  }

  inline bool sat() {
    int comp = 0;
    for(int i=2;i<=2*N+1;++i) if(!viz[i]) dfs(i);
    for(int i=curr;i>=1;--i) if(viz[s[i]]) dfs2(s[i],++comp);
    for(int i=1;i<=comp;++i) if(!vz[i]) if(!f(i,1)) return false;
    return true;
  }

  // add (x OR y), s 0 normal,1 negation
  inline void add_disj(int x, int sx, int y, int sy) {
    g[2*x+(1-sx)].push_back(2*y+sy);
    g[2*y+(1-sy)].push_back(2*x+sx);
    gt[2*y+sy].push_back(2*x+(1-sx));
    gt[2*x+sx].push_back(2*y+(1-sy));
  }

  inline void clear() {
    curr = 0;
    FOR(i, 2*N+2) {
      viz[i] = vz[i] = sol[i] = c[i] = 0;
      v[i].clear();
      g[i].clear();
      gt[i].clear();

    }
  }
};

TwoSAT sat;

void add(int x, int y, int z) {
  int sx = 0, sy = 0, sz = 0;
  if(x < 0) {
    x = -x;
    sx = 1;
  }
  if(y < 0) {
    y = -y;
    sy = 1;
  }
  if(z < 0) {
    z = -z;
    sz = 1;
  }
  sat.add_disj(x, sx, y, sy);
  sat.add_disj(x, sx, z, sz);
  sat.add_disj(z, sz, y, sy);
}


int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>T;
  while(T--) {
    cin>>N;
    sat.N = N;
    FOR(i,3) {
      FOR(j, N) {
        cin>>a[i][j];
      }
    }
    FOR(i,N) {
      add(a[0][i], a[1][i], a[2][i]);
    }
    if(sat.sat()) {
      cout<<"YES\n";
    } else {
      cout<<"NO\n";
    }
    sat.clear();
  }
  return 0;
}