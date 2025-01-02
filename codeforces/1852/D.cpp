#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string.h>

using namespace std;  
using ll = long long;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ve vector
void dead() {
  vector<int> a;
  for(int i = 0; i < 1000000; i++) a.push_back(i);
}


const int N = 2e5 + 10;

bool ok(vector<int>& a, int k) {
  if(a[2] == k) return false;
  return k >= a[0] && k <= a[1];
}

vector<int> merge(vector<int> a, vector<int> b) {
  vector<int> ans(3, -1);
  if(a[1] > b[1]) swap(a, b);
  ans[0] = min(a[0], b[0]);
  ans[1] = max(a[1], b[1]);
  if(a[1] + 1 < b[0]) {
      ans[2] = a[1] + 1;
  }
  if(a[2] != -1 && !ok(b, a[2])) {
    ans[2] = a[2];
  }
  if(b[2] != -1 && !ok(a, b[2])) {
    ans[2] = b[2];
  }
  return ans;
}

vector<int> shift(vector<int>& a, int x) {
  vector<int> ans(a.begin(), a.end());
  ans[0] += x;
  ans[1] += x;
  if(ans[2] != -1) ans[2] += x;
  return ans;
}

void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  int K = k;
  for(int i = 1; i < n; i++) {
    k -= (s[i] != s[i - 1]);
  }
  if(k < 0) {
    cout << "NO" << endl;
    return; 
  }
  
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(2));
  if(s[0] == 'A') {
    dp[0][0] = {0, 0, -1};
    dp[0][1] = {1, 1, -1};
  } else {
    dp[0][1] = {0, 0, -1};
    dp[0][0] = {1, 1, -1};
  }

  for(int i = 1; i < n; i++) {
    if(s[i] == 'A') {
      dp[i][0] = merge(shift(dp[i - 1][0], 0), shift(dp[i - 1][1], 1));
      dp[i][1] = merge(shift(dp[i - 1][0], 2), shift(dp[i - 1][1], 1));
    } else {
      dp[i][0] = merge(shift(dp[i - 1][0], 1), shift(dp[i - 1][1], 2));
      dp[i][1] = merge(shift(dp[i - 1][0], 1), shift(dp[i - 1][1], 0));
    }
    //cout << dp[i][0][0] << "  " << dp[i][0][1] << " " << dp[i][0][2] << endl;
    //cout << dp[i][1][0] << "  " << dp[i][1][1] << " " << dp[i][1][2] << endl;
    //cout << endl;
  }

  if(!ok(dp[n - 1][0], k) && !ok(dp[n - 1][1], k)) {
    cout << "NO" << endl;
    return;
  }
  
  
  string ans = "";
  int i = -1, j = -1;
  if(ok(dp[n - 1][0], k)) {
    i = n - 1;
    j = 0;
  }
  if(ok(dp[n - 1][1], k)) {
    i = n - 1;
    j = 1;
  }

  while(i >= 0) {
    if(j == 0) ans += 'A';
    if(j == 1) ans += 'B';
    if(i == 0) break;
    if(s[i] == 'A') {
      if(j == 0) {
        if(ok(dp[i - 1][0], k)) {
          i--;
          j = 0;
        } else if(ok(dp[i - 1][1], k - 1)) {
          i--;
          j = 1;
          k--;
        } else {
            break;
        }
      } else {
        if(ok(dp[i - 1][0], k - 2)) {
          i--;
          j = 0;
          k -= 2;
        } else if(ok(dp[i - 1][1], k - 1)) {
          i--;
          j = 1;
          k--;
        } else {
          break;
        }
      } 
    } else {
      if(j == 0) {
        if(ok(dp[i - 1][0], k - 1)) {
          i--;
          j = 0;
          k--;
        } else if(ok(dp[i - 1][1], k - 2)) {
          i--;
          j = 1;
          k -= 2;
        } else {
            break;
        }
      } else {
        if(ok(dp[i - 1][0], k - 1)) {
          i--;
          j = 0;
          k--;
        } else if(ok(dp[i - 1][1], k)) {
          i--;
          j = 1;
        } else {
            break;
        }
      }
    }
  }
  
  reverse(ans.begin(), ans.end());
  cout << "YES" << endl;
  cout << ans << endl;
}
  

int main(){
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}

/*
1
14 28
ABBABBBBAABBBA
*/
