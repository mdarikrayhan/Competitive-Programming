// LUOGU_RID: 159155420
#include<bits/stdc++.h>
#define N 200005
//#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,SIZE,stdin),(iS==iT?EOF:*iS++)):*iS++)
#define gc() getchar()
#define fi first
#define se second
#define CHECK_MEMORY ___JQH___
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf=1e9;
const ll INF=2e18;
bool Memory_Begin;
//namespace IO{const int SIZE=(1<<21)+1;char ibuf[SIZE],*iS,*iT,obuf[SIZE],*oS=obuf,*oT=oS+SIZE-1,c,qu[55];int f,qr;inline void flush(){fwrite(obuf,1,oS-obuf,stdout),oS=obuf,fflush(stdout);}inline void putc(char x){*oS++=x;if(oS==oT)flush();}template <class I>inline void read(I &x){for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;}template <class I>inline void print(I x){if(!x)putc('0');if(x<0)putc('-'),x=-x;while(x)qu[++qr]=x%10+'0',x/=10;while(qr)putc(qu[qr --]);}inline void reads(string &s){s.clear();for(c=gc();c<33||c>126;)c=gc();for(;c>=33&&c<=126;c=gc())s.push_back(c);}inline void prints(string s){for(char c:s)putc(c);}struct Flusher_ {~Flusher_(){flush();}}io_flusher_;}
//using IO::read;using IO::putc;using IO::print;using IO::reads;using IO::prints;
template<class I>I updiv(I x,I y){return (x%y==0?x/y:x/y+1);}
template<class I>bool cmin(I &x,I y){if(x>y)return x=y,1;return 0;}
template<class I>bool cmax(I &x,I y){if(x<y)return x=y,1;return 0;}

int n,m,q,rt[N];
int tot;
pii a[N];
struct Ayaka
{
#define ls(p) t[p].ls
#define rs(p) t[p].rs
#define mx(p) t[p].mx
	ull mx:18,ls:23,rs:23;
}t[N*40];
int insert(int y,int l,int r,int L,int R)
{
	if(l==r) return y+1;
	int x=++tot;
	t[x]=t[y];
	if(L<=l&&r<=R)return mx(x)++,x;
	int mid=(l+r)/2,dt=mx(x)-max(l==mid?ls(x):mx(ls(x)),mid+1==r?rs(x):mx(rs(x)));
	if(L<=mid)ls(x)=insert(ls(y),l,mid,L,R);
	if(R>mid)rs(x)=insert(rs(y),mid+1,r,L,R);
	mx(x)=max(l==mid?ls(x):mx(ls(x)),mid+1==r?rs(x):mx(rs(x)))+dt;
	return x;
}
int ask(int x,int l,int r,int L,int R)
{
	if(l==r) return x;
	if(L<=l&&r<=R) return mx(x);
	int mid=(l+r)/2,dt=mx(x)-max(l==mid?ls(x):mx(ls(x)),mid+1==r?rs(x):mx(rs(x)));
	if(mid>=R) return ask(ls(x),l,mid,L,R)+dt;
	else if(mid<L) return ask(rs(x),mid+1,r,L,R)+dt;
	else return max(ask(ls(x),l,mid,L,R),ask(rs(x),mid+1,r,L,R))+dt;
}
bool cmp(pii x,pii y){return x.fi==y.fi?x.se<y.se:x.fi>y.fi;}
bool Memory_End;
signed main()
{
#ifdef CHECK_MEMORY
	cerr<<"Memory: "<<(&Memory_End-&Memory_Begin)/1048576.0<<" MiB\n";
#endif
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].fi,a[i].se=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		rt[i]=insert(rt[i-1],1,n-m+1,max(1,a[i].se-m+1),min(n-m+1,a[i].se));
	cin>>q;
	for(int las=0,l,r,x;q--;)
	{
		cin>>l>>r>>x,x^=las;
		int k=lower_bound(a+1,a+n+1,(pii){x,inf},cmp)-a-1;
		cout<<(las=m-ask(rt[k],1,n-m+1,l,r))<<'\n';
	}
	return 0;
}