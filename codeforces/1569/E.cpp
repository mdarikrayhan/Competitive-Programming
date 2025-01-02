#include <bits/stdc++.h>

using ul = std::uint32_t;
using ull = std::uint64_t;
using li = std::int32_t;
using ll = std::int64_t;
using lf = double;

const ul mod = 998244353;

ul plus(ul a, ul b)
{
	return a + b < mod ? a + b : a + b - mod;
}

ul minus(ul a, ul b)
{
	return a < b ? a + mod - b : a - b;
}

ul mul(ul a, ul b)
{
	return ull(a) * ull(b) % mod;
}

ul k, A, h;

class node {
public:
	ul h = 0;
	ul top = 0;
	ul left = 0;
	ul right = 0;
};

ul treesz = 0;

node tree[66177];

const ul maxk = 5;

ul powA[(1 << maxk - 1) + 2];

std::vector<ul> search(ul topp, ul l, ul r)
{
	std::vector<ul> ret;
	if (l == r) {
		ul nid = ++treesz;
		tree[nid].h = 0;
		tree[nid].top = l;
		ret.push_back(nid);
		return ret;
	}
	std::vector<ul> lefts = search((topp << 1) - 1, l, l + r >> 1);
	std::vector<ul> rights = search((topp << 1) - 1, (l + r >> 1) + 1, r);
	for (ul left : lefts) {
		for (ul right : rights) {
			ul nid = ++treesz;
			tree[nid].h = plus(plus(tree[left].h, tree[right].h), mul(tree[left].top, powA[(topp << 1) - 1]));
			tree[nid].top = tree[right].top;
			tree[nid].left = left;
			tree[nid].right = right;
			ret.push_back(nid);
			nid = ++treesz;
			tree[nid].h = plus(plus(tree[left].h, tree[right].h), mul(tree[right].top, powA[(topp << 1) - 1]));
			tree[nid].top = tree[left].top;
			tree[nid].left = left;
			tree[nid].right = right;
			ret.push_back(nid);
		}
	}
	return ret;
}

std::map<ul, ul> another;

ul ans[(1 << maxk) + 1];

void getans(ul nid, ul topp)
{
	if (!nid) {
		return;
	}
	getans(tree[nid].left, (topp << 1) - 1);
	getans(tree[nid].right, (topp << 1) - 1);
	ans[tree[nid].top] = topp;
}

int main()
{
	std::scanf("%u%u%u", &k, &A, &h);
	powA[0] = 1;
	for (ul i = 1; i <= (1 << k - 1) + 1; ++i) {
		powA[i] = mul(powA[i - 1], A);
	}
	auto lefts = search(2, 1, 1 << k - 1);
	auto rights = search(2, (1 << k - 1) + 1, 1 << k);
	for (auto left : lefts) {
		another[plus(tree[left].h, mul(tree[left].top, powA[2]))] = left;
	}
	for (auto right : rights) {
		ul tmp = plus(tree[right].h, mul(tree[right].top, powA[1]));
		auto it = another.find(minus(h, tmp));
		if (it != another.end()) {
			ul left = it->second;
			getans(left, 2);
			getans(right, 2);
			ans[tree[right].top] = 1;
			for (ul i = 1; i <= (1 << k); ++i) {
				if (i != 1) {
					std::putchar(' ');
				}
				std::printf("%u", ans[i]);
			}
			std::putchar('\n');
			return 0;
		}
	}
	another.clear();
	for (auto right : rights) {
		another[plus(tree[right].h, mul(tree[right].top, powA[2]))] = right;
	}
	for (auto left : lefts) {
		ul tmp = plus(tree[left].h, mul(tree[left].top, powA[1]));
		auto it = another.find(minus(h, tmp));
		if (it != another.end()) {
			ul right = it->second;
			getans(left, 2);
			getans(right, 2);
			ans[tree[left].top] = 1;
			for (ul i = 1; i <= (1 << k); ++i) {
				if (i != 1) {
					std::putchar(' ');
				}
				std::printf("%u", ans[i]);
			}
			std::putchar('\n');
			return 0;
		}
	}
	std::printf("-1\n");
	return 0;
}

