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

        long long n;
        cin >> n;
        string s;
        cin >> s;
        map<char, int> mp;
        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp[s[i]] == 0)
            {
                mp[s[i]] = i + 1;
            }
            else
            {
                int d = mp[s[i]];
                if (d % 2 == 0 && (i + 1) % 2 != 0)
                {
                    flag = 1;
                    break;
                }
                else if (d % 2 != 0 && (i + 1) % 2 == 0)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0)
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