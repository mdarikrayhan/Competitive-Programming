// LUOGU_RID: 158148882
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MP make_pair
mt19937 rnd(time(0));
ll f[1005],g[1025][25],inv[25];
int n,d,MOD;
int main(){
	ios::sync_with_stdio(false);
	// freopen("Otomachi_Una.in","r",stdin);
	// freopen("Otomachi_Una.out","w",stdout);
	cin>>n>>d>>MOD;
	inv[1]=1;
	for(int i=2;i<25;i++) inv[i]=MOD-(MOD/i)*inv[MOD%i]%MOD;
	if(n<=2) {cout<<1;return 0;}
	g[0][0]=1;
	for(int i=2;i<=n+1;i++){
		f[i]=g[i+d-3][d-1];
		if(i==2) f[i]++;
		if(f[i]) for(int j=n+d;j>=i;j--) for(int k=d;k>=1;k--){ 
			ll coef=1;
			for(int t=1;t<=k&&i*t<=j;t++){
				coef=coef*(f[i]+t-1)%MOD*inv[t]%MOD;
				g[j][k]=(g[j][k]+g[j-i*t][k-t]*coef)%MOD;
			}
		}
	}
	memset(g,0,sizeof(g));g[0][0]=1;
	ll ans=0;
	for(int i=2;i<=n/2+1;i++) if(f[i]){
		for(int j=n+d;j>=i;j--) for(int k=d;k>=1;k--){ 
			ll coef=1;
			for(int t=1;t<=k&&i*t<=j;t++){
				coef=coef*(f[i]+t-1)%MOD*inv[t]%MOD;
				g[j][k]=(g[j][k]+g[j-i*t][k-t]*coef)%MOD;
			}
		}
	}
	ans=g[n+d-1][d];
	if(~n&1) ans-=f[n/2+1]*(f[n/2+1]-1)/2;
	cout<<(ans%MOD+MOD)%MOD;
	return 0;
}