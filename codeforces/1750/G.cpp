#include<cstdio>
using namespace std;
const int o=2010;
int n,m,p[o],f[o][o],C[o][o],ans[o];bool S[o];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&p[i]);
	for(int i=C[0][0]=1;i<=n;++i) for(int j=C[i][0]=1;j<=i;++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%m;
	for(int i=f[0][0]=1,j;i<=n;++i) for(f[i][0]=f[i-1][0]*1ll*i%m,j=1;j<=i;++j) f[i][j]=(f[i][j-1]+m-f[i-1][j-1])%m;
	for(int i=1,t=n,c,c1,c2;i<=n;t-=(i>1&&p[i-1]+1==p[i]),c=c1=c2=0,++i){
		for(int j=1;j<=n;++j) S[j]=0;
		for(int j=i;j<=n;++j) S[p[j]]=1;
		for(int j=1;j<n;++j) c+=(S[j]&&S[j+1]);
		for(int j=1;j<p[i];++j) if(S[j]&&(i==1||p[i-1]+1-j)){if(S[j-1]) ++c1;else ++c2;}
		for(int j=0;j<c;++j) ans[t-j]=(ans[t-j]+C[c-1][j]*1ll*f[n-i-j][c-1-j]%m*c1)%m;
		for(int j=0;j<=c;++j) ans[t-j]=(ans[t-j]+C[c][j]*1ll*f[n-i-j][c-j]%m*c2)%m;
		if(i>1&&S[p[i-1]+1]&&p[i-1]+1<p[i]) for(int j=0;j<=c;++j) ans[t-j-1]=(ans[t-j-1]+C[c][j]*1ll*f[n-i-j][c-j])%m;
	}
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	return 0;
}