// LUOGU_RID: 160014052
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define int long long
using namespace std;
int p[200001],dp[200001];
const int mod=998244353;
int qmi(int a,int b,int mod){
	int res=1;
	while(b){
		if(b&1)res=(res*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return res;
}
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=(dp[i-1]+1)*100%mod*qmi(p[i],mod-2,mod)%mod;
	}
	cout<<dp[n]<<endl; 
}