#include <bits/stdc++.h>
#define int long long
#define el '\n'
using namespace std;
const int N=505;
int n,k,dp[N][N*11],value[N];
int solve(int i,int reminder)
{
    if(i==0|| reminder==0) return 0;
    int &ret=dp[i][reminder];
    if(~ret) return ret;
    ret=solve(i-1,reminder);
    for(int j=1;j<=min(k,reminder);j++)
    {
        ret=max(ret,solve(i-1,reminder-j)+value[j]);
    }
    return ret;
}
void LastScenario()
{
    cin>>n>>k;
    map<int,int>ma,fav;
    for(int i=1;i<=n*k;i++)
    {
        int a;cin>>a;
        ma[a]++;
    }
    for(int i=1;i<=n;i++)
    {
        int a;cin>>a;
        fav[a]++;
    }
    for(int i=1;i<=k;i++)
    {
        int a;cin>>a;
        value[i]=a;
    }
    int ans=0;
    for(auto [a,b] : fav)
    {
        ans+=solve(b,ma[a]);
    }
    cout<<ans<<el;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\AIA\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\AIA\\CLionProjects\\untitled\\output.txt", "w", stdout);
#endif
    int t=1;//cin>>t;
    for(int i=1;i<=t;i++)
    {
        memset(dp,-1,sizeof dp);
        //  cout<<"Scenario #"<<i<<":"<<el;
        LastScenario();
    }
    return 0;
}
  	   	 			  	    		  		   		 	