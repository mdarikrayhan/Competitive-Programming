#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld double
#define int ll
#define usaco(fname) freopen(#fname ".in","r",stdin);freopen(#fname ".out","w",stdout);
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// const ll INF = 1e18;
const int INF = 1e9;
const int mod = 1e9+7;
const lld PI = acos(-1.0);
int di[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dj[] = {0, 0, 1, -1, 1, -1, 1, -1};
#define debug(x) cout << #x << ": " << x << endl;
#define add(a, b) a += b, a %= mod
#define mul(a, b) ((a % mod) * (b % mod)) % mod
#define all(x) x.begin(),x.end()

void solve() {
  int n,m;cin>>n>>m;

  vector<int> a(n);
  for (int i =0 ; i < n; i++) cin >> a[i];

  function<bool(int)> check = [&](int k) {
    int now = 0;

    for (int i = 0; i < n; i++) {
      if (a[i] + k >= m) {
        if (a[i]+k-m < now) now = max(now, a[i]);
      } else {
        if (a[i]+k < now) return 0;
        else now = max(now, a[i]);
      }
    }

    return 1;
  };

  int l = 0, r = m-1;
  int ans = m;
  while (l <= r) {
    int mid = (l+r)>>1;

    if (check(mid)) r = mid-1, ans = mid;
    else l = mid+1;
  }
  cout << ans << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t=1;
  while(t--) solve();

  return 0;
}
