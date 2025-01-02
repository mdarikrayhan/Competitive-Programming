#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

inline int read()
{
	int x,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=0;
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return f?x:-x;
}

#define MN 500000
#define N 524288
#define mp(x,y) make_pair(x,y)

struct vec
{
	int x,y,z;
	friend bool operator<(const vec&a,const vec&b)
		{return a.z||(!b.z&&1LL*a.x*b.y<1LL*a.y*b.x);}
	friend bool operator==(const vec&a,const vec&b){return 1LL*a.x*b.y==1LL*a.y*b.x;}
}l[MN+5],r[MN+5],c[MN+5],T[N*2+5];

priority_queue< pair<vec,int> > p[MN+5];
int cnt,u[MN+5],t[MN+5],x[MN+5],y[MN+5],lp[MN+5];

void change(int k,const vec&x){for(T[k+=N]=x;k>>=1;)T[k]=max(T[k<<1],T[k<<1|1]);}

vec query(int l,int r)
{
	vec res=(vec){0,0,1};
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)res=max(res,T[l+1]);
		if( r&1)res=max(res,T[r-1]);
	}
	return res;
}

void ins(int x)
{
	int k=lp[x]?lp[x]:lp[x]=lower_bound(c+1,c+cnt+1,l[x])-c;
	u[x]=0;p[k].push(mp(r[x],x));
	if(p[k].top()==mp(r[x],x))change(k,r[x]);
}

void del(int x)
{
	int k=lp[x]?lp[x]:lp[x]=lower_bound(c+1,c+cnt+1,l[x])-c,s=0;
	for(u[x]=1;u[p[k].top().second];++s)p[k].pop();
	if(s)change(k,p[k].top().first);
}

int main()
{
	int R=read(),n=read(),i,k;
	for(i=1;i<=n;++i)
	{
		t[i]=read();x[i]=read();if(t[i]!=2)y[i]=read();
		if(t[i]==1)++cnt,c[cnt]=l[cnt]=(vec){x[i]+R,y[i]},r[cnt]=(vec){y[i],R-x[i]},x[i]=cnt;
	}
    
	sort(c+1,c+cnt+1);cnt=unique(c+1,c+cnt+1)-c-1;
    
	for(i=1;i<2*N;++i)T[i]=(vec){0,0,1};
    
	for(i=1;i<=cnt;++i)p[i].push(mp(T[1],0));
    
	for(i=1;i<=n;++i)
	{
		if(t[i]==1)ins(x[i]);
		if(t[i]==2)del(x[i]);
		if(t[i]==3)
		{
			if(l[y[i]]<l[x[i]])swap(x[i],y[i]);
			if(r[x[i]]<l[y[i]]){puts("NO");continue;}
			k=lp[y[i]]?lp[y[i]]:lp[y[i]]=lower_bound(c+1,c+cnt+1,l[y[i]])-c;
			del(x[i]);del(y[i]);
			puts(query(1,k)<(r[x[i]]<r[y[i]]?r[x[i]]:r[y[i]])?"YES":"NO");
			ins(x[i]);ins(y[i]);
		}
	}
}/*1697122666.947903*/