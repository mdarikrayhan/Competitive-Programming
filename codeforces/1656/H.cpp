// LUOGU_RID: 160601946
#include <bits/stdc++.h>
using namespace std;

namespace SOL {

using i64 = long long;
using i128 = __int128_t;
void debug(const char *msg, ...) {
#ifdef CLESIP
    va_list arg;
    static char pbString[512];
    va_start(arg,msg);
    vsprintf(pbString,msg,arg);
    cerr << "[DEBUG] " << pbString << "\n";
    va_end(arg);
#endif    
}
template<typename T, typename L>
bool chkmax(T &x, L y) { if (x < y) return x = y, true; return false; }
template<typename T, typename L>
bool chkmin(T &x, L y) { if (y < x) return x = y, true; return false; }

template<typename T>
void read(T &x) {
	x = 0;
	char ch = cin.get();
	while (!isdigit(ch))
		ch = cin.get();
	while (isdigit(ch))
		x = x * 10 + ch - '0', ch = cin.get();
}

template<typename T>
void output(T x) {
	if (x == 0) {
		cout << 0;
		return;
	}
	static int digit[129];
	int cnt = 0;
	while (x > 0)
		digit[++ cnt] = x % 10, x /= 10;
	for (int i = cnt; i >= 1; i --)
		cout << digit[i];
}

i128 gcd(i128 a, i128 b) {
	return b == 0 ? a : gcd(b, a % b);
} 

i128 lcm(i128 a, i128 b) {
	return a * b / gcd(a, b); 
}

const int N = 1010;
i128 a[N], b[N];
int n, m;
bool vis[2][N];

const int SEG_SIZE = N * 4;
struct SegTree {
	#define lc (x * 2)
	#define rc (x * 2 + 1)
	#define mid ((l + r) >> 1)

	i128 val[SEG_SIZE];

	void pull(int x) {
		val[x] = gcd(val[lc], val[rc]);
	}

	void build(int x, int l, int r, int op, int pos) {
		if (l == r) {
			if (op == 0)
				val[x] = a[pos] / gcd(a[pos], b[l]);
			else
				val[x] = b[pos] / gcd(b[pos], a[l]);
			return;
		}
		build(lc, l, mid, op, pos);
		build(rc, mid + 1, r, op, pos);
		pull(x);
	}

	void change(int x, int l, int r, int p) {
		if (l == r)
			return val[x] = 0, void();
		p <= mid ? change(lc, l, mid, p) : change(rc, mid + 1, r, p);
		pull(x);
	}

	#undef lc
	#undef rc
	#undef mid
} segt[2][N];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		read(a[i]), vis[0][i] = false;
	for (int i = 1; i <= m; i ++)
		read(b[i]), vis[1][i] = false;
	for (int i = 1; i <= n; i ++)
		segt[0][i].build(1, 1, m, 0, i);
	for (int i = 1; i <= m; i ++)
		segt[1][i].build(1, 1, n, 1, i);

	int sze0 = n, sze1 = m;
	while (sze0 > 0 && sze1 > 0) {
		vector<int> del0, del1;
		for (int i = 1; i <= n; i ++)
			if (!vis[0][i] && segt[0][i].val[1] != 1)
				del0.push_back(i), vis[0][i] = true, sze0 --;
		for (int i = 1; i <= m; i ++)
			if (!vis[1][i] && segt[1][i].val[1] != 1)
				del1.push_back(i), vis[1][i] = true, sze1 --;
		if (del0.empty() && del1.empty())
			break;
		for (int x : del0) {
			for (int i = 1; i <= m; i ++)
				if (!vis[1][i])
					segt[1][i].change(1, 1, n, x);
		}
		for (int x : del1) {
			for (int i = 1; i <= n; i ++)
				if (!vis[0][i])
					segt[0][i].change(1, 1, m, x);
		}
	}
	if (sze0 && sze1) {
		cout << "YES\n";
		cout << sze0 << " " << sze1 << "\n";
		for (int i = 1; i <= n; i ++)
			if (!vis[0][i])
				output(a[i]), cout << " ";
		cout << "\n";
		for (int i = 1; i <= m; i ++)
			if (!vis[1][i])
				output(b[i]), cout << " ";
		cout << "\n";
	} else {
		cout << "NO\n";
	}
}

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int tt; cin >> tt;
	while (tt --)
		SOL::solve();
	return 0;
}