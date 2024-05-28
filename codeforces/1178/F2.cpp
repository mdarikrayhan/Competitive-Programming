// LUOGU_RID: 159582788
#include<bits/stdc++.h>
#define int int64_t
using namespace std;
const int mod=998244353;
int n,ccf,m,a[1000005],l[505],r[505],dp[1005][1005];
int32_t main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cin>>n>>ccf,dp[1][0]=1;
	while(ccf--){
		cin>>a[m+1];
		if(a[m+1]!=a[m])
			m++;
	} 
	if(m>(n<<1)){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=m;i++){
		if(!l[a[i]])
			l[a[i]]=i;
		r[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		dp[i+1][i]=1; 
		if(l[a[i]]==i&&r[a[i]]==i)
			dp[i][i]=1;
	}
	for(int i=m;i>=1;i--)
		for(int j=i+1,p,ls,rs,x,y;j<=m;j++){
			ls=rs=0,p=*min_element(a+i,a+j+1),x=l[p],y=r[p];
			if(i<=x&&y<=j){
				for(int k=i;k<=x;k++)
					ls=(ls+dp[i][k-1]*dp[k][x-1])%mod;
				for(int k=y;k<=j;k++)
					rs=(rs+dp[y+1][k]*dp[k+1][j])%mod;
				dp[i][j]=ls*rs%mod;
				for(int k=i,lst=0;k<=j;k++)
					if(a[k]==p){
						if(lst)
							dp[i][j]=dp[i][j]*dp[lst+1][k-1]%mod;
						lst=k;
					}
			}
		}
	cout<<dp[1][m];
	return 0;
}