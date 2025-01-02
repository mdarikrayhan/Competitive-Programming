#include<iostream>
using namespace std;
int n,l[10],r[10],m=10005;
double ans,dp[15][10],f[10005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]);
	dp[0][0]=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			double p=1.0*max(0,r[j]-max(i,l[j])+1)/(r[j]-l[j]+1); 
			for(int k=1;k<=j;k++)
				dp[j][k]=dp[j-1][k-1]*p+dp[j-1][k]*(1-p);
			dp[j][0]=dp[j-1][0]*(1-p); 
		}
		for(int j=2;j<=n;j++)
			f[i]+=dp[n][j];
	}
	for(int i=1;i<=m;i++)
		ans+=(f[i]-f[i+1])*i;
	printf("%.12lf",ans);
}