/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{

    string s;
    cin >> s;
    int n = s.size();
    char first = s[0];
    char last = s[n - 1];
    string middle = s.substr(1, n - 2);
    int num = 0;
    try
    {
        num = stoi(middle);
    }
    catch (const std::exception &e)
    {
        cout << "No" << nl;
        return 0;
    }
    if (n != 8)
    {
        cout << "No" << nl;
        return 0;
    }
    if (isupper(first) && isupper(last) && num >= 100000 && num <= 999999)
    {
        cout << "Yes" << nl;
    }
    else
    {
        cout << "No" << nl;
    }
    return 0;
}