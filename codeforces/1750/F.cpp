#include<bits/stdc++.h>
using namespace std;
const int N=5500;
int n,mod;
int dp[N][N],s[N*2];

int main(){
	cin>>n>>mod;
	dp[1][1]=1;
	s[2]=1;
	for(int i=2,t=1;i<=n;i++,t=t*2%mod){
		for(int j=1;2*j+1<=i;j++)
			dp[i][j]=(dp[i][j]+1ll*s[i-2*j-1]*dp[j][j]%mod)%mod;
		dp[i][i]=t;
		for(int j=1;j<i;j++) dp[i][i]=(dp[i][i]+mod-dp[i][j])%mod;
		
		for(int j=1;j<=i;j++) s[i+j]=(s[i+j]+dp[i][j])%mod;
		s[i+1]=(s[i+1]+s[i])%mod;
	}
	cout<<dp[n][n];
}////
	  	 	       	  	 		  	   					