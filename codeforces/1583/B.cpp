#include<cstdio>
int n,m,_,f[100001],x,i,j;
int main(){
	scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)f[i]=0;
		for(i=1;i<=m;i++)scanf("%*d%d%*d",&x),f[x]=1;
		for(i=1;i<=n;i++)if(!f[i])break;
		for(j=1;j<=n;j++)if(i!=j)printf("%d %d\n",i,j);
	}
}