#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(x) int((x).size())

constexpr int M = 1e5 + 5, mod = 1e9 + 7, inf = 1e9;

void solve() {
    ll x;
    cin >> x;

    ll ans = 0;
    for (ll i = 1; i <= x + 1; i ++ ) {
        ll lo = max(1ll, x * x - i * i), hi = (x + 1) * (x + 1) - i * i;

        if (hi > 1ll && ceil(sqrt(lo)) < ceil(sqrt(hi))) {
            ans += ceil(sqrt(hi)) - ceil(sqrt(lo));
        }
    }
    cout << ans * 4 + 4 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;

    while (_ -- ) {
        solve();
    }
    return 0;
}

	  			   	 			 			  	 	 	  		