/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    int C = 0;
    string::size_type pos = 0;
    string s;
    cin >> s;
    string target = "acmicpc";
    while ((pos = s.find(target, pos)) != string::npos)
    {
        ++C;
        pos += target.length();
    }
    cout << C << nl;
    return 0;
}