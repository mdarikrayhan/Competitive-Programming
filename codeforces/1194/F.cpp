// LUOGU_RID: 159218285
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

//mo
#ifndef __w_mo_
#define __w_mo_

template<typename _norp,
#ifndef __nonem_
	_norp M = 998244353,
#endif
	typename _lonp = int64_t>
class mo
{
	public:
		_norp x;
		mo(_norp X = 0)
		{
			while (X >= M) X -= M;
			while (X < 0) X += M;
			x = X;
		}
		
		operator bool()
		{
			return x != 0;
		}
		
		mo& operator = (const _norp y)
		{
			return *this = mo(y);
		}
		
		mo& operator = (const mo y)
		{
			x = y.x;
			return *this;
		}
		
		mo& operator ++ ()
		{
			++ x == M && (x = 0, 1);
			return *this;
		}
		
		mo& operator -- ()
		{
			-- x == -1 && (x = M - 1);
			return *this;
		}
		
		mo operator + (const _norp y) const
		{
			_norp z = x + y;
			return z >= M ? z - M : z;
		}
		
		mo& operator += (const _norp y)
		{
			((x += y) >= M) && (x -= M);
			return *this;
		}
		
		mo operator + (const mo y) const
		{
			_norp z = x + y.x;
			return z >= M ? z - M : z;
		}
		
		mo& operator += (const mo y)
		{
			((x += y.x) >= M) && (x -= M);
			return *this;
		}
		
		mo operator - (const _norp y) const
		{
			_norp z = x - y;
			return z < 0 ? z + M : z;
		}
		
		mo& operator -= (const _norp y)
		{
			((x -= y) < 0) && (x += M);
			return *this;
		}
		
		mo operator - (const mo y) const
		{
			_norp z = x - y.x;
			return z < 0 ? z + M : z;
		}
		
		mo& operator -= (const mo y)
		{
			((x -= y.x) < 0) && (x += M);
			return *this;
		}
		
		friend inline mo operator - (const _norp x, const mo y)
		{
			return mo(x) - y;
		}
		
		mo operator * (const _norp y) const
		{
			return (_lonp)x * y % M;
		}
		
		mo& operator *= (const _norp y)
		{
			x = (_lonp)x * y % M;
			return *this;
		}
		
		mo operator * (const mo y) const
		{
			return (_lonp)x * y.x % M;
		}
		
		mo& operator *= (const mo y)
		{
			x = (_lonp)x * y.x % M;
			return *this;
		}
		
		mo operator ^ (_norp b) const
		{
			mo a = x;
			mo res = 1;
			for (; b; b >>= 1, a *= a) if (b & 1) res *= a;
			return res;
		}
		
		mo& operator ^= (_norp b)
		{
			mo a = x;
			x = 1;
			for (; b; b >>= 1, a *= a) if (b & 1) *this *= a;
			return *this;
		}
		
		mo operator ^ (mo b) const
		{
			return *this ^ b.x;
		}
		
		mo& operator ^= (mo b)
		{
			return *this ^= b.x;
		}
		
		mo operator ~ () const
		{
			return *this ^ (M - 2);
		}
		
		mo operator / (const _norp y) const
		{
			return *this * ~mo(y);
		}
		
		mo& operator /= (const _norp y)
		{
			return *this *= ~mo(y);
		}
		
		mo operator / (mo y) const
		{
			return *this * ~y;
		}
		
		mo& operator /= (mo y)
		{
			return *this *= ~y;
		}
		
		mo operator - () const
		{
			return x == 0 ? x : -x + M;
		}
		
		mo& operator + () const
		{
			x != 0 && (x = -x + M);
			return *this;
		}
};

typedef mo<int> mio;
inline mio operator ""_mio (unsigned long long C)
{
	return mio(C);
}

namespace IO::us
{
	template<typename _norp,
#ifndef __nonem_
	_norp M = 998244353,
#endif
	typename _lonp = int64_t>
	inline void rd(mo<_norp,
#ifndef __nonem_
		M,
#endif
		_lonp> &a)
	{
		_norp x;
		rd(x);
		a = x;
	}
	
	template<typename _norp,
#ifndef __nonem_
	_norp M = 998244353,
#endif
	typename _lonp = int64_t>
	inline void wr(mo<_norp,
#ifndef __nonem_
		M,
#endif
		_lonp> a)
	{
		wr(a.x);
	}
}
using IO::us::rd;
using IO::us::wr;
#endif


typedef mo<int, (int)1e9 + 7> mlo;

//#define int long long

const int N = 2e5 + 7;

int n;
long long T;

long long a[N];

mlo f, g;

mlo ica[N + 1];
mlo vca[N + 1];

inline void INIT()
{
	ica[0] = 1;
	for (int i = 1; i <= N; ++ i)
		ica[i] = ica[i - 1] * i;
	vca[N] = ~ica[N];
	for (int i = N; i >= 1; -- i)
		vca[i - 1] = vca[i] * i;
}

inline mlo C(int n, int m)
{
	return ica[n] * vca[m] * vca[n - m];
}

inline void WORK()
{
	rd(n, T);
	for (int i = 1; i <= n; ++ i)
	{
		rd(a[i]);
		a[i] += a[i - 1];
	}
	
	if (a[1] > T)
	{
		wr("0\n");
		return;
	}
	
	/*
	0	<=	k
	
	i	>=	k
	
	s[i] + k		<=		T
	T - s[i]		>=		k
	
	s[i + 1] + k	>		T
	T - s[i + 1]	<		k
	
	*/
	a[n + 1] = T + T;
	for (int i = 1; i <= n; ++ i)
	{
		if (a[i] > T) break;
		long long L = max(0ll, T - a[i + 1]);
		long long R = min((long long)i, T - a[i]);
		{
			if (L > R) continue;
			mlo s;
			for (int j = L; j <= R; ++ j)
			{
				s += C(i, j);
			}
			f += s * (mlo(2) ^ (n - i)) * i;
		}
		L = max(0ll, T - a[i + 1] + 1);
		{
			if (L > R) continue;
			mlo s;
			for (int j = L; j <= R; ++ j)
			{
				s += C(i, j);
			}
			f += s * (mlo(2) ^ (n - i)) * i;
		}
	}
	
	wr(f / (mlo(2) ^ (n + 1)), '\n');
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