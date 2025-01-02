// LUOGU_RID: 160003346
#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x)
{
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
template <typename T,typename ...Args>void read(T &x,Args&...args){read(x),read(args...);}
template <typename T> void print(T x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) print(x/10);
	putchar(x%10+48);
}
template <typename T> void print(T x,char c){print(x); putchar(c);}
template<typename T>inline void output(T x){print(x,' ');}
template<typename T,typename ...Arg>inline void output(T x,Arg ...arg){output(x);output(arg...);}
const int N=2000007;
const int root=3,mod=998244353;
namespace poly
{
	#define ll long long
	int g[23][N],len,rev[N],A[N],B[N],C[N];
	int fpow(int x,int y)
	{
		int res=1;
		while(y)
		{
			if(y&1) res=(ll)res*x%mod;
			y>>=1; x=(ll)x*x%mod;
		}
		return res;
	}
	void prework()
	{
		for(int i=1;i<23;i++)
		{
			g[i][0]=1; g[i][1]=fpow(root,(mod-1)>>i);
			for(int j=2;j<N;j++)
				g[i][j]=(ll)g[i][j-1]*g[i][1]%mod;
		}
	}
	void makerev()
	{
		int lg=-1; while((1<<(lg+1))!=len) lg++;
		for(int i=0;i<len;i++)
			rev[i]=rev[i>>1]>>1|(i&1)<<lg;
	}
	void NTT(int *F,int typ)
	{
		for(int i=0;i<len;i++)
			if(i<rev[i]) swap(F[i],F[rev[i]]);
		for(int i=2,ii=1,t=1;i<=len;i<<=1,ii<<=1,t++)
			for(int j=0;j<len;j+=i)
				for(int k=0;k<ii;k++)
				{
					int tt=(ll)F[j+k+ii]*g[t][k]%mod;
					F[j+k+ii]=(F[j+k]-tt+mod)%mod;
					F[j+k]=(F[j+k]+tt)%mod;
				}
		if(typ==-1)
		{
			reverse(F+1,F+len);
			int inv=fpow(len,mod-2);
			for(int i=0;i<len;i++)
				F[i]=1ll*F[i]*inv%mod;
		}
	}
	void Mul(int n,int m,int *f,int *g,int *h)
	{
		len=1; while(len<=max(n,m)<<1) len<<=1;
		makerev();
		for(int i=0;i<n;i++) A[i]=f[i];
		for(int i=n;i<len;i++) A[i]=0;
		for(int i=0;i<m;i++) B[i]=g[i];
		for(int i=m;i<len;i++) B[i]=0;
		NTT(A,1); NTT(B,1);
		for(int i=0;i<len;i++) h[i]=(ll)A[i]*B[i]%mod;
		NTT(h,-1);
	}
	void Mul(int n,int m,vector<int>&f,vector<int>&g,vector<int>&h)
	{
		len=1; while(len<=max(n,m)<<1) len<<=1;
		makerev();
		for(int i=0;i<n;i++) A[i]=f[i];
		for(int i=n;i<len;i++) A[i]=0;
		for(int i=0;i<m;i++) B[i]=g[i];
		for(int i=m;i<len;i++) B[i]=0;
		NTT(A,1); NTT(B,1);
		for(int i=0;i<len;i++) C[i]=(ll)A[i]*B[i]%mod;
		NTT(C,-1); for(int i=0;i<n+m-1;i++) h[i]=C[i];
	}
	// #undef ll
}
using poly::fpow;
int n,a,b,fct[N],inv[N];
int _C(int x,int y){return (ll)fct[x]*inv[y]%mod*inv[x-y]%mod;}
vector<int>solve(int l,int r)
{
	if(l>r) return {1};
	if(l==r) return {l,1};
	int mid=(l+r)>>1;
	auto resl=solve(l,mid);
	auto resr=solve(mid+1,r);
	int n=resl.size(),m=resr.size();
	vector<int>res(n+m-1);
	poly::Mul(n,m,resl,resr,res);
	return res;
}
int main()
{
	read(n,a,b); poly::prework();
	fct[0]=inv[0]=1;
	for(int i=1;i<N;i++)
		fct[i]=(ll)fct[i-1]*i%mod,
		inv[i]=fpow(fct[i],mod-2);
	auto res=solve(0,n-2);
	if(a+b-1>n) return puts("0"),0;
	print((ll)res[a+b-2]*_C(a+b-2,a-1)%mod,'\n');
	return 0;
}