#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, sx, sy, d, ans;
        cin >> n >> m >> sx >> sy >> d;
        int flag1 = 0, flag2 = 0;

        if ((sy > d + 1) && (n - sx > d))
        {
            flag1 = 1;
        }
        if ((sx > d + 1) && (m - sy) > d)
        {
            flag2 = 1;
        }

        if (flag1 || flag2)
        {
            ans = abs(1 - n) + abs(1 - m);
            cout << ans << nl;
        }
        else
        {
            cout << "-1" << nl;
        }
    }
    return 0;
}