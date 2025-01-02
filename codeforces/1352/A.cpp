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
        int n;
        cin >> n;
        vector<int> ans;
        if(n%10!=0)
        {
            ans.push_back(n%10);
            n-=n%10;
        }
        if(n%100!=0)
        {
            ans.push_back(n%100);
            n-=n%100;
        }
        if(n%1000!=0)
        {
            ans.push_back(n%1000);
            n-=n%1000;
        }
        if(n%10000!=0)
        {
            ans.push_back(n%10000);
            n-=n%10000;
        }
        if(n!=0)
        {
            ans.push_back(n);
        }
        cout<<ans.size()<<nl;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<nl;
    }
    return 0;
}