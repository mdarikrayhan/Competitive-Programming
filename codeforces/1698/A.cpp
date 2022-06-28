#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve()
{
    int n, xo = -1;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                if (xo == -1)
                {
                    xo = arr[j];
                }
                else
                {
                    xo = (xo ^ arr[j]);
                }
            }
        }
        if (xo == arr[i])
        {
            break;
        }
    }
    cout << xo << nl;
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