// LUOGU_RID: 158539739
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[405][405];
const ll mod=1000000007;

int main(){
	ll n;
	cin >> n;
	dp[1][0]=dp[1][1]=1;
	for (ll i=2;i<=n;i++){
		for (ll j=0;j<=n;j++){
			for (ll k=0;k<j;k++){
				dp[i][j]+=dp[i-1][k]*dp[i-1][j-1-k]%mod;
				dp[i][j]%=mod;
			}
			for (ll k=0;k<=j;k++){
				dp[i][j]+=dp[i-1][k]*dp[i-1][j-k]%mod;
				dp[i][j]%=mod;
				dp[i][j]+=dp[i-1][k]*dp[i-1][j-k]%mod*k%mod*2%mod;
				dp[i][j]%=mod;
				dp[i][j]+=dp[i-1][k]*dp[i-1][j-k]%mod*(j-k)%mod*2%mod;
				dp[i][j]%=mod;
			}
			for (ll k=0;k<=j+1;k++){
				dp[i][j]+=dp[i-1][k]*dp[i-1][j+1-k]%mod*k%mod*(j+1-k)%mod*2%mod;
				dp[i][j]%=mod;
				dp[i][j]+=dp[i-1][k]*dp[i-1][j+1-k]%mod*k%mod*(k-1)%mod;
				dp[i][j]%=mod;
				dp[i][j]+=dp[i-1][k]*dp[i-1][j+1-k]%mod*(j-k)%mod*(j+1-k)%mod;
				dp[i][j]%=mod;
				
			}
//			cout<<i<<","<<j<<":"<< dp[i][j]<< endl;
		}
	} 
	cout<< dp[n][1];
    return 0;
}
/* 
1 2
1 3
2 3
1,2 3
1,3 2
2,1 3
3,1 2 
　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　
　■■■■■　　　　　■■　　　　　　■■■　　　　　■■■　　　■　　　　■　　　　　■　　　　　■■■■　　　　■■■■　　
　■　　　■■　　　　■■　　　　　■　　■■　　　■　　■■　　■　　　　■　　　　■■　　　　　■　　■■　　■■　　■　　
　■　　　　■　　　　■■　　　　■　　　　■　　■　　　　■　　　■　　■　　　　■■■　　　　■■　　■■　　■　　　■■　
　■　　　　■　　　　■■　　　　■　　　　■　　■　　　　■　　　■　　■　　　　　■■　　　　■　　　■■　　　　　　■■　
　■　　　　■　　　　■■　　　　■　　　　　　　■　　　　　　　　　■■　　　　　　■■　　　　　　　　■■　　　　　　■　　
　■　　　■■　　　　■■　　　　■　　■■■　　■　　■■■　　　　■■　　　　　　■■　　　　　　　■■　　　　　■■■　　
　■■■■■　　　　　■■　　　　■　　　　■　　■　　　　■　　　　■■　　　　　　■■　　　　　　■■　　　　　　　　■■　
　■　　　　　　　　　■■　　　　■　　　　■　　■　　　　■　　　　■■　　　　　　■■　　　　　■■　　　　　　　　　　■　
　■　　　　　　　　　■■　　　　■　　　　■　　■　　　　■　　　　■■　　　　　　■■　　　　　■　　　　　　■　　　■■　
　■　　　　　　　　　■■　　　　■■　　■■　　■■　　■■　　　　■■　　　　　　■■　　　　■　　　　　　　■■　　■■　
　■　　　　　　　　　■■　　　　　　■■■■　　　　■■■■　　　　■■　　　　　　■■　　　　■■■■■■　　　■■■■　　
*/
