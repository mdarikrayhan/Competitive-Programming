#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

const int N = 1e6 + 7;

ll f[N], cnt[N];
bool pw[N], vis[20 * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= n; ++i) {
        f[i] = 1;
        for (ll j = 1LL * i * i; j <= n; j *= i) {
            f[i]++;
            pw[j] = 1;
        }
    }
    for (int i = 1; i <= 20; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!vis[i * j]) {
                vis[i * j] = 1;
                cnt[i]++;
            }
        }
        cnt[i] += cnt[i - 1];
    }
    ll ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (pw[i] == 0) {
            ans += cnt[f[i]];
        }
    }
    cout << ans << "\n";
    return 0;
}

