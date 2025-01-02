// LUOGU_RID: 160381399
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define int long long
#define mems(x, v) memset(x, v, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double wisdom;

const int N = 2e5 + 5;
struct Edge {int now, nxt, w;} e[N << 1];
int head[N], cur; void add(int u, int v, int w) {e[++cur].now = v, e[cur].nxt = head[u], e[cur].w = w, head[u] = cur;}

int L[N], R[N], dep[N], vec[N], idx, D[N];
void dfs(int u, int fa) {
	vec[L[u] = ++idx] = u, dep[u] = dep[fa] + 1;
	for (int i = head[u], v; i; i = e[i].nxt)
		if ((v = e[i].now) != fa) D[v] = D[u] + e[i].w, dfs(v, u), vec[++idx] = u;
	R[u] = idx;
} namespace ST {
	int lg[N], mn[20][N]; inline int cmp(int x, int y) {return dep[x] < dep[y] ? x : y;}
	void build() {
		lg[0] = -1; for (int i = 1; i <= idx; i++) mn[0][i] = vec[i], lg[i] = lg[i >> 1] + 1;
		for (int j = 1; j <= 18; j++) for (int i = 1; i + (1 << j) - 1 <= idx; i++)
			mn[j][i] = cmp(mn[j - 1][i], mn[j - 1][i + (1 << (j - 1))]);
	} int LCA(int u, int v) {u = L[u], v = L[v]; if (u > v) swap(u, v); int k = lg[v - u + 1]; return cmp(mn[k][u], mn[k][v - (1 << k) + 1]);}
} using namespace ST;

namespace BIT {
	int qdx[N];
	int lowbit(int x) {return x & -x;}
	void update(int i, int k) {for (; i <= idx; i += lowbit(i)) qdx[i] += k;}
	int query(int i) {int ans = 0; for (; i; i -= lowbit(i)) ans += qdx[i]; return ans;}
	void upd(int l, int r, int v) {update(l, v), update(r + 1, -v);}
} using namespace BIT;
int dis(int u, int v) {return BIT::query(L[u]) + BIT::query(L[v]) - 2 * BIT::query(L[LCA(u, v)]);}

namespace SGT {
	#define ls pos << 1
	#define rs pos << 1 | 1
	#define fst first
	#define scd second

	pii tr[N << 2];
	void pushup(int pos) {
		pii ans[6] = {tr[ls], tr[rs], pii(tr[ls].fst, tr[rs].fst), pii(tr[ls].fst, tr[rs].scd), pii(tr[ls].scd, tr[rs].fst), pii(tr[ls].scd, tr[rs].scd)};
		int id = -1; for (int i = 0; i < 6; i++) if (!~id || dis(ans[i].fst, ans[i].scd) > dis(ans[id].fst, ans[id].scd)) id = i; tr[pos] = ans[id];
	} void build(int l, int r, int pos) {
		if (l == r) return tr[pos] = {vec[l], vec[l]}, void();
		int mid = (l + r) >> 1; build(l, mid, ls), build(mid + 1, r, rs), pushup(pos);
	} void update(int l, int r, int pos, int LL, int R) {
		if (LL <= l && r <= R) return; int mid = (l + r) >> 1;
		if (LL <= mid) update(l, mid, ls, LL, R); if (mid < R) update(mid + 1, r, rs, LL, R); pushup(pos);
	}
} int uu[N], vv[N], w[N];
signed main() {
	int n, q, X; scanf("%lld%lld%lld", &n, &q, &X);
	for (int i = 1; i < n; i++) scanf("%lld%lld%lld", &uu[i], &vv[i], &w[i]), add(uu[i], vv[i], w[i]), add(vv[i], uu[i], w[i]);

	dfs(1, 0), build();
	for (int i = 1; i <= idx; i++) BIT::upd(i, i, D[vec[i]]);
	SGT::build(1, idx, 1);

	int lst = 0;
	while (q--) {
		int id, val; scanf("%lld%lld", &id, &val);
		id = (id + lst) % (n - 1) + 1, val = (val + lst) % X;
		int u = uu[id], v = vv[id]; if (dep[u] < dep[v]) swap(u, v);

		BIT::upd(L[u], R[u], val - w[id]), w[id] = val;
		SGT::update(1, idx, 1, L[u], R[u]);
		printf("%lld\n", lst = dis(SGT::tr[1].first, SGT::tr[1].second));
	}
	return 0;
}
