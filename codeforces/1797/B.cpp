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
    while (T--)
    {
        long long n, k;
        cin >> n >> k;
        long long arr[n + 5][n + 5];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        long long count = 0;
        for (int i = 0, p = n - 1; i < n / 2, p >= n / 2; i++, p--)
        {
            for (int j = 0, q = n - 1; j < n, q >= 0; j++, q--)
            {
                if (arr[i][j] != arr[p][q])
                {
                    count++;
                    arr[i][j] = arr[p][q];
                }
            }
        }
        if (count <= k)
        {
            long long check = k - count;
            if (check % 2 == 0)
            {
                cout << "YES" << nl;
            }
            else
            {
                if(n%2==0)
                {
                    cout << "NO" << nl;
                }
                else
                {
                    cout << "YES" << nl;
                }
            }
        }
        else
        {
            cout << "NO" << nl;
        }
    }
    return 0;
}