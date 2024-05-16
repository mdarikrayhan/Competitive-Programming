#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define fi first
#define sec second

const ll MOD = 1e8;
const ll N = 1e5 + 5;
const ll INF = 1e18;

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  ll tc = 1;
  // cin >> tc;
  while(tc--){
    ll v; cin >> v;
    vector<ll>cost(15);
    ll mn = INF;
    for(int i=1;i<=9;i++){
      cin >> cost[i];
      mn = min(mn,cost[i]);
    }
    ll sz = v/mn;
    string ans = "";
    for(int i=sz;i>=1;i--){
      for(char j='9';j>='1';j--){
        if(v < cost[j-'0']) continue;
        if((v-cost[j-'0'])/mn == i-1){
          ans.pb(j);
          v -= cost[j-'0'];
          break;
        }
      }
    }
    if(ans.size() == 0) cout << -1 << endl;
    else cout << ans << endl;
  }
} 

/*

*/