#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n"
#define int long long
#define ll long long
#define ld long double
#define mod 998244353
//#define mod 1000000007
const int inf = 1e17;
const double esp=1e-9;
#define all(x)  x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define out(x) cout << #x << " = " << x <<endl
#define out2(a,b) cout<< #a << "[" << b << "]" << " = " << a[b] << endl;
#define outp(x) cout << #x << " first = " << x.first << "  second = " << x.second << endl



const int N = 2e5 , K = 17 ; 
int n , k ; 
string s ; 
int dp1[N + 1][K + 1] ; 
int dp2[(1ll << K)] ; 

bool can(int len)
{
   memset(dp1 , 0 , sizeof(dp1)) ; 
   memset(dp2 , 0 , sizeof(dp2)) ; 
   for(int j = 0 ; j <= k ; j += 1)
      dp1[n][j] = 0 ; 

   for(int i = n - 1 ; i >= 0 ; i -= 1)
   {
      for(int j = 0 ; j <= k ; j += 1)
      {
         dp1[i][j] = 0 ;
         if(s[i] == '?' or (s[i] - 'a') == j)
         {
            dp1[i][j] = dp1[i + 1][j] + 1 ; 
         }
      }
   }

   for(int i = n - 1 ; i >= 0 ; i -= 1)
   {
      for(int j = 0 ; j <= k ; j += 1)
      {
         int h = dp1[i + 1][j] ;
         if(i + 1 == n)h = n ; 
         if(dp1[i][j] >= len)
         {
            h = min(h , i + len - 1) ; 
         }
         dp1[i][j] = h ; 
      }
   }
   dp2[0] =  - 1 ; 
   for(int i = 1 ; i <= (1ll << (k + 1)) - 1 ; i += 1)
   {
      dp2[i] = n + 1 ; 
      for(int j = 0 ; j <= k ; j += 1)
      {
         if((i >> j) & 1)
         {
            int from = dp2[i ^ (1ll << j)] + 1 ; 
            if(from >= n)continue ; 
            dp2[i] = min(dp2[i] , dp1[from][j]) ; 
         }
      }
   }

   return dp2[(1ll << (k + 1)) - 1] <= n - 1 ; 
}


int solve()
{
   cin >> n >> k ; k -= 1 ; 
   cin >> s ; 
   int low = 1 , high = n , res = 0 ; 
   while(low <= high)
   {
      int mid = (low + high) / 2 ; 
      if(can(mid))
      {
         res = mid ; 
         low = mid + 1 ; 
      }
      else
      {
         high = mid - 1 ; 
      }
   }
   cout << res << endl ; 




   return 0;
}








int32_t main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   #ifdef LOCAL
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
   #endif
   int t=1;
   // cin>>t;
   for(int i=1;i<=t;i++)
         solve();
   return 0;
}