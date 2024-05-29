#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << (1LL << a[0]) - 1 << "\n";
        return;
    }

    int mx = -1;
    for (int i = 1; i < n; i++) {
        if (!a[i] || a[i] - a[i - 1] >= 2 || (i < n - 1 && a[i - 1] == a[i] && a[i] == a[i + 1])) {
            cout << -1 << "\n";
            return;
        }
        mx = max(mx, a[i - 1] - a[i]);
    }

    long long x;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] - a[i] == mx) {
            if (61 - (mx + 2) < a[i] - 1) {
                cout << -1 << "\n";
                return;
            }
            x = 1LL << (mx + 1);
            for (int j = 0; j < a[i] - 1; j++) {
                x |= 1LL << (mx + 2 + j);
            }
            x -= i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (__builtin_popcountll(x + i) != a[i]) {
            cout << -1 << "\n";
            return;
        }
    }

    cout << x << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}