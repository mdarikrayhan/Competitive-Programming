// LUOGU_RID: 160512508
#include <bits/stdc++.h>
#define int long long
#define fs first
#define sc second
#define ls (u << 1)
#define rs (u << 1 | 1)
#define mid ((l + r) >> 1)
#define lc ls, l, mid
#define rc rs, mid + 1, r
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define gc getchar
#define pc putchar

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;

const int maxn = 1e6 + 10;
const bool multidata = 0;

int read() {
	int x = 0, f = 1; char c = gc();
	while (c < '0' || c > '9') { if (c == '-') f = -f; c = gc(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = gc();
	return x * f;
}

void write(int x) {
	if (x < 0) pc('-'), x = -x;
	if (x < 10) return void (pc(x + '0'));
	write(x / 10), pc(x % 10 + '0');
}

int n, u, v;
int a[maxn];

bool check(int x) {
	int l = -1e18, r = 1e18;
	per(i, n, 1) {
		if (l <= a[i] && a[i] <= r) {
			l = a[i] - x, r = a[i] + x;
		} else {
			l = max(l, a[i] - x), r = min(r, a[i] + x);
		}
	}
	return (l <= u && u <= r) || (l <= v && v <= r);
}

void fake_main() {
	n = read(), u = read(), v = read();
	rep(i, 1, n) a[i] = read();
	int l = abs(u - v), r = 1e18;
	while (l < r) {
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	write(l), pc('\n');
}

signed main() {
	int T = multidata ? read() : 1;
	while (T--) fake_main();
	return 0;
}
