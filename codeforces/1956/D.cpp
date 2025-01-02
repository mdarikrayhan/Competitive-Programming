// LUOGU_RID: 160261389
#include <bits/stdc++.h>
using namespace std;
const int N = 21;

vector<pair<int, int> > ans;

int f[N][N], g[N][N];
int a[N], s[N];

int n;

template <class T = int>
inline T read() {
	char c = getchar();
	bool sign = (c == '-');
	
	while (c < '0' || c > '9')
		c = getchar(), sign |= (c == '-');
	
	T x = 0;
	
	while ('0' <= c && c <= '9')
		x = (x << 1) + (x << 3) + (c & 15), c = getchar();
	
	return sign ? (~x + 1) : x;
}

inline int mex(int l, int r) {
	bitset<N> vis;
	vis.set();

	for (int i = l; i <= r; ++i)
		if (a[i] < N)
			vis.reset(a[i]);

	return vis._Find_first();
}

inline void update(int l, int r) {
	ans.emplace_back(l, r);
	fill(a + l, a + r + 1, mex(l, r));
}

void modify(int l, int r) {
	if (l > r)
		return;

	if (l == r) {
		while (a[l] != 1)
			update(l, r);

		return;
	}

	modify(l, r - 1), update(l, r);
	update(l, r - 1), modify(l, r - 1);
}

void solve(int l, int r) {
	if (!g[l][r]) {
		if (s[r] - s[l - 1] < (r - l + 1) * (r - l + 1)) {
			while (count(a + l, a + r + 1, 0) != r - l + 1)
				update(l, r);

			modify(l, r - 1), update(l, r);
		}

		return;
	} else
		solve(l, g[l][r]), solve(g[l][r] + 1, r);
}

signed main() {
	n = read();

	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + (f[i][i] = a[i] = read());

	for (int len = 1; len <= n; ++len)
		for (int l = 1, r = len; r <= n; ++l, ++r) {
			f[l][r] = max(len * len, s[r] - s[l - 1]);

			for (int k = l; k < r; ++k)
				if (f[l][k] + f[k + 1][r] > f[l][r])
					f[l][r] = f[l][k] + f[k + 1][r], g[l][r] = k;
		}

	printf("%d ", f[1][n]);
	solve(1, n);
	printf("%d\n", ans.size());

	for (auto it : ans)
		printf("%d %d\n", it.first, it.second);

	return 0;
}