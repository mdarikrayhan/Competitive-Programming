#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, x;
    cin >> n >> x;
    queue<pair<ll, ll>> q;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        q.push({a, b});
    }
    ll ans = 0;
    for (ll t = 1; t < 200000; t++) {
        if (q.empty())
            break;
        if (q.front().first <= t && t <= q.front().second) {
            ans += 1;
            continue;
        }
        if (q.front().second < t)
            q.pop();
        if (q.empty())
            break;
        if (t + x <= q.front().first)
            t += x - 1;
        else
            ans += 1;
    }
    cout << ans;
}