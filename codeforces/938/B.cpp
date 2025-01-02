#include <bits/stdc++.h>

using namespace std;
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast_io();
    int n;
    cin >> n;
    int ans = 0;
    int m = 1, f = 1e6;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ans = max(ans, min(a - m, f - a));
    }
    cout << ans << endl;
}