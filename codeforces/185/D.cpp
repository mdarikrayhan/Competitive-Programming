// LUOGU_RID: 160495228
#include<stdio.h>
int T,k,p;
long long l,r;
int ksm(int a,long long b,int mod){
	int res=1;
	while(b){
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
int f(long long x){
	return k%p==0? 0:ksm(k,ksm(2,x,p-1),p);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld%lld%d",&k,&l,&r,&p);
		if(p==2)
			printf("%d\n",(k&1)^1);
		else{
			int ans=(f(l)==1? ksm(2,r-l+1,p):(1ll*(f(r+1)-1+p)%p*ksm((f(l)-1+p)%p,p-2,p)%p));
			if(k&1)
				ans=1ll*ans*ksm(ksm(2,r-l,p),p-2,p)%p;
			printf("%d\n",ans);
		}
	}
	return 0;
}