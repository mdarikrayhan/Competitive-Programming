#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, r, b, k, u, v;
    cin >> t;
    while (t--) {
        cin >> r >> b >> k;
        u = min(r, b);
        v = max(r, b);
        cout << ((v - __gcd(u, v) - 1) / u + 1 < k ? "OBEY\n" : "REBEL\n");
    }
}