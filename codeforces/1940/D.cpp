#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
vector<ll>skal;
set<pair<ll,ll>>S;
map<ll,ll>mp;
ll A[LIM], B[LIM], jaki[2*LIM], n, akt;
void solve() {
  akt=0;
  skal.clear();
  mp.clear();
  S.clear();
  cin >> n;
  rep(i, n) {
    cin >> A[i];
    skal.pb(A[i]*2*n+n+i);
  }
  rep(i, n) {
    cin >> B[i];
    skal.pb(B[i]*2*n+i);
  }
  sort(all(skal));
  for(auto i : skal) if(mp.find(i)==mp.end()) {
    mp[i]=akt;
    jaki[akt]=i/(2*n);
    ++akt;
  }
  ll ans=0, sum=0;
  rep(i, n) {
    sum+=A[i]-B[i];
    pair<ll,ll>p={mp[B[i]*2*n+i], mp[A[i]*2*n+n+i]};
    while(true) {
      auto it=S.lower_bound(p);
      if(it==S.end()) break;
      pair<ll,ll>s=*it;
      if(p.nd<s.st) break;
      S.erase(it);
      p.nd=max(p.nd, s.nd);
    }
    auto it=S.lower_bound(p);
    if(it!=S.begin()) {
      --it;
      pair<ll,ll>s=*it;
      if(s.nd>p.st) p={min(p.st, s.st), max(p.nd, s.nd)};
    }
    S.insert(p);
    ans=max(ans, jaki[p.nd]-jaki[p.st]);
    cout << sum-ans << " ";
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}