#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;
  
#define int long long
  
const int N = 1e3 + 10;
const int md = 1e9 + 7;
const int INF = 1e18;

int32_t main(int32_t argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  // cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1);
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      for (int j = x; j <= y; j++) {
        a[j] = 1;
      }
    }
    vector<int> ans;
    for (int i = 1; i <= m; i++) {
      if (!a[i])
        ans.push_back(i);
    }
    cout << (int) ans.size() << '\n';
    for (auto i : ans)
      cout << i << " ";
    cout << '\n';
  }

  return 0;
}