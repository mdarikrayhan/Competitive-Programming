#include<cstdio>
int _,n,cnt,i,j,a[1001];
int main(){
	scanf("%d",&_);
	while(_--){
		scanf("%*d%d",&n);cnt=0;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++)for(j=i+1;j<=n;j++)cnt+=a[i]<a[j];
		printf("%d\n",cnt);
	}
}