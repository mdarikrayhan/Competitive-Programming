#include <bits/stdc++.h>

using namespace std;

int lr[100100];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m = -1, mx = 0, LR = 0;
    cin >> n;
    for(int i = 0, l, r; i < n; ++ i) {
        cin >> l >> r;
        lr[i] = r - l;
        LR += lr[i];
    }
    mx = abs(LR);
    for(int i = 0; i < n; ++ i) {
        if(mx < abs(LR - 2 * lr[i])) {
            mx = abs(LR - 2 * lr[i]);
            m = i;
        }
    }
    cout << m + 1;
}
