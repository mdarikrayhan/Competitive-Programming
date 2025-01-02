#include<bits/stdc++.h>
using namespace std;

const int M = 998244353, N = 3e5 + 5;
#define int long long

void solve() {
  int n, k; cin >> n >> k;
  map<int,int>mpp, bound;

  auto add = [&](int a, int b) {
    return (a + b) % M;
  };

  auto mul = [&](int a, int b) {
    return (a * b) % M;
  };

  for(int i = 0; i < n; i++) {
    int l, r; cin >> l >> r;
    mpp[l]++, mpp[r+1]--;
    bound[l]++;
  }
  int sum = 0;
  for(auto &[i, x]: mpp) {
    sum += x;
    x = sum;
  }

  auto expo = [&](int a, int b) {
    int res = 1;
    while(b) {
      if(b & 1) res = mul(res, a);
      a = mul(a, a);
      b >>= 1;
    }
    return res;
  };

  vector<int> fact(N), inv(N);
  fact[0] = 1;
  for(int i = 1; i < N; i++) fact[i] = mul(fact[i-1], i);
  inv[N-1] = expo(fact[N-1], M-2);
  for(int i = N-2; i >= 0; i--) inv[i] = mul(inv[i+1], i+1);

  auto ncr = [&](int n, int r) -> int {
    if(r > n) return 0;
    return mul(fact[n], mul(inv[n-r], inv[r]));
  };

  int ans = 0;
  for(auto &[i, x]: bound) {

    int y = mpp[i];

    while(y >= k && x > 0) {
      ans = add(ans, ncr(y-1, k-1));
      x--, y--;
    }

  }
  cout << ans << '\n';
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t = 1;
  // cin>>t;
  while(t--) solve();
  
  return 0;
}