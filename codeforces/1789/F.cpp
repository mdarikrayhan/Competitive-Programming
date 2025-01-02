// LUOGU_RID: 160531252
#include<bits/stdc++.h>
#define N 85
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

int n,ans;
string s;
namespace kleq3
{
	int f[N][N],g[N][N][N];
	int x,y;
	void dfs(int step)
	{
		if(step==n+1)
		{
			if(x)
			{
				memset(f,0,sizeof(f));
				for(int i=1;i<x;i++)
					for(int j=x;j<=n;j++)
						f[i][j]=max({f[i-1][j],f[i][j-1],f[i-1][j-1]+(s[i]==s[j])});
				cmax(ans,f[x-1][n]*2);
			}
			if(x&&y)
			{
				memset(g,0,sizeof(g));
				for(int i=1;i<x;i++)
					for(int j=x;j<y;j++)
						for(int k=y;k<=n;k++)
							g[i][j][k]=max({g[i-1][j][k],g[i][j-1][k],g[i][j][k-1],g[i][j-1][k-1],g[i-1][j][k-1],g[i-1][j-1][k],g[i-1][j-1][k-1]+(s[i]==s[j]&&s[j]==s[k])});
				cmax(ans,g[x-1][y-1][n]*3);
			}
			return ;
		}
		dfs(step+1);
		if(!x) x=step,dfs(step+1),x=0;
		else if(!y) y=step,dfs(step+1),y=0;
	}
}
namespace kgrq5
{
	string t;
	int m;
	void dfs(int step,int ed)
	{
		if(step==ed+1)
		{
			if(!m) return ;
			int res=0,now=1;
			for(int i=1;i<=n;i++)
			{
				if(s[i]==t[now]) now++;
				if(now==m+1) res++,now=1;
			}
			if(res>=2) cmax(ans,res*m);
			return ;
		}
		dfs(step+1,ed);
		t.push_back(s[step]),m++;
		dfs(step+1,ed);
		t.pop_back(),m--;
	}
	void solve()
	{
		t.push_back(' ');
		const int B=16;
		for(int i=1,j;i<=n;i=j+1)
		{
			j=min(n,i+B-1);
			dfs(i,j);
		}
	}
}
bool Memory_End;
signed main()
{
#ifdef CHECK_MEMORY
	cerr<<"Memory: "<<(&Memory_End-&Memory_Begin)/1048576.0<<" MiB\n";
#endif
	reads(s),n=s.length(),s=' '+s;
	kleq3::dfs(1);
	kgrq5::solve();
	print(ans);
	return 0;
}