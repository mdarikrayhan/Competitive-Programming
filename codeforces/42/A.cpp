#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int int64_t
#define uint uint64_t
#define double_t long double
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
template <typename... Args> void out(Args... args) { (cout << fixed << setprecision(4) << ... << args); }
struct Runtime {
    clock_t start;
    Runtime() {
        start = clock();
    }
    ~Runtime() {
        cout << "Runtime: " << fixed << setprecision(3) << (double) (clock() - start) / CLOCKS_PER_SEC << "s\n";
    }
};

const int N = 1e6 + 1, mod = 1e9 + 7;
int n, v, a[20], b[20];
bool valid(double x) {
    double vol = 0;
    for (int i = 0; i < n; ++i) {
        vol += a[i] * x;
        if (a[i] * x > b[i] || vol > v) return 0;
    }
    return 1;
}
void solve() {
    in(n, v);
    for (int i = 0; i < n; ++i) in(a[i]);
    for (int i = 0; i < n; ++i) in(b[i]);
    double lo = 0, hi = *min_element(b, b + n), tm = 30;
    while (tm--) {
        double mid = (lo + hi) / 2;
        if (valid(mid)) lo = mid;
        else hi = mid;
    }
    double ans = 0;
    for (int i = 0; i < n; ++i) ans += a[i] * hi;
    out(ans, "\n");
}
signed main() {
#ifndef ONLINE_JUDGE
    Runtime _;
#endif
    fast_IO;
    int tc = 1;
    // in(tc);
    for (int cs = 1; cs <= tc; cs++) {
        // out("Case ", cs, ": ");
        solve();
    }
}
					 			  								 		   	   		