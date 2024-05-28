#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> d;

int dp(ll x) {
    if (x <= 6) {
        return x;
    }
    if (x <= 11) {
        return 2 + (11 - x);
    }

    int j = 0;
    for (int i = 0; i < 16; ++i) {
        if (d[i + 1] > x) {
            j = i;
            break;
        }
    }
    int res1 = j * (x / d[j]) + dp(x % d[j]);
    x = d[j + 1] - x;
    int res2 = j + 1 + (x / d[j]) * j + dp(x % d[j]);

    return min(res1, res2);
}

void solve() {
    ll n;
    cin >> n;

    d.assign(17, 0);
    d[1] = 1;
    for (int i = 2; i < 17; ++i) {
        d[i] = 10 * d[i - 1] + 1;
    }

    cout << dp(n);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}