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
        int n,flag=0;
        cin >> n;
        string s;
        cin >> s;
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
                x--;
            else if (s[i] == 'R')
                x++;
            else if (s[i] == 'U')
                y++;
            else if (s[i] == 'D')
                y--;

            if(x==1 && y==1){
                cout<<"YES"<<nl;
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"NO"<<nl;
    }
    return 0;
}