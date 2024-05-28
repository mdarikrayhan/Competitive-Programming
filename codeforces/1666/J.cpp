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
const int inf = 1e18;
const double eps=1e-9;
#define all(x)  x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define out(x) cout << #x << " = " << x <<endl
#define out2(a,b) cout<< #a << "[" << b << "]" << " = " << a[b] << endl;
#define outp(x) cout << #x << " first = " << x.first << "  second = " << x.second << endl


const int N = 200 ; 
int arr[N + 1][N + 1] , pref[N + 1][N + 1] , par[N + 10] ; 
array < int , 2 > dp[N + 1][N + 1] ; 

int sum(int i1 , int j1 , int i2 , int j2)
{
   return ((pref[i2][j2] - pref[i2][j1 - 1] - pref[i1 - 1][j2] + pref[i1 - 1][j1 - 1])) ; 
}


int f(int i , int j , int l , int r)
{
   return sum(l , i , r , j) - sum(l , l , r , r) ; 
}

int f1(int i , int j , int r)
{
   int res = 0 ; 
   if(i <= r - 1)
      res += f(i , j , i , r - 1) ; 
   if(r + 1 <= j)
      res += f(i , j , r + 1 , j) ; 
   return res ; 
}

int n ; 


array < int , 2 > dfs(int l , int r)
{
   array < int , 2 >  & res = dp[l][r] ; 
   if(l == r)return res = {f(1 , n , l , l) , l} ; 
   if(l > r)return res = {0 , 0} ; 
   if(res[0] !=  - 1)return res ; 
   res = {inf , inf} ; 
   array < int , 2 > a , b ; 
   for(int i = l ; i <= r ; i += 1)
   {
      auto lef = dfs(l , i - 1) ; 
      auto rig = dfs(i + 1 , r) ; 
      if(res[0] > lef[0] + rig[0] + f(1 , n , l , r))
      {
         a = lef , b = rig ; 
         res[0] = lef[0] + rig[0] + f(1 , n , l , r); 
         res[1] = i ; 
      }
   }

   return res ; 
}

void dfs2(int l , int r , int pr)
{
   if(l > r)return  ; 
   auto [s , n] = dp[l][r]; 
   par[n] = pr ; 
   if(l == r)return  ; 
   dfs2(l , n - 1 , n) ; 
   dfs2(n + 1 , r , n) ; 
}

int solve()
{
   cin >> n ; 
   for(int i = 1 ; i <= n ; i += 1)
   {
      for(int j = 1 ; j <= n ; j += 1)
      {
         cin >> arr[i][j] ; 
         pref[i][j] = pref[i][j - 1] + arr[i][j] ;  
         // cout << arr[i][j] << " " ; 
      }
      // cout << endl ; 
   }

   for(int i = 0 ; i <= n ; i += 1)
   {
      for(int j = 0 ; j <= n ; j += 1)
      {
         dp[i][j] = { - 1 ,  - 1} ; 
      } 
   }
   
   for(int j = 1 ; j <= n ; j += 1)
   {
      for(int i = 1 ; i <= n ; i += 1)
      {
         pref[i][j] += pref[i - 1][j] ; 
      }
   } 
   auto res = dfs(1 , n) ; 
   dfs2(1 , n , 0) ;

   for(int i = 1 ; i <= n ; i += 1)
      cout << par[i] << " " ; 
   cout << endl ; 



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