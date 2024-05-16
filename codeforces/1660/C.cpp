#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>AII;
typedef pair<int,int>PII;
typedef pair<int,string>kkk;
void Greed()
{
    string s;
    cin>>s;
    int n=s.size();
    s="#"+s;
    map<int,int>mp;
    vector<int>dp(n+1);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        int op=s[i]-'a';
        if(mp[op])
        {
            dp[i]=max(dp[i],dp[mp[op]-1]+2);
        }
        mp[op]=i;
    }
    cout<<n-dp[n]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++)
    Greed();
    return 0;
}