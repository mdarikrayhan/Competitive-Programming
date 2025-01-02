// LUOGU_RID: 160547048
#include<stdio.h>
#include<algorithm>
#include<set>
#define N 100009
using namespace std;
inline char nc()
{
	static char buf[99999],*l,*r;
	return l==r&&(r=(l=buf)+fread(buf,1,99999,stdin),l==r)?EOF:*l++;
}
inline void read(int&x)
{
	char c=nc();for(;c<'0'||'9'<c;c=nc());
	for(x=0;'0'<=c&&c<='9';x=(x<<3)+(x<<1)+(c^48),c=nc());
}
int n,m,l[N],r[N],d[N],sz,x,y;set<int>s;
struct node
{
	int a,b;
	inline bool operator<(const node&kkk)const
		{return a^kkk.a?a<kkk.a:b<kkk.b;}
}a[N];
main()
{
	read(n);read(m);
	for(int i=0;i<n;read(a[i].a),read(a[i++].b));a[n++]=(node){0,0};
	sort(a,a+n);
	for(int i=0;i<n;++i)if(s.size()&&*s.begin()-(y-x)<=a[i].a)
	{
		--i;int p=*s.begin()-(y-x),q=*s.begin();s.erase(s.begin());
		if(x<=p-1)l[sz]=x,r[sz]=p-1,d[sz++]=y-x;
		x=p;y=q+1;
	}
	else if(a[i].b-a[i].a>y-x)s.emplace(a[i].b);
	else if(a[i].a>=x)
	{
		int p=a[i].a,q=a[i].a+y-x;
		if(x<=p-1)l[sz]=x,r[sz]=p-1,d[sz++]=y-x;
		x=p+1;y=q;
		if(a[i].b-a[i].a>y-x)s.emplace(a[i].b);
	}
	for(;s.size();)
	{
		int p=*s.begin()-(y-x),q=*s.begin();s.erase(s.begin());
		if(x<=p-1)l[sz]=x,r[sz]=p-1,d[sz++]=y-x;
		x=p;y=q+1;
	}
	l[sz]=x;r[sz]=1<<30;d[sz++]=y-x;
	for(int x,y;m--;)
	{
		read(x);read(y);
		int i=lower_bound(a,a+n,(node){x,y})-a;
		if(i<n&&a[i].a==x&&a[i].b==y){printf("LOSE\n");continue;}
		i=lower_bound(r,r+sz,x)-r;
		if(l[i]<=x&&y-x==d[i]){printf("LOSE\n");continue;}
		printf("WIN\n");
	}
}