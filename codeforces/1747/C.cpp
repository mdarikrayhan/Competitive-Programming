#include <cstdio>
#include <algorithm>
#define maxn 100000

namespace cltstream
{
	#define size 1048576
	char cltin[size + 1], *ih = cltin, *it = cltin;
	inline char gc()
	{
		#ifdef ONLINE_JUDGE
		if (ih == it)
		{
			it = (ih = cltin) + fread(cltin, 1, size, stdin);
			if (ih == it)
				return EOF;
		}
		return *ih++;
		#else
		return getchar();
		#endif
	}

	char cltout[size + 1], *oh = cltout, *ot = cltout + size;
	inline void pc(char c)
	{
		if (oh == ot)
		{
			fwrite(cltout, 1, size, stdout);
			oh = cltout;
		}
		*oh++ = c;
	}
	#define clop() fwrite(cltstream::cltout, 1, cltstream::oh - cltstream::cltout, stdout), cltstream::oh = cltstream::cltout
	#undef size

	template <typename _tp>
	inline void read(_tp& x)
	{
		char c = gc();
		for (; c != 45 && (c < 48 || c > 57) && c != EOF; c = gc());
		int sgn = c == 45 ? c = gc(), -1 : 1;
		for (x = 0; c >= 48 && c <= 57 && c != EOF; x = (x << 3) + (x << 1) + (c ^ 48), c = gc());
		x *= sgn;
	}

	template <typename _tp>
	inline void write(_tp x, char text = -1)
	{
		if (x < 0)
			pc(45), x = -x;
		if (!x)
			pc(48);
		else
		{
			int digit[22];
			for (digit[0] = 0; x; digit[++digit[0]] = x % 10, x /= 10);
			for (; digit[0]; pc(digit[digit[0]--] ^ 48));
		}
		if (text >= 0)
			pc(text);
	}

	inline void put(char str[], char text = -1)
	{
		for (int cur = 0; str[cur]; pc(str[cur++]));
		if (text >= 0)
			pc(text);
	}
}

int T, n;
int a[maxn + 1];

int main()
{
	cltstream::read(T);
	for (; T; --T)
	{
		cltstream::read(n);
		for (int i = 1; i <= n; ++i)
			cltstream::read(a[i]);
		int min = 1e9;
		for (int i = 2; i <= n; ++i)
			min = std::min(min, a[i]);
		if (a[1] <= min)
			cltstream::put("Bob", 10);
		else
			cltstream::put("Alice", 10);
	}
	clop();
	return 0;
}