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



int n , m , k , res = 0 , d ; 
vector < int > vec ; 
vector<vector<int>>vc ; 
int ss , dd , dp[101][31][2] , dp2[101][31][2] , tkn = 1 ; 
int f(int idx , int sm , int ok)
{
   if(idx == n + 1)
   {
      return ((ok & (sm == 0))) ; 
   }
   int  & res = dp[idx][sm][ok] ; 
   if(dp2[idx][sm][ok] == tkn)return res ; 
   dp2[idx][sm][ok] = tkn ; 
   res = 0 ; 
   for(int i = 0 ; i <= k-1 ; i += 1)
   {
      vec[idx] = i ; 
      res = (res + f(idx + 1 , (sm - i + k) % k , ok | ((2 * i) % k == ss))) % m ; 
   }
   return res ; 
}



int32_t solve()
{
   cin >> n >> k >> m ; 
   vec = vector < int > (n + 1 , 0) ; 
   memset(dp , -1 , sizeof(dp)) ; 
   for(int i = 0 ; i <= k - 1 ; i += 1)
   {
      tkn ++  ; 
      ss = i ; 
      res = (res + f(1 , i , 0)) % m ; 
   }

   cout << res << endl ;

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