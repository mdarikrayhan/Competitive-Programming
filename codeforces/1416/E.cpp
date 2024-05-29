#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<int, int> mapka;
 
using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
 
template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }
 
template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}
 
template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}
 
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif
 
struct Sol{
  set<int> secik;
  int off = 0;
  int odw = 0;
  bool znaj(int x){
    x += off;
    if(odw)x *= -1;
    return secik.find(x) != secik.end();
  }
  int dajnaj(){
    int pom;
    if(odw){
      pom = -*secik.begin();
    }else{
      pom = *secik.rbegin();
    }
    pom -= off;
    return pom;
  }
  void us(int x){
    x += off;
    if(odw)x *= -1;
    
    secik.erase(x);
  }
  void dodaj(int x){
    debug(x,off,odw);
    x += off;
    if(odw)x *= -1;
    secik.insert(x);
  }
  void odwroc(int pom){
    odw = !odw;
    off *= -1;
    off -= pom;
  }
  void wys(){
#ifdef LOCAL
    cerr << "secik: ";
    for(int el:secik){
      if(odw)el *= -1;
      el -= off;
      cerr << el << " ";
    }
    cerr << "\n";
#endif
  }
  void run(){
    int res = 1;
    int po = 1;
    int ko = 2e9;
    int n;
    cin >> n;
    R(i,n){
      int pom;
      cin >> pom;
      bool parz = (pom & 1) == 0;
      if(parz && ((po <= pom / 2 && pom / 2 <= ko) || znaj(pom/2))){
        secik.clear();
        off = odw = 0;
        po = pom / 2;
        ko = pom / 2;
      }else{
        res++;
        mini(ko, pom-1);
        while(!secik.empty()){
          int naj = dajnaj();
          if(naj >= pom){
            us(naj);
          }else{
            break;
          }
        }
        if(parz){
          dodaj(pom/2);
        }
        if(po <= ko || SZ(secik)){
          int stareko = ko;
          ko = pom - po;
          po = pom - stareko;
          odwroc(pom);
        }else{
          res ++;
          secik.clear();
          off = odw = 0;
          po = 1;
          ko = pom-1;
        }
      }
      debug(res,po,ko);
      wys();
    }
    cout << res << "\n";
  }
};
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int t;
  cin >> t;
  while(t--){
    Sol sol;
    sol.run();
  }
}
 