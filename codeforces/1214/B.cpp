#include <bits/stdc++.h>

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int b, g, n;
    cin >> b >> g >> n;
    cout << min({b, g, n, b + g - n}) + 1;
}
