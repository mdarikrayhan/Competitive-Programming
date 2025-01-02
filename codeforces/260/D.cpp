#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;

// loal is the cutest girl

#define ll long long
#define ld long double
#define pow2(x) (x)*(x)
#define le left
#define ri right
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define pll pair<long long, long long>
#define isvowel(x) (x) == 'a' || (x) == 'i' || (x) == 'u' || (x) == 'e' || (x) == 'o'
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 

const ld EPS = 1e-9;
const ld PI = 3.141592653589793238462643383279502884197169399375105820974944;

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  
  int n;
  cin >> n;
  vector<pii> a0, a1;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    if (x == 0) a0.pb({y, i});
    else a1.pb({y, i});
  }
  sort(all(a0));
  sort(all(a1));

  int pt0 = 0, pt1 = 0;
  for (int i = 0; i < n-1; i++) {
    cout << a0[pt0].se << ' ' << a1[pt1].se << ' ';
    if (a0[pt0].fi < a1[pt1].fi) {
      a1[pt1].fi -= a0[pt0].fi;
      cout << a0[pt0].fi;
      a0[pt0++].fi = 0;
    } else {
      a0[pt0].fi -= a1[pt1].fi;
      cout << a1[pt1].fi;
      a1[pt1++].fi = 0;
      if (pt1 == a1.size()) {pt1--; pt0++;}
    }
    cout << '\n';
  }

  return 0;
}