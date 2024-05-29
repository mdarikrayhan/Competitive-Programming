// LUOGU_RID: 160596909
#include<bits/stdc++.h>
using namespace std;
#define int long long
using ld=long double;
const int N=1e4+5;
const ld eps=1e-15;
int n,s,a[N];
ld c,p[2][N],g[2][N],dp[2][N];
signed main(){
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>n>>s;
	c=(ld)s/1000000;
	for(int i=0;i<=n;i++)cin>>a[i];
	int f=1;
	for(int i=0;i<=n;i++)g[0][i]=(ld)a[i]/1000000;
	for(int i=n-1;i>=0;i--,f^=1)
		for(int j=0;j<=i;j++){
			g[f][j]=g[f^1][j+1]*(j+1)/(i+1)+g[f^1][j]*(i+1-j)/(i+1);
			if(g[f][j]<eps){dp[f][j]=0;continue;}
			p[f][j]=g[f^1][j+1]/g[f][j]*(j+1)/(i+1),
			dp[f][j]=max(ld(0),p[f][j]*(dp[f^1][j+1]+1)+(1-p[f][j])*dp[f^1][j]-c);
		}
	printf("%0.10Lf\n",dp[f^1][0]);
	return 0;
}