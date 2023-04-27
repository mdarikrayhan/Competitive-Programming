#include<cstdio>
int t,n,a[507],i,m,b,f;
main(){
	for(scanf("%d",&t);t--;i=m=f=puts(m*(n-m)|!f?"Yes":"No")){
		for(scanf("%d",&n);i<n;) scanf("%d",a+i++);
		for(a[n]=1e6;i--;f|=(a[i+1]<a[i])) scanf("%d",&b), m+=b;
	}
}