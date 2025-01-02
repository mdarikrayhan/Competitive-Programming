#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n"
#define int long long
#define ll long long
#define ld long double
const int mod = vector<int>{998244353 , 1000000007}[1] ; 
const int inf = 1e17;
const double eps=1e-9;
const double pi=    3.14159265358979323846;
#define all(x)  x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
int max(int a , int b){return ((a >= b)?a : b) ; }
int min(int a , int b){return ((a >= b)?b : a) ; }
template<typename T>using ordered_set=
tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const int N = 2e5 ; 
int n , m , k , to , dep[N + 1] , ck , vis[N + 10] ;
vector < int > vec1[N + 1] ; 
vector < int > vec[N + 1] ; 
vector < int > chain[N + 1] ; 



void f1(int node , int par)
{
   vis[node] = 1 ; 
   if(par != 0)
   {
      vec[node].push_back(par) ; 
      vec[par].push_back(node) ; 
   }
   for(auto child : vec1[node])
      if(!vis[child])
         f1(child , node) ; 
}

void f(int node , int par , int dp)
{
   dep[node] = dp ; 
   for(auto child : vec[node])
      if(child != par)
      {
         f(child , node , dp + 1) ; 
         dep[node] = max(dep[node] , dep[child]) ; 
      }
   sort(all(vec[node]) , [ & ](int a , int b){return dep[a] > dep[b] ; }) ; 
}

void dfs(int node , int par , int cnt = 0)
{
   // assert(ck <= k) ; 
   // if(ck > k)
   // {
   //    debug(ck)
   // }

   chain[ck].push_back(node) ;
   for(auto child : vec[node])
      if(child != par)
      {
         if(chain[ck].size() == to)
         {
            ck ++  ; 
         }
         dfs(child , node) ; 
      }
   if(chain[ck].size() < to and par != 0)
   {
      chain[ck].push_back(par) ; 
   }
}


int solve(int test)
{
   ck = 1 ; 
   set < array < int , 2 >> st ; 
   cin >> n >> m >> k ; 
   to = ((2 * n + k - 1) / k) ; 
   for(int i = 0 ; i <= n ; i += 1)
   {
      vis[i] = 0 ; 
      vec1[i].clear() ; 
      vec[i].clear() ; 
      chain[i].clear() ; 
   }

   for(int i = 1 ; i <= m ; i += 1)
   {
      int a , b ; 
      cin >> a >> b ; 
      st.insert({min(a , b) , max(a , b)}) ; 
   }

   for(auto [a , b]:st)
   {
      vec1[a].push_back(b) ; 
      vec1[b].push_back(a) ; 
   }
   int r = 1 ; 
   f1(r , 0) ; 
   for(int i = 1 ; i <= n ; i += 1)
      if(vec[i].size() == 1)
         r = i ; 
   f(r , 0 , 1) ;
   dfs(r , 0 , 1) ; 
   // debug(test) ; 
   for(int i = 1 ; i <= k ; i += 1)
   {
      if(chain[i].size() == 0)chain[i].push_back(1) ; 
      cout << chain[i].size() << " " ; 
      for(auto a : chain[i])
         cout << a << " " ; 
      cout << endl ; 
   }




   return 0;
}








signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   #ifdef LOCAL
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
   #endif
   int t=1;
   // cin>>t;
   for(int i=1;i<=t;i++)
   {
         solve(i);
   }
   return 0;
}