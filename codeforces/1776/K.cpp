#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
#define N 127
#define B 100000
#define DB double
DB a[100012],s[N][100012];
int n;long long T,b[N];
DB c[N][N];
inline DB po(long long n,int k){DB res=1.0;while(k--)res/=n;return res;}
inline DB ph(long long n,int k){if(n==0)return 0;return (k==0)?n:((k==1)?(logl(n)+0.5/n):(-(1.0/(k-1))*po(n,k-1)));}
inline DB ca(long long n,int k){return (n<=B)?s[k][n]:(s[k][B]+ph(n,k)-ph(B,k));}
DB f[N];
inline void cal(long long n,DB *c)
{
	--n;int i,j;
	for(i=1;i<=100;i++)f[i]=ca(n,i)*((i&1)?(1):(-1))/i;
	c[0]=1;
	for(i=1;i<=100;i++)
	{
		DB res=0;
		for(j=0;j<i;j++)res+=c[j]*(i-j)*f[i-j];c[i]=res/i;
	}
	for(i=100;i>=1;i--)c[i]=c[i-1]/(n+1);
	for(i=min(100ll,n+2);i<=100;i++)c[i]=0;c[0]=0;
//	for(i=1;i<=100;i++)cerr<<c[i]<<endl;
}
DB nw[N];
int main(){
//jiuk
//	DB res=0;
//	for(int i=90;i<=95;i++)res+=1.0/i;cerr<<res<<" "<<ph(95)-ph(89)<<endl;return 0;
	for(int i=1;i<=B;i++)a[i]=1,s[0][i]=i;
	for(int i=1;i<=100;i++)
	for(int j=1;j<=B;j++)a[j]/=j,s[i][j]=s[i][j-1]+a[j];
	scanf("%lld%d",&T,&n);int i,j,k;
	if(n==1){printf("1");return 0;}
	for(i=1;i<=n;i++){scanf("%lld",&b[i]);if(b[i]==T)while(1);cal(T-b[i],c[i]);}
	for(i=1;i<=n;i++)
	{
		DB ans=0;
		for(j=1;j<=n;j++)nw[j]=1.0;
		for(j=1;j<=min(B,100);j++)
		{
			DB res=c[i][j];
			for(k=1;k<=n;k++)if(k!=i)res*=nw[k];
			for(k=1;k<=n;k++)nw[k]=max(0.0,nw[k]-c[k][j]);
			ans+=res;
		}
		printf("%.12lf ",ans);
	}return 0;
}