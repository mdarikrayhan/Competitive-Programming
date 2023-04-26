#include<cstdio>
#include<algorithm>
using namespace std;
long long a[2],b[20001];
int i,f,n,_;
int main(){
	scanf("%d",&_);
	while(_--){
		scanf("%d",&n);a[0]=a[1]=0;
		for(i=1;i<=n;i++)scanf("%lld",&b[i]),a[i&1]=__gcd(a[i&1],b[i]);
		f=1;
		for(i=1;i<=n;i+=2)if(b[i]%a[0]==0)f=0;
		if(f){printf("%lld\n",a[0]);continue;}
		f=1;
		for(i=2;i<=n;i+=2)if(b[i]%a[1]==0)f=0;
		if(f)printf("%lld\n",a[1]);else puts("0");
	}
}