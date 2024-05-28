// LUOGU_RID: 159298473
//cpp
//#define __filed_
//#define __fasIO_
//#define __subit_
//#define __moret_

#ifndef __wht_pre_
#define __wht_pre_

#include <bits/stdc++.h>

using namespace std;

#ifdef ONLINE_JUDGE
#define __subit_
#undef __filed_
#endif

#ifndef __w_IO__
#define __w_IO__

namespace IO
{
	#ifdef __fasIO_
		const int maxn = 1 << 20;
		char in[maxn + 1], out[maxn], *p1 = in, *p2 = in, *p3 = out;
		#define getchar() (p1 == p2 && (p2 = (p1 = in) + fread(in + 1, 1, maxn, stdin), p1 == p2) ? EOF : *( ++ p1))
		#define flush() (fwrite(out + 1, 1, p3 - out, stdout))
		#define putchar(x) (p3 == out + maxn && (flush() , p3 = out), *( ++ p3) = x)
		class Flush{public: ~Flush(){flush();}}_;
	#endif
	#define isdigit(x) ('0' <= x && x <= '9')
	namespace us
	{
		inline void rd(char *x)
		{
			do *x = getchar();
			while (*x <= 32 || *x == 127);
			while (*x  > 32 && *x != 127)
				* ++ x = getchar();
			*x = 0;
		}
		
		template<typename _Tp>
		inline void rd(_Tp &x)
		{
			x = 0;
			bool fl(false);
			char ch;
			do ch = getchar(), fl |= ch == '-'; while (!isdigit(ch));
			do x = x * 10 + (ch ^ 48), ch = getchar(); while (isdigit(ch));
			if (fl) x = -x;
		}
		
		template<>
		inline void rd(char &x)
		{
			do x = getchar();
			while (x <= 32 || x == 127);
		}
		
		template<>
		inline void rd(std::string &x)
		{
			char c;
			x.clear();
			do c = getchar();
			while (c <= 32 || c == 127);
			while (c  > 32 && c != 127)
				x.push_back(c), c = getchar();
		}
		
		template<typename _Tp>
		inline void wr(_Tp x)
		{
			x < 0 ? x = -x, putchar('-') : 0;
			static short st[50], top(0);
			do st[ ++ top] = x % 10, x /= 10; while (x);
			while (top) putchar(st[top -- ] | 48);
		}
		
		template<>
		inline void wr(char c)
		{
			putchar(c);
		}
		
		template<>
		inline void wr(char* s)
		{
			while (*s)
				putchar(*s ++ );
		}
		
		template<>
		inline void wr(const char* s)
		{
			while (*s)
				putchar(*s ++ );
		}
		
		template<typename _Tp, typename ...Args>
		void rd(_Tp &&x, Args &&...args)
		{
			rd(x); rd(args...);
		}
		
		template<typename _Tp, typename ...Args>
		void wr(_Tp x, Args ...args)
		{
			wr(x); wr(args...);
		}
		
		#undef isdigit
	}
}
//using namespace IO::us;

#endif

#ifdef __filed_
#define fin(x) freopen(x ".in", "r", stdin)
#define fout(x) freopen(x ".out", "w", stdout)
#define fre(x) fin(x), fout(x)
#else
#define fin(x) void()
#define fout(x) void()
#define fre(x) void()
#endif

#define rend return 0

#ifndef __filed_
#ifndef __fasIO_
#ifndef __subit_
#undef rend
#define rend         \
	system("pause"); \
	return 0
#endif
#endif
#endif

#ifdef __subit_
#define erd(...) void()
#define ewr(...) void()
#else
#define erd(...) rd(__VA_ARGS__)
#define ewr(...) wr(__VA_ARGS__)
#endif

int Turn;
#ifndef __moret_
#define rdT() Turn = 1
#else
#define rdT() rd(Turn)
#endif
using IO::us::rd;
using IO::us::wr;

#define EXPAND5(...) EXPAND4(EXPAND4(EXPAND4(EXPAND4(__VA_ARGS__))))
#define EXPAND4(...) EXPAND3(EXPAND3(EXPAND3(EXPAND3(__VA_ARGS__))))
#define EXPAND3(...) EXPAND2(EXPAND2(EXPAND2(EXPAND2(__VA_ARGS__))))
#define EXPAND2(...) EXPAND1(EXPAND1(EXPAND1(EXPAND1(__VA_ARGS__))))
#define EXPAND1(...) __VA_ARGS__
#define PARENS ()

#endif


//#define int long long

const int N = 1e6 + 7;

int m, n;

int tri[N][26];
int imp[N];
int f[N];

deque<int> q;

int ans[N];

int lex;

void dfs(int u)
{
	int p = f[u] - lex;
	if (q.empty() || p <= q.back())
		q.push_back(p);
	lex += !!imp[u];
	
	for (int i = 0; i < 26; ++ i)
	{
		int to = tri[u][i];
		if (!to) continue;
		f[to] = f[u] + 1;
		if (imp[to])
			to[imp][ans] = f[to] = min(f[to], q.back() + lex + 1);
		dfs(to);
	}
	if (q.back() == p)
		q.pop_back();
}

inline void INIT() { }

inline void WORK()
{
	rd(m);
	for (int i = 1; i <= m; ++ i)
	{
		int fa;
		char ch;
		rd(fa, ch);
		tri[fa][ch - 'a'] = i;
	}
	rd(n);
	for (int i = 1; i <= n; ++ i)
	{
		int x;
		rd(x);
		imp[x] = i;
	}
	dfs(0);
	for (int i = 1; i <= n; ++ i)
		wr(ans[i], ' ');
	wr('\n');
}

#undef int

int main()
{
	fre("");
	INIT();
	for (rdT(); Turn; -- Turn, ewr('\n'))
		WORK();
	rend;
}