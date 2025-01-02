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



const int N = 2e5 ; 
vector < array < int , 2 >> vec[N + 10] ; 
int del[N + 10] , n; 
array < int , 2 > fib[N + 1] ; 
map < int , int > mp ; 

array < int , 4 > f(int node , int par , int sze , int ped) // [a , b , id , sz]
{
   int sz = 1 ; 
   for(auto [child , ed] : vec[node])
   {
      if(child == par)continue ; 
      if(del[ed])continue ; 
      auto [a , b , id , szc] = f(child , node , sze , ed) ; 
      if(id != 0)return {a , b , id , szc} ; 
      sz += szc ; 
   }
   if(sz == fib[sze][0])
   {
      del[ped] = 1 ; 
      return {node , par , ped , sz} ; 
   }
   else if(sz == fib[sze][1])
   {
      del[ped] = 1 ; 
      return {node , par , ped , sz} ; 
   }
   return {0 , 0 , 0 , sz} ; 
}

bool g(int node , int par , int sze , int ped)
{
   if(sze == 1)return 1 ; 
   if(!mp[sze])return 0 ; 
   auto [a , b , id , sza] = f(node , par , sze , 0) ; 
   del[id] = 1 ; 
   if(id == 0)return 0 ; 
   return g(a , 0 , sza , 0) & g(b , 0 , sze - sza , 0) ; 
}

void pre()
{
   int a = 1 , b = 1 ; 
   mp[1] = 1 ; 
   for( ;  ; )
   {
      int c = (a + b) ; 
      if(c > N)break ; 
      mp[c] = 1 ; 
      fib[c] = {a , b} ; 
      a = b ; 
      b = c ; 
   }
}


int solve()
{
   pre() ; 
   cin >> n ; 
   for(int i = 1 ; i <= n - 1 ; i += 1)
   {
      int a , b ; 
      cin >> a >> b ; 
      vec[a].push_back({b , i}) ; 
      vec[b].push_back({a , i}) ; 
   }
   if(!mp[n])
   {
      cout<<"NO" << endl ; 
      return 0 ; 
   }
   cout << (g(1 , 0 , n , 0)?"YES" : "NO") << endl ; 





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