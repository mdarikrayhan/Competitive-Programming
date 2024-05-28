// LUOGU_RID: 100110360
#include<bits/stdc++.h>
#define inl inline
using namespace std;
typedef long long ll;
const int N=2005,P=998244353;
int n,a,b,p,c[N],d[N][N],f[N];
inl int Ad(int x,int y) {return x+y>=P?x+y-P:x+y; }
inl int Pow(int x,int y)
{
	int at=1;
	for(;y;y>>=1,x=1ll*x*x%P) if(y&1) at=1ll*at*x%P;
	return at;
}
int main()
{
	scanf("%d%d%d",&n,&a,&b); p=1ll*a*Pow(b,P-2)%P; d[1][0]=d[1][1]=1;
	for(int i=2,j;i<=n;++i) for(d[i][0]=1,j=1;j<=i;++j)
		d[i][j]=(1ll*d[i-1][j]*Pow(P+1-p,j)+1ll*d[i-1][j-1]*Pow(p,i-j))%P;
	for(int i=1,j,at;i<=n;c[i]=Ad(1,P-at),++i)
		for(at=0,j=1;j<i;++j) at=(1ll*c[j]*d[i][j]+at)%P;
	for(int i=1;i<=n;i++)
	{
		int at=0; for(int j=1;j<i;j++)
			at=((1ll*j*(i-j)+1ll*j*(j-1)/2+f[j]+f[i-j])%P*c[j]%P*d[i][j]+at)%P;;
		at=(1ll*(i*(i-1)/2)*c[i]%P*d[i][i]+at)%P;
		f[i]=1ll*at*Pow(P+1-1ll*c[i]*d[i][i]%P,P-2)%P;
	}
	printf("%d\n",f[n]);
}