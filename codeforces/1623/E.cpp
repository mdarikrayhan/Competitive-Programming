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
int n , k ; 
string s , str[N + 10] ; 
int lf[N + 10] , rg[N + 10] , ok[N + 10] , idx[N + 10] ; 
char rgt[N + 10] ; 

vector < int > vec ; 

void dfs(int node)
{
   if(lf[node] != 0)dfs(lf[node]) ; 
   vec.push_back(node) ; 
   if(rg[node] != 0)dfs(rg[node]) ; 
}

bool ok1(int node)
{
   return (s[node] < rgt[node]) ; 
}

int dfs2(int node , int dep)
{
   int h = 0 ; 
   if(lf[node] != 0)
   {
      if(dfs2(lf[node] , dep + 1)) 
      {
         h = 1 ; 
         str[node] += str[node] ; 
         if(rg[node])dfs2(rg[node] , 1) ; 
         return 1 ; 
      }
      else if(k >= dep and ok1(node))
      {
         k -= dep ; 
         str[node] += str[node] ; 
         if(rg[node])dfs2(rg[node] , 1) ; 
         return 1 ; 
      }
   }
   else
   {
      if(k >= dep and ok1(node))
      {
         k -= dep ; 
         str[node] += str[node] ; 
         if(rg[node])dfs2(rg[node] , 1) ; 
         return 1 ; 
      }
   }
   return 0 ;  
}



int solve()
{
   cin >> n >> k ; 
   cin >> s ; 
   s = '.' + s ; 
   for(int i = 1 ; i <= n ; i += 1)
   {
      str[i] = s[i] ; 
      int l , r ; 
      cin >> l >> r ; 
      lf[i] = l , rg[i] = r ; 
   }
   dfs(1) ; 
   char ch = 'a' - 1 ; 
   char ls = s[vec.back()] ; 
   for(int i = vec.size() - 1 ; i >= 0 ; i -= 1)
   {
      idx[vec[i]] = i ; 
      if(ls != s[vec[i]])
         ch = ls ; 
      rgt[vec[i]] = ch ; 
      ls=s[vec[i]] ; 
   }
   dfs2(1 , 1) ; 
   for(auto a : vec)
      cout << str[a] ; 
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