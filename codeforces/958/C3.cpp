#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define mod 998244353
#define endl "\n"
//#define mod 1000000007
const int inf = 1e17;
const long double esp=1e-9;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x)  x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define out(x) cout << #x << " = " << x <<endl
#define out2(a,b) cout<< #a << "[" << b << "]" << " = " << a[b] << endl;
#define outp(x) cout << #x << " first = " << x.first << "  second = " << x.second << endl
////////////////////////////////////////////////////////////////////////////////////////////////



const int N = 500000 , K = 100 ; 
int dp[K + 1][N + 1] , pref[N + 1]; 


struct BIT {
   vector<int> bit;
   int n;
   BIT(int n) : n(n + 1), bit(n + 1 , inf) {}
   int query(int r) {
      r++;
      int ret = inf;
      while (r > 0) {
         ret = min(ret , bit[r]);
         r -= r & -r;
      }
      return ret;
   }

   void update(int idx, int v) {
      idx++;
      while (idx < n) {
         bit[idx] = min(bit[idx] , v);
         idx += idx & -idx;
      }
   }
};




int32_t solve()
{
   int n , k , p ; 
   cin >> n >> k >> p ; 
   for(int j = 0 ; j <= k ; j += 1)
      for(int i = 0 ; i <= n ; i += 1)
         dp[j][i] = inf ; 

   for(int i = 1 ; i <= n ; i += 1)
   {
      cin >> pref[i] ; 
      pref[i] = (pref[i - 1] + pref[i]) % p ; 
   }
   auto idx = [ & ](int id) -> int{
   return (p - id) ; 
   } ; 

   dp[0][0] = 0 ; 
   for(int j = 1 ; j <= k ; j += 1)
   { 
      // segment_tree seg(p + 2) ; 
      BIT up(p + 1) , down(p + 1) ; 
      for(int i = 1 ; i <= n ; i += 1)
      {
         if(dp[j - 1][i - 1] != inf)
         {
            down.update(pref[i - 1] , dp[j - 1][i - 1] - pref[i - 1]) ; 
            up.update(idx(pref[i - 1]) , dp[j - 1][i - 1] - pref[i - 1]) ; 
         }
         int sm = inf , bg = inf ; 
         sm = down.query(pref[i]) ; 
         bg = up.query(idx(pref[i] + 1)) + p ; 
         if(min(sm , bg) != inf)
            dp[j][i] = min(sm , bg) + pref[i] ; 
      }  
   }

   cout << dp[k][n] << endl ; 


   return 0;
}








int32_t main()
{
   IOS ; 
   #ifdef LOCAL
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
   #endif
   int test=1;
   // cin>>test;
   for(int i=1;i<=test;i++)
         solve();
   return 0;
}