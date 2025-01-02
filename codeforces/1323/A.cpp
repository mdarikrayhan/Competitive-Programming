#include <bits/stdc++.h>

using namespace std;

/*
#pragma GCC optimize("Ofast,O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2,fma,tune=native")
*/

typedef long long ll;
typedef long double ld;
#define mp(x, y) make_pair(x, y)
#define endl '/n'
#define all(a) (a.begin(), a.end())
ll maxn = (ll) 1E7;
ll INF = (ll) 1E18 + (ll) 1;
ll MOD = (ll) 1E9 + (ll) 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> x, y;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2) {
            x.push_back(i+1);
        } else {
            y.push_back(i+1);
        }
    }

    if (!y.empty()) {
        cout << 1 << '\n' << y[0];
    } else if (x.size() >= 2) {
        cout << 2 << '\n' << x[0] << " " << x[1];
    } else cout << -1;

    return;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int tt;
    tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
        cout << '\n';
    }

    return 0;
}
