// LUOGU_RID: 160453773
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

constexpr int N = 5e5 + 5, K = 55;

struct Edge {
	int u, v, col;
	
	Edge(int _u = 0, int _v = 0, int _c = 0):
		u(_u), v(_v), col(_c) { return; }
};
struct Disjoint {
	int fa[N], dis[N], sz[N];
	vector<int> stk;
	
	void Init(int n) {
		stk.clear();
		for (int i = 1; i <= n; i ++)
			fa[i] = i, sz[i] = 1, dis[i] = 0;
		return;
	}
	int Find(int u) {
		while (fa[u] ^ u) u = fa[u];
		return u;
	}
	int Get_Dis(int u) {
		int ans = 0;
		while (fa[u] ^ u)
			ans ^= dis[u], u = fa[u];
		return ans;
	}
	bool Merge(int u, int v) {
		int du = Get_Dis(u), dv = Get_Dis(v);
		u = Find(u), v = Find(v);
		if (u == v) return false;
		if (sz[u] > sz[v]) swap(u, v);
		stk.emplace_back(u), fa[u] = v;
		dis[u] = du ^ dv ^ 1, sz[v] += sz[u]; return true;
	}
	void Reset() {
		int u = stk.back(), v = fa[u];
		dis[u] = 0, fa[u] = u, sz[v] -= sz[u];
		stk.pop_back(); return;
	}
} D[K];

int n, m, k, q, lst[N];
Edge edge[N];

namespace Segment_Tree {
	pair<int, int> qry[N];
	vector<int> upd[N << 2];
	
	void Update(int l, int r, int id, int p = 1, int L = 1, int R = q) {
		if (l > r) return;
		if (l <= L && R <= r) return upd[p].emplace_back(id), void();
		int Mid = L + R >> 1;
		if (l <= Mid) Update(l, r, id, p << 1, L, Mid);
		if (Mid < r) Update(l, r, id, p << 1 | 1, Mid + 1, R);
		return;
	}
	void Update(int pos, pair<int, int> k) {
		return qry[pos] = k, void();
	}
	void Dfs(int p = 1, int L = 1, int R = q) {
		array<int, K> cnt; int Mid = L + R >> 1;
		for (int i = 1; i <= k; i ++) cnt[i] = 0;
		for (auto id : upd[p]) {
			auto [u, v, col] = edge[id];
			if (col) cnt[col] += D[col].Merge(u, v);
		}
		if (L == R) {
			auto [id, col] = qry[L];
			auto &[u, v, c] = edge[id];
			if (D[col].Find(u) != D[col].Find(v) || D[col].Get_Dis(u) != D[col].Get_Dis(v))
				Puts("YES"), c = col;
			else Puts("NO");
		}
		else Dfs(p << 1, L, Mid), Dfs(p << 1 | 1, Mid + 1, R);
		for (int i = 1; i <= k; i ++)
			while (cnt[i] --) D[i].Reset();
		return;
	}
}

using Segment_Tree::Update;
using Segment_Tree::Dfs;

void slv() {
	n = Read<int>(), m = Read<int>(), k = Read<int>(), q = Read<int>();
	for (int i = 1; i <= m; i ++) {
		int u = Read<int>(), v = Read<int>();
		edge[i] = Edge(u, v, 0);
	}
	for (int i = 1; i <= q; i ++) {
		int id = Read<int>(), col = Read<int>();
		Update(lst[id] + 1, i - 1, id);
		Update(i, {id, col}), lst[id] = i;
	}
	for (int i = 1; i <= m; i ++) Update(lst[i] + 1, q, i);
	for (int i = 1; i <= k; i ++) D[i].Init(n);
	Dfs();
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
