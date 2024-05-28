// LUOGU_RID: 159805532
#include<bits/stdc++.h>
#define db double
using namespace std;
const int Max=1e5+5,nmax=800+5;
db dp[5][nmax];
int n,k;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		for(int j=nmax-5;j>=1;j--)
		{
			dp[1][j]=dp[2][j];
			dp[2][j]=dp[1][j]*(k*(j+1)-1)+dp[1][j+1]+(db)j*(j+3)/2;
			dp[2][j]/=k*(j+1);
		}
	}
	printf("%.9lf",dp[2][1]*k);
}