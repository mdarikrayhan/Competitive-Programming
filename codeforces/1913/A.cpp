#include <iostream>
#include <string>
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
        int i = 0;
        string s, a, b;
        cin >> s;
        a = s[0];
        for (i = 1; i < s.length(); i++)
        {
            if (s[i] == '0')
            {
                a += '0';
            }
            else
            {
                break;
            }
        }
        while(i<s.length())
        {
            b += s[i];
            i++;
        }
        ll x = 0, y = 0;
        if (a.length() != 0)
        {
            x = stoll(a);
        }
        if (b.length() != 0)
        {
            y = stoll(b);
        }
        if (y > x)
        {
            cout << x << " " << y << nl;
        }
        else
        {
            cout << -1 << nl;
        }
    }
    return 0;
}