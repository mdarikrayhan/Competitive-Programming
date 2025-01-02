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
    int l = a[1], r = a[1];
    for (int i = 2; i <= n; i++) {
        debug(i, l, r);
        int tl = a[i], tr = a[i] + k - 1;
        l = max(tl, l - k + 1);
        r = min(tr, r + k - 1);
        if (l > a[i] + k - 1) {
            cout << "NO" << endl;
            return;
        }
        if(l > r){
            cout << "NO" << endl;
            return;
        }
    }

    if (l == a[n])cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main() {
    IOS
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}