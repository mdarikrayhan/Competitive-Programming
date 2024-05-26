#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353ll
#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
ll power(long long x, ll y, ll p)
{
   ll res = 1; // Initialize result
   x = x % p;
   if (x == 0)
      return 0; // In case x is divisible by p;

   while (y > 0)
   {
      if (y & 1)
         res = (res * x) % p;
      y = y >> 1; // y = y/2
      x = (x * x) % p;
   }
   return res;
}
const ll N = (1 << 18) + 4;
ll n;
string s;
vector<ll> hs(N), ans(N);
vector<vector<ll>> v((1 << 18) + 5);
ll dfs2(ll ve, ll pa)
{
   ll a = -1, b = -1;
   set<ll> st;
   if (v[ve].size() == 1)
   {
      ans[ve] = 1;
      return 1;
   }
   for (auto ch : v[ve])
   {
      if (ch != pa)
      {
         // st.insert(hs[ch]);
         if (a == -1)
         {
            a = dfs2(ch, ve);
         }
         else
         {
            b = dfs2(ch, ve);
         }
      }
   }
   ans[ve] = (a % MOD * b % MOD) % MOD;
   if (hs[ve]==1)
   {
      ans[ve]%=MOD;
      return ans[ve];
   }
   else
   {
      ans[ve]=2%MOD*ans[ve];
      ans[ve]%=MOD;
      return ans[ve];
   }
}
string dfs(ll ve, ll pa, ll h)
{
   ll cnt=0;
   string a,b;
   for (auto ch : v[ve])
   {
      if (ch != pa)
      {
         if(!cnt){
            a=dfs(ch,ve,h);
            cnt++;
         }
         else{
            b=dfs(ch,ve,h);
         }
      }
   }
   hs[ve]=(a==b);
   if(a>b){
      swap(a,b);
   }
   return s[ve-1]+a+b;
}
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(NULL);
   ll t(1);
   // cin >> t;
   while (t--)
   {
      cin >> n;
      cin >> s;
      for (ll i = 1; i < (1 << n); i++)
      {
         if (2 * i < (1 << n))
         {
            v[i].push_back(2 * i);
            v[i].push_back(2 * i + 1);
            v[i * 2].push_back(i);
            v[2 * i + 1].push_back(i);
         }
      }
      dfs(1,0,1);
      dfs2(1,0);
      cout<<ans[1]<<' ';
   }
   return 0;
}