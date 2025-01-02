#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
const int a[] = {0, 1, 2, 3, 4, 8, 12, 5, 10, 15};
ll fpow(ll x, int n) {
    ll res = 1, a = x;
    while (n) {
        if (n & 1) res *= a;
        n >>= 1;
        a *= a;
    }
    return res;
}
ll solve(ll n) {
    if (n <= 3) return n;
    for (int m = 1; m <= 30; m++) {
        ll tm = (1ll << 2 * m) - 1;
        if (tm < n) continue;
        n -= (1ll << 2 * (m - 1));
        // cout << "n=" << n << '\n';
        ll res = (1ll << 2 * (m - 1)) + (n) / 3;
        // cout << "res=" << res << '\n';
        for (int b = 0; b < 2 * m; b += 2) {
            ll mask = ((3ll << b) & res) >> b;
            if ((n) % 3 == 1) {
                if (mask == 1) res ^= (3ll) << b;
                if (mask == 2) res ^= (1ll) << b;
                if (mask == 3) res ^= (2ll) << b;
            }
            if ((n) % 3 == 2) {
                if (mask == 1) res ^= (2ll) << b;
                if (mask == 2) res ^= (3ll) << b;
                if (mask == 3) res ^= (1ll) << b;
            }
        }
        return res;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        cout << solve(n) << '\n';
    }
    return 0;
}