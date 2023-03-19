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
        long long n;
        cin >> n;
        long long sum = 0, odd = 0;
        for (int i = 0; i < n; i++)
        {

            long long x;
            cin >> x;
            if (x % 2 == 0)
            {
                sum += x;
            }
            else
                odd += x;
        }
        if (sum > odd)
        {
            cout << "YES" << nl;
        }
        else
        {
            cout << "NO" << nl;
        }
    }
    return 0;
}