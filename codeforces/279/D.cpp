// LUOGU_RID: 160514370
#include<bits/stdc++.h>
#define ll long long
using namespace std;

namespace fast_IO {
#define IOSIZE 100000
//	int precision = 3, POW[10] = {1, 10, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9};	// 四舍五入到第precision位
	char ibuf[IOSIZE], obuf[IOSIZE], *p1 = ibuf, *p2 = ibuf, *p3 = obuf;
#ifdef ONLINE_JUDGE
#define getchar() ((p1==p2)and(p2=(p1=ibuf)+fread(ibuf,1,IOSIZE,stdin),p1==p2)?(EOF):(*p1++))
#endif 
#define putchar(x) ((p3==obuf+IOSIZE)&&(fwrite(obuf,p3-obuf,1,stdout),p3=obuf),*p3++=x)
#define isdigit(ch) (ch>47&&ch<58)
#define isspace(ch) (ch<33)
	template<typename T> inline T read() { T s = 0; int w = 1; char ch; while (ch = getchar(), !isdigit(ch) and (ch != EOF)) if (ch == '-') w = -1; if (ch == EOF) return false; while (isdigit(ch)) s = s * 10 + ch - 48, ch = getchar(); return s * w; }
	template<typename T> inline bool read(T &s) { s = 0; int w = 1; char ch; while (ch = getchar(), !isdigit(ch) and (ch != EOF)) if (ch == '-') w = -1; if (ch == EOF) return false; while (isdigit(ch)) s = s * 10 + ch - 48, ch = getchar(); return s *= w, true; }
	template<typename T> inline void print(T x) { if (x < 0) putchar('-'), x = -x; if (x > 9) print(x / 10); putchar(x % 10 + 48); }
	inline bool read(char &s) { while (s = getchar(), isspace(s)); return true; }
	inline bool read(char *s) { char ch; while (ch = getchar(), isspace(ch)); if (ch == EOF) return false; while (!isspace(ch)) *s++ = ch, ch = getchar(); *s = '\000'; return true; }
	inline void print(char x) { putchar(x); }
	inline void print(char *x) { while (*x) putchar(*x++); }
	inline void print(const char *x) { for (int i = 0; x[i]; i++) putchar(x[i]); }
	inline bool read(std::string& s) { s = ""; char ch; while (ch = getchar(), isspace(ch)); if (ch == EOF) return false; while (!isspace(ch)) s += ch, ch = getchar(); return true; }
	inline void print(std::string x) { for (int i = 0, n = x.size(); i < n; i++) putchar(x[i]); }
	inline bool read(bool &b) { char ch; while(ch=getchar(), isspace(ch)); b=ch^48; return true; }
	inline void print(bool b) { putchar(b+48); }
//	inline bool read(double &x) { int a = 0, b = 0; char ch = getchar(); bool f = 0; while(ch<48 || ch>=57) { if(ch == '-')	f = 1; ch = getchar(); } while(48<=ch && ch<=57) { a = (a<<1) + (a<<3) + (ch^48); ch = getchar(); } if(ch != '.') { x = (f ?-a :a); return 1; } ch = getchar(); while(48<=ch && ch<=57) { b = (b<<1) + (b<<3)  +(ch^48), ch = getchar(); } x = b; while(x > 1) x /= 10; x = (f ?-a-x :a+x); return 1; }
//	inline void print(double x) { if(x<0) { putchar('-'), x=-x; } x=round((long double)x*pow(10, precision))/pow(10, precision), print((long long)x), putchar('.'), x-=(long long)(x); for(int i=1; i<=precision; i++)	x *= 10, putchar(x+48), x -= (int)x; } 
	template<typename T, typename... T1> inline int read(T& a, T1&... other) { return read(a) + read(other...); }
	template<typename T, typename... T1> inline void print(T a, T1... other) { print(a), print(other...); }
	struct Fast_IO { ~Fast_IO() { fwrite(obuf, p3 - obuf, 1, stdout); } } io;
	template<typename T> Fast_IO& operator >> (Fast_IO &io, T &b) { return read(b), io; }
	template<typename T> Fast_IO& operator << (Fast_IO &io, T b) { return print(b), io; }
#define cout io
#define cin io
#define endl '\n'
} using namespace fast_IO;

const int Maxn = 24, INF = 0x3f3f3f3f;

namespace Josh_zmf {
	
	int N, a[Maxn], f[2][1<<23];
	struct node { int x, y; };
	vector <node> have[Maxn];

	inline int lowbit(int t) { return t&(-t); }

	inline int main() {
		cin>> N;
		for(int i=0; i<N; i++)	cin>> a[i]; // 状压下标从 0 开始方便
		for(int i=0; i<N; i++) { // 预处理一下哪两个 a 可以凑出一个 a[i]
			for(int j=0; j<N; j++) {
				for(int k=j; k<N; k++) { // k = j, 因为两个一样的也可以拼
					if(a[j] + a[k] == a[i])	have[i].push_back({j, k});
				}
			}
		}
		memset(f[0], 0x3f, (1<<N)<<2), memset(f[1], 0x3f, (1<<N)<<2); // 初始化，这些情况都不合法
		f[0][1] = 1; // a[1] 必须选
		for(int i=1; i<N; i++) {
			memset(f[i&1], 0x3f, (1<<i)<<2); // 滚动数组要清空
			for(node tmp: have[i]) { // 枚举由哪两个点转移过来
				int x = tmp.x, y = tmp.y;
				for(int k=(1<<i)-1; ~k; k--) {
					if(f[i&1^1][k] == INF)	continue; // 不存在这种情况
					if(!((k>>x)&1) || !((k>>y)&1))	continue; // x/y 没存下来
					int now = k|(1<<i); // a[i] 必须存下来
					f[i&1][now] = min(f[i&1][now], f[i&1^1][k]+1); // 新添一个容器
					for(int kk=k; kk; kk-=lowbit(kk)) { // 枚举哪个容器被替换
						now = (kk-lowbit(kk))|(k&(lowbit(kk)-1))|(1<<i);
						f[i&1][now] = min(f[i&1][now], f[i&1^1][k]);
					}
				}
			}
		}
		int ans = INF;
		for(int k=(1<<N)-1; ~k; k--) {
			if(!((k>>(N-1))&1))	continue;
			ans = min(ans, f[(N-1)&1][k]);
		}
		if(ans == INF)	cout<< "-1";
		else 	cout<< ans;
		return 0;
	}

}

int main() {
	Josh_zmf::main();
	return 0;
}