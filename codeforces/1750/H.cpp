#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define M 25
#define ll long long
int T,n,b[N],o1[N],o2[N],ps[N],w[N],o[N][M],fa[N][M];
ll ans;char a[N];struct Node {int l,r;bool fl;}z[N];
Node qry(int x,int y)
{
	int t=x;if(y>n) return (Node) {n+1,n,1};
	while(1)
	{
		t=lower_bound(o[x]+1,o[x]+o[x][0]+1,t)-o[x];
		t=t>o[x][0]?n+1:o[x][t];if(t>y) return (Node) {y,t-1,1};
		if(t*2-x>y) return (Node) {y,t*2-x-1,0};
		t+=b[t];if(ps[t]<=y) {t=ps[t];continue;}
		if(z[t].r>=y) return (Node) {max(z[t].l,y),z[t].r,z[t].fl};
		for(int i=17;i>=0;--i) if(z[fa[t][i]].r<y) t=fa[t][i];
		t=fa[t][0];return (Node) {max(z[t].l,y),z[t].r,z[t].fl};
	}
}
void get(int x,Node y)
{
	int t=y.l+b[y.l];z[x]=y;fa[x][0]=t;
	if(!y.fl && z[x].r<t-1)
	{
		for(int i=1;i<=17;++i) fa[x][i]=fa[fa[x][i-1]][i-1];
		ps[x]=ps[t];w[x]=w[t]+z[x].r-z[x].l+1;
	}
	else
	{
		for(int i=0;i<=17;++i) fa[x][i]=x;
		ps[x]=z[x].r+1;w[x]=z[x].r-z[x].l+1;
	}
}
void slv()
{
	scanf("%d %s",&n,a+1);ans=o1[0]=b[n+1]=0;
	for(int i=n;i;--i) b[i]=a[i]=='0'?b[i+1]+1:0;
	for(int i=0;i<=17;++i) fa[n+1][i]=n+1;
	z[n+1].l=ps[n+1]=n+1;z[n+1].r=n;
	for(int i=n,t;i;--i)
	{
		for(int j=1;j<=o1[0];++j)
			if(b[o1[j]]>o1[j]-i) o2[++o2[0]]=o1[j];
		o1[0]=o2[0];for(int j=1;j<=o1[0];++j) o1[j]=o2[j];o2[0]=0;
		o[i][0]=o1[0];for(int j=1;j<=o[i][0];++j) o[i][j]=o1[j];t=i;
		if(a[i]=='0')
		{
			Node t1=qry(i+b[i],i+b[i]*2-1);t=t1.l;
			if(a[i-1]=='1') get(i+b[i],t1);
			if(!t1.fl && t1.r<t+b[t]-1)
				ans+=t1.r-t+w[t+b[t]]+1,t=ps[t+b[t]];
			else ans+=t1.r-t+1,t=t1.r+1;
		}
		while(1)
		{
			ans-=t;t=lower_bound(o1+1,o1+o1[0]+1,t)-o1;
			t=t>o1[0]?n+1:o1[t];ans+=t;if(t>n) break;
			ans+=t-i;t+=b[t];ans+=w[t];t=ps[t];
		}
		if(a[i]=='0' && a[i-1]=='1')
		{++o1[0];for(int j=o1[0];j>1;--j) o1[j]=o1[j-1];o1[1]=i;}
	}printf("%lld\n",ans);
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}