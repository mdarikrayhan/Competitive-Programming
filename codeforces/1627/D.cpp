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


const int N = 1e6 ; 
int arr[N + 10] ; 




int solve()
{
   int n ; 
   cin >> n ; 
   for(int i = 1 ; i <= n ; i += 1)
   {
      int a ; 
      cin >> a ; 
      arr[a] = 1 ; 
   }
   int ct = 0 ; 
   for(int i = N ; i >= 1 ; i -= 1)
   {
      if(arr[i])
      {
         // ct += 1 ; 
         continue ; 
      }
      int ls =  - 1 ; 
      for(int j = 2 * i ; j <= N ; j += i)
      {
         if(!arr[j])continue ; 
         if(ls ==  - 1)
         {
            ls = j ; 
         }
         else
         {
            arr[i] |= (gcd(ls , j) == i) ; 
            ls = j ; 
         }
      }
      // ct += arr[i] ; 
   }
   for(int i = 1 ; i <= N ; i += 1)
   {
      ct += arr[i] ; 
   }

   cout << ct - n << endl ; 



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