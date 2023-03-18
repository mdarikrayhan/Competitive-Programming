#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        int n;
        cin >> n;
        string s;
        cin >> s;
        int a = 0, d = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A')
            {
                a++;
            }
            else
            {
                d++;
            }
        }
        if (a > d)
        {
            cout << "Anton" << nl;
        }
        else if (d > a)
        {
            cout << "Danik" << nl;
        }
        else
        {
            cout << "Friendship" << nl;
        }
    
    return 0;
}