#include<stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		char x[100001]={};
		for(int i=0;i<2*n-1;++i){
			char s[100001];
			scanf("%s",s);
			for(int j=0;j<m;++j)x[j]^=s[j];
		}
		puts(x);
	}
}