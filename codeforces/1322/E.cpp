// This code wrote by chtholly_micromaker(MicroMaker)
#include <bits/stdc++.h>
#define reg register
#define ALL(x) (x).begin(),(x).end()
#define mem(x,y) memset(x,y,sizeof x)
#define ln putchar('\n')
#define lsp putchar(32)
#define pb push_back
#define MP std::make_pair
#define dbg(x) std::cerr<<__func__<<"\tLine:"<<__LINE__<<' '<<#x<<": "<<x<<"\n"
#define dprintf(x...) std::fprintf(stderr,x)
typedef std::pair<int,int> pii;
template <class t> inline void read(t &s)
{
	s=0;
	reg int f=0;
	reg char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))s=(s<<3)+(s<<1)+(c^48),c=getchar();
	if(f)s=-s;
}
template <class t> inline void write(t x)
{
	if(!x)return std::putchar('0'),void();
	if(x<0)std::putchar('-'),x=-x;
	static int buf[50],top=0;
	while(x)buf[++top]=x%10,x/=10;
	while(top)putchar(buf[top--]^'0');
}
inline void setIn(std::string s){freopen(s.c_str(),"r",stdin);return;}
inline void setOut(std::string s){freopen(s.c_str(),"w",stdout);return;}
inline void setIO(std::string s=""){setIn(s+".in");setOut(s+".out");return;}
template <class t>inline bool ckmin(t&x,t y){if(x>y)return x=y,1;return 0;}
template <class t>inline bool ckmax(t&x,t y){if(x<y)return x=y,1;return 0;}
inline int lowbit(int x){return x&(-x);}
const int MaxN=5e5+50;
int a[MaxN],n;
struct RMQ
{
	int CPOP,ps,inf; // 0 : min  1 : max
	inline int cmp(int x,int y){if(!CPOP)return x<y;return x>y;}
	inline int best(int x,int y){return cmp(x,y)?x:y;}
	inline int at(int x){return (!((x+ps)&1))?a[x]:inf;}
	int Q[MaxN],h,t,L,R;
	inline void init(int _a,int _b)
	{
		CPOP=_a,ps=_b;
		if(!CPOP)inf=2e9;else inf=-2e9;
		L=1,R=0;
	}
	inline int ask(int l,int r)
	{
		if(l>r)return inf;
		ckmax(L,l);
		while(R+1<=r-1)
		{
			++R;
			while(h<=t&&!cmp(at(Q[t]),at(R)))--t;
			Q[++t]=R;
		}
		while(h<=t&&Q[h]<L)++h;
		reg int res=inf;
		if(h<=t)res=at(Q[h]);
		return best(res,at(r));
	}
}mn0,mn1,mx0,mx1;
int far[MaxN],ans[MaxN];
inline int check(int mid,int k)
{
	if(mid-k<1||mid+k>n)return 0;
	if(a[mid-1]<a[mid]&&a[mid]>a[mid+1])
	{
		if(mid&1)return mx0.ask(mid-k,mid+k)<mn1.ask(mid-k,mid+k);
		return mx1.ask(mid-k,mid+k)<mn0.ask(mid-k,mid+k);
	}
	if(mid&1)return mn0.ask(mid-k,mid+k)>mx1.ask(mid-k,mid+k);
	return mn1.ask(mid-k,mid+k)>mx0.ask(mid-k,mid+k);
}
signed main(void)
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	mn0.init(0,0),mn1.init(0,1),mx0.init(1,0),mx1.init(1,1);
	far[1]=0,ans[1]=a[1],far[n]=0,ans[n]=a[n];
	for(int i=2;i<n;++i)
	{
		reg int k=far[i-1];
		if(check(i,k+1))++k;
		else if(!check(i,k))--k;
		if(a[i-1]<a[i]&&a[i]>a[i+1])
		{
			if(k&1)ans[i]=(((i+k)&1)?mx1:mx0).ask(i-k,i+k);
			else ans[i]=(((i+k)&1)?mn1:mn0).ask(i-k,i+k);
		}
		else if(a[i-1]>a[i]&&a[i]<a[i+1])
		{
			if(k&1)ans[i]=(((i+k)&1)?mn1:mn0).ask(i-k,i+k);
			else ans[i]=(((i+k)&1)?mx1:mx0).ask(i-k,i+k);
		}
		else ans[i]=a[i];
		far[i]=k;
	}
	write(*std::max_element(far+1,far+n+1)),ln;
	for(int i=1;i<=n;++i)write(ans[i]),lsp;ln;
	return 0;
}




