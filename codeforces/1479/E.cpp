// LUOGU_RID: 160218500
#include<bits/stdc++.h>
 
using namespace std;
int n;
int a[2505];
const int mo=998244353;
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
 
int d1,d2,s1,s2;
int main(){
	scanf("%d",&n);
	if(n==1){
		puts("0");
		return 0;
	}
	int sum=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
	sort(a+1,a+1+n);
	d1=mo-2,d2=0;s1=s2=1;
	int now=1;
	int ans=0,D,S;
	for(int i=1;i<sum;i++){
		while(now<=n&&a[now]==i){
			int val=1ll*d1*fast_pow(s1,mo-2)%mo;
			ans=add(ans,val);now++;
		}
		D=(1ll*d1*s2%mo*(3ll*sum-2*i)+(mo-1ll)*d2%mo*s1%mo*(2*sum-i))%mo,S=s1*1ll*s2%mo*(sum-i)%mo;
		d2=d1;s2=s1;
		d1=D;s1=S;
	}
	int val=1ll*d1*fast_pow(s1,mo-2)%mo;
	ans=add(ans,mo-val);
	// ans=add(ans,mo-f[sum]);
	printf("%d\n",ans);//system("pause");
	return 0;
}