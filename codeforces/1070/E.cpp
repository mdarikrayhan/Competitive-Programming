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
template<typename T>using max_heap=priority_queue<T,vector<T>,less<T>>;

const int N = 2e5 ; 

array < int , 2 > st[4 * N + 10] ; 

array < int , 2 > merge(array < int , 2 >  & a , array < int , 2 >  & b)
{
   return {a[0] + b[0] , a[1] + b[1]} ; 
}

void build(int node , int from , int to)
{
   if(from == to)
   {
      st[node] = {0 , 0} ; 
      return  ; 
   }
   int mid = (from + to) / 2 ; 
   build(node * 2 , from , mid) ; 
   build(node * 2 + 1 , mid + 1 , to) ; 
   st[node] = merge(st[node * 2] , st[node * 2 + 1]) ; 
}

void update(int node , int from , int to , int idx , int val1 , int val2)
{
   if(!(from <= idx and idx <= to))return  ; 
   if(from == to)
   {
      st[node][0] += val1 ; 
      st[node][1] += val2 ; 
      return  ; 
   }
   int mid = (from + to) / 2 ; 
   update(node * 2 , from , mid , idx , val1 , val2) ; 
   update(node * 2 + 1 , mid + 1 , to , idx , val1 , val2) ; 
   st[node] = merge(st[node * 2] , st[node * 2 + 1]) ; 
}

array < int , 2 > qry(int node , int from , int to , int k)
{
   if(from > to)return {0 , 0} ; 
   if(from == to)
      return st[node] ; 
   int mid = (from + to) / 2 ; 
   if(k <= st[node * 2][0])
      return qry(node * 2 , from , mid , k) ; 
   else
   {
      array < int , 2 > ar = qry(node * 2 + 1 , mid + 1 , to , k - st[node * 2][0]) ; 
      ar[0] += st[node * 2][0] ; 
      ar[1] += st[node * 2][1] ; 
      return ar ; 
   }
   return {0 , 0} ; 
}

int n , m , t  ; 

void upd(int idx , int val1 , int val2)
{
   update(1 , 0 , n , idx , val1 , val2) ; 
}


int cst(int k)
{
   return qry(1 , 0 , n , k)[1] ; 
}



int solve()
{
   cin >> n >> m >> t ; 
   int ps = 0 ; 
   build(1 , 0 , n) ;

   max_heap < array < int , 2 >> pq ; 
   int mn = inf ; 
   for(int i = 1 ; i <= n ; i += 1)
   {
      int a ; 
      cin >> a ; 
      mn = min(mn , a) ; 
      upd(i , 1 , a) ; 
      pq.push({a , i}) ; 
   }
   if(mn > t)
   {
      cout << 0 << " " << t << endl ; 
      return 0 ; 
   }
   int ans =  - inf , k = 0 ;  
   while(pq.size() > 0)
   {
      auto [cur , idx] = pq.top() ; 
      if(cur <= t)
      {
         int low = 0 , high = qry(1 , 0 , n , n)[0] / m , res = 0 ; 
         while(low <= high)
         {
            int mid = (low + high) / 2 ; 
            if(cst(mid * m) * 2 <= t)
            {
               res = mid ; 
               low = mid + 1 ; 
            }
            else
            {
               high = mid - 1 ; 
            }
         }
         int net = res * m ; 
         int tt = t - cst(res * m) * 2 ; 
         low = 0 , high = min(m , qry(1 , 0 , n , n)[0] - res * m) , res = 0 ; 
         while(low <= high)
         {
            int mid = (low + high) / 2 ; 
            if(cst(net + mid) - cst(net) <= tt)
            {
               res = mid ; 
               low = mid + 1 ; 
            }
            else
            {
               high = mid - 1 ; 
            }
         }
         net += res ; 
         if(ans < net)
         {
            ans = net ; 
            k = cur ; 
         }
      }
      while(pq.size() > 0 and pq.top()[0] == cur)
      {
         upd(pq.top()[1] , - 1 , - pq.top()[0]) ; 
         pq.pop() ; 
      }
      // break ; 

   }

   cout << ans << " " << k << endl ; 


   return 0;
}








int32_t main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   #ifdef LOCAL
      freopen("input.txt","r",stdin);
      freopen("error.txt","w",stdout);
   #endif
   int t=1;
   cin>>t;
   for(int i=1;i<=t;i++)
         solve();
   return 0;
}