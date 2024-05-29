// LUOGU_RID: 160030655
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=205;
int n,d,mod;
ll ans,C[N][N],F[N],f[N][N];
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>d>>mod,C[0][0]=1,f[1][0]=F[1]=1;
	if(d==1)cout<<(n==2?4:0)<<'\n',exit(0);
	for(int i=1;i<=n;i++)for(int j=0;j<=i;j++)C[i][j]=(C[i-1][j]+(j?C[i-1][j-1]:0))%mod;
	for(int i=2;i<=n;i++) {
		for(int j=1;j<=d;j++) {
			for(int k=1;k<i;k++)f[i][j]=(f[i][j]+f[i-k][j-1]*F[k]%mod*C[i-2][k-1])%mod;
			F[i]=(F[i]+(j<d)*f[i][j])%mod;
		}
	}
	ll way=1;
	for(int i=2;i<=n;i++)f[i][1]--;
	for(int x=1;x<=n;x++)for(int i=0;i<=d;i++)for(int j=0;i+j<=d;j++)if(i!=1||j==0)way=(way+f[x][i]*f[n-x+1][j])%mod;
	cout<<way*n*(n-1)*2%mod<<'\n';
	return 0;
}