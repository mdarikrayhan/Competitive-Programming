#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min3(a,b,c) min(min(a,b),c)
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define gap " "
#define vi vector<int>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define rev_sort(v) sort(all(v),greater<int>())
#define sz(c) int((c).size())
const double PI = acos(-1);
const long long INF = 1e18;
const long long MOD = 1000000007;

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key

#ifdef ONLINE_JUDGE
#define debug(...) 42
#else
#include "debug.h"
#endif

/*-----------  END -----------*/

ll dfs(ll u, ll p, vector<vll> &adj, vector<ll> &a){
  ll cnt = 0;
  for(auto it: adj[u]){
    if (it != p)
    {
      cnt += dfs(it, u, adj, a);
    }
  }
  if (p == -1)
  {
    return cnt;
  }
  else{
    if (cnt >= 2)
    {
      return 10;
    }
    cnt += (a[u] == 1);
    return min(cnt, 1ll);
  }
}

void solve(int ts = 1)
{
  ll n; cin >> n;
  vector<vll> adj(n);
  for (int i = 0; i < n-1; ++i)
  {
    ll u, v; cin >> u >> v;
    u--; v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  ll q; cin >> q;
  while(q--){
    ll m; cin >> m;
    vll a(n, 0);
    ll start = -1;
    for (int i = 0; i < m; ++i)
    {
      ll x; cin >> x;
      x--;
      a[x]++;
      start = x;
    }
    assert(start != -1);
    ll cnt = dfs(start, -1, adj, a);
    debug(cnt);
    if (cnt <= 2)
    {
      cout << "YES\n";
    }
    else cout << "NO\n";
  }
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    freopen("error.out", "w", stderr);
  #endif
 

  int ts;
  ts=1;
  // cin>>ts;
  for(int i = 1; i <= ts; i++){
    solve(i);
  }
}