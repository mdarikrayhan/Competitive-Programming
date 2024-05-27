// LUOGU_RID: 160339592
#include<bits/stdc++.h>
#define int long long
using namespace std;
int q,len,d[70],b,dp[15][70][1050],l,r;
int dfs(int num,int k,int zer,int lim){
	if(!num){
		return (k==0);
	}
	if(!zer&&!lim&&dp[b][num][k]!=-1){
		return dp[b][num][k];
	}
	int up=(!lim)?(b-1):d[num];
	int ans=0;
	for(int i=0;i<=up;i++){
		ans+=dfs(num-1,(zer&&(i==0))?0:(k^(1<<i)),zer&&(i==0),lim&&(i==up));
	}
	if(!zer&&!lim){
		dp[b][num][k]=ans;
	}
	return ans;
}
int sol(int n){
	len=0;
	while(n){
		d[++len]=n%b;
		n/=b;
	}
	return dfs(len,0,1,1);
}
signed main(){
	memset(dp,-1,sizeof(dp));
	scanf("%lld",&q);
	while(q--){
		scanf("%lld%lld%lld",&b,&l,&r);
		printf("%lld\n",sol(r)-sol(l-1));	
	}
	return 0;
}