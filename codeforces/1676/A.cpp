#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve()
{
    string s;
    cin >> s;
    if ( s[0] + s[1] + s[2] == s[3] + s[4] + s[5])
    {
        cout << "YES" << nl;
    }
    else
    {
        cout << "NO" << nl;
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