#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        ll n, k;
        cin >> n >> k;
        if (k == 0)
        {
            for (int i = 0; i < n / 2; i++)
            {
                cout << i << " " << n - 1 - i << nl;
            }
            continue;
        }
        if (k == 3 && n == 4)
        {
            cout << -1 << nl;
            continue;
        }
        else if (k == n - 1)
        {
            cout << 0 << " " << n - 3 - 1 << nl; // 0
            cout << 1 << " " << 3 << nl;         // 1
            cout << 2 << " " << n - 2 - 1 << nl; // 0
            for (int i = 4; i < n / 2; i++)
            {
                cout << i << " " << n - 1 - i << nl;
            }
            cout << k << " " << n - 2 << nl; // n-2
            continue;
        }

        cout << k << " " << n - 1 << nl;
        cout << 0 << " " << n - k - 1 << nl;
        for (int i = 1; i < n / 2; i++)
        {
            if (i != k && (n - 1 - i) != k)
            {
                cout << i << " " << n - 1 - i << nl;
            }
        }
    }
    return 0;
}