// LUOGU_RID: 159519812
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=102;
const int mod=1e9+7;
int n,m,k;
int C[N][N],fp[N][N],f[N][N*N];
int power(int a,int b){
	int res=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1) res=res*a%mod;
	return res;
}
signed main(){
	for(int i=1;i<=100;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			fp[i][j]=power(C[n][j],(m-1)/n+(i<=(m-1)%n+1));
		}
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(k,i*n);j++){
			for(int t=0;t<=min(j,n);t++){
				f[i][j]=(f[i][j]+f[i-1][j-t]*fp[i][t]%mod)%mod;
			}
		}
	}
	cout<<f[n][k];
	return 0;
}
