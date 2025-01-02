// LUOGU_RID: 159043665
#include<bits/stdc++.h>
#define N 100005
//#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,SIZE,stdin),(iS==iT?EOF:*iS++)):*iS++)
#define gc() getchar()
#define fi first
#define se second
//#define CHECK_MEMORY ___JQH___
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf=1e9;
const ll INF=2e18;
bool Memory_Begin;
namespace IO{const int SIZE=(1<<21)+1;char ibuf[SIZE],*iS,*iT,obuf[SIZE],*oS=obuf,*oT=oS+SIZE-1,c,qu[55];int f,qr;inline void flush(){fwrite(obuf,1,oS-obuf,stdout),oS=obuf,fflush(stdout);}inline void putc(char x){*oS++=x;if(oS==oT)flush();}template <class I>inline void read(I &x){for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;}template <class I>inline void print(I x){if(!x)putc('0');if(x<0)putc('-'),x=-x;while(x)qu[++qr]=x%10+'0',x/=10;while(qr)putc(qu[qr --]);}inline void reads(string &s){s.clear();for(c=gc();c<33||c>126;)c=gc();for(;c>=33&&c<=126;c=gc())s.push_back(c);}inline void prints(string s){for(char c:s)putc(c);}struct Flusher_ {~Flusher_(){flush();}}io_flusher_;}
using IO::read;using IO::putc;using IO::print;using IO::reads;using IO::prints;
template<class I>I updiv(I x,I y){return (x%y==0?x/y:x/y+1);}
template<class I>bool cmin(I &x,I y){if(x>y)return x=y,1;return 0;}
template<class I>bool cmax(I &x,I y){if(x<y)return x=y,1;return 0;}

int n,q,ans[N];
vector<pii>e[N*50];
struct Ayaka{string op;ll x,y;}a[N];	
#define leaf(x) (!ls[x]&&!rs[x])
int tot=1,ls[N*50],rs[N*50],ti[N*50];
void insert(int v,ll l,ll r,ll L,ll R,int x)
{
	if(L<=l&&r<=R) return ti[v]=x,void();
	ll mid=(l+r)/2;
	if(!ls[v]) ls[v]=++tot;
	if(!rs[v]) rs[v]=++tot;
	if(ti[v]) ti[ls[v]]=ti[rs[v]]=ti[v],ti[v]=0;
	if(mid>=R) insert(ls[v],l,mid,L,R,x);
	else if(mid<L) insert(rs[v],mid+1,r,L,R,x);
	else insert(ls[v],l,mid,L,R,x),insert(rs[v],mid+1,r,L,R,x);
}
void connect(int x,int y)
{
	if(leaf(x)&&leaf(y)) return e[min(ti[x],ti[y])].push_back({x,y});
	else if(leaf(x)) return connect(x,ls[y]),connect(x,rs[y]);
	else if(leaf(y)) return connect(ls[x],y),connect(rs[x],y);
	else return connect(ls[x],ls[y]),connect(rs[x],rs[y]);
}
int getpos(int v,ll l,ll r,ll pos)
{
	if(leaf(v)) return v;
	ll mid=(l+r)/2;
	if(mid>=pos) return getpos(ls[v],l,mid,pos);
	else return getpos(rs[v],mid+1,r,pos);
}
int prt[N*50];
int getf(int x){return prt[x]==x?x:prt[x]=getf(prt[x]);}
void merge(int x,int y)
{
	x=getf(x),y=getf(y);
	if(x!=y) prt[x]=y;
}
bool Memory_End;
signed main()
{
#ifdef CHECK_MEMORY
	cerr<<"Memory: "<<(&Memory_End-&Memory_Begin)/1048576.0<<" MiB\n";
#endif
	read(n),read(q);
	ll m=(1ll<<n)-1;
	ti[1]=q+1;
	for(int i=1;i<=q;i++)
	{
		reads(a[i].op),read(a[i].x),read(a[i].y);
		if(a[i].op[0]=='b') insert(1,0,m,a[i].x,a[i].y,i);
	}
	for(int i=1;i<=tot;i++)
	{
		prt[i]=i;
		if(!leaf(i)) connect(ls[i],rs[i]);
	}
	
	for(int i=q+1;i>=1;i--)
	{
		for(pii p:e[i]) merge(p.fi,p.se);
		if(a[i].op[0]=='a') ans[i]=(getf(getpos(1,0,m,a[i].x))==getf(getpos(1,0,m,a[i].y)));
	}
	for(int i=1;i<=q;i++)
		if(a[i].op[0]=='a') print(ans[i]),putc('\n');
	return 0;
}