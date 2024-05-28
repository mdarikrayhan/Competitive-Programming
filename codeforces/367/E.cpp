// LUOGU_RID: 159990061
#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int MOD=1e9+7;

int f[2][N][N];

void llz(){
	int n,m,X;
	cin>>n>>m>>X;
	if(n>m){cout<<0<<"\n";return;}
	f[0][0][0]=1;
	for(int i=1;i<=m;++i){
		int t=i&1;
		for(int x=0;x<=n;++x){
			for(int y=0;y<=x;++y){
				if(i!=X)f[t][x][y]=f[t^1][x][y];
				else f[t][x][y]=0;
				if(x>0)f[t][x][y]=(f[t][x][y]+f[t^1][x-1][y])%MOD;
				if(y>0&&i!=X)f[t][x][y]=(f[t][x][y]+f[t^1][x][y-1])%MOD;
				if(x>0&&y>0)f[t][x][y]=(f[t][x][y]+f[t^1][x-1][y-1])%MOD;
				//cout<<i<<" "<<x<<" "<<y<<" "<<f[t][x][y]<<"\n";
			}
		}
	}
	int ans=f[m&1][n][n];
	for(int i=1;i<=n;++i)ans=1ll*ans*i%MOD;
	cout<<ans<<"\n";
}

signed main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--)llz();
	return 0;
}