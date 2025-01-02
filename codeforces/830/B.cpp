#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN = 1e5 + 5;
vector<set<ll>> v(MAXN);

int main() {

  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    v[a[i]].insert(i);
  }
  sort(a.begin(), a.end());
  ll ans = n;
  ll idx = 0, cnt = 0;
  for(auto x : a) {
    // cout << "x = " << x << endl;
    auto it = v[x].lower_bound(idx);
    if(it == v[x].end()) {
      ans += n - cnt;
      idx = 0;
      it = v[x].lower_bound(idx);
    }
    idx = *it;
    cnt++;
    v[x].erase(it);
    // cout << "it = " << *it << endl;
  }
  cout << ans << endl;

  return 0;
}