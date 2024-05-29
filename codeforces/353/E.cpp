#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
const ll INF=0x3f3f3f3f;
const ll MO9=998244353;
const ll MO1=1e9+7;
const ll MO=MO9;
const int N=1e6+5;
ll n,m;
string s;
ll dp[N];
ll pre[N];
void solve()
{
    string str;
    cin>>str;
    n=str.size();
    // cin>>s;
    int l=0;
    while(l<n&&str[l]==str.back())
    {
        str.push_back(str[l]);
        l++;
    }
    for(int i=l;i<str.size();i++)s.push_back(str[i]);
    int p=0;
    for(int i=0;i<s.size();i++)
    {
        pre[i+1]=p;
        if(i!=0&&s[i]!=s[i-1])p=i;
    }
    for(int i=2;i<=n;i++)
    {
        dp[i]=max(dp[i-1],dp[pre[i]]+1);
    }
    dp[n];
    cout<<dp[n]<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int ttt=1;
    // cin>>ttt;
    while(ttt--)
    solve();
    return 0;
}