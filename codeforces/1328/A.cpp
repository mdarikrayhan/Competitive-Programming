#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve()
{
    int a, b;
    cin >> a >> b;
    if (a % b == 0)
    {
        cout << 0 << nl;
    }
    else if ((a % b) > b)
    {

        cout << a % b - b << nl;
    }
    else
    {
        cout << b - a % b << nl;
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