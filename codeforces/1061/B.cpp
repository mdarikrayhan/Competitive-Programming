#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, m, sm = 0, k = 0;
    cin >> n >> m;
    int a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], sm += a[i];
    sort(a, a + n + 1);
    for (int i = n; i > 0; --i) k += max(a[i] - a[i - 1], (int) (a[i] > 0)), a[i - 1] = max(a[i] - max(a[i] - a[i - 1], (int) (a[i] > 0)), 1LL);
    cout << sm - k;
    return 0;
}