#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
 
// using namespace boost::multiprecision;
 
// #define int cpp_int 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define int long long
#define ull unsigned long long
#define EPS 1e-9
int cas = 0; 
using namespace __gnu_pbds;
 
#define test_case \
  int t;          \
  cin >> t;       \
  while (t--)
 
#define print_case cout << "Case " << ++cas << ": "
#define mod (int) 1e9+7
const int N = 9e5+7;
const int INF = INT64_MAX;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() { 
  int n; cin >> n;
  vector<int>sol; 
  vector<pair<int,int>>vp;
  for(int i = 0; i < n; i++) {
    int a, b; cin >> a >> b; 
    vp.push_back({a, b});
    a *= b; sol.push_back(a);
  } 
  int ans = sol[0];
  for(int i = 0; i < n; i++) {
    ans = __gcd(sol[i], ans);
  } 
  for(auto i : vp) {
    int aa = __gcd(ans, i.first);
    int bb = __gcd(ans, i.second);
    ans = max(aa, bb);
  }
  if(ans == 1) return void(cout << -1);
  cout << ans;

}
 
int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  // test_case
  solve(),
      cout<<'\n';
  cout<<fixed<<setprecision(10);
  cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
  return EXIT_SUCCESS;
}