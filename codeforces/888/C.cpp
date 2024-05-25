#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  map<char, vector<int>> mp;
  for (char c = 'a'; c <= 'z'; c++) {
    mp[c].push_back(0);
  }
  for (int i = 1; i <= n; i++) {
    mp[s[i]].push_back(i);
  }
  for (char c = 'a'; c <= 'z'; c++) {
    mp[c].push_back(n + 1);
  }

  int ans = n;
  for (auto [c, v] : mp) {
    int sz = v.size();
    int mx = 0;
    for (int i = 1; i < sz; i++) {
      mx = max(mx, v[i] - v[i - 1]);
    }
    // cout << c << ' ' << mx << '\n';
    ans = min(ans, mx);
  }
  cout << ans << '\n';

  return 0;
}
  	 	  	 		 					   				   			