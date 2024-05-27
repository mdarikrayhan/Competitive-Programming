// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // for memset
#include <functional> // for lambda functions
#include <iomanip> // for fixed and setprecision
#include <set>
#include <map>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <numeric>
#include <cstdio> // fflush, freopen
#include <cmath>
#include <list>
#include <bitset>
#include <stack>
#include <cassert>
#include <random>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// *st.find_by_order(index)
// st.order_of_key(value)


template <typename T>
void print(const T& value) {
  std::cout << value << "\n";
}


#define int long long
const int MAXN = 105;
const int MOD = 1e9 + 7;

int fact[MAXN];
int inv_fact[MAXN];

bool multi = true;


inline int pow_mod(int a, int b){
  int res = 1;
  while (b > 0) {
    if (b % 2 == 1){
      res = (res * a) % MOD;
    }
    b >>= 1;
    a = (a * a) % MOD;
  }
  return res;
}

inline void init() {
  fact[0] = 1;
  inv_fact[0] = 1;

  for (int i = 1; i < MAXN; i++){
    fact[i] = (fact[i - 1] * i) % MOD;
    inv_fact[i] = pow_mod(fact[i], MOD - 2);
  }
}

inline int nCr(int n, int r){
  if (n < r){
    return 0;
  }
  int res = (fact[n] * inv_fact[r]) % MOD;
  return (res * inv_fact[n - r]) % MOD;
}

inline void solve(){
  int n, k;
  cin >> n >> k;
  vector<int> crr(n + 1);
  for (int i = 1; i <= n; i++){
    cin >> crr[i];
  }
  int mx = n / k + 1;
  vector<vector<int>> dp(n + 1, vector<int>(mx, 0));

  dp[0][0] = 1;

  for (int i = 1; i <= n; i++){
    for (int j = 0; j < mx; j++){
      dp[i][j] = dp[i - 1][j];
      if (j == 0){
        continue;
      }
      int cnt = 1;
      int res = dp[i][j];
      for (int s = i - 1; s > 0; s--){
        if (crr[s] == crr[i]){
          if (++cnt >= k){
            res = (res + (dp[s - 1][j - 1] * nCr(cnt - 2, k - 2)) % MOD) % MOD;
          }
        }
      }
      dp[i][j] = res;
    }
  }
  for (int i = (n / k); i >= 0; i--){
    if (dp[n][i] > 0){
      print(dp[n][i]);
      return;
    }
  }
  return;
}

#undef int
int main(){
  // freopen("template.in", "r", stdin);
  // freopen("template.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  if (multi) {
    cin >> t;
  }
  init();
  while (t--) {
    solve();
  }
  return 0;
}