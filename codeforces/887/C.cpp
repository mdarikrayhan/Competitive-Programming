#include<cstdio>
using namespace std;
int A[]={13,14,5,6,17,18,21,22,1,3,5,7,9,11,24,22,3,4,17,19,10,9,16,14} ;
int B[]={15,16,7,8,19,20,23,24,2,4,6,8,10,12,23,21,1,2,18,20,12,11,15,13};
int C[30];
int slove(int n,int m){
	for(int i=n*4-2;i<=n*4;i++)if(C[i]!=C[i-1])return 0;
	for(int i=m*4-2;i<=m*4;i++)if(C[i]!=C[i-1])return 0;
	return 1;
}
int slove(int n){
	int m=(n-1)*8,k=n*8;
	int ok=1;
	for(int i=m;i<m+8;i++){
		int j=(i+6)%k;
		if(j<m)j+=m;
		if(C[A[i]]!=C[B[j]]){
			ok=0;break;
		}
	}if(ok)return 1;
	else{
		for(int i=m;i<m+8;i++){
			int j=(i+2)%k;
			if(j<m)j+=m;
			if(C[A[i]]!=C[B[j]])return 0;
		}return 1;
	}
}
int main(){
	for(int i=1;i<=24;i++)scanf("%d",&C[i]);
	if((slove(1,3)&&slove(1))||(slove(2,6)&&slove(3))||(slove(4,5)&&slove(2)))printf("YES");else printf("NO");
	return 0;
}