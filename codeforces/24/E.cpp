#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int int64_t
#define uint uint64_t
#define fst first 
#define snd second
#define beg begin()
#define end end()
#define rbeg rbegin()
#define rend rend()
#define dcn greater<>()
#define mem(ar, v) memset(ar, v, sizeof(ar))
#define nl cout << "\n";
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define at_(p) find_by_order(p)
#define find_(v) order_of_key(v)
#define fast_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
template <class T> using index_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using index_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename... Args> void in(Args &...args) { (cin >> ... >> args); }
template <typename... Args> void out(Args... args) { (cout << fixed << setprecision(20) << ... << args); }
struct Runtime {
    clock_t start;
    Runtime() {
        start = clock();
    }
    ~Runtime() {
        cout << "Runtime: " << fixed << setprecision(3) << (double) (clock() - start) / CLOCKS_PER_SEC << "s\n";
    }
};

const int N = 5e5 + 1, mod = 1e9 + 7;
int n;
pair<int, int> pr[N];
bool safe(double tm) {
  double mx = -2e18 ;
  for (int i = 0; i < n; ++i) {
    if (pr[i].snd > 0) mx = max(mx, pr[i].snd * tm + pr[i].fst);
    else if (pr[i].snd * tm + pr[i].fst <= mx) return 1;
  }
  return 0;
}
void solve() {
    in(n);
    for (int i = 0; i < n; ++i) in(pr[i].fst, pr[i].snd);
    sort(pr, pr + n);
    double lo = 0.0, hi = 1e9;
    int it = 64;
    while (it--) {
      double mid = (lo + hi) / 2;
      if (safe(mid)) hi = mid;
      else lo = mid;
    }
    if (lo == 1e9) out("-1\n");
    else out(lo, "\n");
}
signed main() {
#ifndef ONLINE_JUDGE
    Runtime _;
#endif
    fast_IO;
    int tc = 1;
    // in(tc);
    for (int cs = 1; cs <= tc; cs++) {
        // out("Case #", cs, ": ");
        solve();
    }
}
	 	 								  	 	   		  		 	