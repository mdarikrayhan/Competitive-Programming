#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.length();
    int lcase = 0,ucase=0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            lcase++;
        }
        else
        {
            ucase++;
        }
    }
    if(ucase>lcase){
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        cout<<s<<nl;
    }
    else{
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout<<s<<nl;
    }
    return 0;
}