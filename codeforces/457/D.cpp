// LUOGU_RID: 157351445
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long double
using namespace std;

int n,m,k;
ll fac[100005];

inline ll C(int n,int m){return fac[n]-fac[n-m]-fac[m];}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) fac[i]=fac[i-1]+log(1.0*i);
	ll ans=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			int x=(i+j)*n-i*j;
			if(x<=k) ans+=exp(C(n,i)+C(n,j)+C(m-x,k-x)-C(m,k));
		}
	}
	if(ans>1e99) ans=1e99;
	printf("%.12Lf\n",ans);

	return 0;
}