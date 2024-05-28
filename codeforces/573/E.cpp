// LUOGU_RID: 160436132
#include<bits/stdc++.h>
using namespace std;
long long i,j,n,x,Max,dp[100010];
signed main(){
    scanf("%lld",&n);
    for (i=1;i<=n;i++) dp[i]=-1e18;
    for (i=1;i<=n;i++){
    	scanf("%lld",&x);
    	for (j=i;j>0;j--) dp[j]=max(dp[j],dp[j-1]+j*x); 
    	}
    for (i=1;i<=n;i++) Max=max(Max,dp[i]);
    printf("%lld\n",Max);
	return 0;
}