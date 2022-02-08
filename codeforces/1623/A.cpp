#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve()
{
    int n, m, r, c, a, b;
    cin >> n >> m >> r >> c >> a >> b;
    cout << min(a < r ? (2 * (n - r) + r - a) : a - r, b < c ? (2 * (m - c) + c - b) : b - c) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}