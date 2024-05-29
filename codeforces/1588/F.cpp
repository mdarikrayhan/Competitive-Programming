// LUOGU_RID: 160236530
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 200010
const int B=1010;

int read ()
{
	int k=1,s=0;char ch=getchar ();
	while (!isdigit (ch)) {if (ch=='-') k=-1;ch=getchar ();}
	while (isdigit (ch)) {s=s*10+ch-'0';ch=getchar ();}
	return k*s;
}

int n,m,p[N];
long long a[N],tag[N],sum[N];
int pre[N],tot,bel[N],b[N];
int mark[N],idx,num[N];
int cnt[N],siz[B<<1][B<<1];
struct Node
{
	int op,x,y;
}O[N];

void Init ()
{
	n=read ();
	for (int i=1;i<=n;i++)
		a[i]=read ();
	for (int i=1;i<=n;i++)
	{
		p[i]=read ();
		pre[p[i]]=i;
	}
	m=read ();
	for (int i=1;i<=m;i++)
		O[i].op=read (),O[i].x=read (),O[i].y=read ();
}

void Work ()
{
	for (int l=1,r;l<=m;l+=B)
	{
		r=min (l+B-1,m);
		for (int i=0;i<=n;i++)
		{
			bel[i]=cnt[i]=num[i]=0;
			tag[i]=0;
		}
		for (int i=1;i<=n;i++)
			sum[i]=sum[i-1]+a[i];
		for (int i=l;i<=r;i++)
		{
			int op=O[i].op,x=O[i].x,y=O[i].y;
			if (op==2) bel[x]=x;
			else if (op==3) bel[x]=x,bel[y]=y;
		}
		tot=0;
		for (int i=1;i<=n;i++)
			if (bel[i]==i)
			{
				b[++tot]=i,bel[i]=0;
				int now=i;
				while (!bel[now]) bel[now]=i,now=pre[now];
			}
		idx=0;
		for (int i=l;i<=r;i++)
		{
			int op=O[i].op,x=O[i].x,y=O[i].y;
			if (op==1)
			{
				if (!num[x-1]) num[x-1]=++idx;
				if (!num[y]) num[y]=++idx;
			}
		}
		for (int i=0;i<=n;i++)
		{
			if (i>0) cnt[bel[i]]++;
			if (num[i])
			{
				for (int j=1;j<=tot;j++)
					siz[num[i]][j]=cnt[b[j]];
			}
		}
		for (int i=l;i<=r;i++)
		{
			int op=O[i].op,x=O[i].x,y=O[i].y;
			if (op==1)
			{
				long long ans=sum[y]-sum[x-1];
				for (int j=1;j<=tot;j++)
					ans+=1ll*tag[b[j]]*(siz[num[y]][j]-siz[num[x-1]][j]);
				printf ("%lld\n",ans);
			}
			else if (op==2)
			{
				int now=bel[x];
				while (!mark[now])
				{
					tag[now]+=y;
					mark[now]=1;
					now=bel[p[now]];
				}
				while (mark[now])
				{
					mark[now]=0;
					now=bel[p[now]];
				}
			}
			else if (op==3)
			{
				swap (p[x],p[y]);
				pre[p[x]]=x,pre[p[y]]=y;
			}
		}
		for (int i=1;i<=n;i++)
			a[i]+=tag[bel[i]];
	}
}

signed main ()
{
	Init ();
	Work ();
	return 0;
}