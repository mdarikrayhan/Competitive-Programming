#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
static const auto fast = []()
{ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;} ();
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;  // find_by_order(*) , order_of_key
 
 
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#define mod 1000000007
#define mod2 998244353
#define INF  1e18
//counting number of set bits
#define bitsi(n) __builtin_popcount(n)
#define bitsl(n) __builtin_popcount(n)
#define bitsll(n) __builtin_popcountll(n)
#define endl "\n" 
#define f first
#define s second
#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end));i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define pb push_back
#define read(a,n) for(ll i=0;i<n;i++){cin>>a[i];}
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
//string to int stoi(s) to long long int stoll(s)
typedef long long ll;
typedef long  double lld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ull,ull> puu;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
 
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define debug(...)
#define debugArr(arr, n)
#endif

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
ll binexp(ll a,ll x,ll m){
    ll ans=1;
    a%=m;
    while(x){
    if(x&1){ ans=(ans*a)%m;}
     a=(a*a)%m;
     x>>=1;
}
return ans;
}
//return {x,y,gcd} ; a*x + b*y = gcd
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3

ll mod_inverse(ll b,ll m){return binexp(b,m-2,m);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mod_inverse(b, m), m) + m) % m;}  //only for prime m
 
void sieveOfEratosthenes(int n){
vector<bool> primes(n+1,1);
 primes[0]=0; primes[1]=0;
     for(int i=2;i*i<=n;i++){
     if(primes[i]==1){
          for(int j=i*i;j<=n;j+=i){
         primes[j]=0;
       }}}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//,
    void dfs(ll ii, ll root, vll adj[], vll &col){
     for(auto x:adj[ii]){
          if(x == root){continue;}
          col[x] = 1 - col[ii];
          dfs(x, ii, adj, col);
     }
    }
 
     void solve(){
     ll n; cin >> n;     
     vll adj[n + 1];
     rep(i, 0, n-1){
          ll u, v; cin >> u >> v;  
          adj[u].pb(v); 
          adj[v].pb(u);
     }

     vll col(n + 1);
     dfs(1, 1, adj, col);
    // debug(col);
      ll sum = 0;  // adjacents must have different highest bit 
     for(auto x:col){sum+= x;}
     ll val = 1;
    if(n - sum <= sum){
        sum = n - sum; 
        val = 0;
    }
    vll a, b; 
    ll ii = 0, jj = 0;
      vll h(n + 1); 
     ll x = 2; 
     for(int i = 1; i <= n; i++){
        if(x <= i){h[i] = h[i-1]+1;x*=2;}
        else{
           h[i] = h[i-1];
        }
        if((sum & 1LL << h[i])){
            a.pb(i);
        }
        else{
           b.pb(i);
      }
      }
      debug(val, sum, h);
     vll mp(n+1);
     rep(i,1, n+1){
          if(col[i] == val){mp[i] = a[ii++];}
          else{ mp[i] = b[jj++];}
     }

     rep(i, 1, n+1){
          cout << mp[i] <<  " ";
     }
     cout << endl;

     // adjacent have different h[i]
     
          
     }
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int main(){
       //freopen("input.txt", "r", stdin);
       //freopen("output.txt", "w", stdout);
     ll T;cin>>T;
      while(T--){
        solve();
}
}