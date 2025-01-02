#include <bits/stdc++.h>

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m;
    for(cin >> n >> m; n && m && min(n, m) * 2 <= max(n, m); n < m ? m %= n * 2 : n %= m * 2);
    cout << n << ' ' << m;
}
