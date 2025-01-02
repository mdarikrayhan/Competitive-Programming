// LUOGU_RID: 160037378
#include<bits/stdc++.h>
using namespace std;

const int N=107;
int n,p[N],ln,l[N],r[N],lsh[N<<2],f[N][N<<2],R,g[N<<2],ans;
struct dat{int x,y;}nd[N];
int calc(int x,int y){return lsh[y]-lsh[x];}
bool cmp(dat x,dat y){return x.x<y.x;}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i],&ln);
		nd[i].x=p[i]; nd[i].y=ln;
	//	l[i]=p[i]-ln,r[i]=p[i]+ln;
		lsh[++lsh[0]]=p[i],
		lsh[++lsh[0]]=p[i]-ln,
		lsh[++lsh[0]]=p[i]+ln;
	}
	sort(lsh+1,lsh+1+lsh[0]);
	lsh[0]=unique(lsh+1,lsh+1+lsh[0])-lsh-1;
	sort(nd+1,nd+1+n,cmp);
	for(int i=1;i<=n;i++)
		p[i]=lower_bound(lsh+1,lsh+1+lsh[0],nd[i].x)-lsh,
		l[i]=lower_bound(lsh+1,lsh+1+lsh[0],nd[i].x-nd[i].y)-lsh,
		r[i]=lower_bound(lsh+1,lsh+1+lsh[0],nd[i].x+nd[i].y)-lsh;
	for(int i=1;i<=n;i++)
	{
		for(int j=p[i];j<=lsh[0];j++)
			f[i][j]=max(f[i-1][j],f[i-1][p[i]]+calc(p[i],min(r[i],j)));
		R=p[i];
		for(int j=i;j>=1;j--)
		{
			if(j!=i) R=max(R,r[j]);
			g[R]=max(g[R],f[j-1][l[i]]+calc(l[i],R));
		}
		for(int j=lsh[0]-1;j>=1;j--)
			g[j]=max(g[j],g[j+1]-calc(j,j+1));
		for(int j=1;j<=lsh[0];j++)
			f[i][j]=max(max(f[i][j-1],f[i][j]),g[j]);
	}
	ans=0;
	for(int j=1;j<=lsh[0];j++) ans=max(ans,f[n][j]);
	printf("%d\n",ans);
	return 0;
}