// LUOGU_RID: 157897849
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 82, inf = 1e9, mod = 1e9 + 7;
int u,v,w;
int rd[N][N],dp[N][N][N][N];
int n,m,k;
//起点为·cur，区间【l，r】，包含k各点
int DP(int cur,int l,int r,int k) {
	if(dp[cur][l][r][k]!=-1) return dp[cur][l][r][k];
	if(k==1) return 0;
	int res=inf;
	for(int i=l+1;i<r;i++) {
		//if(k==2) cout<<cur<<" "<<l<<" "<<r<<" "<<i<<endl;
		if(rd[cur][i]!=inf) {
			
			int nl=l,nr=r;
			if(i>cur) nl=cur;
			else nr=cur;
			res=min(res,rd[cur][i]+DP(i,nl,nr,k-1));
		}
	}
	dp[cur][l][r][k]=res;
	return res;
}
int main()
{
	ios::sync_with_stdio(false);	
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) rd[i][j]=inf;
	cin>>m;
	for(int i=1;i<=m;i++) {
		cin>>u>>v>>w;
		rd[u][v]=min(rd[u][v],w);
	}
	memset(dp,-1,sizeof dp);
	int ans=inf;
	for(int i=1;i<=n;i++)
    	ans=min(ans,DP(i,0,n+1,k));
    if(ans==inf) cout<<-1;
    else cout<<ans;
    return 0;
}
