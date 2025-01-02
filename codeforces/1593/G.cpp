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
 
const int N=1000009;
// int preev[N][2],preodd[N][2];
int pre[N][2];

void solve()
{
  string s;
  cin >> s;

  int n = s.size();
  for(int i = 0; i < n; i++){
    if(s[i] == '(' || s[i] == ')') s[i] = 'a';
    else s[i] = 'b';
  }

  for(int i = 2; i <= n; i++){
    pre[i][0] = pre[i-2][0];
    pre[i][1] = pre[i-2][1];

    if(s[i-2] == 'a' && s[i-1] == 'b') pre[i][0]++;
    else if(s[i-2] == 'b' && s[i-1] == 'a') pre[i][1]++;
  }

  int q,l,r;
  cin >> q;
  while(q--){
    cin >> l >> r;

    int ab = pre[r][0] - pre[l-1][0];
    int ba = pre[r][1] - pre[l-1][1];
    cout << abs(ab-ba) << '\n';
  }


}
int main()
{
  fastio;
  int t;
  t = 1;
  cin >> t;
  while(t--) solve();
  return 0;
}