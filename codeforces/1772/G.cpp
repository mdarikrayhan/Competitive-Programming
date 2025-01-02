#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll f (ll a, ll b) {return (a + b - 1) / b;}
void solve(){
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    sort(a.begin(), a.end());
    vector<ll> t(n), b(n);
    for (ll i = 0; i < n; i++) {
        if (i > 0 and b[i - 1] >= a[i]) t[i] = t[i - 1], b[i] = b[i - 1] + 1;
        else t[i] = a[i] - i, b[i] = a[i] + 1;
    }
    ll ans = 0;
    while (x < y) {
        ll i = upper_bound(t.begin(), t.end(), x) - t.begin();
        ll p = i, m = n - i;
        if (x + p >= y) return cout << ans + (y - x) << '\n', void();
        if (p <= m) return cout << "-1\n", void();
        ll k = f(y - x - p, p - m);
        if (i < n) k = min(k, f(t[i] - x, p - m));
        ans += k * n;
        x += k * (p - m);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    while (t--) solve();
}
