#include <bits/stdc++.h>

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long l1, r1, l2, r2, k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    cout << (r2 < l1 || r1 < l2 ? 0 : min(r1, r2) - max(l1, l2) + !(max(l1, l2) <= k && k <= min(r1, r2)));
}
