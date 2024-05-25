#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=int(a);i<int(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define dforn(i,n) dforr(i,0,n)
#define fore(e,c) for(const auto &e : (c))
#define db(v) cerr<<#v" = "<<(v)<<'\n'
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define fst first
#define snd second
using ll = long long;
using ull = unsigned ll;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using veci = vector<int>;
using vecll = vector<ll>;
using vecb = vector<bool>;
using vecveci = vector<veci>;
template<class T>ostream&operator<<(ostream&o,vector<T>const&v){o<<"[ ";for(auto const&x:v)o<<x<<" ";return o<<"]";}
template<class T,class U>ostream&operator<<(ostream&o,pair<T,U>const&p){return o<<"("<<p.fst<<", "<<p.snd<<")";}
template<class T>void maxa(T&x,T const&y){  x=max(x,y);  }
template<class T>void mina(T&x,T const&y){  x=min(x,y);  }
template<class T>void sort2(T&x,T&y){  if(y<x)swap(x,y);  }
template<class T>void sort3(T&x,T&y,T&z){  sort2(x,y);sort2(y,z);sort2(x,y);  }

void solve();
void global_init();

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t; // Comment this line out for single-testcase problems
  global_init();
  forn(_,t) solve();
}

// Change constants according to the problem if needed
const ll MAXN = -1;
const ll INF = 1e18+100;
const ll MOD = 1000000007; /* NTT prime: 998244353 */
const ld EPS = 1e-9;
const ld PI = acosl(-1);

void global_init() {
// Solution goes here (called once per execution)

}

void solve() {
// Solution goes here (called once per testcase)

  int n, m; cin >> n >> m;
  vecveci a(n, veci(m));
  forn(i, n) forn(j, m) cin >> a[i][j];

  vector<int> ds;
  for (int x = 1; x*x <= a[0][0]; ++x) {
      if (a[0][0] % x == 0) {
          ds.pb(x);
          if (x != a[0][0] / x) ds.pb(a[0][0]/x);
      }
  }
  sort(all(ds));

    int ans = 1;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int d : ds) {
        forn(i, n) forn(j, m) vis[i][j] = false;
        vis[0][0] = true;
        forn(i, n) forn(j, m) {
            if (!vis[i][j]) continue;
            pii vs[2] = {{i+1, j}, {i, j+1}};
            for (auto [ii, jj] : vs) {
                if (ii >= n || jj >= m) continue;
                if (a[ii][jj] % d != 0) continue;
                vis[ii][jj] = true;
            }
        }
        if (vis[n-1][m-1]) ans = d;
    }
  
    cout << ans << "\n";

}