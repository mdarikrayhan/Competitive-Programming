#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char p=getchar();
	while(p<'0'||p>'9')
	{
		if(p=='-') f=-1;
		p=getchar();
	}
	while(p>='0'&&p<='9')
	{
		x=(x<<1)+(x<<3)+p-'0';
		p=getchar();
	}
	return x*f;
}
const int Maxn=5e5+5;
struct Edge
{
	int u,v,next;
}e[Maxn<<1];
int head[Maxn],cnt=0;
void add(int u,int v)
{
	e[++cnt]=(Edge){u,v,head[u]};
	head[u]=cnt;
}
long long a[Maxn];
long long res=0;
long long dp[Maxn];
void dfs(int x,int fa)
{
	dp[x]=a[x];res=max(res,dp[x]);
	long long Maxx1=-1e14,Maxx2=-1e14,Maxx3=-1e14;
	long long Sum=0;
	for(int i=head[x];~i;i=e[i].next)
	{
		int y=e[i].v;
		if(y==fa) continue;
		dfs(y,x);
		if(dp[y]>=Maxx1)
		{
			if(Maxx1==-1e14)
			{
				Maxx1=dp[y];
			}
			else
			{
				Sum+=(Maxx3>0?Maxx3:0);
				Maxx3=Maxx2;
				Maxx2=Maxx1;
				Maxx1=dp[y];
			}
		}
		else if(dp[y]>=Maxx2)
		{
			if(Maxx2==-1e14)
			{
				Maxx2=dp[y];
			}
			else
			{
				Sum+=(Maxx3>0?Maxx3:0);
				Maxx3=Maxx2;
				Maxx2=dp[y];
			}
		}
		else if(dp[y]>Maxx3)
		{
			if(Maxx3==-1e14)
			{
				Maxx3=dp[y];
			}
			else
			{
				Sum+=(Maxx3>0?Maxx3:0);
				Maxx3=dp[y];
			}
		}
		else
		{
			Sum+=(dp[y]>0?dp[y]:0);
		}
		dp[x]=max(dp[x],dp[y]);
		res=max(res,a[x]+dp[y]);
	}
	// if(d.size()>=1)
	// {
	// 	dp[x]=max(dp[x],d.back());
	// }
	if(Maxx1!=-1e14&&Maxx2!=-1e14)
	{
		dp[x]=max(dp[x],a[x]+Maxx1+Maxx2+Sum+(Maxx3>0?Maxx3:0));
		res=max(res,Maxx1+Maxx2);
		if(Maxx3!=-1e14)
		{
			res=max(res,a[x]+Maxx1+Maxx2+Maxx3+Sum);
		}
	}
}
int main()
{
	int T=read();
	while(T--)
	{
		cnt=0;
		//memset(dp,0,sizeof dp);
		int n=read();
		for(int i=1;i<=n;i++)
		{
			head[i]=-1;
		}
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		for(int i=1;i<n;i++)
		{
			int u=read(),v=read();
			add(u,v);add(v,u);
		}
		res=0;
		dfs(1,0);
		printf("%lld\n", res);
	}
}