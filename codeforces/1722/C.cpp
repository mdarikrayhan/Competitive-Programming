
#include<bits/stdc++.h>
using namespace std;
void solve()
{

    int n;
    cin>>n;
    vector<string>s[3];
    map<string,int>mp;

    for(int i   =0; i<3; i++)
    {
        s[i].resize(n);
        for(int j=0; j<n; j++)
        {
            cin>>s[i][j];
            mp[s[i][j]]++;
        }
    }
    int a[3]= {0};
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(mp[s[i][j]]==2)
            {
                a[i]+=1;
            }
            else if(mp[s[i][j]]==1)
            {
                a[i]+=3;
            }
        }
    }
    cout<<a[0]<<' '<<a[1]<<' '<<a[2];
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
