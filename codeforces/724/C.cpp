#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const long long N = 1e5 + 1;
long long n, m, k, mx;

long long exgcd(long long a, long long b, long long& x, long long& y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}


long long solve(long long dx, long long dy)
{
	long long a = 2 * n, b = -2 * m, c = dy - dx, x, y;
	long long d = exgcd(a, b, x, y);
	if (c % d)
		return LLONG_MAX;
	a /= d;
	b /= d;
	c /= d;
	b = abs(b);
	x = (x * c % b + b) % b;
	long long ans = 2 * n * x + dx;
	if (ans <= 0 || ans >= mx)
		return LLONG_MAX;
	return ans;
}

int main()
{
	scanf("%lld %lld %lld", &n, &m, &k);
	mx = n * m / __gcd(n, m);
	for (long long i = 1; i <= k; ++i)
	{
		long long x, y;
		scanf("%lld %lld", &x, &y);
		long long ans = LLONG_MAX;
		ans = min(ans, solve(+x, +y));
		ans = min(ans, solve(+x, -y));
		ans = min(ans, solve(-x, +y));
		ans = min(ans, solve(-x, -y));
		printf("%lld\n", ans == LLONG_MAX ? -1 : ans);
	}
	return 0;
}