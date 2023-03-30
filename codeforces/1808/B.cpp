#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, temp = 0;
        cin >> n >> m;
        vector<long long> arr[300015];
        long long ans[300015];
        for (int j = 0; j < n; j++)
        {
            ans[j] = 0;
            for (int k = 0; k < m; k++)
            {
                if (j == 0)
                {
                    arr[k].clear();
                }
                long long a;
                cin >> a;
                arr[k].push_back(a);
            }
        }
        for (long long q = 0; q < m; q++)
        {
            sort(arr[q].begin(), arr[q].end());
        }
        for (long long e = 0; e < m; e++)
        {
            for (long long f = 0; f < n; f++)
            {
                ans[f] += arr[e][f];
            }
        }
        for (long long k = 0; k < n; k++)
        {
            temp += ans[k] * (n - 1 - 2 * (n - 1 - k));
        }
        cout << temp << nl;
    }
    return 0;
}