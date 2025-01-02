#include <bits/stdc++.h>
using namespace std;
#define N 810000
int n,T,cnt,top,m;
struct poi
{
	int x,y;
	poi(){}
	poi(int x,int y):x(x),y(y){}
	friend bool operator == (const poi &r1,const poi &r2)
	{return r1.x==r2.x&&r1.y==r2.y;}
	friend bool operator < (const poi &r1,const poi &r2)
	{
		if(r1.x==r2.x)return r1.y<r2.y;
		return r1.x<r2.x;
	}
	friend int operator ^ (const poi &r1,const poi &r2)
	{return r1.x*r2.y-r2.x*r1.y;};
	friend poi operator - (const poi &r1,const poi &r2)
	{return poi(r1.x-r2.x,r1.y-r2.y);};
}a[N],st[N],b[N];
int xl[N],xr[N],yl[N],yr[N];
int onleft(poi p1,poi p2,poi p3)
{
	return ((p1-p2)^(p3-p2))>=0;
}
int check(int x,int y)
{
	for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
			if(xl[y+j]>x+i||xr[y+j]<x+i||yl[x+i]>y+j||yr[x+i]<y+j)
				return 0;
	return 1;
}
int main()
{
	//freopen("tt.in","r",stdin);
	memset(xl,0x3f,sizeof(xl));
	memset(yl,0x3f,sizeof(yl));
	while(scanf("%d%d",&n,&m)!=EOF&&n)
	{		
		top=0;cnt=0;
		for(int i=1,x,y;i<=m;i++)
		{
			scanf("%d%d",&x,&y);b[i]=poi(x,y);
			xl[y]=min(xl[y],x);xr[y]=max(xr[y],x);
			yl[x]=min(yl[x],y);yr[x]=max(yr[x],y);
		}
		for(int i=1;i<=m;i++)	
			for(int j=0;j<=1;j++)
				for(int k=0;k<=1;k++)
					if(check(b[i].x-j,b[i].y-k))
						a[++cnt]=poi(b[i].x-j,b[i].y-k);

		sort(a+1,a+1+cnt);
		cnt=unique(a+1,a+1+cnt)-a-1;
		for(int i=1;i<=cnt;i++)
		{
			while(top>=2&&onleft(st[top],st[top-1],a[i]))
				top--;
			st[++top]=a[i];
		}
		int t=top;
		for(int i=cnt-1;i>=1;i--)
		{
			while(top>t&&onleft(st[top],st[top-1],a[i]))
				top--;
			st[++top]=a[i];
		}
		printf("%d\n",top-1);
		for(int i=1;i<top;i++)
			printf("%d %d\n",st[i].x,st[i].y);
		for(int i=1,x,y;i<=m;i++)
		{
			x=b[i].x;y=b[i].y;
			xl[y]=1<<30;xr[y]=0;
			yl[x]=1<<30;yr[x]=0;
		}
	}	
	return 0;
}