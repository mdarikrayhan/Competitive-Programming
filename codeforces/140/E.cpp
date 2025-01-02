// LUOGU_RID: 160511437
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
const int N=1e6+10;
int mod;
int c[5005],fac[5005];
int dp[5005][5005];
int f[5005],g[5005];
int l[N];
int n,m;
signed main(){
	cin>>n>>m>>mod;
	l[0]=0;
	for(int i=1;i<=n;i++) cin>>l[i];
	c[0]=fac[0]=1;
	for(int i=1;i<=min(5000ll,m);i++)
		c[i]=c[i-1]*(m-i+1)%mod,fac[i]=fac[i-1]*i%mod;
	dp[0][0]=1;
	for(int i=1;i<=5000;i++)
		for(int j=0;j<=5000;j++){
			if(j>1) dp[i][j]=(dp[i][j]+dp[i-1][j]*(j-1)%mod)%mod;
			dp[i][j+1]=(dp[i][j+1]+dp[i-1][j])%mod;
		}
	f[0]=1;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=0;j<=l[i-1];j++)
			sum=(sum+f[j])%mod;
		for(int j=0;j<=l[i];j++){
			g[j]=sum*c[j]%mod*dp[l[i]][j]%mod;
			if(j<=l[i-1]) g[j]=(g[j]+mod-f[j]*fac[j]%mod*dp[l[i]][j]%mod)%mod;
		}
		for(int j=0;j<=l[i];j++)
			f[j]=g[j];
	}
	int ans=0;
	for(int i=0;i<=l[n];i++) ans=(ans+f[i])%mod;
	cout<<ans;
	return 0;
}
