// LUOGU_RID: 160421115
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define rpe(i,x) for(int i=_he[x];i;i=_ne[i])
#define lb(x) (x&(-x))
using namespace std;
typedef long long LL;
const int N=2010,MOD=998244353;


int n,a[N][N],d[N],fac[N],f[N],g[N][N],C[N][N];
bool fl[N],fl2[N];

int t[N],t2[N];
void add(int x,int v){for(;x<=n;x+=lb(x))(t[x]+=v)%=MOD;}
int ask(int x){int res=0;for(;x;x-=lb(x))(res+=t[x])%=MOD;return res;}
void add2(int x,int v){for(;x<=n;x+=lb(x))(t2[x]+=v)%=MOD;}
int ask2(int x){int res=0;for(;x;x-=lb(x))(res+=t2[x])%=MOD;return res;}

int main()
{
	scanf("%d",&n);
	rep(i,1,n)rep(j,1,n)scanf("%d",&a[i][j]);	
	
	d[0]=1;rep(i,2,n)d[i]=(LL)(i-1)*(d[i-1]+d[i-2])%MOD;
	f[0]=1;rep(i,1,n)f[i]=(LL)f[i-1]*d[n]%MOD;	
	fac[0]=1;rep(i,1,n)fac[i]=(LL)fac[i-1]*i%MOD;
	rep(i,0,n)C[i][0]=1;
	rep(i,1,n)rep(j,1,n)C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
		
	g[0][0]=1;
	rep(i,1,n)
	{
		g[i][0]=d[i];
		rep(j,1,n-i)g[i][j]=(g[i-1][j-1]+g[i][j-1])%MOD;
	}		
	
	int ans=0;
	rep(i,1,n)
	{
		int tot=0;
		rep(j,1,a[1][i]-1)tot+=(!fl[j]);
		(ans+=(LL)tot*fac[n-i]%MOD*f[n-1]%MOD)%=MOD;
		fl[a[1][i]]=1;
	}
	
	rep(i,2,n)
	{
		memset(fl,0,sizeof(fl));
		memset(fl2,0,sizeof(fl2));
		memset(t,0,sizeof(t));
		memset(t2,0,sizeof(t2));
		rep(j,1,n)add2(j,1);
		
		int t=0;
		rep(j,1,n)
		{
			t++;
			{
				int v=a[i-1][j];
				if(!(fl[v]|fl2[v]))add2(v,-1);
				fl2[v]=1;
				if((!fl[v])&&fl2[v])add(v,1);
				if(fl[v]&&fl2[v])t--;
			}
			
			int tmp=ask(a[i][j]-1);
			(ans+=(LL)g[n-j][t-1]*f[n-i]%MOD*tmp%MOD)%=MOD;
			tmp=ask2(a[i][j]-1);
			(ans+=(LL)g[n-j][t]*f[n-i]%MOD*tmp%MOD)%=MOD;
			
			{
				int v=a[i-1][j];
				if(v<a[i][j])
				{
					if((!fl[v])&&fl2[v])
					(ans-=(LL)g[n-j][t-1]*f[n-i]%MOD)%=MOD;
					else if(!(fl[v]|fl2[v]))
					(ans-=(LL)g[n-j][t]*f[n-i]%MOD)%=MOD;	
				}
			}
		
			{
				int v=a[i][j];
				if(!(fl[v]|fl2[v]))add2(v,-1);
				if((!fl[v])&&fl2[v])add(v,-1);
				fl[v]=1;
				if(fl[v]&&fl2[v])t--;	
			}
		}
	}
	printf("%d\n",(ans+MOD)%MOD);
	return 0;
}