#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define int long long

# ifdef LOCAL

# include "C:\Program Files\DEBUG\debug.h"

# else
# define debug(...) 114514
# define ps 114514
# endif


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    if (a[n] == 0) {
        cout << "YES" << endl;
        return;
    }
    vector<int> vis(100);
    vector<__int128> pw(100);
    __int128 tmp = 1;
    int tot = 0;
    pw[0] = 1;
    while (tmp <= (long long) 1e16) {
        tmp *= k;
        tot++;
        pw[tot] = tmp;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = tot; j >= 0; j--) {
            if (a[i] / pw[j] >= 2) {
                cout << "NO" << endl;
                return;
            }
            if (a[i] / pw[j] >= 1) {
                vis[j]++;
                a[i] %= pw[j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= tot; i++) {
        if (vis[i] > 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main() {
    IOS
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}