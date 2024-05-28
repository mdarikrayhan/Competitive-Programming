// LUOGU_RID: 159992101
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,p,k,a[200005],dp[200005][55],sum[200005];
signed main() 
{
    cin>>n>>k>>p;
    for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
    	dp[i][1]=sum[i]%p;
    	for(int j=2;j<=min(i,k);j++)
    	{
    		for(int x=i-1;x>=1;x--)
    		{
    			if(dp[x][j-1]+p-1<=dp[i][j]&&dp[x][j-1]!=0) break;
    			dp[i][j]=max(dp[i][j],dp[x][j-1]+(sum[i]-sum[x])%p);
			}
		}
	}
	cout<<dp[n][k];
    return 0;
}