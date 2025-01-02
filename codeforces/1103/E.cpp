#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define Int register int
#define MAXN 400005
#define lim 100000

template <typename T> inline void read (T &t){t = 0;char c = getchar();int f = 1;while (c < '0' || c > '9'){if (c == '-') f = -f;c = getchar();}while (c >= '0' && c <= '9'){t = (t << 3) + (t << 1) + c - '0';c = getchar();} t *= f;}
template <typename T,typename ... Args> inline void read (T &t,Args&... args){read (t);read (args...);}
template <typename T> inline void write (T x){if (x < 0){x = -x;putchar ('-');}if (x > 9) write (x / 10);putchar (x % 10 + '0');}

int n;
ull inv = 6723469279985657373ull;

struct Poly{
	ull a[5];
	Poly(){a[0] = a[1] = a[2] = a[3] = a[4] = 0;}
	Poly operator + (Poly p){
		Poly res;
		for (Int i = 0;i < 5;++ i) res.a[i] = a[i] + p.a[i];
		return res;
	}
	Poly operator * (Poly p){
		ull tmp[10];Poly res;
		memset (tmp,0,sizeof (tmp));
		for (Int i = 0;i < 5;++ i)
			for (Int j = 0;j < 5;++ j)
				tmp[i + j] += a[i] * p.a[j];
		for (Int i = 0;i < 5;++ i) res.a[i] = tmp[i] - tmp[i + 5];
		return res; 
	}
	ull Turn (){
		ull tmp = a[1];for (Int i = 0;i < 5;++ i) a[i] -= tmp;
		tmp = a[2];for (Int i = 0;i < 5;i += 2) a[i] -= tmp;
		return a[0];
	}
}ans[MAXN],bas[10],zero;

Poly quick_pow (Poly a,int b){
	Poly res;memset (res.a,0,sizeof (res.a)),res.a[0] = 1;
	for (;b;b >>= 1,a = a * a) if (b & 1) res = res * a;
	return res;
}

void FWT (Poly *a,int type){
	int id[10];Poly b[10];
	for (Int len = 1;len < lim;len *= 10)
		for (Int i = 0;i < lim;i += len * 10)
			for (Int j = 0;j < len;++ j){
				for (Int d = 0;d < 10;++ d){
					id[d] = i + j + d * len;
					b[d] = a[id[d]],a[id[d]] = zero;
				}
				for (Int d = 0;d < 10;++ d)
					for (Int e = 0;e < 10;++ e)
						a[id[d]] = a[id[d]] + bas[(10 + type) * d * e % 10] * b[e];
			}
}

signed main(){
	read (n);
	for (Int i = 1,a;i <= n;++ i) read (a),++ ans[a].a[0];
	for (Int i = 0;i < 10;++ i) bas[i].a[i % 5] = i >= 5 ? -1 : 1;
	FWT (ans,1);
	for (Int i = 0;i < lim;++ i) ans[i] = quick_pow (ans[i],n);
	FWT (ans,-1);
	for (Int i = 0;i < n;++ i) write (((ans[i].Turn() * inv) >> 5) % (1ull << 58)),putchar ('\n');
	return 0;
}