#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef long long ll;
typedef long double ld;
#ifndef ONLINE_JUDGE
#include "debug.h"
#define debug(v)                                                                 \
cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif
#define fr(n) for (ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 0; i < (n); i++)
#define ENDL '\n'
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define ret(msg) {cout << msg << '\n'; return;}
#define vll vector<ll>
#define pll pair<ll,ll>
#define tll tuple<ll,ll,ll>
#define vpll vector<pair<ll,ll>>
#define vvll vector<vector<ll>>
#define vvpll vector<vpll>
const ll N = 998244353;
const ll M = 1000000007;
ll MOD = 1e9 + 7; 
inline ll popcnt (ll x) { return __builtin_popcountll(x); }
void solve()
{
  ll n;
  cin>>n;
  vpll a(n);
  fr(n)
  {
    cin>>a[i].F;
    a[i].S = i;
  }
  vll f(n);
  sort(all(a));
  reverse(all(a));
  fr(n) f[a[i].S] = i+1;
  fr(n) cout<<f[i]<<" "; cout<<ENDL;
} 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll t = 1;
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  cin>>t;
  while (t--) solve();
  return 0;
}