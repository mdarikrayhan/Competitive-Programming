#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a,b;
const int maxn=1010;
const int mod=1e9+7;
int dp[maxn][maxn];
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1){
			res=res*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
signed main(){
	scanf("%lld%lld%lld",&n,&a,&b);
	for(int i=n;i>=1;i--){
		for(int j=n;j>=0;j--){
			if(i+j>=n){
				dp[i][j]=(i+j+a*qpow(b,mod-2)%mod)%mod;
			}
			else{
				dp[i][j]=(a*qpow(a+b,mod-2)%mod*dp[i+1][j]%mod+b*qpow(a+b,mod-2)%mod*dp[i][i+j]%mod)%mod;
			}
		}
	}
	printf("%lld\n",dp[1][0]);
	return 0;
}