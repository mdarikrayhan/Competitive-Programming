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
    for (int tt = 1; tt <= T; tt++)
    {
        long long number,ans=0;
        cin >> number;
        vector<long long> arr(number, 0);
        map<long long, long long> record;
        for (long long i = 0; i < number; i++)
        {
            cin >> arr[i];
            record[arr[i]]++;
        }
        if (record[0] == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            if (record[0] == number)
            {
                cout << 1 << endl;
                continue;
            }
            int noofzero = number - record[0] + 1;
            bool flag = 0;
            for (long long i = 0; i < number; i++)
            {
                if (arr[i] > 0 && arr[i] != 1)
                {
                    flag = 1;
                }
            }
            if (record[0] > noofzero)
            {
                if (flag)
                {
                    ans=1;
                }
                else
                {
                    ans=2;
                }
            }
            else
            {
                ans=0;
            }
            cout << ans << nl;
        }
    }
    return 0;
}