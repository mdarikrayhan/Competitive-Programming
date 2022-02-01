#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                a++;
            else
                b++;
        }
        if (a != b)
            cout << min(a, b);
        else
            cout << a - 1;
        cout << endl;
    }
}
