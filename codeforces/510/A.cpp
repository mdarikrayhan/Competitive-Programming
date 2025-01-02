#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0, m = 0;
    cin >> n >> m;
    int count = m - 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < m; j++)
            {
                cout << '#';
            }
            cout << nl;
        }
        else
        {
            if (count == 0)
            {
                cout << '#';
                count = m - 1;
                for (int j = 0; j < m - 1; j++)
                {
                    cout << '.';
                }
            }

            else if (count == m - 1)
            {
                for (int j = 0; j < m - 1; j++)
                {
                    cout << '.';
                }
                cout << '#';
                count = 0;
            }
            cout << nl;
        }
    }

    return 0;
}