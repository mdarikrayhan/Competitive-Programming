// LUOGU_RID: 160212505
#include<bits/stdc++.h>

using namespace std;
int n;
int a[100005];
const int mo=998244353,N=300000;
int fast_pow(int a,int p){
	int sum=1;
	while(p){
		if(p&1)sum=1ll*sum*a%mo;
		a=1ll*a*a%mo;
		p>>=1;
	}
	return sum;
}
int add(int u,int v){
	return (u+v>=mo?u+v-mo:u+v);
}
int f[300005];
int main(){
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
	for(int i=2;i<=N;i++)f[i]=add(1ll*add(1ll*(n-1)*sum%mo,mo-1ll*(n-2)*(sum-(i-1))%mo)*f[i-1]%mo,mo-add(1ll*(i-1)*(n-1)%mo*1ll*f[i-2]%mo,1ll*(i-1)*(n-1)%mo))*1ll*fast_pow(sum-(i-1),mo-2)%mo;
	int ans=0;
	for(int i=1;i<=n;i++)ans=add(ans,f[a[i]]);
	ans=add(ans,mo-f[sum]);
	printf("%d\n",ans);
	return 0;
}