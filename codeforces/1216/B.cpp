
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  t = 1;
  while (t--) solve();
}

void solve() {
  ll n;
  cin >> n;
  ll a[n];
  for (ll i = 0; i < n; i++)
    cin >> a[i];
  ll I[n];
  for (ll i = 0; i < n; i++) I[i] = i;
  sort(I, I+n, [&](ll x, ll y) {
      return a[x] > a[y];
      });
  ll f = 0;
  for (ll i = 0; i < n; i++) {
    ll j = I[i];
    f += 1 + a[j]*i;
  }
  cout << f << '\n';
  for (ll i = 0; i < n; i++)
    cout << I[i] + 1 << " ";
  cout << '\n';
}
