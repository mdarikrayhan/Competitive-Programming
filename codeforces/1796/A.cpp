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
        int n;
        cin >> n;
        int C = 0;
        string s;
        cin >> s;
        string target = "FBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFB";
        for (int i = 0; i < 150 - n + 1; i++)
        {
            int flag = 0;
            for (int j = 0; j < n; j++)
            {
                if (s[j] != target[i + j])
                {
                    flag = 1;
                }
            }

            if (flag == 0)
            {
                C++;
            }
        }
        if (C == 0)
        {
            cout << "NO" << nl;
        }
        else
        {
            cout << "YES" << nl;
        }
    }

    return 0;
}