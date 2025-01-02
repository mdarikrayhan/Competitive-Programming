#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
void solve() {
    ll n, k; cin >> n >> k;
    if (k * (k - 1) < n) return cout << "NO", void();
    cout << "YES\n";
    map<ll,ll> mp;
    for (ll i = 1; i <= k; i++) {
        cout << i << ' ' << i % k + 1 << '\n';
        mp[i] = i % k + 1;
        n--;
        if (!n) return;
    }
    while (n) {
        for (ll i = 1; i <= k; i++) {
            cout << i << ' ' << mp[i] % k + 1 << '\n';
            mp[i]++;
            n--;
            if (!n) return;
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
}
