#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve()
{
    int n, r = 0;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
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
        for (int i = r + 1; i <= n; i++)
        {
            if (arr[i] == r)
            {
                int l = i;
                for (int i = l; i >= r; i--)
                {
                    cout << arr[i] << " ";
                }
                for (int i = l + 1; i <= n; i++)
                {
                    cout << arr[i] << " ";
                }
                break;
            }
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