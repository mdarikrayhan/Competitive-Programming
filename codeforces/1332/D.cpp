#include<stdio.h>
int main(){
	int k;
	scanf("%d",&k);
	if(k==0){
		printf("1 1\n300000");
	}else{
		printf("3 4\n262143 %d %d 0\n131072 0 %d 0\n131072 131072 262143 %d",k,k,k,k);
	}
	return 0;
}
