#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    if (s.find("0000000")+1||s.find("1111111")+1)
        cout << "YES" << nl;
    else
        cout << "NO" << nl;
    return 0;
}