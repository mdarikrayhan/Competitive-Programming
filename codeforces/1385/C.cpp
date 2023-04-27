#include<cstdio>
int t,n,a[200007],i;
main(){
	for(scanf("%d",&t);t--;printf("%d\n",i))
	{
		for(scanf("%d",&n),i=0;i<n;) 
		scanf("%d",a+i++);
		for(i=n;i&&a[i-1]>=a[i];i--);
		for(;i&&a[i-1]<=a[i];--i);
	}
}