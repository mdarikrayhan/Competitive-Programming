/*
 * Author: ylx
 * LANG: c++
 * PROG: 
 */
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void qmax(int &x,int y) {if (x<y) x=y;}
void qmin(int &x,int y) {if (x>y) x=y;}
inline int read()
{
	char s;
	int k=0,base=1;
	while ((s=getchar())!='-'&&s!=EOF&&!(isdigit(s)));
	if (s==EOF) exit(0);
	if (s=='-') base=-1,s=getchar();
	while (isdigit(s)) k=k*10+(s^'0'),s=getchar();
	return k*base;
}
inline void write(int x)
{
	static char cnt,num[15];cnt=0;
	if (!x)
	{
		putchar('0');
		return;
	}
	for (;x;x/=10) num[++cnt]=x%10;
	for (;cnt;putchar(num[cnt--]+48));
}
const int maxn=210;
const double eps=1e-9;
int n,T;
int cnt[maxn*maxn],tot,s[maxn];//cnt[i]:直线i上的点的个数,s[i]:点i周围有的直线的条数
struct matrix
{
	double a[maxn][maxn];
	void clear()
	{
		for (int i=0;i<maxn;i++)
		{
			for (int j=0;j<maxn;j++) a[i][j]=0;
			a[i][i]=1;
		}
	}
	friend matrix operator * (const matrix &a,const matrix &b)
	{
		matrix c;
		for (int i=1;i<=tot;i++)
			for (int k=1;k<=tot;k++) c.a[i][k]=0;
		for (int i=1;i<=tot;i++)
			for (int k=1;k<=tot;k++)
				for (int j=1;j<=tot;j++) 
				{
					c.a[i][k]+=a.a[i][j]*b.a[j][k];
				}
		return c;
	}
	void sc()
	{
		for (int i=1;i<=tot;i++)
		{
			for (int j=1;j<=tot;j++)
				printf("%.10lf ",a[i][j]);
			printf("\n");
		}
		printf("-----------------\n");
	}
} sum[9];
struct node
{
	int x,y;
} a[maxn];
int F[maxn][maxn],id,vis[maxn*maxn],X,Y;
bool check_line(node x,node y,node z)
{
	return (z.x-x.x)*(z.y-y.y)==(z.y-x.y)*(z.x-y.x);
}
vector<int> V[maxn*maxn];
double p[maxn],P[maxn];
int num[1<<7];
#define lowbit(x) (x&-x)
void work()
{
	for (int i=0;i<=7;++i) num[1<<i]=i;
	Y--;
	if (!Y)
	{
		for (int i=1;i<=n;i++) p[i]=0;
		p[X]=1;
	} else
	{
		Y=min(Y,128);
		bool flag=false;
		for (;Y;Y^=lowbit(Y)) 
		{
			register int i=num[lowbit(Y)];
			if (!flag)
			{
				flag=true;
				for (int j=1;j<=n;j++) p[j]=sum[i].a[j][X];
			} else
			{
				double cur=.0;
				for (int j=1;j<=n;j++,cur=.0)
				{
					for (int k=1;k<=n;k++)
						cur+=sum[i].a[j][k]*p[k];
					P[j]=cur;
				}
				swap(p,P);
			}
		}
	}
	double ans=0.0,sum=0.0;
	for (int i=1;i<=id;i++)
	{
		sum=0.0;
		for (int j=0;j<cnt[i];j++) sum+=p[V[i][j]]/(double)cnt[i];
		ans=max(ans,sum);
	}
	printf("%.8f\n",ans);
}
int main()
{
#ifdef ylx
	freopen("989E.in","r",stdin);
	freopen("989E.out","w",stdout);
#endif
	n=read();tot=n;
	for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
			if (!F[i][j])
			{
				++id;
				for (int k=1;k<=n;k++) if (check_line(a[i],a[j],a[k])) V[id].push_back(k),s[k]++;
				cnt[id]=V[id].size();
				for (int k=V[id].size()-1;k>=0;--k)
					for (int l=V[id].size()-1;l>=0;--l) F[V[id][k]][V[id][l]]=id;
			}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			if (i^j)
			{
				sum[0].a[i][j]=1.0/(double)s[i]/cnt[F[i][j]];
				if (vis[F[i][j]]!=i)
				{
					vis[F[i][j]]=i;
					sum[0].a[i][i]+=1.0/s[i]/cnt[F[i][j]];
				}
			}
	}
	for (int i=1;i<=7;i++) 
	{
		sum[i]=sum[i-1]*sum[i-1];
	}
	T=read();
	while (T--)
	{
		X=read();
		Y=read();
		work();
	}
	return 0;
}
//2018年 06月 12日 星期二 19:50:40 CST
