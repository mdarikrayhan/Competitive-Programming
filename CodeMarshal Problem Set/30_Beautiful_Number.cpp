#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
long long int m, n;
long long int ans = 0;
int fi(long long int a[], long long int bi, int x, int y)
{
    if (bi > n)
        return 0;
    if (x == m)
    {
        return 0;
    }
    fi(a, bi, x + 1, y);
    bi *= a[x];
    y++;
    if (y % 2)
    {
        ans += (n / bi);
    }
    else
    {
        ans -= (n / bi);
    }
    fi(a, bi, x + 1, y);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> m;
        long long int a[m];
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        cin >> n;
        ans = 0;
        fi(a, 1, 0, 0);
        cout << ans << endl;
    }
    return 0;
}