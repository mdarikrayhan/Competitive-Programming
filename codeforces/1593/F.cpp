#include <bits/stdc++.h>
using namespace std;

 #define Gene template< class
 #define Rics printer& operator,
 Gene c> struct rge{c b, e;};
 Gene c> rge<c> range(c i, c j){ return {i, j};}
 struct printer{
     ~printer(){cerr<<endl;}
     Gene c >Rics(c x){ cerr<<boolalpha<<x; return *this;}
     Rics(string x){cerr<<x;return *this;}
     Gene c, class d >Rics(pair<c, d> x){ return *this,"(",x.first,", ",x.second,")";}
     Gene ... d, Gene ...> class c >Rics(c<d...> x){ return *this, range(begin(x), end(x));}
     Gene c >Rics(rge<c> x){
         *this,"["; for(auto it = x.b; it != x.e; ++it)
             *this,(it==x.b?"":", "),*it; return *this,"]";}
 };
 #define debug() cerr<<"LINE "<<__LINE__<<" >> ", printer()
 #define dbg(x) "[",#x,": ",(x),"] "
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 int my_rand(int l, int r) {
     return uniform_int_distribution<int>(l, r) (rng);
 }
  
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define ff first
#define ss second
#define ok cerr<<"Line "<<__LINE__<<" : "<<"ok"<<endl
#define DBG(a) cerr<< "Line "<<__LINE__ <<" : "<< #a <<" = "<<(a)<<endl
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int N=41;
ll dp[N][N][N][N*2][2];
   // n,moda,modb,dif
ll setbit(ll n, int k)
{
    return (n | (1ll << k));
}
bool checkbit(ll n, int k)
{   
    return ((n >> k) & 1);
}
void solve()
{
  int n,A,B;
  string s;
  cin >> n >> A >> B >> s;

  memset(dp,-1,sizeof(dp));

  dp[0][0][0][40][0] = 0;
  dp[0][0][0][40][1] = 0;

  int cn = 40;

  for(int i = 0; i < n; i++){
    int dig = s[i] - '0';
    for(int moda = 0; moda < A; moda++){
      for(int modb = 0; modb < B; modb++){
        for(int dif = -n; dif <= n; dif++){
          if(dp[i][moda][modb][dif+cn][0] == -1) continue;
          // int v = dp[i][moda][modb][dif+cn][0];
          // debug(),dbg(i),dbg(moda),dbg(modb),dbg(dif),dbg(v);
          // if(i == n) continue;
          int redDigit = dp[i][moda][modb][dif+cn][1];
          int blackDigit = i - redDigit;

          // Color this digit to Red;
          int newmoda = (moda * 10 + dig) % A;
          ll newNum = setbit(dp[i][moda][modb][dif+cn][0],i+1);
          int d = redDigit+1-blackDigit;
          dp[i+1][newmoda][modb][d+cn][0] = newNum;
          dp[i+1][newmoda][modb][d+cn][1] = redDigit+1;

          //Color this digit to Black
          int newmodb = (modb * 10 + dig) % B;
           d = redDigit-blackDigit-1;
          dp[i+1][moda][newmodb][d+cn][0] = dp[i][moda][modb][dif+cn][0];
          dp[i+1][moda][newmodb][d+cn][1] = redDigit;



        }
      }
    }
  }

  ll ans = -1,mn = INT_MAX;
  for(int dif = -n; dif <= n; dif++){
    if(dp[n][0][0][dif+40][0] != -1){
      int d = abs(dif);
      if(d < mn && d < n){
        mn = d;
        ans = dp[n][0][0][dif+40][0];
      }
    }
  }



  if(ans == -1) {
    cout << -1 << '\n';
    return;
  }

  for(int i = 1; i <= n; i++){
    if(checkbit(ans,i)) cout << 'R';
    else cout << 'B';
  }
  cout << '\n';

}
int main()
{
  int t;
  t = 1;
  cin >> t;
  while(t--) solve();
  return 0;
}