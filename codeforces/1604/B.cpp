#include<cstdio>
int _,n,f,i,a[100001];
int main(){
	scanf("%d",&_);
	while(_--){
		scanf("%d",&n);f=n&1;
		for(i=1;i<=n;i++)scanf("%d",&a[i]),f&=a[i]>a[i-1];
		puts(f?"NO":"YES");
	}
}