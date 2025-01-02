// LUOGU_RID: 158547363
#include"bits/stdc++.h"
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
namespace fastio {
	const int MAXBUF = 1 << 23;
	char buf[MAXBUF], *p1 = buf, *p2 = buf;
	char pbuf[MAXBUF], *pp = pbuf;
	inline char getc() { return (p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, MAXBUF, stdin)), p1 == p2 ? EOF : *p1++; }
	inline void putc(char c) { (pp == pbuf + MAXBUF) && (fwrite(pbuf, 1, MAXBUF, stdout), pp = pbuf), *pp++ = c; }
	inline void print_final() { fwrite(pbuf, 1, pp - pbuf, stdout), pp = pbuf; }
}
#ifndef LocalTest
	using fastio::getc;
	using fastio::putc;
	using fastio::print_final;
#else
	#define getc getchar
	#define putc putchar
	void print_final(){}
#endif
template <class _Tp>inline _Tp& read(_Tp& x) {
    bool sign = 0;
    char ch = getc();
    for (; !isdigit(ch); ch = getc()) sign |= (ch == '-');
    for (x = 0; isdigit(ch); ch = getc()) x = x * 10 + (ch ^ 48);
    return sign ? (x = -x) : x;
}
template <class _Tp>inline void write(_Tp x) {
    if (x < 0) putc('-'), x = -x;
    if (x > 9) write(x / 10);
    putc((x % 10) ^ 48);
}
template <typename _Tp,typename ...Args>inline void write(_Tp x,Args ...args){
    write(x),putc(' '),write(args...);
}
template<typename _Tp,typename ...Args>inline bool read(_Tp& x,Args& ...args) {
    return read(x)&&read(args...);
}
const int maxn = 5000;
const int mo = 998244353;
const int B = 11;
int ksm(int b,int t){
	int r=1;
	while(t){
		if(t&1)r=1ll*r*b%mo;
		b=1ll*b*b%mo,t>>=1;
	}
	return r;
}
int inv(int x){
	return ksm(x,mo-2);
}
int n,c,a[maxn],f[maxn][maxn],g[maxn][maxn],V[maxn];
int pw[maxn],ip[maxn],x[maxn],A[maxn];
int main(){
	read(n,c);
	for(int i=1;i<=n;i++)
		read(a[i]);
	if(c>B){
		pw[0]=1,ip[0]=1;
		for(int i=1;i<=n;i++)pw[i]=2ll*pw[i-1]%mo;
		for(int i=1;i<=n;i++)ip[i]=inv(--pw[i]);
		for(int l=1;l<=n;l++){
			for(int j=1;j<=c;j++)V[j]=0;
			int Pr=1,Se=0;
			for(int r=l;r<=n;r++){
				Pr=1ll*Pr*ip[V[a[r]]]%mo;
				if(!V[a[r]])Se++;
				if(Se==c)g[l][r]=Pr;
				Pr=1ll*Pr*pw[++V[a[r]]]%mo;
				if(r==n)x[l]=(ksm(2,n-l+1)-(Se==c?Pr:0)+mo)%mo;
			}
		}
		x[n+1]=1,f[0][0]=1;
		for(int p=1;p<=n/c;p++){
			for(int i=0;i<n;i++){
				if(f[p-1][i]==0)continue;
				for(int j=i+1;j<=n;j++)
					f[p][j]=(f[p][j]+1ll*f[p-1][i]*g[i+1][j])%mo;
			}
		}
		A[0]=(ksm(2,n)+mo-1)%mo;
		for(int p=1;p<=n;p++){
			for(int i=0;i<=n;i++)
				A[p]=(A[p]+1ll*f[p][i]*x[i+1])%mo;
			A[0]=(A[0]-A[p]+mo)%mo;
		}
		for(int i=0;i<=n;i++)write(A[i]),putc(' ');
	}else{
		f[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int p=0;p<=n/c;p++)
				for(int s=(1<<c)-1;s>=0;s--)
					f[p][s|(1<<a[i]-1)]=(f[p][s|(1<<a[i]-1)]+f[p][s])%mo;
			for(int p=n/c;p>=1;p--)f[p][0]=(f[p][0]+f[p-1][(1<<c)-1])%mo;
			for(int p=0;p<=n/c;p++)f[p][(1<<c)-1]=0;
		}
		for(int p=0;p<=n;p++)
			for(int s=0;s<(1<<c);s++)
				A[p]=(A[p]+f[p][s])%mo;
		for(int i=0;i<=n;i++)write((A[i]-(i==0)+mo)%mo),putc(' ');
	}
	print_final();
}
	 	  			 				 		   	 	 				 	 	