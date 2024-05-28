#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back
using ll = long long;
const int inf = 1e5 + 7;
using namespace std;

ll n, a[3 * inf], ans[3 * inf];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie();

    cin >> n;
    fill(ans, ans + n, INT_MIN);
    pair<ll, ll> odd, even;
    if (n % 2) {
        even = {n / 2 - 1, n / 2};
        odd = {n / 2 - 1, n / 2 - 1};
    } else {
        even = {n / 2 - 1, n / 2 - 1};
        odd = {n / 2 - 2, n / 2 - 1};
    }
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 2; i++) {
        if ((n - i) % 2 == 0) {
            ans[i] = max({a[even.first], a[even.first + 1], a[even.second], a[even.second + 1]});
            even.first--;
            even.second++;
        } else {
            ans[i] = max(min(a[odd.first + 1], max(a[odd.first], a[odd.first + 2])),
                         min(a[odd.second + 1], max(a[odd.second], a[odd.second + 2])));
            odd.first--;
            odd.second++;
        }
        if (i >= 2) ans[i] = max(ans[i], ans[i - 2]);
    }
    ans[n - 2] = ans[n - 1] = *max_element(a, a + n);
    for (int i = 0; i < n; i++) cout << ans[i] << " ";

}