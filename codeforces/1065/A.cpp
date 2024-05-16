#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  int tt = 1;
  cin >> tt;
  while(tt--) {
    solve();
  }
  return 0;
}

#define int long long

void solve() {
  int s,a,b,c;
  cin >> s >> a >> b >> c;
  cout << (s / c / a) * b + (s / c) << '\n';
}