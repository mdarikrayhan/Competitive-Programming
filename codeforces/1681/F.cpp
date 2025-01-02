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



const int N = 5e5 ; 
vector < array < int , 2 > >col[N + 10] , vec[N + 10] ;  
int sub[N + 10] , st[N + 10] , ed[N + 10] , tim = 1 ; 


int dfs(int node , int par)
{
   sub[node] = 1 ;  
   st[node] = tim ++  ; 
   for(auto [child , ed] : vec[node])
   {
      if(child == par)continue ; 
      col[ed].push_back({node , child}) ; 
      sub[node] += dfs(child , node) ; 
   }
   ed[node] = tim ++  ; 
   return sub[node] ; 
}

int isanc(int a , int b)
{
   return ((st[a] <= st[b] and ed[b] <= ed[a])) ; 
}

int res = 0 ; 

int solve(int node , int cl , int  & ptr)
{
   int cur = sub[node] , rs = 0 ; 
   vector < int > vc ; 
   while(ptr < col[cl].size())
   {
      if(!isanc(node , col[cl][ptr][1]))break ; 
      ptr ++  ; 
      cur -= sub[col[cl][ptr - 1][1]] ; 
      int h = solve(col[cl][ptr - 1][1] , cl , ptr) ;  
      vc.push_back(h) ; 
   }
   for(auto a : vc)
      res += cur * a ; 
   return cur ; 
}


int32_t solve()
{
   int n ; 
   cin >> n ; 
   for(int i = 1 ; i < n ; i += 1)
   {
      int a , b , c ; 
      cin >> a >> b >> c ; 
      vec[a].push_back({b , c}) ; 
      vec[b].push_back({a , c}) ; 
   }
   dfs(1 , 0) ; 
   for(int i = 1 ; i <= n ; i += 1)
   {
      if(col[i].size() == 0)continue ; 
      int ptr = 0 ; 
      solve(1 , i , ptr) ; 
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