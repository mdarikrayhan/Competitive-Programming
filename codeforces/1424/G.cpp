#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false) ; cin.tie(0);
  
  int n; cin >> n;
  map<int , int> mp;
  for(int i = 0; i < n; i++){
    int b , d; cin >> b >> d;
    mp[b]++ , mp[d]--;
  }

  vector<pair<int , int>> rcnt;

  for(auto [x , y] : mp){
    rcnt.push_back({x , y});
  }

  for(int i = 1; i < rcnt.size(); i++){
    rcnt[i].second += rcnt[i - 1].second;
  }

  pair<int , int> ans;
  int mx = 0;

  for(int i = 0; i < rcnt.size(); i++){
    if(mx < rcnt[i].second){
      mx = rcnt[i].second;
      ans = {rcnt[i].first , mx};
    }
  }

  cout << ans.first << " " << ans.second << "\n";
  
  return 0;
}