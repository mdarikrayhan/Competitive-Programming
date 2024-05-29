// LUOGU_RID: 159874294
// created:  May/22/2024 19:51:41
#include<cstdio>
#include<cctype>
#include<algorithm>
#define F(i,l,r) for(int i=(l),i##_end=(r);i<i##_end;++i)
#define I128 //||is_same<T,__int128_t>::value||is_same<T,__uint128_t>::value
using namespace std;
template<typename T>enable_if_t<is_integral<T>::value I128,void> readmain(T &x)
{
	bool neg=false;int c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')neg=true;
	for(x=0;isdigit(c);c=getchar())x=(T)(10*x+(c-'0'));
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
typedef unsigned long long ull;
constexpr int N=1e5+5,MOD=998244353;
int qpow(ull a,int b)
{
	ull c=1;
	for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
	return (int)c;
}
int n,f[N],fac[2*N],invfac[2*N],ans;
int find(int x){return f[x]<0?x:f[x]=find(f[x]);}
int main()
{
	read(n);
	F(i,fac[0]=1,2*n+1)fac[i]=(int)((ull)fac[i-1]*i%MOD);
	invfac[2*n]=qpow(fac[2*n],MOD-2);
	for(int i=2*n;i;--i)invfac[i-1]=(int)((ull)invfac[i]*i%MOD);
	F(i,0,n)f[i]=-1;
	ans=(int)((ull)fac[2*n-2]*invfac[n-1]%MOD*qpow(2,MOD-n)%MOD);
	F(i,0,n-1)
	{
		int u,v;read(u,v);--u,--v;
		u=find(u);v=find(v);
		if(f[u]<f[v])swap(u,v);
		int p=(int)((ull)-f[u]*-f[v]%MOD);
		ans=(int)((ull)ans*p%MOD*p%MOD);
		f[v]+=f[u];f[u]=v;
	}
	printf("%d\n",ans);
	return 0;
}
