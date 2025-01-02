#include"bits/stdc++.h"
using namespace std;
// Code By ReTF
#pragma GCC optimize(2)
#pragma GCC optimize(3)
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
const int maxn = 50010;
int n,q,a[maxn],F[maxn],Dp[maxn],Tg[maxn],Q[maxn],Idx;
int Ad[maxn],As[maxn];
vector<int>e[maxn];
void dfs(int p,int Fa){
	F[p]=Fa,Dp[p]=Dp[Fa]+1;
	for(auto To:e[p])if(To^Fa)dfs(To,p);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	read(n,q);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=2,p;i<=n;i++)read(p),e[p].push_back(i);
	dfs(1,0);
	for(int i=1;i<=q;i++)read(Q[i]);
	for(int i=1,p=i;i<=n;p=(++i)){
		while(p)Tg[p]=i,p=F[p];
		for(int j=1;j<=q;j++)
			if(Tg[Q[j]]==i)
				Ad[j]=Ad[j]+Dp[i]-Dp[Q[j]],As[j]++,j+=a[i]-1;
	}
	for(int i=1;i<=q;i++)write(Ad[i]),putc(' '),write(As[i]),putc('\n');
	print_final();
}