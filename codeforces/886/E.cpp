// LUOGU_RID: 159487556
#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
int n,k,dp[1000001]={1},inv[1000001],fac[1000001]={1},sum[2000001]={1},ans;
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int qpow(int a,int b){
    int res=1;
	while(b){
	    if(b&1) res=(res*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return res;
}
int C(int n,int m){
	return ((fac[n]*inv[m]%MOD)*inv[n-m])%MOD;
}
signed main(){
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++){
		fac[i]=(fac[i-1]*i)%MOD;
	}
	inv[n]=qpow(fac[n],MOD-2);
	for (int i=n-1;i>=0;i--) 
	{
		inv[i]=inv[i+1]*(i+1)%MOD;
	}
	for(int i=1;i<=n;i++)
	{
        if(i-k-1>=0)
		    dp[i]=fac[i-1]*(sum[i-1]+MOD-sum[i-k-1])%MOD;
        else   
            dp[i]=fac[i-1]*(sum[i-1]+MOD)%MOD;
        sum[i]=(sum[i-1]+dp[i]*inv[i])%MOD;
	}
	for(int i=1;i<=n;i++)
	{
		ans=(ans+((dp[i-1]*C(n-1,i-1))%MOD*fac[n-i])%MOD)%MOD;
	}
	printf("%lld\n",(fac[n]+MOD-ans)%MOD);
    return 0;
}