#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// const ll mod = 1000000007;
// const ll mod = 998244353;

void solve() {
    int n, k, x, y;
    ll z, ans;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<ll, ll>> dp_right(n, {0, 0}), dp_left(n, {0, 0});
    z = 0;
    for (int i = 0; i < n; i++) {
        z += a[i];
        if (i < k - 1) {
            continue;
        }
        if (i == 0 || z > dp_left[i - 1].first) {
            dp_left[i] = { z, i - k + 2 };
        } else {
            dp_left[i] = dp_left[i - 1];
        }
        z -= a[i - k + 1];
    }
    z = 0;
    for (int i = n - 1; i >= 0; i--) {
        z += a[i];
        if (i > n - k) {
            continue;
        }
        if (i == n-1 || z >= dp_right[i + 1].first) {
            dp_right[i] = { z, i + 1 };
        } else {
            dp_right[i] = dp_right[i + 1];
        }
        z -= a[i + k - 1];
    }
    ans = 0;
    for (int i = k - 1; i < n - k; i++) {
        z = dp_left[i].first + dp_right[i+1].first;
        if (z > ans || (z == ans && dp_left[i].second < x) ||
            (z == ans && dp_left[i].second == x && dp_right[i+1].second < y)) {
            ans = z;
            x = dp_left[i].second;
            y = dp_right[i+1].second;
        }
    }
    cout << x << ' ' << y << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
