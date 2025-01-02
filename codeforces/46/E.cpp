#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1505][1505],dp[1505][1505];
signed main()
{
	ios_base::sync_with_stdio(false);
	memset(dp,-0x3f,sizeof(dp)); //一定要记得！！！会有负数情况！！！
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=m;i++) dp[0][i]=0;
	for(int i=1;i<=n;i++)
	{
		if(i&1)
		{
			int sum=0; //前缀和
			for(int j=1;j<=m;j++)
			{
				sum+=a[i][j];
				dp[i][j]=max(dp[i][j-1]-sum+a[i][j]/*因为这里每次转移之后加上了 sum 所以还原的时候要减掉 sum*/,dp[i-1][j-1])+sum; //转移
			}
		}
		else
		{
			int sum=0;
			for(int j=1;j<=m;j++) sum+=a[i][j]; //由于是倒序需要先预处理
			for(int j=m;j>=1;j--)
			{
				dp[i][j]=max(dp[i][j+1]-sum-a[i][j+1],dp[i-1][j+1])+sum;
				sum-=a[i][j]; //每次减掉已经用完的
			}
		}
	}
	int ans=-1e9; //一定要记得！！！会有负数情况！！！
	for(int i=1;i<=m;i++)
		ans=max(ans,dp[n][i]); //最后对答案取 max
	cout<<ans; //实而不华的输出！
	return 0;
}