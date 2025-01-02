// LUOGU_RID: 159184143
#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 3e5 + 10,maxm = 5e3 + 10; 
long long a[maxn],dp[maxm][maxm];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	const int len1 = n % k,len2 = k - len1,numx = n / k + 1,numy = n / k;
	memset(dp,0x3f,sizeof(dp));
	for(int i = 0;i <= len1;i++)
		for(int j = 0;j <= len2;j++)
			if(!(i || j))dp[i][j]=0;
			else{
				if(i)dp[i][j] = min(dp[i][j],dp[i-1][j] + a[i*numx+j*numy] - a[i*numx-numx+j*numy+1]);
				if(j)dp[i][j] = min(dp[i][j],dp[i][j-1] + a[i*numx+j*numy] - a[j*numy-numy+i*numx+1]);
			}
		
	printf("%lld",dp[len1][len2]);
}