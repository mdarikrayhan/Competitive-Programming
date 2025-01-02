// LUOGU_RID: 160410314
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,jc[1000010],ans,aans;
int cj(int a){
    if(jc[a]) return jc[a];
    return jc[a]=a*cj(a-1)%mod;
}
int ksm(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}
int C(int n,int m){
    return cj(n)*ksm(cj(m),mod-2)%mod*ksm(cj(n-m),mod-2)%mod;
}
signed main(){
	jc[0]=jc[1]=1;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		ans=(ans+ksm(-1,i+1)*C(n,i)*ksm(3,n*(n-i)+i)%mod+mod)%mod;
	for(int i=1;i<=n;i++)
		aans=(aans+ksm(-1,i)*C(n,i)%mod*ksm(ksm(3,mod-2),n*i)%mod*(ksm((1-ksm(ksm(3,mod-2),n-i)),n)-1)+mod)%mod;
	printf("%lld",(ans*2-aans*ksm(3,n*n+1)%mod+mod)%mod);
	return 0;
}