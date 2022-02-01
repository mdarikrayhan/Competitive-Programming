#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ocount = 0, zcount = 0;
        string s;
        cin >> s;
        int l = s.length();
        for (int i = 0; i < l; i++)
        {
            if (s[i] == '0')
            {
                ocount++;
            }
            else
            {
                zcount++;
            }
        }
        if (ocount == zcount)
        {
            cout << ocount-1 << endl;
        }
        else if (ocount < zcount)
            cout << ocount << endl;
        else if (zcount < ocount)
            cout << zcount << endl;
    }
}
