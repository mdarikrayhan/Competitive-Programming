#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("2\n");
		printf("%d %d\n",n,n-1);
		while(n>=3){
			printf("%d %d\n",n,n-2);
			n--;
		}
	}
	return 0;
}