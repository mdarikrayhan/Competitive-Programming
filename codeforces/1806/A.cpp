#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        long long a, b, c, d, ans = 0;
        cin >> a >> b >> c >> d;
        if (a == c && b == d)
        {
            cout << 0 << nl;
            continue;
        }
        if (d < b)
        {
            cout << -1 << nl;
            continue;
        }
        while (b != d)
        {
            b++;
            a++;
            ans++;
        }
        if (a < c)
        {
            cout << -1 << nl;
            continue;
        }
        while (a != c)
        {
            a--;
            ans++;
        }
        cout << ans << nl;
    }
    return 0;
}