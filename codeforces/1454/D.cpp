#include<iostream>
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		long long n,d=1,mn=0,m,c,i;
		scanf("%lld",&n),m=n;
		for(i=2;i*i<=m;i++)if(m%i==0){
			for(c=0;m%i==0;m/=i,++c);
			if(c>mn)mn=c,d=i;
		}
		if(m>1 && mn==0)mn=1,d=m;
		while(n%d==0)n/=d;
		printf("%lld\n",mn);
		for(int i=1;i<mn;++i)printf("%lld ",d);
		printf("%lld\n",d*n);
	}
}