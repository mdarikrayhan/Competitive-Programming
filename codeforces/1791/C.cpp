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
    for (int i = 1; i <= T; i++)
    {
        int n, flag = 0;
        cin >> n;
        string s;
        cin >> s;
        while(s.size()>1){
            int n=s.size();
            if(s[n-1]!=s[0]){
                //remove the last character
                s.pop_back();
                //remove the first character
                s.erase(s.begin());
            }
            else
                break;
        }
        cout<<s.size()<<nl;
    }
    return 0;
}