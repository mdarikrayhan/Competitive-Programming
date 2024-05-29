#include<iostream>
#include<iomanip>
#include<cmath>
#include<ctime>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<climits>
//#define NDEBUG
#include<cassert>
#include<cstring>
#include<complex>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<bitset>
//#define LL __int128
#define LL long long
#define uint unsigned int
#define ULL unsigned LL
//#define int LL
//#define double long double
#define mkp make_pair
#define par pair<int,int>
#define psb push_back
#define epb emplace_back
#define f(x) ((x).first)
#define s(x) ((x).second)
using namespace std;
#define Lbt(x) ((x)&(-(x)))
#define Swap(x,y) (x^=y^=x^=y)
const int Mxxx=1e5;
inline char gc()
{
	static char buf[Mxxx],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxxx,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool fl=false)
{
	static char buf[Mxxx],*p1=buf,*p2=buf+Mxxx;
	return (fl||((*p1++=ch)&&p1==p2))&&(fwrite(buf,1,p1-buf,stdout),p1=buf),0;
}
//#define gc getchar
//#define pc(x,y) y?0:(putchar(x),0)
#define output pc('!',true)
inline int read()
{
	char ch=gc();
	int gans=0,gflag=0;
	for(;ch<'0'||'9'<ch;gflag|=ch=='-',ch=gc());
	for(;'0'<=ch&&ch<='9';gans=(gans<<1)+(gans<<3)+(ch^48),ch=gc());
	return gflag?-gans:gans;
}
template<typename T>
inline char read(T&gans)
{
	char ch=gc();
	int gflag=0;gans=0;
	for(;ch<'0'||'9'<ch;gflag|=ch=='-',ch=gc());
	for(;'0'<=ch&&ch<='9';gans=(gans<<1)+(gans<<3)+(ch^48),ch=gc());
	return gans=gflag?-gans:gans,ch;
}
template<typename T>
inline void write(T x)
{
	if(x>9)write(x/10);
	pc(x%10^48);
}
template<typename T>
inline void writenum(T x,char ch)
{
	if(x<0)pc('-'),x=-x;
	write(x);pc(ch);
}
inline void writechar(char x,char ch)
{
	pc(x);pc(ch);
}
template<typename T>
inline T Max(T x,T y)
{
	return x>y?x:y;
}
template<typename T>
inline T Min(T x,T y)
{
	return x<y?x:y;
}
template<typename T>
inline T Abs(T x)
{
	return x<0?-x:x;
}
template<typename T>
inline void ckmx(T&x,T y)
{
	x=Max(x,y);
}
template<typename T>
inline void ckmn(T&x,T y)
{
	x=Min(x,y);
}
namespace tre
{
	const int Mx=1<<19;
	int N,mn[Mx+5];
	inline void Bld(int x,int*p)
	{
		int i;for(N=1;N<x;N<<=1);
		for(i=0;i<=N;i++)mn[N+i]=INT_MAX;
		for(i=1;i<x;i++)mn[N+i]=p[i];
		for(i=N-1;i;i--)mn[i]=Min(mn[i<<1],mn[i<<1|1]);
	}
	inline int Ask(int l,int r)
	{
		int p=0;
		for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
		{
			if(!(l&1))if(!p||mn[p]>mn[l|1])p=l|1;
			if(r&1)if(!p||mn[p]>mn[r^1])p=r^1;
		}
		for(;p<N;)
		{
			if(mn[p<<1]==mn[p])p=p<<1;
			else p=p<<1|1;
		}return p-N;
	}
}
namespace tr
{
	const int Mx=5e7;
	int cnt,ls[Mx+5],rs[Mx+5],tt[Mx+5];
	#define L ls[k],l,mid
	#define R rs[k],mid+1,r
	inline void Ins(int&k,int l,int r,int x)
	{
//		int p=k;k=++cnt;tt[k]=tt[p]+v;
//		ls[k]=ls[p];rs[k]=rs[p];
		assert(!k);if(!k)k=++cnt;
		tt[k]++;assert(cnt<=Mx);
		if(l==r)return;
		int mid=(l+r)>>1;
		if(x<=mid)Ins(L,x);
		else Ins(R,x);
	}
	inline void Add(int&k,int l,int r,int x,int v)
	{
//		int p=k;k=++cnt;tt[k]=tt[p]+v;
//		ls[k]=ls[p];rs[k]=rs[p];
		if(!k)k=++cnt;
		tt[k]+=v;assert(cnt<=Mx);
		if(l==r)return;
		int mid=(l+r)>>1;
		if(x<=mid)Add(L,x,v);
		else Add(R,x,v);
	}
	inline int Mrg(int x,int y)
	{
		if(!x||!y)return x|y;
		int p=++cnt;
		assert(cnt<=Mx);
		ls[p]=Mrg(ls[x],ls[y]);
		rs[p]=Mrg(rs[x],rs[y]);
		tt[p]=tt[x]+tt[y];
		return p;
	}
	inline int Ask(int k,int l,int r,int x,int y)
	{
		if(!k)return 0;
		if(x<=l&&r<=y)return tt[k];
		int t=0,mid=(l+r)>>1;
		if(x<=mid)t+=Ask(L,x,y);
		if(mid<y)t+=Ask(R,x,y);
		return t;
	}
	inline LL Slv(int k,int l,int r,int f,int x,int y,int rt)
	{
		if(!k)return 0;
//		if(l==r)cout<<"Slv:"<<l<<" "<<f<<":"<<(f?Ask(rt,x,y,l,y):Ask(rt,x,y,x,l))<<"\n";
		if(l==r)return f?Ask(rt,x,y,l,y):Ask(rt,x,y,x,l);
		int mid=(l+r)>>1;return Slv(L,f,x,y,rt)+Slv(R,f,x,y,rt);
	}
}
const int Mx=2e5;
int n,tot,fa[Mx+5],ls[Mx+5],rs[Mx+5],rt[Mx+5][2],sz[Mx+5][2];
int blg[Mx+5],typ[Mx+5],pos[Mx+5];LL ans,val[Mx+5];
inline int Bld(int l,int r,int f=0)
{
	if(l>r)return 0;
	int p=tre::Ask(l,r);fa[p]=f;
	ls[p]=Bld(l,p-1,p);
	if(!ls[p])
	{
		tot++;
		blg[tot-n+1]=p;
		typ[tot-n+1]=0;
		tr::Ins(rt[p][0],1,n,pos[tot-n+1]);
	}else rt[p][0]=tr::Mrg(rt[ls[p]][0],rt[ls[p]][1]);
	rs[p]=Bld(p+1,r,p);
	if(!rs[p])
	{
		tot++;
		blg[tot-n+1]=p;
		typ[tot-n+1]=1;
		tr::Ins(rt[p][1],1,n,pos[tot-n+1]);
	}else rt[p][1]=tr::Mrg(rt[rs[p]][0],rt[rs[p]][1]);
	if((sz[p][0]=tr::Ask(rt[p][0],1,n,1,n))<=(sz[p][1]=tr::Ask(rt[p][1],1,n,1,n)))
	val[p]=tr::Slv(rt[p][0],1,n,0,1,n,rt[p][1]);
	else val[p]=tr::Slv(rt[p][1],1,n,1,1,n,rt[p][0]);
//	cout<<"Bld:"<<p<<" "<<l<<"_"<<r<<" "<<f<<":"<<sz[p][0]<<"_"<<sz[p][1]<<"|"<<val[p]<<" "<<(LL)sz[p][0]*sz[p][1]<<"|"<<ans<<"\n";
	return ans+=Min(val[p],(LL)sz[p][0]*sz[p][1]-val[p]),p;
}
int rtt[Mx+5][2];
inline void Cng(int p,int f,int v1,int v2)
{
	if(!p)return;
//	cout<<"Cng-:"<<p<<" "<<f<<"|v|"<<v1<<" "<<v2<<":"<<sz[p][0]<<" "<<sz[p][1]<<":"<<val[p]<<" "<<(LL)sz[p][0]*sz[p][1]<<"|"<<ans<<"\n";
	ans-=Min(val[p],(LL)sz[p][0]*sz[p][1]-val[p]);
	if(!f)
	{
		val[p]-=tr::Ask(rt[p][1],1,n,1,v2)+tr::Ask(rtt[p][1],1,n,1,v2);
		val[p]+=tr::Ask(rt[p][1],1,n,1,v1)+tr::Ask(rtt[p][1],1,n,1,v1);
		tr::Add(rtt[p][0],1,n,v1,1);
		tr::Add(rtt[p][0],1,n,v2,-1);
	}
	else
	{
//		cout<<"Ask-:"<<v2<<":"<<tr::Ask(rt[p][0],1,n,v2,n)<<"\n";
		val[p]-=tr::Ask(rt[p][0],1,n,v2,n)+tr::Ask(rtt[p][0],1,n,v2,n);
//		cout<<"Ask+:"<<v1<<":"<<tr::Ask(rt[p][0],1,n,v1,n)<<"\n";
		val[p]+=tr::Ask(rt[p][0],1,n,v1,n)+tr::Ask(rtt[p][0],1,n,v1,n);
		tr::Add(rtt[p][1],1,n,v1,1);
		tr::Add(rtt[p][1],1,n,v2,-1);
	}
//	cout<<"Cng+:"<<p<<" "<<f<<"|v|"<<v1<<" "<<v2<<":"<<sz[p][0]<<" "<<sz[p][1]<<":"<<val[p]<<" "<<(LL)sz[p][0]*sz[p][1]<<"|"<<ans<<"\n";
	ans+=Min(val[p],(LL)sz[p][0]*sz[p][1]-val[p]);
	f=fa[p];Cng(f,rs[f]==p,v1,v2);
}
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	#endif
	static int Q,wt[Mx+5];
	int i,x,y,vx,vy;n=read();
	for(i=1;i<=n;i++)pos[i]=read();
	for(i=1;i<n;i++)wt[i]=read();
	tre::Bld(n,wt);Bld(1,tot=n-1);
