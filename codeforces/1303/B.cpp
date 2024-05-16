#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, g, b, h;
        cin >> n >> g >> b;
        h = (n + 1) / 2;
        cout << max((h - 1) / g * b + h, n) << '\n';
    }
    return 0;
}