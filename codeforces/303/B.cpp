// LUOGU_RID: 158985236
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m, x, y, a, b;
    cin >> n >> m >> x >> y >> a >> b;
    int g = __gcd(a, b);
    a /= g, b /= g;
    int mul = min(n / a, m / b);
    a *= mul, b *= mul;
    int u = min(n - a, x - (a + 1) / 2);
    int v = min(m - b, y - (b + 1) / 2);
    u = max(u, 0), v = max(v, 0);
    cout << u << " " << v << " " << u + a << " " << v + b << "\n";
    return 0;
}