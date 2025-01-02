#include<bits/stdc++.h>
#define int long long 
using namespace std;
int i,j,n,m,T,ans,x,y,X,Y,w,o,a[2020][2020];
char s[2020];
int sum(int x,int y){
	for (o=(x/n)^(y/m),w=0;o;o>>=1) w^=o&1;
	return (x*y-(x%n)*(y%m))/2+(w?((x%n)*(y%m)-a[x%n][y%m]):(a[x%n][y%m]));
}
signed main(){
	scanf("%lld %lld %lld",&n,&m,&T);
	for (i=1;i<=n;i++)
		for (scanf("%s",s+1),j=1;j<=m;j++)
			a[i][j]=a[i+n][j+m]=s[j]^48,a[i+n][j]=a[i][j+m]=a[i][j]^1;
	for (n<<=1,m<<=1,i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	while (T--){
		scanf("%lld %lld %lld %lld",&x,&y,&X,&Y);x--;y--;
		printf("%lld\n",sum(X,Y)-sum(X,y)-sum(x,Y)+sum(x,y));
	}
	return 0;
}