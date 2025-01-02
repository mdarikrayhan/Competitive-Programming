// LUOGU_RID: 112150751
#include<stdio.h>
#include<algorithm>
using namespace std;
const int N=255,P=1e9+7;
int n,k,m,inv[N];
int f[N][N][N],g[N][N][N],h[N][N][N],a[N][N];
int ksm(int x,int y){
	int res=1;
	for(;y;y>>=1,x=1ll*x*x%P)if(y&1)res=1ll*res*x%P;
	return res;
}
int main(){
	scanf("%d%d%d",&n,&k,&m);
	if(k==1||k==n)return printf("%d\n",n),0;
	inv[0]=inv[1]=1;
	for(int i=2;i<=m;++i)inv[i]=1ll*(P-P/i)*inv[P%i]%P;
	for(int i=3;i<=m;++i)f[i][2][i-2]=1;
	for(int j=2;j<m;++j){
		for(int i=j+1;i<=m;++i){
			int p1=1ll*(m-i)*(i+1-j)*inv[m]%P*inv[i+1]%P,p2=1ll*i*inv[m]%P*inv[i-1]%P;
			for(int k=1;k<m;++k)f[i+1][j+1][k]=(1ll*(P-p1)*f[i+1][j][k]+f[i][j][k]+1ll*(P-p2)*(g[i-1][j][k]+h[i-1][j-1][k]))%P;
			f[i+1][j+1][m-1]=(1ll*(P-p2)*(i+1)+f[i+1][j+1][m-1])%P;
			if(i==m){
				for(int k=1;k<m-1;++k)a[j-1][k]=f[i+1][j+1][k];
				a[j-1][m-1]=P-f[i+1][j+1][m-1];
				break;
			}
			for(int k=1;k<m;++k){
				f[i+1][j+1][k]=1ll*m*(i+1)%P*inv[m-i]%P*inv[j]%P*f[i+1][j+1][k]%P;
				g[i][j][k]=(g[i-1][j][k]+f[i][j][k])%P;
				h[i][j][k]=(h[i-1][j-1][k]+f[i][j][k])%P;
			}
		}
	}
	for(int i=1;i<m-1;++i){
		for(int j=i;j<m-1;++j)if(a[j][i]){
			swap(a[i],a[j]);
			break;
		}
		int in=ksm(a[i][i],P-2);
		for(int j=i;j<m;++j)a[i][j]=1ll*a[i][j]*in%P;
		for(int j=1;j<m-1;++j)if(j!=i&&a[j][i]){
			int d=a[j][i];
			for(int k=1;k<m;++k)a[j][k]=(1ll*(P-d)*a[i][k]+a[j][k])%P;
		}
	}
	int res=f[n][k][m-1];
	for(int i=1;i<m-1;++i)res=(1ll*a[i][m-1]*f[n][k][i]+res)%P;
	printf("%d\n",res);
	return 0;
}