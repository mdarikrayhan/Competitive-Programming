#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        char ch = s[0];
        int x = 1;
        int y = 1;
        for (int i=0;i<s.size();i++)
        {
            y++;
            if (ch == s[i])
            {
                cout << x << " ";
            }
            else
            {
                x = y - 1;
                ch = s[i];
                cout << x << " ";
            }
        }
        cout << nl;
    }
    return 0;
}