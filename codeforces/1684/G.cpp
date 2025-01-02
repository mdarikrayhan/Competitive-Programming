// LUOGU_RID: 159200943
#include<bits/stdc++.h>
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define fd(i,l,r) for(int i=(l);i>=(r);--i)
#define fu(i,l,r) for(int i=(l);i<(r);++i)
#define ll long long
using namespace std;
const int N=1007,M=2e6+7,inf=1e8;
int n,m,a[N],res,o,s;
int h,t,d[N],q[N];
int tot=1,cur[N],head[N],nx[M],to[M],w[M];
void add2(int x,int y,int z){to[++tot]=y;nx[tot]=head[x];head[x]=tot;w[tot]=z;}
void add(int x,int y,int z){add2(x,y,z);add2(y,x,0);}
bool bfs()
{
	fo(i,0,o) d[i]=-1,cur[i]=head[i];
	d[0]=1; q[h=t=1]=0;
	while(h<=t)
	{
		int x=q[h];
		for(int i=head[x],j;i;i=nx[i])
			if(d[j=to[i]]==-1&&w[i]) d[j]=d[x]+1,q[++t]=j;
		h++;
	}
	return d[o]!=-1;
}
int dfs(int x,int lim)
{
	if(x==o||!lim) return lim;
	int res=0;
	for(int i=head[x],j;i;i=nx[i])
	{
		j=to[i];
		if(w[i]&&d[j]==d[x]+1)
		{
			int tmp=dfs(j,min(lim,w[i]));
			w[i]-=tmp;w[i^1]+=tmp;res+=tmp;lim-=tmp;
			if(!lim) break;
		}
	}
	if(!res) d[x]=-1;
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	fo(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(a[n]>=(m+1)/2) return !printf("-1");
	fo(i,1,n)
	{
		if(a[i]*3>m) break;
		s=i;
	}
	o=n+1;
	fo(i,1,s) fo(j,s+1,n)
	{
		if(a[j]%a[i]==0&&a[j]+a[j]+a[i]<=m) add(j,i,1);
	}
	fo(i,s+1,n) add(0,i,1);
	fo(i,1,s) add(i,o,1);
	while(bfs()) res+=dfs(0,inf);
	if(res<n-s) return !printf("-1");
	printf("%d\n",s);
	fo(j,1,s)
	{
		int pd=0;
		for(int i=head[j],k;i;i=nx[i])
		{
			k=to[i];if(k==o||!w[i]) continue;
			printf("%d %d\n",a[j]+a[k],a[j]+a[k]+a[k]);
			pd=1;break;
		}
		if(!pd) printf("%d %d\n",a[j]*3,a[j]*2);
	}
}