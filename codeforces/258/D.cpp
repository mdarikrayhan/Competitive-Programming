// LUOGU_RID: 160458898
//蒟蒻一枚 rp++
//即得易见平凡，仿照上例显然。留作习题答案略，读者自证不难
//反之亦然同理，推论自然成立，略去过程Q.E.D.，由上可知证毕
#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define re register
#define il inline
#define gc() getchar()
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define tep(i,x) for(int i=head[x];~i;i=ne[i])
#define ls(x) x<<1
#define rs(x) x<<1|1
#define mid ((l+r)>>1)
#define eps (1e-9)
#define inf 0x3f3f3f3f
#define INF 1e16
#define pii pair<int,int>
#define mp(i,j) make_pair(i,j)
#define pb push_back
#define fi first
#define sc second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
namespace IO{
	template<typename T> inline void read(T &x){
		bool f=1;x=0;char ch=gc();
		while(ch<'0'||ch>'9'){if(ch=='-')f=0;ch=gc();}
		while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch&15),ch=gc();
		x=f?x:-x;
	}
	template<typename T> inline void write(T x){
		if(x<0) putchar('-'),x=-x;
	   	if(x>9) write(x/10);
	   	putchar(char('0'+x%10));
	}
	template <typename T,typename ...Args> inline
	void read(T &x,Args &...args){read(x);read(args...);}
	template<typename T> inline void write(T x,char c){write(x),putchar(c);}
}
using namespace IO;
//bool _ST;
const int N=1005;
int n,q,a[N];
double f[N][N];

//bool _ED;
signed main(){
	//fprintf(stderr,"%.20lf MB\n",(&_ST-&_ED)/1048576.0);
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n,q);
	rep(i,1,n) read(a[i]);
	rep(i,1,n) rep(j,1,n) f[i][j]=(a[i]<a[j])?1:0;
	rep(_,1,q){
		int l,r;
		read(l,r);
		f[l][r]=f[r][l]=(f[l][r]+f[r][l])/2.0;
		rep(i,1,n) if(i!=l&&i!=r) f[l][i]=f[r][i]=(f[l][i]+f[r][i])/2.0,f[i][l]=f[i][r]=(f[i][l]+f[i][r])*0.5;
	}
	double ans=0;
	rep(i,1,n){
		rep(j,1,i-1) ans=(ans+f[i][j]);
	}
	printf("%.10lf",ans);
	//fprintf(stderr,"%.4lf s\n",1.0*clock()/CLOCKS_PER_SEC);
	return 0;
}
//谨记:
//十年OI一场空，不开longlong见祖宗
//数据千万条，清空第一条。多测不清空，爆零两行泪。清空不规范，TLE总相伴。
//快读要加类型名

