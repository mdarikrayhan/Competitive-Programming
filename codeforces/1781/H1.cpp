#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int T,h,w,m,r[2],c[2];
int dp[2][2][2][16],msk[43][43];
bool vis[43][43],ok[43][43];
vector<pair<int,int> >v[43][43];
void calc(int w,int lst,int tp){
	memset(dp[1],0,sizeof(dp[1]));
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<16;k++){
				dp[1][0][j|tp|(!i&lst)][k]=(dp[1][0][j|tp|(!i&lst)][k]+dp[0][i][j][k])%mod;
				dp[1][1][j][k|w]=(dp[1][1][j][k|w]+dp[0][i][j][k])%mod;
			}
	memcpy(dp[0],dp[1],sizeof(dp[1]));
}
void dfs(int x,int y){
	vis[x][y]=1;
	bool lst=0;
	for(auto i:v[x][y])
		if(!vis[i.first][i.second])
			dfs(i.first,i.second),lst=1;
	calc(msk[x][y],lst,ok[x][y]);
}
int main(){
	cin>>T;
	while(T--){
		cin>>h>>w>>m;
		for(int i=0;i<m;i++)
			cin>>r[i]>>c[i],r[i]--,c[i]--;
		int ans=0;
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++){
				int K=0;
				for(int k=0;k<i;k++)
					for(int l=0;l<j;l++)
						v[k][l].clear();
				memset(ok,0,sizeof(ok));
				for(int k=0;k<=h-i;k++)
					for(int l=0;l<=w-j;l++){
						int x=-1,y=-1,W=1;
						for(int o=0;o<m;o++)
							if(0<=r[o]-k&&r[o]-k<i&&0<=c[o]-l&&c[o]-l<j){
								W=0;
								if(x==-1)
									x=r[o]-k,y=c[o]-l;
								else
									v[x][y].push_back({r[o]-k,c[o]-l}),
									v[r[o]-k][c[o]-l].push_back({x,y}),
									x=-1,y=-1;
							}K|=W;
						if(x!=-1)ok[x][y]=1;
					}
				for(int k=0;k<i;k++)
					for(int l=0;l<j;l++){
						msk[k][l]=0;
						if(k==0)msk[k][l]|=1;
						if(l==0)msk[k][l]|=2;
						if(k==i-1)msk[k][l]|=4;
						if(l==j-1)msk[k][l]|=8; 
					}
				memset(vis,0,sizeof(vis));
				memset(dp,0,sizeof(dp));
				dp[0][0][K][0]=1;
				for(int k=0;k<i;k++)
					for(int l=0;l<j;l++)
						if(!vis[k][l])
							dfs(k,l);
				ans=((ans+dp[0][0][1][15])%mod+dp[0][1][1][15])%mod;
			}
		cout<<ans<<'\n';
	}
}