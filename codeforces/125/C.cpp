#include <bits/stdc++.h>
using namespace std;

int io_=[](){ ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using PII = pair<int, int>;
using VI = vector<int>;
using MII = map<int, int>;

template<typename T> void cmin(T &x,const T &y) { if(y<x) x=y; }
template<typename T> void cmax(T &x,const T &y) { if(x<y) x=y; }
template<typename T> bool ckmin(T &x,const T &y) { 
    return y<x ? (x=y, true) : false; }
template<typename T> bool ckmax(T &x,const T &y) { 
    return x<y ? (x=y, true) : false; }
template<typename T> void cmin(T &x,T &y,const T &z) {// x<=y<=z 
    if(z<x) { y=x; x=z; } else if(z<y) y=z; }
template<typename T> void cmax(T &x,T &y,const T &z) {// x>=y>=z
    if(x<z) { y=x; x=z; } else if(y<z) y=z; }

// mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
// mt19937_64 rnd_64(chrono::system_clock::now().time_since_epoch().count());

/*
---------1---------2---------3---------4---------5---------6---------7---------
1234567890123456789012345678901234567890123456789012345678901234567890123456789
*/

void solve() {
  int n; cin >> n;

  int ans = 3;
  auto check = [&](int i) {
    return i * (i - 1) / 2 <= n;
  };
  while (check(ans + 1)) {
    ans++;
  }

  vector<vector<int>> a(ans);
  int k = 1;
  for (int i = 0; i < ans; i++) {
    for (int j = i + 1; j < ans; j++) {
      a[i].push_back(k);
      a[j].push_back(k);
      k++;
    }
  }

  cout << ans << '\n';
  for (auto&& v : a) {
    for (int i : v) cout << i << ' ';
    cout << '\n';
  }
}

int main() {
  int t = 1; 
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
