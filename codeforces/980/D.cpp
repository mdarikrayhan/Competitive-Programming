#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n"
// #define int long long
#define ll long long
#define ld long double
#define mod 998244353
//#define mod 1000000007
const int inf = 1e9;
const double esp=1e-9;
#define all(x)  x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define out(x) cout << #x << " = " << x <<endl
#define out2(a,b) cout<< #a << "[" << b << "]" << " = " << a[b] << endl;
#define outp(x) cout << #x << " first = " << x.first << "  second = " << x.second << endl



const int N = 5000 ; 
int arr[N + 10] , lef[N + 10] , res[N + 1] ; 


bool ok(int a , int b)
{
   ll c = (1ll * a * b) ; 
   if(c < 0)return 0 ; 
   return a == b ; 
   ll d = sqrtl(c) ; 
   return 1ll * d * d == c ; 
}

int solve()
{
   int n ; 
   cin >> n ;
   for(int i = 1 ; i <= n ; i += 1)
   {
      cin >> arr[i] ; 
      lef[i] = n + 1 ; 
      if(arr[i] == 0)
      {
         lef[i] = 0 ; 
         continue ; 
      }
      for(int j = 10000 ; j >= 1 ; j -= 1)
         if((abs(arr[i]) % (j * j)) == 0)
            arr[i] /= (j * j) ; 
   }

   for(int i = 1 ; i <= n ; i += 1)
   {
      if(arr[i] == 0)continue ; 
      for(int j = i + 1 ; j <= n ; j += 1)
      {
         if(arr[j] == 0)continue ; 
         if(ok(arr[i] , arr[j]))
         {
            lef[i] = j ; 
            break ; 
         }
      }
   }


   for(int i = 1 ; i <= n ; i += 1)
   {
      int sm = 0 ; 
      for(int j = i ; j >= 1 ; j -= 1)
      {
         sm += (lef[j] > i) ; 
         res[max(1 , sm)] += 1 ; 
      }
   }

   for(int i = 1 ; i <= n ; i += 1)
      cout << res[i] << " " ; 
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