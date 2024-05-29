// LUOGU_RID: 159172868
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define F first
#define S second
#define ll int
#define N 210
#define M 3700
using namespace std;
ll n,mod,f[2][N][M],C[N][N];
typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod{
    ull b,m;
    FastMod(ull b):b(b),m(ull((L(1)<<64)/b)){}
    ull reduce(ull a){
        ull q=(ull)((L(m)*a)>>64);
        ull r=a-q*b;
        return r>=b?r-b:r;
    }
}F(2);
int main(){
	ll i,j,k,l,p;
	cin>>n>>mod;
	F=FastMod(mod);
	for(i=0;i<N;++i)
	{
		C[i][0]=1;
		for(j=1;j<=i;++j)
		{
			C[i][j]=F.reduce(C[i-1][j-1]+C[i-1][j]);
		}
	}
	for(i=1;i<=n+1;++i)
	{
		ll cur=i*i,tk=0;
		for(j=i;j<=n+1;++j)
		{
			tk+=cur/j;
			cur%=j;
			cur+=i;
		}
		if(tk>=n)
		{
			break;
		}
	}
	ll okl=i,ans=0;
	for(i=okl;i<=n;++i)
	{
		memset(f,0,sizeof(f));
		for(j=0;j<=i;j++)
		{
			f[1][j][0]=C[n][j];
		}
		for(j=1;j+i<=n+1;++j)
		{
			ll u=j&1,v=u^1;
			for(l=0;l<i+j;++l)
			{
				ll lim=min((j-1)*l,(j+i-l)*i);
				for(k=0;k<=lim;++k)
				{
					ll w=f[u][l][k];
					if(w)
					{
						ll lim2=min(n-l,((j+i)*i-k-l*i)/(j+i));
						for(p=(i+j==n+1?n-l:j==0);p<=lim2;++p)
						{
							f[v][l+p][k+p*j]=F.reduce(f[v][l+p][k+p*j]+1ull*w*C[n-l][p]);
						}
						f[u][l][k]=0;
					}
				}
			}
		}
		for(j=0;j<=(n+1-i)*(n+1);++j)
		{
			ans=F.reduce(ans+f[(n-i)&1][n][j]);
		}
	}
	cout<<ans<<'\n';
	return 0;
}