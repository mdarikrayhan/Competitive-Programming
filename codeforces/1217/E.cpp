// LUOGU_RID: 160458888
#include<bits/stdc++.h>
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define ll long long
#define lll __int128
#define fi first
#define se second
#define e emplace
#define eb emplace_back
#define db double
#define ef emplace_front
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vp vector<pii>
#define mp make_pair

//#define LOCALJUDGE
#define int ll
bool ST;
static const ll MOD=998244353,Phi=998244352,inv2=499122177,Root=3,iRoot=332748118;
static const ll inf=1e9,INF=4557430888798830399;
static const double eps=1e-8,pi=3.1415926535;
char in[1<<20],*p1=in,*p2=in;
using namespace std;
//#define getchar() (p1==p2&&(p2=(p1=in)+fread(in,1,1<<20,stdin),p1==p2)?EOF:*p1++)
struct tup{int x,y,z;tup(int X=0,int Y=0,int Z=0){x=X,y=Y,z=Z;}};
namespace FastIO
{
	template<typename T> inline void write(T x,char ch=' ')
	{
		if(is_same<char,T>::value)putchar(x);
		else
		{
			if(x<0)x=-x,putchar('-');
			static char st[25];int top=0;
			do{st[top++]=x%10+'0',x/=10;}while(x);
			while(top)putchar(st[--top]);
		}
		ch!='~'?putchar(ch):0;
	}
	inline void write(const char*x,char ch=' ')
	{
		for(int i=0;x[i]!='\0';++i)putchar(x[i]);
		ch!='~'?putchar(ch):0;
	}
	inline void read(char&s){do s=getchar();while(s=='\n'||s==' ');}
	inline void read(char s[])
	{
		int len=0;char st;
		do st=getchar();while(st=='\n'||st==' ');
		s[++len]=st,st=getchar();
		while(st!='\n'&&st!=' ')s[++len]=st,st=getchar();
		s[++len]='\0';
	}
	template<typename T> inline void read(T &s)
	{
		s=0;char ch=getchar();
		while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
		bool tf=(ch=='-')&&(ch=getchar());
		while((ch>='0')&&(ch<='9'))s=(s<<1)+(s<<3)+ch-'0',ch=getchar();
		s=(tf?-s:s);
	}
	template<typename T1,typename T2> inline void read(pair<T1,T2> &s){read(s.fi),read(s.se);}
	template<typename T,typename...Args> inline void write(T x,Args...args){write(x,'~'),write(args...);}
	template<typename T,typename...Args> inline void read(T&x,Args&...args){read(x),read(args...);}
}
using namespace FastIO;
namespace MTool
{
	inline int Cadd(int a,int b){return (ll)a+b>=MOD?(ll)a+b-MOD:a+b;}
	inline int Cdel(int a,int b){return a-b<0?a-b+MOD:a-b;}
	inline int Cmul(int a,int b){return 1ll*a*b%MOD;}
	inline int sqr(int a){return 1ll*a*a%MOD;}
	inline void Madd(int&a,int b){a=((ll)a+b>=MOD?(ll)a+b-MOD:a+b);}
	inline void Mdel(int&a,int b){a=(a-b<0?a-b+MOD:a-b);}
	inline void Mmul(int&a,int b){a=1ll*a*b%MOD;}
	template<typename T> inline bool Mmax(T&a,T b){return a<b?a=b,1:0;}
	template<typename T> inline bool Mmin(T&a,T b){return a>b?a=b,1:0;}
	template<typename...Args> inline void Madd(int&a,int b,Args...args){Madd(a,b),Madd(a,args...);}
	template<typename...Args> inline void Mmul(int&a,int b,Args...args){Mmul(a,b),Mmul(a,args...);}
	template<typename...Args> inline void Mdel(int&a,int b,Args...args){Mdel(a,b),Mdel(a,args...);}
	template<typename...Args> inline int Cadd(int a,int b,Args...args){return Cadd(Cadd(a,b),args...);}
	template<typename...Args> inline int Cmul(int a,int b,Args...args){return Cmul(Cmul(a,b),args...);}
	template<typename...Args> inline int Cdel(int a,int b,Args...args){return Cdel(Cdel(a,b),args...);}
	template<typename...Args,typename T> inline bool Mmax(T&a,T b,Args...args){return Mmax(a,b)|Mmax(a,args...);}
	template<typename...Args,typename T> inline bool Mmin(T&a,T b,Args...args){return Mmin(a,b)|Mmin(a,args...);}
	inline int power(int x,int y){int s=1;for(;y;y>>=1,Mmul(x,x))if(y&1)Mmul(s,x);return s;}
}
using namespace MTool;
namespace WrongAnswer_90
{
	int n,m,a[200010];
	inline pii add(pii p1,pii p2)
	{
		pii p3=p1;Mmin(p3.se,p1.fi+p2.fi,p2.se);
		Mmin(p3.fi,p2.fi);
		return p3;
	}
	pii v[10];
	namespace Segment
	{
		#define ls(p) (t[p].l+t[p].r)
		#define rs(p) (ls(p)^1)
		struct{int l,r;pii v[10];}t[400010];
		void build(int p,int l,int r)
		{
			t[p].l=l,t[p].r=r;
			if(l==r)
			{
				int y=a[l];
				for(int i=0;i<10;y/=10,++i)
				{
					if(y%10)t[p].v[i]=mp(a[l],INF*2);
					else t[p].v[i]=mp(INF,INF*2);
				}
				return;
			}
			int mid=l+((r-l)>>1);
			build(ls(p),l,mid),build(rs(p),mid+1,r);
			for(int i=0;i<10;++i)t[p].v[i]=add(t[ls(p)].v[i],t[rs(p)].v[i]);
		}
		void change(int p,int x)
		{
			if(t[p].l==t[p].r)
			{
				int y=a[x];
				for(int i=0;i<10;y/=10,++i)
				{
					if(y%10)t[p].v[i]=mp(a[x],INF*2);
					else t[p].v[i]=mp(INF,INF*2);
				}
				return;
			}
			if(x<=t[ls(p)].r)change(ls(p),x);
			else change(rs(p),x);
			for(int i=0;i<10;++i)t[p].v[i]=add(t[ls(p)].v[i],t[rs(p)].v[i]);
		}
		void ask(int p,int l,int r)
		{
			if(l<=t[p].l&&r>=t[p].r)
			{
				for(int i=0;i<10;++i)v[i]=add(v[i],t[p].v[i]);
				return;
			}
			if(l<=t[ls(p)].r)ask(ls(p),l,r);
			if(r>t[ls(p)].r)ask(rs(p),l,r);
		}
		#undef ls
		#undef rs
	}
	using namespace Segment;
	inline void mian()
	{
		read(n,m);int opt,x,y;
		for(int i=1;i<=n;++i)read(a[i]);
		build(1,1,n);
		while(m--)
		{
			read(opt,x,y);
			if(opt==1)a[x]=y,change(1,x);
			else
			{
				for(int i=0;i<10;++i)v[i]=mp(INF,2*INF);
				ask(1,x,y);int ans=INF;
				for(int i=0;i<10;++i)Mmin(ans,v[i].se);
				if(ans>=INF)puts("-1");
				else write(ans,'\n');
			}
//			for(int i=0;i<9;++i)t[i].print(1),puts("");
//			puts("");
		}
	}
}
bool ED;
signed main()
{
	#ifdef LOCALJUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	#endif
	double st=clock();
	WrongAnswer_90::mian();
	double ed=clock();
	#ifndef LOCALJUDGE
 	cerr<<endl;
	#endif
 	cerr<<"Time: "<<ed-st<<" ms\n";
	#ifdef LOCALJUDGE
 	cerr<<"     ";
	#endif
 	cerr<<"Memory: "<<abs(&ST-&ED)/1024.0/1024.0<<" MB\n";
	return 0;
}
