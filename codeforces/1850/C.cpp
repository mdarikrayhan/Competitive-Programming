#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    char a[8][8];
    for (int _ = 0; _ < t; _++)
    {
        string s = "";
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (a[i][j] >= 'a' && a[i][j] <= 'z')
                {
                    s += a[i][j];
                }
            }
        }
        cout << s << '\n';
    }
    return 0;
}
