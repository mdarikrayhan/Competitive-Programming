#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve()
{
    int n, k;
    string s, srev;
    cin >> n >> k >> srev;
    s = srev;
    reverse(srev.begin(), srev.end());
    if (s == srev)
    {
        cout << 1 << nl;
    }
    else
    {
        if (k > 0)
        {
            cout << 2 << nl;
        }
        else
        {
            cout << 1 << nl;
        }
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