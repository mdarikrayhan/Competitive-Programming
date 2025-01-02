#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2E5+10;
const int inf=1<<30;
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int l[N],r[N],a[N],b[N],c[N];
int d[N<<1],ans[N],cnt;
int u[N<<1],v[N<<1];
struct st
{
	int w,x,y,val,op;
	bool operator<(const st m)const
	{
		if(w!=m.w)return w<m.w;
		return val<m.val;
	}
}q[N*3];
void push(int *a,int w,int val)
{
	while(w<=cnt)
	{
		a[w]+=val;
		w+=w&-w;
	}
}
int ask(int *a,int w)
{
	int res=0;
	while(w)
	{
		res+=a[w];
		w-=w&-w;
	}
	return res;
}
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)l[i]=read();
	for(int i=1;i<=n;++i)r[i]=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=m;++i)b[i]=read();
	for(int i=1;i<=m;++i)c[i]=read();
	for(int i=1;i<=n;++i)
	{
		d[++cnt]=l[i]+a[i];
		d[++cnt]=a[i]-l[i]+1;
	}
	sort(d+1,d+1+cnt);
	cnt=unique(d+1,d+1+cnt)-d-1;
	int s=0;
	for(int i=1;i<=n;++i)
	{
		q[++s]={l[i],l[i],a[i],1,0};
		q[++s]={r[i]+1,l[i],a[i],-1,0};
	}
	for(int i=1;i<=m;++i)
	{
		q[++s]={b[i],b[i],c[i],2,i};
	}
	sort(q+1,q+1+s);
	for(int i=1;i<=s;++i)
	{
		if(q[i].op)
		{
			ans[q[i].op]+=ask(u,upper_bound(d+1,d+1+cnt,q[i].x+q[i].y)-d-1);
			ans[q[i].op]+=ask(v,upper_bound(d+1,d+1+cnt,q[i].y-q[i].x)-d-1);
		}
		else
		{
			push(u,lower_bound(d+1,d+1+cnt,q[i].x+q[i].y)-d,q[i].val);
			push(v,lower_bound(d+1,d+1+cnt,q[i].y-q[i].x+1)-d,-q[i].val);
		}
	}
	for(int i=1;i<=m;++i)
	{
		write(ans[i],' ');
	}
}
