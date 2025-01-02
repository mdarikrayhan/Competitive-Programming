#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    ll ans = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (arr[i] <= arr[i + 1]) {
            continue;
        }
        ll x = (arr[i] - 1) / arr[i + 1];
        ans += x;
        x++;
        arr[i] = arr[i] / x;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}