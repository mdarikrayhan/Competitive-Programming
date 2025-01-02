// Hydro submission #6652de16e9f28a763361551c@1716731106943
//没想出来分类计数 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int maxn=1e5+10;
int n,k;
int f[maxn],dp[maxn],a[maxn],s[maxn];
//dp[i][j]表示前i种幸运数选j个的方案
//dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*s[i] 
//内存会炸，需要用01背包滚一维 
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=ans*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(){
	f[0]=1;
	for(int i=1;i<maxn;i++){
		f[i]=f[i-1]*i%mod;
	}
}
int C(int n,int m){
	if(m>n)
		return 0;
	return f[n]*qpow(f[m]*f[n-m]%mod,mod-2)%mod;
}
int check(long long x)
{
	while(x)
	{
		if(x%10!=4&&x%10!=7) return 0;
		x/=10;
	}
	return 1;
}
map<int,int> mp;
int cnt,t,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	init();
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(check(a[i])){
			if(!mp[a[i]])
				mp[a[i]]=++cnt;//第几类神仙数
			s[mp[a[i]]]++; 
		}
		else t++;
	}
	dp[0]=1;
	for(int i=1;i<=cnt;i++){
		for(int j=cnt;j>=1;j--){
			dp[j]=dp[j]+dp[j-1]*s[i]%mod;
			dp[j]%=mod;
		}
	}
	for(int i=0;i<=k;i++){
		ans=ans+dp[i]*C(t,k-i)%mod;
		ans%=mod;
	}
	cout<<ans<<endl; 
}