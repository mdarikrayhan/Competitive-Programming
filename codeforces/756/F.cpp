#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005, p = 1e9 + 7;
string str;
int top;
struct num
{
	long long val1, val2, len1, len2;
	num()
	{
		val1 = val2 = 0, len1 = len2 = 1;
	}
	num(long long v1, long long v2, long long l1, long long l2)
	{
		val1 = v1, val2 = v2, len1 = l1, len2 = l2;
	}
	bool operator != (const num &tmp) const
	{
		return val1 != tmp.val1 || val2 != tmp.val2 || len1 != tmp.len1 || len2 != tmp.len2;
	}
	void clear(void)
	{
		val1 = val2 = 0, len1 = len2 = 1;
	}
} tmp, now, d[Maxn], val[Maxn];
long long fast_pow(long long x, long long y)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now % p;
		now = now * now % p;
		y >>= 1;
	}
	return ans;
}
num add(num a, num b)
{
	num result;
	result.len1 = a.len1 * b.len1 % p, result.len2 = a.len2 * b.len2 % (p - 1);
	result.val1 = (a.val1 * b.len1 + b.val1) % p;
	result.val2 = (a.val2 * b.len2 + b.val2) % (p - 1);
	return result;
}
num mul(num a, num b)
{
	num result;
	result.len1 = fast_pow(b.len1, a.val2);
	result.val1 = b.val1 * (b.len1 == 1 ? a.val2 : (fast_pow(b.len1, a.val2) - 1 + p) % p * fast_pow(b.len1 - 1 + p, p - 2) % p);
	return result;
}
num cal(num a, num b)
{
	long long tmp_val1 = ((fast_pow(a.len1, b.val2 - a.val2 + 2 + p - 1) - 1) * fast_pow(a.len1 - 1, p - 2) - 1 - (b.val1 - a.val1 + 1) + p) % p;
	long long tmp_val2 = (a.val1 - 1) * (fast_pow(a.len1, b.val2 - a.val2 + 1 + p - 1) - 1) % p, sum;
	if (a.len1 == 1)
	{
		tmp_val1 = (b.val1 - a.val1 + 2 + p) * (b.val1 - a.val1 + 1 + p) / 2 % p;
		tmp_val2 = a.val1 * (b.val1 - a.val1 + 1 + p) % p;
		sum = (tmp_val1 + tmp_val2) % p;
	}
	else sum = (tmp_val1 + tmp_val2) * fast_pow(a.len1 - 1, p - 2) % p;
	return num(sum, 0, fast_pow(a.len1, b.val2 - a.val2 + p), 0);
}
num Copy(num a, num b)
{
	num result;
	if (a.len1 == b.len1)
		return cal(a, b);
	result = add(result, cal(a, num(a.len1 - 1, (a.len2 - 1 + p - 1) % (p - 1), a.len1, a.len2)));
	num t = (num){a.len1, a.len2, a.len1 * 10 % p, a.len2 * 10 % (p - 1)};
	while (t.len1 != b.len1)
	{
		result = add(result, cal(t, num((t.len1 - 1) % p, (t.len2 - 1 + p - 1) % (p - 1), t.len1, t.len2)));
		(t.len1 *= 10) %= p, (t.val1 *= 10) %= p;
		(t.len2 *= 10) %= (p - 1), (t.val2 *= 10) %= (p - 1);
	}
	result = add(result, cal(t, b));
	return result;
}
int main()
{
	cin >> str;
	str = '(' + str + ')';
	int siz = str.size();
	for (int i = 0; i < siz; i++)
	{
		if (tmp != (num){0, 0, 1, 1} && !isdigit(str[i]))
			now = Copy(tmp, now), tmp.clear();
		if (str[i] == '(')
		{
			top++;
			d[top] = now, now.clear();
		}
		if (str[i] == ')')
		{
			val[top] = add(val[top], now);
			if (d[top] != (num){0, 0, 1, 1}) now = mul(d[top], val[top]);
			else now = val[top];
			val[top].clear(), d[top].clear();
			top--;
		}
		if (isdigit(str[i])) now = add(now, (num){str[i] - '0', str[i] - '0', 10, 10});
		if (str[i] == '+') val[top] = add(val[top], now), now.clear();
		if (str[i] == '-') tmp = now, now.clear();
	}
	printf("%lld", now.val1);
	return 0;
}