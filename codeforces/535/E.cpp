#include <bits/stdc++.h>

using ul = std::uint32_t;
using ull = std::uint64_t;
using li = std::int32_t;
using ll = std::int64_t;
using lf = double;

ul n;

const ul maxn = 2e5;

using lll = __int128;

class frac {
public:
	lll s = 0;
	lll m = 1;
	frac(lll aa = 0, lll bb = 1): s(aa), m(bb) {}
};

frac operator+(const frac& a, const frac& b)
{
	return frac(a.s * b.m + a.m * b.s, a.m * b.m);
}

frac operator-(const frac& a, const frac& b)
{
	return frac(a.s * b.m - a.m * b.s, a.m * b.m);
}

frac operator*(const frac& a, const frac& b)
{
	return frac(a.s * b.s, a.m * b.m);
}

frac operator/(const frac& a, const frac& b)
{
	frac ret(a.s * b.m, a.m * b.s);
	if (ret.m < 0) {
		ret.m = -ret.m;
		ret.s = -ret.s;
	}
	return ret;
}

bool operator<(const frac& a, const frac& b)
{
	return a.s * b.m < a.m * b.s;
}

bool operator>(const frac& a, const frac& b)
{
	return a.s * b.m > a.m * b.s;
}

bool operator<=(const frac& a, const frac& b)
{
	return a.s * b.m <= a.m * b.s;
}

bool operator>=(const frac& a, const frac& b)
{
	return a.s * b.m >= a.m * b.s;
}

bool operator==(const frac& a, const frac& b)
{
	return a.s * b.m == a.m * b.s;
}

bool operator!=(const frac& a, const frac& b)
{
	return a.s * b.m != a.m * b.s;
}

class vec {
public:
	frac x = 0;
	frac y = 0;
	vec(frac a = 0, frac b = 0): x(a), y(b) {}
};

vec operator+(const vec& a, const vec& b)
{
	return vec(a.x + b.x, a.y + b.y);
}

vec operator-(const vec& a, const vec& b)
{
	return vec(a.x - b.x, a.y - b.y);
}

frac operator*(const vec& a, const vec& b)
{
	return a.x * b.x + a.y * b.y;
}

frac operator^(const vec& a, const vec& b)
{
	return a.x * b.y - a.y * b.x;
}

bool operator<(const vec& a, const vec& b)
{
	return a.x != b.x ? a.x < b.x : a.y < b.y;
}

bool operator==(const vec& a, const vec& b)
{
	return a.x == b.x && a.y == b.y;
}

vec blob[maxn + 1];

ul ord[maxn + 1];

std::vector<ul> stack;

std::map<vec, std::vector<ul>> samepoints;

std::vector<ul> ans;

int main()
{
	std::scanf("%u", &n);
	for (ul i = 1; i <= n; ++i) {
		li s, r;
		std::scanf("%d%d", &s, &r);
		blob[i] = vec(frac(1, s), frac(1, r));
		samepoints[blob[i]].push_back(i);
		ord[i] = i;
	}
	std::sort(ord + 1, ord + n + 1, [](ul a, ul b){return blob[a] < blob[b];});
	for (ul i = 1; i <= n; ++i) {
		ul curr = ord[i];
		const vec& cp = blob[curr];
		if (stack.size() && blob[stack.back()] == cp) {
			continue;
		}
		while (stack.size() >= 2 && (blob[stack.back()] - blob[stack[stack.size() - 2]] ^ cp - blob[stack.back()]) < 0) {
			stack.pop_back();
		}
		stack.push_back(curr);
	}
	while (stack.size() >= 2 && blob[stack.back()].y >= blob[stack[stack.size() - 2]].y) {
		stack.pop_back();
	}
	for (ul i : stack) {
		for (ul j : samepoints[blob[i]]) {
			ans.push_back(j);
		}
	}
	std::sort(ans.begin(), ans.end());
	for (ul i = 0; i != ans.size(); ++i) {
		if (i != 0) {
			std::putchar(' ');
		}
		std::printf("%u", ans[i]);
	}
	std::putchar('\n');
	return 0;
}

