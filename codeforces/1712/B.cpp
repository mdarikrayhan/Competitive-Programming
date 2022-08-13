#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        if (n % 2 == 0)
        {
            for (int i = 1; i <= n; i = i + 2)
            {
                cout << i + 1 << " " << i << " ";
            }
            cout << nl;
        }
        else
        {
            cout << 1 << " ";
            for (int i = 2; i <= n; i = i + 2)
            {
                cout << i + 1 << " " << i << " ";
            }
            cout << nl;
        }
    }
    return 0;
}