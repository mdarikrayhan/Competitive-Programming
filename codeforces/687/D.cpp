// LUOGU_RID: 158478367
#include<bits/stdc++.h>

#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)

using namespace std;
typedef int ll;
namespace IO{
	char buf[1 << 20], *p1 = buf, *p2 = buf;
	#define getchar() (p1 == p2 && (p2 = (p1 = buf) + \
		fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)
	inline ll read(){
		ll x = 0,h = 1;
		char ch = getchar();
		while(!(ch=='-'||('0'<=ch&&ch<='9'))) ch = getchar();
		if(ch=='-') h = -1;
		else x = ch-'0';
		ch = getchar();
		while('0'<=ch&&ch<='9'){
			x = x*10+ch-'0';
			ch = getchar();
		}
		return x*h;
	}
	inline ll digread(){
		char ch = getchar();
		while(!('0'<=ch&&ch<='9')) ch = getchar();
		return ch-'0';
	}
	inline char readCH(){
		char ch = getchar();
		while(!(ch=='x')) ch = getchar();
		return ch;
	}
	inline void print(ll x){
		if(x>9) print(x/10);
		putchar(x%10+'0');
	}
	inline void write(ll x){
		if(x<0) putchar('-'),x = -x;
		print(x);
	}
}
using namespace IO;
namespace MathLab{
	inline ll ksm(ll _x,ll _k,ll _mod){
		ll _res = 1;
		while(_k){
			if(_k&1) _res = _res*_x%_mod;
			_x = _x*_x%_mod;
			_k>>=1;
		}
		return _res;
	}
	inline ll phi(ll _x){
		ll _res = _x;
		for(ll _i = 2; _i*_i <= _x; _i++){
			if(_x%_i==0){
				while(_x%_i==0) _x/=_i;
				_res = _res*(_i-1)/_i;
			}
		}
		if(_x>1) _res = _res*(_x-1)/_x;
		return _res;
	}
	inline ll gcd(ll _x,ll _y){
		return _y?gcd(_y,_x%_y):_x;
	}
	inline ll lcm(ll _x,ll _y){
		return _x*_y/gcd(_x,_y);
	}
	inline bool IsPrime(ll _x){
		if(_x<=1) return 0;
		for(ll _i = 2; _i*_i <= _x; _i++) if(_x%_i==0) return 1;
		return 0;
	}
	inline void AddMod(ll &_x,ll _y,ll _mod){
		_x = (_x+_y>=_mod?_x+_y-_mod:_x+_y);
	}
	inline void MulMod(ll &_x,ll _y,ll _mod){
		_x = _x*_y%_mod;
	}
	inline ll GetMid(ll _x){
		return (_x&1LL)?((_x>>1LL)+1LL):(_x>>1LL);
	}
	inline ll GetFac(ll _x,ll _mod){
		return _x?GetFac(_x-1,_mod)*_x%_mod:1LL;
	}
	inline ll Inv(ll _x,ll _mod){
		return ksm(_x,_mod-2,_mod);
	}
	
}
#define File(name)                     \
    freopen(#name ".in", "r", stdin);  \
    freopen(#name ".out", "w", stdout);
#define ERR assert(0)
#define RunTime ((double)clock()/CLOCKS_PER_SEC)

/*
有时候程序没反应就把 IO 里面重定义 getchar 删掉 
-std=c++14  -Wall -Wextra -Wl,--stack=102400000000 -fno-ms-extensions
*/



namespace YYZ{
	const ll N = 2010;
	const ll M = 1000010;
	ll n,m,Q;
	struct Edge{
		ll from,to,val;
		ll id;
		bool operator <(const Edge &x) const{return val>x.val;}
	} edge[M];
	ll fa[N];
	void init(){for(ll i = 1; i <= n*2; i++) fa[i] = i;}
	ll find(ll x){return fa[x]==x?x:fa[x] = find(fa[x]);}
	void merge(ll x,ll y){
		x = find(x),y = find(y);
		if(x==y) return;
		fa[x] = y; 
	}
	void main(){
		n = read(),m = read(),Q = read();
		for(ll i = 1; i <= m; i++) edge[i].from = read(),edge[i].to = read(),edge[i].val = read(),edge[i].id = i;
		sort(edge+1,edge+m+1);
		while(Q--){
			ll L = read(),R = read();
			bool flag = 0;
			init();
			for(ll i = 1; i <= m; i++){
				if(edge[i].id<L||edge[i].id>R) continue;
				if(find(edge[i].from)==find(edge[i].to)){
					printf("%d\n",edge[i].val);flag = 1;
					break;
				} else {
					merge(edge[i].from,edge[i].to+n);
					merge(edge[i].to,edge[i].from+n);
				}
			}
			if(!flag) puts("-1");
		}
	}
}
int main(){
	YYZ::main();
	return 0;
}
/*

*/
