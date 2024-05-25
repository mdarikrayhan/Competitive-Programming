#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

#define int long long
#define all(x) (x).begin(),(x).end()
const ll N = 2e5 + 10;

void test_case(){
  ll n , x , y;
  string s , t;
  cin >> n >> x >> y >> s >> t;
  ll _1 = 0;
  for(int i = 0 ; i < n ; i++){
    _1 += (s[i] == '1');
    _1 += (t[i] == '1');
  }
  if(_1%2 == 1){
    cout << -1 << endl;
    return;
  }
  vector<ll> a;
  for(int i = 0 ; i < n ; i++){
    if(s[i] != t[i]) a.push_back(i);
  }
  sort(all(a));
  if(a.size() == 0){
    cout << 0 << endl;
    return;
  }
  if(a.size() == 2){
    if(a[0] == a[1] - 1){
      cout << min(x , 2*y) << endl;
    } else {
      cout << min((a[1] - a[0])*x , y) << endl;
    }
    return;
  }
  if(y <= x){
    cout << y*(a.size()/2) << endl;
    return;
  }
  n = a.size();
  ll dp[n + 1];
  for(int i = 0 ; i <= n ; i++) dp[i] = 1e16;
  dp[0] = 0 , dp[1] = 0;
  for(int i = 2 ; i <= n ; i++){
    if(i%2 == 1){
      dp[i] = min(dp[i - 2] + (a[i - 1] - a[i - 2])*x , dp[i - 1]);
    } else {
      dp[i] = min(dp[i - 2] + (a[i - 1] - a[i - 2])*x , dp[i - 1] + y);
    }
  }
  cout << dp[n] << endl;
}
int32_t main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for(int i = 0 ; i < t ; i++) {
    test_case();
  }
}