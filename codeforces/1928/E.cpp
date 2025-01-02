#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;   
using namespace std;
typedef long long ll;

//
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
//
#define ld long double
#define pb push_back
/* You may enter other macros defined by you */
#define vi vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rep1(i,a,b) for(ll i=a;i<=b;i++)
#define ff first
#define ss second
#define pll pair<ll, ll>
#define vpll vector<pair<ll,ll> >
#define vvl vector<vector<ll> >
#define printv(a) for(auto x: a){cout<<x<<" ";}cout<<"\n";
#define input(a,n) rep(i,0,n)cin>>a[i];
#define input1(a,n) rep1(i,1,n)cin>>a[i];
#define mp make_pair

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define minv(a) *min_element(all(a))
#define maxv(a) *max_element(all(a))
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
// random number generator
mt19937 rnd(593); 

  
const ll mod = 1e9+7;
//const ll mod = 998244353;
const ld PI = acos(-1);
const ld EPS = 1e-9;
const ll INF = 1e8;
const ll N=3e5+10;
inline int add(int x, int y) { int ret = x + y; if (ret >= mod) ret -= mod; return ret; }
inline int sub(int x, int y) { int ret = (x - y); if (ret < 0) ret += mod; return ret; }
inline int mul(int x, int y) { int ret = (1ll * x * y) % mod; return ret; }
int exp(int a, int b) { int ret = 1; while (b) { if (b & 1) ret = mul(ret, a); a = mul(a, a); b >>= 1;} return ret; }
int dv(int a, int b) { int ret = exp(b, mod - 2); ret = mul(ret, a); return ret; }


void solve(){   
  ll n,x,y,s;cin>>n>>x>>y>>s;
  s-=n*(x%y);  
  if( s<0 ||s%y!=0){
    cout<<"NO\n";
    return;
  }
  s/=y;
  vi dp(s+1,INF);
  dp[0]=0;
  vi ans(n,0);
  vi prev(s+1,-1);
  vi val(s+1,-1);
  for(ll i=1;i<=s;i++){
    for(ll r=2;  i-(r*(r-1))/2>=0 ;r++){
      if(dp[i]>dp[i-(r*(r-1))/2]+r){
        dp[i]=dp[i-(r*(r-1))/2]+r;
        prev[i]=i-(r*(r-1))/2;
        val[i]=r;
      }
    }
  }
  auto endd=[&](){
    for(ll i=0;i<n;i++){
      ans[i]*=y;
      ans[i]+=(x%y);
    }
    cout<<"YES\n";
    printv(ans);
  };
  for(ll i=0;i<n;i++){
    if(i==0){
      ans[i]=x/y;
      s-=(x/y);
      if(s<0){
        cout<<"NO\n";
        return;
      }
    }
    else{
      ans[i]=ans[i-1]+1;
      s-=(ans[i-1]+1);
      if(s<0){
        cout<<"NO\n";
        return;
      }
    }
    if(s==0){
      endd();
      return;
    }
    // now do here
    if(dp[s]>n-1-i){
      continue;
    }
    ll st=i+1;
    while(s>0){
      for(ll i=0;i<val[s];i++){
        ans[st+i]=i;
      }
      st+=val[s];
      s-=(val[s]*(val[s]-1))/2;
    }
    endd();
    return;
  }
  cout<<"NO\n";
  return;
    
}
    
int main(){

  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int t;
  cin>>t;while(t--)
    solve();
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";

  return 0; 
}