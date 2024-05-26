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
template<typename T>using min_heap=priority_queue<T,vector<T>,greater<T>>;


const int N = 5000 , M = 3e5 , K = 5000 ; 
int arr[N + 10] , brr[N + 10] , crr[N + 10] , drr[N + 10] ; 
vector < int > vec[N + 10] ; 
int n , m , k , vis[N + 10] ; 




int solve()
{

   cin >> n >> m >> k ; 
   for(int i = 1 ; i <= n ; i += 1)
   {
      cin >> arr[i] ; 
      cin >> brr[i] ; 
      cin >> crr[i] ; 
      drr[i] = i ; 
   }

   for(int i = 1 ; i <= m ; i += 1)
   {
      int a , b ; 
      cin >> a >> b ; 
      drr[b] = max(drr[b] , a) ; 
   }

   for(int i = 1 ; i <= n ; i += 1)
   {
      vec[drr[i]].push_back(i) ; 
   }


   int ans = 0 , sm = 0  ; 
   min_heap < int  > pq ; 
   for(int i = 1 ; i <= n ; i += 1)
   {
      while(k < arr[i] and pq.size() > 0)
      {
         k ++  ;  
         pq.pop() ; 
      }
      if(k < arr[i])
      {
         cout <<  - 1 << endl ; 
         return 0 ; 
      }
      k += brr[i] ; 
      sort(all(vec[i]) , [ & ](int a , int b){return crr[a] > crr[b] ; }) ; 
      for(auto a:vec[i])
      {
         if(k == 0 and pq.size() > 0 and pq.top() < crr[a])
         {
            pq.pop() ; 
            pq.push(crr[a]) ; 
            continue ; 
         }
         if(k <= 0)break ; 
         k --  ; 
         pq.push(crr[a]) ; 
      }
   }
   while(pq.size() > 0)
   {
      sm += pq.top() ; 
      pq.pop() ; 
   }
   cout << sm << endl ; 
   


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