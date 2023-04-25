#include<stdio.h>

int main()
{
	int t;
	long long a,b,d,x;
	scanf("%d",&t);
	while(t--) {
		scanf("%lld%lld%lld",&a,&b,&d);
		x=0;
		if((a&-a)<(d&-d)||(b&-b)<(d&-d)) {
			puts("-1");
			continue;
		}
		for(int i=0; (x|a|b)>x; i++)
			if(((a|b)&(d&-d)<<i)&&!(x&(d&-d)<<i))
				x+=d<<i;
		printf("%lld\n",x);
	}
}