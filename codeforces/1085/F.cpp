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
const int inf = 1e9 + 7;
const double esp=1e-9;
#define all(x)  x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define out(x) cout << #x << " = " << x <<endl
#define out2(a,b) cout<< #a << "[" << b << "]" << " = " << a[b] << endl;
#define outp(x) cout << #x << " first = " << x.first << "  second = " << x.second << endl



const int N = 2e5 ; 
int n , q ; 
string str ; 

struct BIT {
   vector<int> bit;
   int n;
   BIT(int n) : n(n + 1), bit(n + 1) {}
   int sum(int r) {
      r++;
      int ret = 0;
      while (r > 0) {
         ret += bit[r];
         r -= r & -r;
      }
      return ret;
   }

   int query(int l , int r)
   {
      if(r == 0)return sum(l) ; 
      return sum(r) - sum(l - 1) ; 
   }

   int at(int idx)
   {
      if(idx == 0)return sum(0) ; 
      return sum(idx) - sum(idx - 1) ; 
   }

   void update(int idx, int v) {
      idx++;
      while (idx < n) {
         bit[idx] += v;
         idx += idx & -idx;
      }
   }
};

int solve()
{
   cin >> n >> q ; 
   cin >> str ; 
   str = '.' + str ; 
   BIT r(n + 2) , p(n + 2) , s(n + 2) ; 
   for(int i = 1 ; i <= n ; i += 1)
   {
      if(str[i] == 'R')
      {
         r.update(i , 1) ; 
      }
      else if(str[i] == 'P')
      {
         p.update(i , 1) ; 
      }
      else
      {
         s.update(i , 1) ; 
      }
   }

   auto fst = [ & ](BIT  & b) -> int{
      int low = 1 , high = n , res = inf ; 
      while(low <= high)
      {
         int mid = (low + high) / 2 ; 
         if(b.query(1 , mid) != 0)
         {
            res = mid ; 
            high = mid - 1 ; 
         }
         else
         {
            low = mid + 1 ; 
         }
      }
      return res ; 
   } ;


   auto lst = [ & ](BIT  & b) -> int{
      int low = 1 , high = n , res = inf ; 
      while(low <= high)
      {
         int mid = (low + high) / 2 ; 
         if(b.query(mid , n) != 0)
         {
            res = mid ; 
            low = mid + 1 ; 
         }
         else
         {
            high = mid - 1 ; 
         }
      }
      return res ; 
   } ;


   auto lef = [ & ](BIT  & b) -> int{
      int low = 1 , high = n , res = 0 ; 
      while(low <= high)
      {
         int mid = (low + high) / 2 ; 
         if(b.query(1 , mid) == mid)
         {
            res = mid ; 
            low = mid + 1 ; 
         }
         else
         {
            high = mid - 1 ; 
         }
      }
      return res ; 
   } ;

   auto rig = [ & ](BIT  & b) -> int{
      int low = 1 , high = n , res = 0 ; 
      while(low <= high)
      {
         int mid = (low + high) / 2 ; 
         if(b.query(mid , n) == (n + 1 - mid))
         {
            res = n + 1 - mid ; 
            high = mid - 1 ; 
         }
         else
         {
            low = mid + 1 ; 
         }
      }
      return res ; 
   } ;

   auto give = [ & ](BIT  & q , BIT  & d) -> int{
      int f = fst(d) , l = lst(d) ; 
      if(f == inf)
         return ((q.query(1 , n) == n) * n) ; 
      int res = 0 ; 
      res += q.query(f , l) ; 
      res += lef(q) ; 
      res += rig(q) ; 
      return res ; 
   } ; 

   auto get = [ & ]() -> int{
      int res = 0 ; 
      res += give(r , s) ; 
      res += give(s , p) ; 
      res += give(p , r) ; 
      return res ; 
   } ; 
   cout << get() << endl ; 
   for(int i = 1 ; i <= q ; i += 1)
   {
      int idx ; 
      char c ; 
      cin >> idx >> c ; 
      if(str[idx] == 'R')
      {
         r.update(idx ,  - 1) ; 
      }
      else if(str[idx] == 'P')
      {
         p.update(idx ,  - 1) ; 
      }
      else
      {
         s.update(idx ,  - 1) ; 
      }

      str[idx] = c ; 

      if(str[idx] == 'R')
      {
         r.update(idx , 1) ; 
      }
      else if(str[idx] == 'P')
      {
         p.update(idx , 1) ; 
      }
      else
      {
         s.update(idx , 1) ; 
      }

      cout << get() << endl ; 
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
   int t=1;
   // cin>>t;
   for(int i=1;i<=t;i++)
         solve();
   return 0;
}