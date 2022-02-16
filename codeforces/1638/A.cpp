#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve()
{
    int n,i, l = 0, r = 0;
    cin >> n;
    int arr[n+1];
    for ( i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for ( i = 1; i <= n; i++)
    {
        if (i == arr[i])
        {
            cout << i << " ";
        }
        else
        {
            r = i;
            break;
        }
    }
    if (r > 0)
    {
        for ( i = r + 1; i <= n; i++)
        {
            if (arr[i] == r)
            {
                l = i;
                break;
            }
        }
        for ( i = l; i >= r; i--)
        {
            cout << arr[i] << " ";
        }
        for ( i = l + 1; i <= n; i++)
        {
            cout << arr[i]<<" ";
        }
    }
    cout << nl;
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