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
        unordered_map<char, int> mp;
        for (int i = 0; i < 9; i++)
        {
            char c;
            cin >> c;
            mp[c]++;
        }
        for(auto it:mp){
            if(it.second==2){
                cout<<it.first<<nl;
                break;
            }
        }
    }
    return 0;
}