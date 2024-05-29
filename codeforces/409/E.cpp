#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#define ll long long
#define ld long double
#define ull unsigned ll
#define st string
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pb push_back
#define ins insert
#define F first
#define S second
#define int ll
using namespace std;
using namespace __gnu_pbds;
const int N = 2e5+5, INF = 2e18+1, MOD = 1e9+7, cnst = 512;
tree <pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> sat;
mt19937_64 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
//
void solve () {
    ld r;
    cin >> r;
    for (int a = 1; a <= 10; a ++) {
        for (int h = 1; h <= 10; h ++) {
            if (abs(a * h / sqrt(a * a + 4 * h * h) - r) <= 1e-5) {
                cout << a << " " << h;
                return;
            }
        }
    }
    return;
}
/*
*/
int32_t main()
{
    //
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen ("choco.in", "r", stdin);
    //freopen ("choco.out", "w", stdout);
    int T = 1;
    //cin >> T;
    while (T --) {
		solve();
    }
    return 0;
}
