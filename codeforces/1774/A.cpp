#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                v.push_back(1);
            }
            else
            {
                v.push_back(0);
            }
        }
        string ans;
        int flag = 0;
        if(v[0]==1){
            flag=1;
        }
        for(int i=1;i<n;i++)
        {
            if(v[i]==1 && flag ==0){
                ans.push_back('+');
                flag = 1;
            }
            else if(v[i]==1 && flag ==1){
                ans.push_back('-');
                flag = 0;
            }
            else{
                ans.push_back('+');
            }
        }
        cout<<ans<<nl;
    }
    return 0;
}