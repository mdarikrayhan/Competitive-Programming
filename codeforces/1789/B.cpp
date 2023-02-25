#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
bool isreverse(string s)
{
    string temp = s;
    reverse(temp.begin(), temp.end());
    if (temp == s)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        string s;
        cin >> n >> s;
        int flag = 1, r = s.size() - 1,loop=0;
        while (loop < r)
        {
            if (flag == 0 && (s[loop] == s[r]))
            {
                break;
            }
            if (s[loop] != s[r])
            {
                if (s[r] == '1')
                    s[r] = '0';
                else
                    s[r] = '1';
                r--;
                loop++;
                flag = 0;
            }
            else if (s[loop] == s[r])
            {
                loop++, r--;
            }
        }

        if (isreverse(s))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}