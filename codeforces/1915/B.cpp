#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        map<char, int> mp;
        for(int i=0;i<3;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<3;j++)
            {
                mp[s[j]]++;
            }
        }
        for(auto i:mp)
        {
            if(i.second==2)
            {
                cout<<i.first<<nl;
            }
        }
    }
    return 0;
}