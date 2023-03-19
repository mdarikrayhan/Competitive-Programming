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
        long long n, sum = 1;
        cin >> n;
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        if (arr[0] != 1)
        {
            cout << "NO" << nl;
        }
        else
        {
            int flag = 1;
            for (long long i = 1; i < n; i++)
            {
                if (arr[i] <= sum)
                {
                    sum += arr[i];
                }
                else
                {
                    cout << "NO" << nl;
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                cout << "YES" << nl;
            }
        }
    }
    return 0;
}