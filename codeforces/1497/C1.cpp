#include<iostream>
int main(){
	int T,n,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		n%2==1?printf("1 %d %d\n",n/2,n/2):((n/2)%2==1?printf("2 %d %d\n",n/2-1,n/2-1):printf("%d %d %d\n",n/2,n/4,n/4));
	}
}