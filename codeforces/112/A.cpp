#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    if (s1 == s2)
    {
        cout << "0" << nl;
    }
    else if (s1 < s2)
    {
        cout << "-1" << nl;
    }
    else
    {
        cout << "1" << nl;
    }
    return 0;
}