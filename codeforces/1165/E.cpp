/**
   author: Saurabh Chaudhary
   created: 2024-05-24 22:19:11
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (auto& i : a) cin >> i;
  for (auto& i : b) cin >> i;

  for (ll i = 0; i < n; i++) {
    a[i] = a[i] * (i + 1) * (n - i);
  }

  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());

  ll ans = 0;
  ll mod = 998244353;
  for (ll i = 0; i < n; i++) {
    ans += (a[i] % mod) * b[i] % mod;
    ans %= mod;
  }

  cout << ans << '\n';

  return 0;
}
