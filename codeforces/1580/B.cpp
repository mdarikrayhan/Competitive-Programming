// LUOGU_RID: 160428057
#include<bits/stdc++.h>
using namespace std;
const int N=110;

int MOD;
int C[N][N],f[N][N][N],fac[N];

void llz(){
	int n,m,k;
	cin>>n>>m>>k>>MOD;
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%MOD;
	for(int i=0;i<=n;++i)f[0][i][0]=1;
	for(int x=1;x<=n;++x){
		f[x][1][1]=fac[x];
		for(int j=x+1;j<=n;++j)f[x][j][0]=fac[x];
		for(int y=2;y<=min(x,m);++y){
			for(int z=0;z<=min(x-y+1,k);++z){
				for(int siza=0;siza<x;++siza){
					if(siza==0)f[x][y][z]=(f[x][y][z]+f[x-1][y-1][z])%MOD;
					else if(siza==x-1)f[x][y][z]=(f[x][y][z]+f[x-1][y-1][z])%MOD;
					else{
						for(int i=0;i<=min(z,siza);++i){
							if(f[siza][y-1][i]&&f[x-1-siza][y-1][z-i])f[x][y][z]=(f[x][y][z]+1ll*C[x-1][siza]*f[siza][y-1][i]%MOD*f[x-1-siza][y-1][z-i]%MOD)%MOD;
						}
					}
				}
				//cout<<x<<" "<<y<<" "<<z<<" "<<f[x][y][z]<<"\n";
			}
		}
	}
	int ans=f[n][m][k];
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