#include<stdio.h>
struct l{int x;long long d;}a[50003],b[50003];
int f,t,n,m,j,k,i;
int g(l c[],int n){
    for(i=0;i<n;++i){
		for(scanf("%d",&c[i].x),c[i].d=1;c[i].x%m==0;c[i].x/=m,c[i].d*=m);
		if(i&&c[i].x==c[i-1].x)c[i-1].d+=c[i].d,--i,--n;
	}
    return n;
}
int main(){
    for(scanf("%d",&t);t;printf("%s\n",f?"Yes":"No"),--t){
        scanf("%d%d",&n,&m);n=g(a,n);scanf("%d",&k);k=g(b,k);
        for(f=n==k,i=0;i<n&&f;++i)f=a[i].x==b[i].x&&a[i].d==b[i].d;
    }
}