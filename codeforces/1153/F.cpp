#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
typedef long long ll;
const int mod=998244353;
const int maxn=4e3+10;
ll quick(ll a,ll b){
	a%=mod;
	ll res=1;
	while(b){
		if(b&1){
			res=res*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll dp[maxn][maxn][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k,l;
	cin>>n>>k>>l;
	ll res=1,fac=1,fact=1;
	for(int i=1;i<=n;i++){
		res=res*2%mod;
		fac=fac*i%mod;
	}
	for(int i=1;i<=2*n+1;i++){
		fact=fact*i%mod;
	}
	dp[0][0][0]=1;
	for(int i=1;i<=2*n+1;i++){
		for(int j=0;j<=i;j++){
			dp[i][j][0]=dp[i-1][j-1][0];
			dp[i][j][1]=dp[i-1][j-1][1];
			if(j>=k){
				dp[i][j][1]=(dp[i][j][1]+dp[i-1][j][0])%mod;
			}
			if(j>0){
				dp[i][j-1][0]=(dp[i][j-1][0]+dp[i-1][j][0]*j%mod)%mod;
				dp[i][j-1][1]=(dp[i][j-1][1]+dp[i-1][j][1]*j%mod)%mod;
			}
		}
	}
	cout<<dp[2*n+1][0][1]*res%mod*fac%mod*quick(fact,mod-2)%mod*l%mod<<'\n';
	return 0;
}