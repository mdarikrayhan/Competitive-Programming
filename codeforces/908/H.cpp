// LUOGU_RID: 160588136
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define N 502
#define lowbit(x) (x&(-x))
typedef long long ll;
int n,f[N],b[N],siz[N],js,d[N],ans;
int lg[8400000],m;
int dp[8400000],ff[8400000],xs[8400000];
char ch[102][102];
int getroot(int t){if(f[t]==-1)return t;return f[t]=getroot(f[t]);}
inline void fwt(int x[],int tle,int mde)
{
	for(int i=2;i<=tle;i<<=1)
	for(int j=0,stp=i>>1;j<tle;j+=i)
	for(int k=j;k<j+stp;k++)x[k+stp]+=mde*x[k];
}
int main()
{memset(f,-1,sizeof(f));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ch[i]+1);
		for(int j=1;j<i;j++)
		{
			if(ch[i][j]=='A')
			{
				int x=getroot(i),y=getroot(j);
				if(x^y)f[x]=y;
			}
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<i;j++)if(ch[i][j]=='X'&&getroot(i)==getroot(j)){puts("-1");return 0;}
	for(int i=1;i<=n;i++)siz[getroot(i)]++;
	for(int i=1;i<=n;i++)
	{
		if(siz[i]>1)b[i]=++js;
	}
	if(!js){printf("%d\n",n-1);return 0;}
	for(int i=1;i<=n;i++)for(int j=1;j<i;j++)if(ch[i][j]=='X')
	{
		int x=getroot(i),y=getroot(j);
		if(siz[x]>1&&siz[y]>1)d[b[x]]|=1<<(b[y]-1),d[b[y]]|=1<<(b[x]-1);
	}lg[0]=-1;m=1<<js;dp[0]=1;
	for(register int i=1;i<m;i++)
	{lg[i]=lg[i>>1]+1;
		int nw=lowbit(i),la=i^nw;nw=lg[nw]+1;
		if(!(la&d[nw]))dp[i]=dp[la];
	}
	for(int i=0;i<m;i++)ff[i]=dp[i];
	if(dp[m-1]){printf("%d\n",n);return 0;}
	ans=n;fwt(ff,m,1);fwt(dp,m,1);
	for(int i=0;i<m;i++)xs[i]=1;
	for(int i=2;i<=m;i<<=1)for(int j=0,stp=i>>1;j<m;j+=i)
	for(int k=j;k<j+stp;k++)xs[k]*=-1;
	while(1)
	{ans++;
		for(register int i=0;i<m;i++)dp[i]=dp[i]*ff[i];
		int te=0;
		for(int i=0;i<m;i++)te+=dp[i]*xs[i];
		if(te){printf("%d\n",ans);return 0;}
	}
}
