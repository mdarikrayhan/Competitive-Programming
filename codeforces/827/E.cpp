// LUOGU_RID: 156990935
#include <cstdio>
#include <cmath>

using namespace std;

const int N = 1 << 20 | 5;
const double PI = acos(-1);

int n;
char s[N];
struct Complex{
	double a, b;
	inline Complex operator + (const Complex &x)
	{
		return {a + x.a, b + x.b};
	}
	inline Complex operator - (const Complex &x)
	{
		return {a - x.a, b - x.b};
	}
	inline Complex operator * (const Complex &x)
	{
		return {a * x.a - b * x.b, a * x.b + b * x.a};
	}
};
Complex a[N], b[N];
bool f[N];

Complex w[N];
inline void FFT(Complex a[], int n, int ty)
{
	Complex t;
	for(int i = 0, j = 0; i < n; i ++ )
	{
		if(i < j) t = a[i], a[i] = a[j], a[j] = t;
		for(int k = n >> 1; (j ^= k) < k; k >>= 1) ;
	}
	w[0] = {1, 0};
	for(int i = 1; i < n; i <<= 1)
	{
		Complex wi = {cos(PI / i), sin(PI / i) * ty};
		for(int j = i - 2; j >= 0; j -= 2)
		{
			w[j] = w[j >> 1];
			w[j + 1] = w[j] * wi;
		}
		for(int j = 0; j < n; j += i << 1)
			for(int k = j; k < j + i; k ++ )
			{
				Complex t1 = a[k], t2 = a[k + i] * w[k - j];
				a[k] = t1 + t2, a[k + i] = t1 - t2;
			}
	}
	if(ty == -1)
	{
		double t = 1.0 / n;
		for(int i = 0; i < n; i ++ ) a[i].a *= t;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T -- )
	{
		scanf("%d%s", &n, s);
		for(int i = 0; i < n; i ++ )
		{
			a[i].a = s[i] == 'V';
			a[n - i - 1].b = s[i] == 'V';
			b[n - i - 1].a = s[i] == 'K';
			b[i].b = -(s[i] == 'K');
		}
		int k = 1;
		while(k < n << 1) k <<= 1;
		// for(int i = 0; i < k; i ++ ) printf("%d ", int(a[i].a + 0.5));
		// puts("");
		// for(int i = 0; i < k; i ++ ) printf("%d ", int(b[i].a + 0.5));
		// puts("");
		FFT(a, k, 1), FFT(b, k, 1);
		for(int i = 0; i < k; i ++ ) a[i] = a[i] * b[i];
		FFT(a, k, -1);
		// for(int i = 0; i < k; i ++ ) printf("%d ", int(a[i].a + 0.5));
		// puts("");
		f[n] = 0;
		for(int i = 1; i < n; i ++ ) f[i] = int(a[n - i - 1].a + 0.5) > 0;
		for(int i = 1; i < n; i ++ )
			for(int j = i + i; j < n; j += i)
				f[i] |= f[j];
		int cnt = 0;
		for(int i = 1; i <= n; i ++ ) cnt += !f[i];
		printf("%d\n", cnt);
		for(int i = 1; i <= n; i ++ ) if(!f[i]) printf("%d ", i);
		puts("");
		for(int i = 0; i < k; i ++ ) a[i].a = a[i].b = b[i].a = b[i].b = 0;
	}
	return 0;
}