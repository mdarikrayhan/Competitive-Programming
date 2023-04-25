#include<cstdio>
using namespace std;
const int o=5010,MOD=998244353;
int n,f[o],C[o][o];
int main(){
	scanf("%d",&n);f[1]=1;
	for(int i=C[0][0]=1;i<=n;++i) for(int j=C[i][0]=1;j<=i;++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	for(int i=2;i<=n;++i) for(int j=1;j<i;++j) f[i]=(f[i]+f[j]*1ll*f[i-j]%MOD*C[i-1][j-1]*(1+(i-j>1)))%MOD;
	printf("%d",(f[n]-1)*2%MOD);
	return 0;
}