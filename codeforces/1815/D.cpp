#include<cstdio>
using namespace std;
const int MOD=998244353;
inline void ad(int&a,long long b){a=(a+b)%MOD;}
int T,m,f[61][2],g[61][2];long long n;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%lld%d",&n,&m);
		if(m==1) printf("%lld\n",n%MOD);
		else if(m==2){
			for(int i=0;i<=60;++i) f[i][0]=f[i][1]=g[i][0]=g[i][1]=0;
			f[60][0]=1;
			for(int i=60;i--;) for(int j=0;j<2;++j) for(int k=0;k<3;++k)
				if(k<=j*2+((n>>i)&1)&&j*2+((n>>i)&1)-k<2)
					ad(f[i][j*2+((n>>i)&1)-k],f[i+1][j]),ad(g[i][j*2+((n>>i)&1)-k],g[i+1][j]*2ll+f[i+1][j]*(k&1));
			printf("%d\n",g[0][0]);
		}
		else if(n&1) printf("%d\n",(int)(((n+1)*(__int128)(n+1))/4%MOD));
		else printf("%d\n",(int)((n*(__int128)n/4+n/2)%MOD));
	}
	return 0;
}
