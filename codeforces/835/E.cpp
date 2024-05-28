#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)

const int A = 11;
const int N = 1 << A | A;

bool f[A];
int g[A];
int idx = -1;
int m, s;
int ans1 = 0, ans2 = 0;
int n, x, y;

int query(const vector <int>& v) {
	if (v.empty()) {
		return 0;
	}

	int sz = (int)v.size();
	printf("? %d", sz);
	for (auto u : v) {
		printf(" %d", u);
	}
	putchar(10);
	fflush(stdout);

	int k;
	scanf("%d", &k);
	fflush(stdin);
	return k;
}	


int main() {

	scanf("%d%d%d", &n, &x, &y);

	s = x ^ y;

	rep(i, 1, 11) {
		if (((1 << i) - 1) >= n) {
			m = i;
			break;
		}
	}

	rep(i, 0, m - 1) {
		vector <int> v;
		rep(j, 1, n) {
			if ((j >> i) & 1) {
				v.emplace_back(j);
			}
		}

		int cnt = query(v);
		int sz = (int)v.size();

		if (sz & 1) {
			f[i] = (cnt != x);
		} else {
			f[i] = (cnt != 0);
		}
	}
	
	rep(i, 0, m - 1) {
		if (!f[i]) continue;
		idx = i;
		
		vector <int> v;
		rep(j, 1, n) {
			if ((j >> i) & 1) {
				v.emplace_back(j);
			}
		}

		g[i] = -1;

		rep(p, 0, m - 1) {
			if (p == i) continue;
			vector <int> w;
			for (auto u : v) {
				if ((u >> p) & 1) {
					w.emplace_back(u);
				}
			}

			int cnt = query(w);
			int sz = (int)w.size();

			if (sz & 1) {
				g[p] = (cnt == y);
			} else {
				g[p] = (cnt == s);
			}
		}

		break;
	}

	rep(i, 0, m - 1) {
		ans1 |= ((i == idx ? 1 : g[i]) << i);
		if (i == idx) {
			continue;
		}

		ans2 |= ( ( f[i] ?  (g[i] ^ 1) : g[i] ) << i  );
	}

	if (ans1 > ans2) {
		swap(ans1, ans2);
	}

	printf("! %d %d\n", ans1, ans2);
	fflush(stdout);
	return 0;
}


