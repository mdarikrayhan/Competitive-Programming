// LUOGU_RID: 158966966
/* The code is from koukilee*/
#include <cstdio>

using i32 = int; using i64 = long long; // std::mt19937 rd(time(0));
constexpr i64 MAXN = 1010100, mod = 1e9 + 7, INF = 2009100720100812; 

//char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<21],*O=obuf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline void read (i64 &sum) noexcept {
    i64 tf = 0; char ch = getchar(); sum = 0;
    while(ch < '0' || ch > '9') tf = ch == '-' ? 1 : 0, ch = getchar();
    while(ch >= '0' && ch <= '9') sum = (sum << 1) + (sum << 3) + (ch ^ 48), ch = getchar();
    (tf) && (sum =- sum);
}template <typename i64,typename ...Args>
inline void read (i64 &tmp, Args &...tmps) noexcept{read(tmp); read(tmps...);}
void printt (i64 x) noexcept {if(x >= 10) printt(x / 10); putchar(x % 10 + '0');} 
inline void print (i64 x) noexcept{x < 0 ? putchar('-'), printt(-x) : printt(x);}
inline void put (i64 x) noexcept{print(x), putchar('\n');}

// 

i64 T, n, l[MAXN], r[MAXN], s[MAXN], ans[MAXN];

inline i64 highbit(i64 x) noexcept{return (x != (1ll << 62)) ? (1ull << (63 - __builtin_clzll(x))) : (1ll << 62);}
inline i64 sum(i64 L, i64 R) noexcept{return (s[R] ^ s[L - 1]) ? (s[R] ^ s[L - 1]) : (1ll << 62);}

int main() noexcept{
	read(T);
	while (T--){
		read(n); for (i32 i = 1; i <= n; i++) read(s[i]), l[i] = r[i] = 0;
		for (i32 i = 1; i <= n; i++) s[i] = s[i - 1] ^ s[i];
		
		l[1] |= highbit(sum(1, n)), r[n] |= highbit(sum(1, n)), ans[1] = 1;
		
		for (i32 len = n - 1; len; len--){
			for (i32 i = 1; i <= n - len + 1; i++){
				i64 j = i + len - 1;
				i64 f = (((sum(i, j) | (1ll << 62)) & l[i]) | ((sum(i, j) | (1ll << 62)) & r[j]));
				if (f) l[i] |= highbit(sum(i, j)), r[j] |= highbit(sum(i, j));
				if (len == 1) ans[i] = f > 0;
			}
		}
		
		for (i32 i = 1; i <= n; i++) print(ans[i]);
		putchar('\n');
	}
    return 0;
}