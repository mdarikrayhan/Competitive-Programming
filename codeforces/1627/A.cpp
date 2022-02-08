#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        char tmp;
        int ans = -1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> tmp;
                if (tmp == 'B')
                {
                    if ((i == x || j == y) && ans != 0)
                        ans = 1;
                    if (i == x && j == y)
                        ans = 0;
                    if (ans == -1)
                        ans = 2;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}