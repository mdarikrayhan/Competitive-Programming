#include<bits/stdc++.h>
using namespace std;
#define ll long long
int P;
#define MAXN 500005
int n,ans,i,j,f[MAXN],g[MAXN];
int Pow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
	return s;
}
int C(int x,int y)
{
	return (ll)f[x]*g[y]%P*g[x-y]%P;
}
int main()
{
	scanf("%d%d",&n,&P);
	for(i=f[0]=1;i<=n;i++)f[i]=(ll)f[i-1]*i%P;
	for(g[n]=Pow(f[n],P-2),i=n-1;~i;i--)g[i]=(ll)g[i+1]*(i+1)%P;
	for(i=0;i<n;i++)for(j=max(0,(i<<1)-n);j<i;j++)ans=(ans+(ll)C(n,i)*C(i,j)%P*C(n-i,i-j)%P*f[n-i-1]%P*(i-j)%P*Pow(n-1,i-j)%P*Pow(n-i,j))%P;
	cout<<ans<<endl;
	return 0;
}