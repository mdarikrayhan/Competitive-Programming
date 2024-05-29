#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t, n, a, b, k;
    cin >> t >> n >> a >> b >> k;
    ll l = 0, r = t + 1;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        ll x = ((n + 1) / 2) * min(a, m) + (n / 2) * min(b, m);
        if (x >= m * k) l = m;
        else r = m;
    }
    cout << l;
}