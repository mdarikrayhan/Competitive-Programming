#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0 && b == 0 && c == 0 && d == 0)
    {
        cout << 0 << nl;
        return;
    }
    if (a == 1 && b == 1 && c == 1 && d == 1)
    {
        cout << 2 << nl;
        return;
    }
    if (a == 0 && d == 0)
    {
        cout << 1 << nl;
        return;
    }
    if (b == 0 && c == 0)
    {
        cout << 1 << nl;
        return;
    }
    else
    {
        cout << 1 << nl;
        return;
    }
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