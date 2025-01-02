#include <bits/stdc++.h>

using ul = std::uint32_t;
using ull = std::uint64_t;
using li = std::int32_t;
using ll = std::int64_t;
using lf = double;

ul n;

const ul maxn = 1e5;

std::vector<ul> edges[maxn + 1];

using pulul = std::pair<ul, ul>;

std::vector<pulul> out;

ul ans;

void search(ul curr, ul prev, ul t)
{
	out.push_back(pulul(curr, t));
	ul tar = t - 1;
	ul remain = edges[curr].size() - 1;
	for (ul next : edges[curr]) {
		if (next == prev) {
			continue;
		}
		if (t == ans) {
			t = tar - remain;
			out.push_back(pulul(curr, t));
		}
		search(next, curr, t + 1);
		++t;
		--remain;
		out.push_back(pulul(curr, t));
	}
	if (curr != 1 && t != tar) {
		t = tar;
		out.push_back(pulul(curr, t));
	}
}

int main()
{
	std::scanf("%u", &n);
	for (ul i = 1; i <= n - 1; ++i) {
		ul u, v;
		std::scanf("%u%u", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for (ul i = 1; i <= n; ++i) {
		ans = std::max(ans, ul(edges[i].size()));
	}
	search(1, 0, 0);
	std::printf("%u\n", ul(out.size()));
	for (const auto& p : out) {
		std::printf("%u %u\n", p.first, p.second);
	}
	return 0;
}

