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
int arr[N + 10] , n , k , sm = 0 ; 


int solve()
{
   ld res = 0 ; 
   cin >> n >> k ;
   int den = (1ll << n) ; 
   n = (1ll << n) ;  
   for(int i = 0 ; i < n ; i += 1)
   {
      // den *= 2 ; 
      cin >> arr[i] ; 
      sm += arr[i] ; 
   }
   res = sm ;
   res /= den ; 
   cout << res << endl ; 
   for(int i = 1 ; i <= k ; i += 1)
   {
      int a , b ; 
      cin >> a >> b ; 
      sm -= arr[a] ; 
      arr[a] = b ; 
      sm += arr[a] ; 
      res = sm ; 
      res /= den ; 
      cout << res << endl ; 
   }






   return 0;
}








int32_t main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   #ifdef LOCAL
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
   #endif
   cout<<fixed<<setprecision(10);
   int t=1;
   // cin>>t;
   for(int i=1;i<=t;i++)
         solve();
   return 0;
}