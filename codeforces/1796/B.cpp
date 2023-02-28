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
    for (int x = 1; x <= T; x++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 == s2)
        {
            cout << "YES" << nl;
            cout << s1 << nl;
        }
        else if (s1[0] == s2[0])
        {
            cout << "YES" << nl;
            cout << s2[0] << "*" << nl;
        }
        else if (s1[s1.size() - 1] == s2[s2.size() - 1])
        {
            cout << "YES" << nl;
            cout << "*" << s1[s1.size() - 1] << nl;
        }
        else
        {
            int ok = 0;
            for (int i = 0; i < s1.size() - 1; i++)
            {
                string sb = s1.substr(i, 2);
                for (int j = 0; j < s2.size() - 1; j++)
                {
                    string k = s2.substr(j, 2);
                    if (sb == k)
                    {
                        ok = 1;
                        cout << "YES" << nl;
                        cout << "*" << sb << "*" << nl;
                        break;
                    }
                }
                if (ok == 1)
                {
                    break;
                }
            }
            if (ok == 0)
            {
                cout << "NO" << nl;
            }
        }
    }
    return 0;
}