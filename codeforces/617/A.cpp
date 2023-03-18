#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int ans = 0;
    while (n>=5)
    {
        n -= 5;
        ans++;
    }
    while (n>=4)
    {
        n -= 4;
        ans++;
    }
    while (n>=3)
    {
        n -= 3;
        ans++;
    }
    while (n>=2)
    {
        n -= 2;
        ans++;
    }
    if (n == 0)
    {
        cout << ans << nl;
    }
    else
    {
        cout << ans + 1 << nl;
    }

    return 0;
}