#include <bits/stdc++.h>

using ul = std::uint32_t;
using ull = std::uint64_t;
using li = std::int32_t;
using ll = std::int64_t;
using lf = double;

const ul maxn = 1e5;
const ull maxl = 1e12;

ul n;

ll l[maxn + 1];

char s[maxn + 2];

ll Gall = 0;
ll Wall = 0;
ll all = 0;

const ll ilegal = -1;

ll calc(ll Gsum)
{
	ll gremain = Gsum;
	ll height = 0;
	ll wable = 0;
	bool flag = true;
	ll Wsum = 0;
	for (ul i = 1; i <= n; ++i) {
		ll down = 0;
		if (s[i] == 'G') {
			ll c = std::min(l[i], gremain);
			height += c;
			gremain -= c;
			down = l[i] - c;
		} else if (s[i] == 'W') {
			down = l[i];
			wable += l[i];
		} else {
			down = l[i];
		}
		height -= down;
		if (height + wable + wable < 0) {
			flag = false;
			break;
		} else if (height < 0) {
			Wsum = std::max(Wsum, -height >> 1);
		}
	}
	if (!flag) {
		return ilegal;
	} else {
		return (all - Gsum - Wsum) + Gsum * 5 + Wsum * 3;
	}
}

int main()
{
	std::scanf("%u", &n);
	for (ul i = 1; i <= n; ++i) {
		std::scanf("%lld", &l[i]);
		l[i] <<= 1;
	}
	std::scanf("%s", s + 1);
	ll height = 0;
	bool flag = false;
	ll low1 = 0;
	ll low2 = 0;
	ul firstW = 0;
	for (ul i = 1; i <= n; ++i) {
		if (s[i] == 'G') {
			height += l[i];
		} else if (s[i] == 'W') {
			height += l[i];
			if (!flag) {
				firstW = i;
			}
			flag = true;
		} else {
			height -= l[i];
		}
		low2 = std::min(low2, height);
		if (!flag) {
			low1 = std::min(low1, height);
		}
	}
	if (low1 < 0) {
		low2 -= low1;
		l[1] -= low1;
	}
	if (low2 < 0) {
		l[firstW] -= low2;
	}
	for (ul i = 1; i <= n; ++i) {
		if (s[i] == 'G') {
			Gall += l[i];
		} else if (s[i] == 'W') {
			Wall += l[i];
		}
		all += l[i];
	}
	ll gl = 0, gr = Gall + 1;
	while (gl + 1 != gr) {
		ll gmidr = gl + gr >> 1;
		ll gmidl = gmidr - 1;
		ll ansl = calc(gmidl);
		ll ansr = calc(gmidr);
		if (ansl == ilegal || ansl > ansr) {
			gl = gmidr;
		} else {
			gr = gmidr;
		}
	}
	std::printf("%lld\n", calc(gl) >> 1);
	return 0;
}

