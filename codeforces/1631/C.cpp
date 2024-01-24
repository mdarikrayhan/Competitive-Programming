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
        n--;
        if (k == 0)
        {
            for (int i = 0; i < (n + 1) / 2; i++)
            {
                cout << i << " " << n - i << nl;
            }
            continue;
        }
        if (k == 3 && n == 3)
        {
            cout << -1 << nl;
            continue;
        }
        else if (k == n)
        {
            cout << 0 << " " << n - 3 << nl; // 0
            cout << 1 << " " << 3 << nl;     // 1
            cout << 2 << " " << n - 2 << nl; // 0
            for (int i = 4; i < (n + 1) / 2; i++)
            {
                cout << i << " " << n - i << nl;
            }
            cout << n - 1 << " " << n << nl; // n-1
            continue;
        }

        cout << 0 << " " << n - k << nl;
        for (int i = 1; i < (n + 1) / 2; i++)
        {
            if (i != k && (n - i) != k)
            {
                cout << i << " " << n - i << nl;
            }
        }
        cout << k << " " << n << nl;
    }
    return 0;
}