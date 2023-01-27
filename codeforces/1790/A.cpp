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
    string s1 = "314159265358979323846264338327";
     for (int i = 1; i <= T; i++)
    {
        string s;
        cin >> s;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == s1[i])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        cout << count << nl;
    }
    return 0;
}