#include<cstdio>
const int mod=1000000007;
int n,d[51],f[51][51],g[51][51][51];
long long G(int i,int j,int k){
	if(i<0||j<0)return 0;
	int&s=g[i][j][k];
	if(s)return s-1;
	if(k)s=(i*G(i-1,j,k-1)+j*G(i+1,j-1,k-1))%mod;
	else if(i)s=((i-1)*G(i-2,j,0)+j*G(i,j-1,0))%mod;
	else if(j>2)for(int c=3,a=(j-1)*(j-2)/2;c<=j;a=1ll*a*(j-c++)%mod)s=(s+a*G(0,j-c,0))%mod;
	else s=!j;
	return s++;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",d+i);
	for(int i=n;i--;){
		int a=d[i]==2,b=d[i]==3;
		for(int j=i+1;j<=n;j++){
			if(j==n)f[i][j]=G(a,b,0);
			else for(int k=j+1;k<=n;k++)f[i][j]=(f[i][j]+G(a,b,k-j)*f[j][k])%mod;
			a+=d[j]==2;b+=d[j]==3;
		}
	}
	printf("%d\n",f[1][1+*d]);
}