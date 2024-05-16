#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
  ios::sync_with_stdio(false) ; cin.tie(0);
  
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    map<int , int> mp;
    for(int i = 0; i < n; i++){
      int a; cin >> a;
      mp[a]++;
    }
    
    vector<int> cnt (n);
    
    for(auto [x , y] : mp){
      cnt.push_back(y);
    }

    sort(cnt.begin() , cnt.end());

    int x = cnt.size();
    int want = INT_MIN;

    for(int i = 0; i < x; i++){
      want = max(want , cnt[i] * (x - i));
    }
    
    cout << n - want << "\n";
  }

  return 0;
}