// LUOGU_RID: 160015343
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define mkp make_pair
const int N=505;
#define pii pair<int,int>
#define fi first
#define se second
int n,m,k;
ll dp[N][N],sum[N][N],s[2][N][N],d[2][N][N];
vector<pii>c[2][N][N];
bool add(int x,int y,int t,int w){
	if(x+y-2>=t&&t%4==(x+y-2)%4){sum[x][y]+=w;return 1;} 
	else return 0;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x,y,d,t,e;i<=k;i++){
		scanf("%d%d%d%d%d",&x,&y,&d,&t,&e);x++;y++;
		if(add(x,y,t,e)){
			if(d%4==3)c[0][x][y+d].push_back(mkp(d,e));
			if(d%4==2)c[1][x+d][y].push_back(mkp(d,e));
		}
		if(add(x+d,y-d,t+1,e))
			if(d%4==1)c[0][x+d][y].push_back(mkp(d,e));
		add(x+d,y,t+2,e);
		add(x,y+d,t+3,e);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			s[0][i][j]=s[0][i][j-1]+sum[i][j];
			s[1][i][j]=s[1][i-1][j]+sum[i][j];
		}
	for(int i=1;i<=n;i++)dp[i][0]=1ll<<60;
	for(int j=1;j<=m;j++)dp[0][j]=1ll<<60;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(i==1&&j==1){dp[i][j]=sum[i][j];continue;}
			else dp[i][j]=1ll<<60;
			for(pii p:c[0][i][j])d[0][i][j-p.fi]+=p.se;
			for(pii p:c[1][i][j])d[1][i-p.fi][j]+=p.se;
			ll vx=0,vy=0;
			for(int k=1;k<j;k++){
				vx+=d[0][i][j-k];
				dp[i][j]=min(dp[i][j],dp[i][j-k]+s[0][i][j]-s[0][i][j-k]-vx);
            }
            for(int k=1;k<i;k++){
            	vy+=d[1][i-k][j];
            	dp[i][j]=min(dp[i][j],dp[i-k][j]+s[1][i][j]-s[1][i-k][j]-vy);
            }
  	    }
  	printf("%lld\n",dp[n][m]);
}