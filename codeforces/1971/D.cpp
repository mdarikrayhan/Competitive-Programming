#include<bits/stdc++.h>

using namespace std;

void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fast();
    int t;
    cin>>t;

    while(t--)
    {
        string str;
        cin>>str;
        int shift = 0,cnt=0;
        vector<char>ans;
        ans.push_back(str[0]);
        for(int i = 1 ; i < str.size(); i++)
        {
            if(str[i]==ans[ans.size()-1])
            {
                continue;
            }
            ans.push_back(str[i]);
        }
        if(ans.size() == 1)
            cout<<1<<endl;
        else if(ans.size() == 2 && ans[0] == '1')
             cout<<2<<endl;
        else
            cout<<ans.size()-1<<endl;
    }

}
