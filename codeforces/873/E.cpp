// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  pair<int, int> a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i].fi, a[i].se = i;
  sort(a + 1, a + n + 1);
  a[0] = mp(0, 0);
  // there are 3 borders, choose 2 and set the other one
  // first -> d1 - c2 border
  // second -> d2 - c3 border
  // third -> final border
  // can not be > 2 * other
  pair<int, int> b[n + 1][n + 1];
  for(int i = 1; i <= n; ++i) {
    pair<int, int> mx = mp(0, 0);
    for(int j = i; j <= n; ++j) {
      mx = max(mx, mp(a[j].fi - a[j - 1].fi, j));
      b[i][j] = mx;
    }
  }
  pair<int, pair<int, int>> mx = mp(0, mp(0, 0));
  for(int i = n; i >= 1; --i) {
    // if(a[i].fi == a[i - 1].fi)
    //   continue;
    int cl = n + 1, cr = n;
    for(int j = i - 1; j >= 1; --j) { 
      // if(a[j].fi == a[j - 1].fi)
      //   continue;
      int s1 = n - i + 1, s2 = i - j;
      if(s1 > 2 * s2 || s2 > 2 * s1)
        continue;
      // 1 ... j
      int mnsz = max(s1, s2) / 2 + max(s1, s2) % 2;
      int mxsz = min(s1, s2) * 2;
      // find max diff between them
      // choose another position such that the diff between x and the prev pos > 0
      int r = n - s1 - s2 - mnsz + 1, l = n - s1 - s2 - mxsz + 1;
      if(r < 1)
        break;
      l = max(l, 1), r = max(r, 1);
      mx = max(mx, mp(a[i].fi - a[i - 1].fi, mp(a[j].fi - a[j - 1].fi, b[l][r].fi)));
    }
  }
  // cout << mx.fi << " " << mx.se.fi << " " << mx.se.se << endl;
  for(int i = n; i >= 1; --i) {
    // if(a[i].fi == a[i - 1].fi)
    //   continue;
    int cl = n + 1, cr = n;
    for(int j = i - 1; j >= 1; --j) { 
      // if(a[j].fi == a[j - 1].fi)
      //   continue;
      int s1 = n - i + 1, s2 = i - j;
      if(s1 > 2 * s2 || s2 > 2 * s1)
        continue;
      // 1 ... j
      int mnsz = max(s1, s2) / 2 + max(s1, s2) % 2;
      int mxsz = min(s1, s2) * 2;
      // find max diff between them
      // choose another position such that the diff between x and the prev pos > 0
      int r = n - s1 - s2 - mnsz + 1, l = n - s1 - s2 - mxsz + 1;
      // cout << i << " " << j << " " << l << " " << r << endl;
      if(r < 1)
        break;
      l = max(l, 1), r = max(r, 1);
      if(mx == mp(a[i].fi - a[i - 1].fi, mp(a[j].fi - a[j - 1].fi, (b[l][r]).fi))){
        // output this
        int ans[n + 1];
        fill(ans, ans + n + 1, -2);
        for(int k = 1; k < (b[l][r]).se; ++k) {
          ans[a[k].se] = -1;
        }
        for(int k = (b[l][r]).se; k < j; ++k) {
          ans[a[k].se] = 3;
        }
        for(int k = j; k < i; ++k) {
          ans[a[k].se] = 2;
        }
        for(int k = i; k <= n; ++k) {
          ans[a[k].se] = 1;
        }
        for(int k = 1; k <= n; ++k)
          cout << ans[k] << " ";
        cout << endl;
        // cout << mx.fi << " " << mx.se.fi << " " << mx.se.se << endl;
        exit(0);
      }
    }
  }
  assert(false);
  return 0;
}