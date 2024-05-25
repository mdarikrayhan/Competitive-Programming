#include <bits/stdc++.h>
// Ordered Set / Ordered Map
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define el "\n"
const ll mod = 998244353;
void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// Ordered Set / Ordered Map
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void work() {
    ll n; cin >> n;
    vector<ll> vec(n + 1); for (ll i = 1; i <= n; i++) cin >> vec[i];
    ll x = sqrt(n);
    vector<vector<ll>> dp(n + 1, vector<ll> (x + 1, -1));
    for (ll i = 1; i <= x; i++) {
        for (ll j = n; j >= 1; j--) {
            if (vec[j] + i + j > n) dp[j][i] = 1;
            else dp[j][i] = dp[vec[j] + i + j][i] + 1;
        }
    }
    ll q; cin >> q;
    while (q--) {
        ll p, k; cin >> p >> k;
        if (k > x) {
            ll ans = 0;
            for (; p <= n; ans++) p = p + k + vec[p];
            cout << ans << el;
        } else {
            cout << dp[p][k] << el;
        }
    }
}

signed main() {
    FIO
    fileIO();

    ll t = 1;
    // cin >> t;
    while (t--) {
        work();
    }
}   
		   	  	  		 			 	       	   	