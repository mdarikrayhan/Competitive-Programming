#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[205][40005][2],h[205],q[205],m[205];
signed main(){
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
    	cin>>h[i];
		m[i]=min(h[i-1],h[i]);
    	q[i]=q[i-1]+h[i];
    }
    memset(dp,0x3f3f3f,sizeof dp);
    dp[0][0][0]=dp[0][0][1]=0;
    for(int i=1;i<=n;i++){
    	for(int j=0;j<=q[i];j++){
    		if(j>a) break;
    		if(q[i]-j>b) continue;
    		if(j>=h[i]) dp[i][j][0]=min(dp[i-1][j-h[i]][0],dp[i-1][j-h[i]][1]+m[i]);
    		dp[i][j][1]=min(dp[i-1][j][1],dp[i-1][j][0]+m[i]);
    	}
    }
    int ans=0x3f3f3f;
    for(int i=0;i<=a;i++) ans=min(ans,min(dp[n][i][0],dp[n][i][1]));
    if(ans==0x3f3f3f) cout<<-1;
    else cout<<ans;
	return 0;
}