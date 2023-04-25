#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10,p=1e9+7;
inline int qpow(int x,int y){
	int s=1;while(y){
		if(y&1) s=1ll*s*x%p;
		x=1ll*x*x%p,y>>=1;
	}return s;
}
int inv[N];
int main(){
	inv[0]=0,inv[1]=1;
	for(int i=2;i<=5e6;i++) inv[i]=1ll*(p-p/i)*inv[p%i]%p;
	int T,n,m,ans,H,G,F;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(m==1) H=2,G=1,F=1;
		else H=qpow(2,m),G=1ll*m*qpow(2,m-1)%p,F=1ll*m*(m+1)%p*qpow(2,m-2)%p;
		ans=0;(F+=G)%=p;
		for(int i=1,Cn=n,Cm=1;i<=n;i++){
			F=(F+2ll*G+2ll*i*H)%p;
			ans=(ans+1ll*Cn*Cm%p*F%p)%p;
			Cn=1ll*Cn*(n-i)%p*inv[i+1]%p;
			Cm=1ll*Cm*(m+i)%p*inv[i]%p;
		}
		printf("%lld\n",1ll*ans*inv[n]%p);
	}
	return 0;
}