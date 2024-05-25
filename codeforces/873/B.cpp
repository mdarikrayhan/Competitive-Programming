#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
string s;
int n, pref1[N], pref2[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cin >> s;
  s = '.' + s;
  for (int i = 1; i <= n; i++) {
    pref1[i] += pref1[i - 1] + (s[i] == '1'); 
    pref2[i] += pref2[i - 1] + (s[i] == '0'); 
  }

  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    mp[pref1[i] - pref2[i]] = i;
  }

  int ans = 0;
  for (int i = 0; i <= n; i++) {
    int l = i, r = mp[pref1[i] - pref2[i]];
    ans = max(ans, r - l);
  }
  cout << ans << '\n';

  return 0;
}
 	  			 			  		     	    				 	