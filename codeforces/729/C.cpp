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
template <typename... Args> void out(Args... args) { (cout << fixed << setprecision(8) << ... << args); }
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
int n, k, s, T;
vector<pair<int, int>> car;
vector<int> dis;
bool valid(int fl) {
    int t = 0;
    for (auto &d : dis) {
        int l = 0, h = d;
        while (l <= h) {
            int m = (l + h) / 2;
            if (2 * m + (d - m) <= fl) l = m + 1;
            else h = m - 1;
        }
        if (h == -1) return 0;
        t += h + 2 * (d - h);
    }
    return t <= T;
}
void solve() {
    in(n, k, s, T);
    for (int i = 0; i < n; ++i) {
        int p, f; in(p, f);
        car.push_back({f, p});
    }
    sort(car.beg, car.end);
    int g[k];
    for (int i = 0; i < k; ++i) in(g[i]);
    sort(g, g + k);
    dis.push_back(g[0]);
    for (int i = 1; i < k; ++i) dis.push_back(g[i] - g[i - 1]);
    dis.push_back(s - g[k - 1]);
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (valid(car[mid].fst)) hi = mid - 1;
        else lo = mid + 1;
    }
    if (lo == n) out("-1\n");
    else {
        int ans = 1e9 + 1;
        for (int i = lo; i < n; ++i) ans = min(ans, car[i].snd);
        out(ans, "\n");
    }
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
    	  	  				    		    	 	 		