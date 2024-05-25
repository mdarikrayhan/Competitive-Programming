#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  vector<int> l(m), a(n,-1), taken(n+1,-1);
  for(int i = 0; i < m; i++) {
    cin >> l[i];
    l[i]--;
  }
  for(int i = 0; i < m-1; i++) {
    int diff = l[i+1]-l[i];
    if(diff <= 0) diff+=n;
    if((a[l[i]] != -1 && a[l[i]] != diff) || (taken[diff]!=-1 && taken[diff]!=l[i])) {
      cout << -1 << '\n';
      return;
    }
    a[l[i]] = diff;
    taken[diff]=l[i];
  }
  vector<int> not_taken;
  for(int i = 1; i < n+1; i++) {
    if (taken[i] == -1) not_taken.push_back(i);
  }
  for (auto u : a) {
    if (u == -1) {
      cout << not_taken.back() << ' ';
      not_taken.pop_back();
    } else {
      cout << u << ' ';
    }
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tt = 1;
  //cin >> tt;
  while(tt--) solve();
}