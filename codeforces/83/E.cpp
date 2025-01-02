#include <bits/stdc++.h>
#define _for(i, a, b) for (int i = a; i <= b; ++i)
#define for_(i, a, b) for (int i = a; i >= b; --i)
#define far(i, vec) for (auto i : vec)
#define bdmd int mid = (l + r) >> 1
typedef unsigned long long ull;
typedef long double ldb;
typedef long long ll;
typedef double db;
typedef std::pair <int, int> pii;
typedef std::pair <ll, ll> pll;
namespace IO {
	int rnt () {
		int x = 0, w = 1; char c = getchar ();
		while (!isdigit (c)) { if (c == '-') w = -1; c = getchar (); }
		while (isdigit (c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar ();
		return x * w;
	}
} // namespace IO
const int N = 2e5 + 10, SN = 1 << 21, inf = 0x3f3f3f3f;
namespace SOLVE {
	using namespace IO;
	int n, m, S, f[SN], tag, ans;
	char s[N][21];
	int G (char* s, char* t) {
		for_ (k, m, 1) {
			bool flag = true;
			_for (i, 1, k)
				flag &= (s[m - k + i] == t[i]);
			if (flag) return k;
		}
		return 0;
	}
	void In () {
		n = rnt ();
		_for (i, 1, n)
			scanf ("%s", s[i] + 1);
		m = strlen (s[1] + 1);
		return;
	}
	void Solve () {
		S = (1 << (m + 1)) - 1;
		memset (f, 0x3f, sizeof (f));
		f[1] = 0, tag = 0;
		_for (i, 1, n) {
			int w = f[1] + tag + m, sta = 1;
			_for (j, 1, m) {
				sta = sta << 1 | (s[i][j] == '1');
				w = std::min (w, f[sta] + tag + m - j);
			}
			tag += m - G (s[i - 1], s[i]);
			if (i > 1) {
				f[1] = std::min (f[1], w - tag);
				sta = 0;
				_for (j, 1, m) {
					sta |= ((s[i - 1][m - j + 1] == '1') << (j - 1));
					f[sta | (1 << j)] = std::min (f[sta | (1 << j)], w - tag);
				}
			}
		}
		ans = inf;
		_for (i, 1, S)
			ans = std::min (ans, f[i] + tag);
		return;
	}
	void Out () {
		printf ("%d\n", ans);
		return;
	}
}
int main () {
#ifndef ONLINE_JUDGE
	freopen ("data.in", "r", stdin);
	// freopen ("data.out", "w", stdout);
#endif
	SOLVE::In ();
	SOLVE::Solve ();
	SOLVE::Out ();
	return 0;
} /*

*/
			   	   	 	    	 	  					