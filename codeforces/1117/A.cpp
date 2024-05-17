#include <bits/stdc++.h>

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 1, cr = 0, mx = -1;
    for(cin >> n; cin >> n;) {
        if(mx < n) {
            mx = n;
            ans = 1;
            cr = 1;
        } else if(mx == n) {
            ++ cr;
        } else {
            ans = max(ans, cr);
            cr = 0;
        }
    }
    cout << max(ans, cr);
}
