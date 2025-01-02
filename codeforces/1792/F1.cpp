// LUOGU_RID: 160086470
#include<bits/stdc++.h>
#define N 5005
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
const int inf=1e9,mod=998244353;
const ll INF=2e18;
bool Memory_Begin;
namespace IO{const int SIZE=(1<<21)+1;char ibuf[SIZE],*iS,*iT,obuf[SIZE],*oS=obuf,*oT=oS+SIZE-1,c,qu[55];int f,qr;inline void flush(){fwrite(obuf,1,oS-obuf,stdout),oS=obuf,fflush(stdout);}inline void putc(char x){*oS++=x;if(oS==oT)flush();}template <class I>inline void read(I &x){for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;}template <class I>inline void print(I x){if(!x)putc('0');if(x<0)putc('-'),x=-x;while(x)qu[++qr]=x%10+'0',x/=10;while(qr)putc(qu[qr --]);}inline void reads(string &s){s.clear();for(c=gc();c<33||c>126;)c=gc();for(;c>=33&&c<=126;c=gc())s.push_back(c);}inline void prints(string s){for(char c:s)putc(c);}struct Flusher_ {~Flusher_(){flush();}}io_flusher_;}
using IO::read;using IO::putc;using IO::print;using IO::reads;using IO::prints;
template<class I>I updiv(I x,I y){return (x%y==0?x/y:x/y+1);}
template<class I>bool cmin(I &x,I y){if(x>y)return x=y,1;return 0;}
template<class I>bool cmax(I &x,I y){if(x<y)return x=y,1;return 0;}

int n,C[N][N],f[N],g[N];
void init()
{
	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
}
bool Memory_End;
signed main()
{
#ifdef CHECK_MEMORY
	cerr<<"Memory: "<<(&Memory_End-&Memory_Begin)/1048576.0<<" MiB\n";
#endif
	read(n);
	init();
	f[1]=g[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++) g[i]=(g[i]+(ll)g[j]*f[i-j]%mod*C[i-1][j-1]%mod)%mod;
		f[i]=g[i]*2%mod;
	}
	print((f[n]-2+mod)%mod);
	return 0;
}