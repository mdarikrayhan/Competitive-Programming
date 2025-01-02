#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<bitset>
#include<set>
#include<unordered_map>
#include<random>
#include<chrono>
#include<deque>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define mp std::make_pair
#define ulf Useful_little_function
#define abs ccf
#define INF (0x3f3f3f3f)
#define INT_INF (2147483647)
#define LLINF (0x3f3f3f3f3f3f3f3fll)
#define LL_INF (9223372036854775807)
#define memset __builtin_memset
#define popcount __builtin_popcount
std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());
typedef long long ll;
typedef std::pair<int,int> pii;
typedef unsigned int uint;
typedef unsigned long long ull;
inline void file(){freopen(".in","r",stdin);freopen(".out","w",stdout);}
namespace IO{
    #define BUF_SIZE (1<<16)
    #define OUT_SIZE (1<<16)
    bool IOerror=0;
    inline char nc(){static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;if(p1==pend){p1=buf;pend=buf+fread(buf,1,BUF_SIZE,stdin);if(pend==p1)return IOerror=1,-1;}return *p1++;}
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){bool sign=0;char ch=nc();x=0;for(;blank(ch);ch=nc());if(IOerror)return;if(ch=='-')sign=1,ch=nc();for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';if(sign)x=-x;}
    inline void read(ll &x){bool sign=0;char ch=nc();x=0;for(;blank(ch);ch=nc());if(IOerror)return;if(ch=='-')sign=1,ch=nc();for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';if(sign)x=-x;}
    inline void read(double &x){bool sign=0;char ch=nc();x=0;for(;blank(ch);ch=nc());if(IOerror)return;if(ch=='-')sign=1,ch=nc();for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';if(ch=='.'){double tmp=1;ch=nc();for(;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');}if(sign)x=-x;}
    inline void read(char *s){char ch=nc();for(;blank(ch);ch=nc());if(IOerror)return;for(;!blank(ch)&&!IOerror;ch=nc())*s++=ch;*s=0;}
    inline void read(char &c){for(c=nc();blank(c);c=nc());if(IOerror){c=-1;return;}}
    struct Ostream_fwrite{
        char *buf,*p1,*pend;
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
        inline void out(char ch){if(p1==pend){fwrite(buf,1,BUF_SIZE,stdout);p1=buf;}*p1++=ch;}
        inline void print(int x){static char s[15],*s1;s1=s;if(!x)*s1++='0';if(x<0)out('-'),x=-x;while(x)*s1++=x%10+'0',x/=10;while(s1--!=s)out(*s1);}
        inline void println(int x){print(x);out('\n');}
        inline void print(ll x){static char s[25],*s1;s1=s;if(!x)*s1++='0';if(x<0)out('-'),x=-x;while(x)*s1++=x%10+'0',x/=10;while(s1--!=s)out(*s1);}
        inline void println(ll x){print(x);out('\n');}
        inline void print(double x,int y){//y<18
			static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
            if(x<-1e-12)out('-'),x=-x;x*=mul[y];ll x1=(ll)floor(x);if(x-floor(x)>=0.5)++x1;ll x2=x1/mul[y],x3=x1-x2*mul[y];print(x2);if(y>0){out('.');for(size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i);print(x3);}
        }
        inline void println(double x,int y){print(x,y);out('\n');}
        inline void print(char *s){while(*s)out(*s++);}
        inline void println(char *s){while(*s)out(*s++);out('\n');}
        inline void flush(){if(p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
        ~Ostream_fwrite(){flush();}
    }Ostream;
    inline void print(int x){Ostream.print(x);}
    inline void println(int x){Ostream.println(x);}
    inline void print(char x){Ostream.out(x);}
    inline void println(char x){Ostream.out(x);Ostream.out('\n');}
    inline void print(ll x){Ostream.print(x);}
    inline void println(ll x){Ostream.println(x);}
    inline void print(double x,int y){Ostream.print(x,y);}
    inline void println(double x,int y){Ostream.println(x,y);}
    inline void print(char *s){Ostream.print(s);}
    inline void println(char *s){Ostream.println(s);}
    inline void println(){Ostream.out('\n');}
    inline void flush(){Ostream.flush();}
    #undef OUT_SIZE
    #undef BUF_SIZE
}using namespace IO;
namespace Little_function{
	inline int abs(int x){return x<0?-x:x;}
	inline ll abs(ll x){return x<0?-x:x;}
	inline double abs(double x){return x<0?-x:x;}
	inline int max(const int &a,const int &b){return a>b?a:b;}
	inline ll max(const ll &a,const ll &b){return a>b?a:b;}
	inline double max(const double &a,const double &b){return a>b?a:b;}
	inline int min(const int &a,const int &b){return a<b?a:b;}
	inline ll min(const ll &a,const ll &b){return a<b?a:b;}
	inline double min(const double &a,const double &b){return a<b?a:b;}
	inline void chkmax(int &a,const int &b){if(b>a)a=b;}
	inline void chkmax(ll &a,const ll &b){if(b>a)a=b;}
	inline void chkmax(double &a,const double &b){if(b>a)a=b;}
	inline void chkmin(int &a,const int &b){if(b<a)a=b;}
	inline void chkmin(ll &a,const ll &b){if(b<a)a=b;}
	inline void chkmin(double &a,const double &b){if(b<a)a=b;}
	inline void swap(int &x,int &y){x^=y^=x^=y;}
	inline void swap(ll &x,ll &y){x^=y^=x^=y;}
	inline void swap(double &x,double &y){double t=x;x=y,y=t;}
	inline int madd(const int &a,const int &b,const int &p){return (a+b)%p;}
	inline int mdel(const int &a,const int &b,const int &p){return (a-b<0?a-b+p:a-b);}
	int gcd(int a,int b){return !b?a:gcd(b,a%b);}
	ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
}using namespace Little_function;
namespace modint{
	#define N 200005
	const int mod=1e9+7;
	int ni[N],mul[N],invmul[N];
	inline int md(const int &x){return x>=mod?x-mod:x;}
	inline int madd(const int &x,const int &y){return x+y<mod?x+y:x+y-mod;}
	inline int mdel(const int &x,const int &y){return x-y<0?x-y+mod:x-y;}
	inline void modadd(int &x,const int &y){x=(x+y<mod?x+y:x+y-mod);}
	inline void moddel(int &x,const int &y){x=(x-y<0?x-y+mod:x-y);}
	inline int qpow(int a,int k){int s=1;for(;k;k>>=1,a=(ll)a*a%mod)if(k&1)s=(ll)s*a%mod;return s;}
	inline void _init(int n){
		ni[1]=1;
		for(int i=2;i<=n;++i) ni[i]=mod-(ll)ni[mod%i]*(mod/i)%mod;
		mul[0]=invmul[0]=1;
		for(int i=1;i<=n;++i) mul[i]=(ll)mul[i-1]*i%mod;
		invmul[n]=qpow(mul[n],mod-2);
		for(int i=n-1;i;--i) invmul[i]=(ll)invmul[i+1]*(i+1)%mod;
	}
	inline int C(int n,int m){if(m>n)return 0;return (ll)mul[n]*invmul[m]%mod*invmul[n-m]%mod;}
	#undef N
}
const int N=2e5+13;
int n,a[N],b[N];
int main(){
	int q;
	read(n),read(q);
	ll sum=0;
	for(int i=1;i<=n;++i) read(a[i]),sum+=a[i];
	for(int i=1,flag=0,now=0;i<=q;++i){
		int op,x,y;
		read(op);
		if(op==1){
			read(x),read(y);
			if(b[x]<flag) sum-=now;
			else sum-=a[x];
			a[x]=y,sum+=y;
			b[x]=i;
		}
		else{
			read(x);
			sum=(ll)x*n,flag=i,now=x;
		}
		println(sum);
	}
	return 0;
}