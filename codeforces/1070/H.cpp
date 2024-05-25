#include <bits/stdc++.h>
using namespace std;
string s;
unordered_map<string, int> sum;
unordered_map<string, bool> vis;
unordered_map<string, string> fa;
int n, k;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    vis.clear();
    for (int j = 0; j < s.size(); j++) {
      string ch = "";
      for (int k = j; k < s.size(); k++) {
        ch += s[k];
        sum[ch] += (!vis[ch]), vis[ch] = true, fa[ch] = s;
      }
    }
  }
  for (cin >> k; k; k--) {
    cin >> s;
    sum[s] ? cout << sum[s] << " " << fa[s] << '\n' : cout << "0 -\n";
  }
  return 0;
}
	 			         	   	    	 	 				