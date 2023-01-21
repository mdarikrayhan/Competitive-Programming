#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    int t;
    cin >> t;
    getchar();
    for (int i = 1; i <= t; i++)
    {

        getline(cin, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] >= 'a' && s[j] <= 'z')
            {
                s[j] = s[j] - 32;
            }
        }
        cout << "Case " << i << ": " << s << nl;
    }

    return 0;
}