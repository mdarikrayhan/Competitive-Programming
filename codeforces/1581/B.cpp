#include<stdio.h>
long long T,n,m,k; 
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&k);
		puts((m>=n-1&&n*(n-1)/2>=m)&&((n==1&&k>1)||(n*(n-1)/2==m&&k>2)||k>3)? "YES":"NO");
	}
	return 0;
}