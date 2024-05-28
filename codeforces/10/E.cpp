#include <bits/stdc++.h>

using ul = std::uint32_t;
using ull = std::uint64_t;
using li = std::int32_t;
using ll = std::int64_t;
using lf = double;

const ul maxn = 400;

ul n;

ul a[maxn + 1];

int main()
{
	std::scanf("%u", &n);
	for (ul i = 1; i <= n; ++i) {
		std::scanf("%u", &a[i]);
	}
	const ul inf = 2e9;
	ul ans = inf;
	for (ul l = 2; l <= n; ++l) {
		ul k = a[l - 1] - 1;
		ul tmp = 0;
		ul sum = 0;
		for (ul r = l; r <= n; ++r) {
			ul u = k / a[r];
			ul t = u * a[r];
			sum += u;
			tmp += t;
			k -= t;
			ul sum1 = sum + 1;
			ul tmp1 = tmp + a[r];
			if (tmp1 < a[l - 1]) {
				continue;
			}
			if (tmp1 - a[r] == a[l - 1]) {
				continue;
			}
			ul tmp2 = tmp1;
			ul sum2 = 0;
			for (ul i = 1; i <= n; ++i) {
				ul u = tmp2 / a[i];
				ul t = u * a[i];
				sum2 += u;
				tmp2 -= t;
			}
			if (sum2 > sum1) {
				ans = std::min(ans, tmp1);
			}
		}
	}
	if (ans != inf) {
		std::printf("%u\n", ans);
	} else {
		std::printf("-1\n");
	}
	return 0;
}

