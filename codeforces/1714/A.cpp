#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        int n, h, m, ini;
        cin >> n >> h >> m;
        ini = (h * 60 + m);
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int h1, m1, ini2;
            cin >> h1 >> m1;
            ini2 = (h1 * 60 + m1);
            if (ini2 > ini)
            {
                ans = min(ans, ini2 - ini);
            }
            if (ini2 == ini)
            {
                ans = 0;
            }
            else
            {
                ini2 = ini2 + (24 * 60);
                ans = min(ans, ini2 - ini);
            }
        }
        cout << ans / 60 << " " << ans % 60 << '\n';
    }
    return 0;
}