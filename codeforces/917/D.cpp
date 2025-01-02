// becoder Submission #undefined @ 1716819184368
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fi first
#define se second
#define PII pair<int,int>
#define PLI pair<ll,int>
#define PLL pair<ll,ll>
#define iter vector<Node>::iterator
using namespace std;
const int N=105,Mod=1e9+7;
int n,F[N],a[N][N],b[N][N],fac[N],ifac[N],inv[N],pw[N],val[N][N];
vector<PII>E;
int ksm(int x,int y=Mod-2)
{
    if(y<0)y+=Mod-1;
    int z=1;
    while(y){if(y&1)z=(ll)z*x%Mod;x=(ll)x*x%Mod;y>>=1;}
    return z;
}
int Det(int A[N][N],int n)
{
	// for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=n;j++)printf("%d ",A[i][j]);
	int sum=1;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
	{
		while(A[i][i])
		{
			int k=(ll)(A[j][i]/A[i][i])*(Mod-1)%Mod;
			for(int p=i;p<=n;p++)(A[j][p]+=(ll)k*A[i][p]%Mod)%=Mod;
			swap(A[i],A[j]),sum=Mod-sum;
		}
		swap(A[i],A[j]),sum=Mod-sum;
		// for(int i=1;i<n;i++,puts(""))for(int j=1;j<n;j++)printf("%d ",A[i][j]);
	}
	for(int i=1;i<=n;i++)sum=(ll)sum*A[i][i]%Mod;
	return sum;
}
void Gauss(int A[N][N])
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)if(i!=j)
		{
			int k=(ll)(Mod-1)*A[j][i]%Mod*ksm(A[i][i])%Mod;
			for(int p=i;p<=n+1;p++)(A[j][p]+=(ll)k*A[i][p]%Mod)%=Mod;
		}
	}
	for(int i=1;i<=n;i++)A[i][n+1]=(ll)A[i][n+1]*ksm(A[i][i])%Mod;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	
    fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=pw[0]=1;
    for(int i=2;i<N;i++)fac[i]=(ll)fac[i-1]*i%Mod,inv[i]=(ll)(Mod-Mod/i)*inv[Mod%i]%Mod,ifac[i]=(ll)ifac[i-1]*inv[i]%Mod;
	scanf("%d",&n);
    for(int i=1,x,y;i<n;i++)
    {
        scanf("%d%d",&x,&y);
		E.push_back({x,y});
    }
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)val[i][j]=i==j?n-1:Mod-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n;j++)pw[j]=(ll)pw[j-1]*i%Mod;
		for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)b[j][k]=val[j][k];
		a[i][n+1]=Det(b,n-1);
		for(int j=1;j<=n;j++)a[i][j]=pw[j-1];
		// printf("%d %d\n",i,a[i][n+1]);
		for(PII p:E)++val[p.fi][p.fi],++val[p.se][p.se],--val[p.fi][p.se],--val[p.se][p.fi];
	}
	Gauss(a);
	for(int i=1;i<=n;i++)printf("%d ",a[i][n+1]);

	cerr<<1.0*clock()/CLOCKS_PER_SEC;
}