//	cerr<<"ans:"<<ans<<"\n";
//	for(i=1;i<=n;i++)cerr<<"blg/typ:"<<i<<":"<<blg[i]<<" "<<typ[i]<<"\n";;
	int ttt=0;
	for(Q=read();Q;Q--)
	{
		x=read();y=read();if(x==y){writenum(ans,10);continue;}vx=pos[x],vy=pos[y];
		Cng(blg[x],typ[x],vy,vx);Cng(blg[y],typ[y],vx,vy);Swap(pos[x],pos[y]);
		writenum(ans,10);
//		if(n==50000&&(++ttt)==6750)return output;
	}
	return output;
}
/*
3
3 2 1
2 1
3
1 3
3 2
3 1
*/
/*
5
4 3 2 5 1
3 2 1 4
7
5 4
5 2
1 5
2 4
2 4
4 3
3 3
*/
/*
10
1 9 8 5 3 2 7 6 10 4
4 3 9 6 8 1 5 2 7
0
*/
/*
10
4 8 6 9 10 7 1 2 3 5
4 6 9 3 8 1 5 7 2
1
8 4
*/
/*
10
7 4 1 6 8 5 3 10 9 2
9 1 6 5 3 7 8 4 2
16
6 7
9 6
6 4
3 9
3 2
6 9
1 9
7 1
8 8
7 7
2 4
5 9
9 3
5 2
5 10
8 1
*/