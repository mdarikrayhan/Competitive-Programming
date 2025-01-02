#include<stdio.h>
int main(){
	long long i,t,n,r,s,p,a[200003];
	for(scanf("%lld",&t);t;printf("%lld\n",s+(r>0?r:-r)),--t){
		for(scanf("%lld",&n),i=0;i<n;++i)scanf("%lld",&a[i]);
		for(r=a[n-1],s=0,i=1;i<n;++i)p=a[i]-a[i-1],s+=p>0?p:-p,r-=p>0?p:0;
	}
}