// LUOGU_RID: 159564471
#include <bits/stdc++.h>

#define fir first
#define sec second
#ifdef LOCAL
#define dbg(x) cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';
#define dpi(x, y) cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << " ; " << "the " << #y << " = " << y << '\n';
#define dbgf(fmt, args...) fprintf(stderr, fmt, ##args);
#else
#define dbg(x) void();
#define dpi(x, y) void();
#define dbgf(fmt, args...) void();
#endif

using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using vi = vector<int>;
using vpii = vector<pii>;

bool Mbe;
constexpr int MOD = 998244353;
template<typename T> T add(T a, T b, T p = MOD) { return (a + b >= p) ? (a + b - p) : (a + b); }
template<typename T> T del(T a, T b, T p = MOD) { return (a - b < 0) ? (a - b + p) : (a - b); }
template<typename T> T mul(T a, T b, T p = MOD) { return 1ll * a * b % p; }
template<typename T> T cadd(T &a, T b, T p = MOD) { return a = add(a, b, p); }
template<typename T> T cdel(T &a, T b, T p = MOD) { return a = del(a, b, p); }
template<typename T> T cmul(T &a, T b, T p = MOD) { return a = mul(a, b, p); }
template<typename T> T cmax(T &a, T b) { return a = max(a, b); }
template<typename T> T cmin(T &a, T b) { return a = min(a, b); }

namespace FastIO {
	constexpr int LEN = 1 << 20;
	char in[LEN + 1], out[LEN + 1];
	char *pin = in, *pout = out, *ein = in, *eout = out + LEN;

	char gc() { return pin == ein && (ein = (pin = in) + fread(in, 1, LEN, stdin), ein == in) ? EOF : *pin ++; }
	void pc(char c) { pout == eout && (fwrite(out, 1, LEN, stdout), pout = out); (*pout ++) = c; return; }
	void Flush() { fwrite(out, 1, pout - out, stdout); pout = out; }

	template<typename T> T Read() {
		T x = 0; int f = 1; char ch = gc();
		while (ch < '0' || ch > '9') f = (ch == '-' ? (~f + 1) : f), ch = gc();
		while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = gc();
		return x * f;
	}
	template<typename T> void Write(T x, char c) {
		static char stk[40]; int tp = 0;
		if (x < 0) pc('-'), x = ~x + 1;
		do stk[tp++] = x % 10 + 48, x /= 10; while (x);
		while (tp --) pc(stk[tp]); pc(c); return;
	}
	void Read(char *s) {
		char ch = gc();
		while (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
			(ch >= '0' && ch <= '9'))) ch = gc();
		while ((ch != EOF) && ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
			(ch >= '0' && ch <= '9'))) *s = ch, s ++, ch = gc();
		*s = '\0'; return;
	}
	void Write(char *s) {
		while (*s != '\0') pc(*s), s ++; return;
	}
	void Puts(char *s) {
		Write(s), pc('\n'); return;
	}
}

#define getchar FastIO::gc
#define putchar FastIO::pc
#define Flush FastIO::Flush
#define Read FastIO::Read
#define Write FastIO::Write
#define Puts FastIO::Puts

constexpr int N = 1e5 + 5;
int n, f[N], g[N], ans[N], dir[N], tot;
pair<int, int> edge[N];
vector<tuple<int, int, int> > G[N];
vector<int> stk;

void Dfs1(int u, int fa) {
	for (auto [v, w, id] : G[u]) {
		if (v == fa) continue;
		Dfs1(v, u), f[u] += f[v] + !w;
	}
	return;
}
void Dfs2(int u, int fa) {
	for (auto [v, w, id] : G[u]) {
		if (v == fa) continue;
		g[v] = g[u] - !w + !(w ^ 1);
		Dfs2(v, u);
	}
	return;
}
void Dfs3(int u, int fa) {
	for (auto [v, w, id] : G[u]) {
		if (v == fa) continue;
		if (w) stk.emplace_back(ans[id] = ++ tot);
		else ans[id] = stk.back(), stk.pop_back();
		if (!~w) dir[id] = (u != edge[id].fir);
		Dfs3(v, u), w ? stk.pop_back() : (stk.emplace_back(ans[id]), void());
	}
	return;
}

void slv() {
	n = Read<int>();
	for (int i = 1; i < n; i ++) {
		int u = Read<int>(), v = Read<int>(), w = Read<int>();
		if (w) G[u].emplace_back(v, w, i), G[v].emplace_back(u, w ^ 1, i);
		else G[u].emplace_back(v, -1, i), G[v].emplace_back(u, -1, i);
		edge[i] = make_pair(u, v);
	}
	Dfs1(1, 0), g[1] = f[1], Dfs2(1, 0);
	int rt = 1;
	for (int u = 2; u <= n; u ++)
		if (g[u] < g[rt]) rt = u;
	Dfs3(rt, 0);
	auto write = [&](int id) {
		if (dir[id]) swap(edge[id].fir, edge[id].sec);
		Write(edge[id].fir, ' '), Write(edge[id].sec, ' ');
		Write(ans[id], '\n'); return;
	};
	Write(tot, '\n');
	for (int i = 1; i < n; i ++) write(i);
	return;
}
void clr() {

	return;
}

bool Med;
int main() {
#ifdef LOCAL
	freopen("!in.in", "r", stdin);
	freopen("!out.out", "w", stdout);
	fprintf(stderr, "%.3lf Mb\n", fabs((&Mbe - &Med) / 1048576.0));
#endif
	int T = 1;
//	int T = Read<int>();
	while (T --) slv(), clr();
	Flush();
#ifdef LOCAL
	fprintf(stderr, "%d ms\n", (int)clock());
#endif
	return 0;
}
