#include<bits/stdc++.h>
using namespace std;
long long t,n,a,b,x;
int main(){
	for(scanf("%lld",&t);~--t;a=b=0){
		scanf("%lld%lld",&n,&x);
		for(int i=2,j;i<n;++i){
			scanf("%lld",&j),a+=(j&1),b+=j;
		}
		scanf("%lld",&x);
		printf("%lld\n",((n==3&&a==1)||b==n-2)?-1:(a+b)/2);
	}
}