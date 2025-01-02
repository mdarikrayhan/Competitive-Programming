// LUOGU_RID: 160473297
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair <int, int> Pii;
const int N = 3e5 + 5, Lg = 26, inf = 1e18;
struct Edge {int u, v, w;} op[N];
int n, q, dep[N << 1], wt[N << 1], pr[N << 1], idx, fa[N << 1][Lg + 1], ch[N << 1][2], dfn[N << 1], tim, Mp[N << 1];
inline bool operator < (Edge x, Edge y) {return x.w < y.w;}
inline int find(int u) {return pr[u] == u ? pr[u] : pr[u] = find(pr[u]);}
inline void Kruskal() {
	sort(op + 1, op + n); idx = n;
	for(int i = 1; i <= (n << 1); ++ i) pr[i] = i;
	for(int i = 1; i < n; ++ i) {
		int u = find(op[i].u), v = find(op[i].v), w = op[i].w;
		pr[u] = pr[v] = fa[u][0] = fa[v][0] = ++ idx;
		ch[idx][0] = u, ch[idx][1] = v, wt[idx] = w;
	}
}
inline void dfs(int u) {
	Mp[dfn[u] = ++ tim] = u, dep[u] = dep[fa[u][0]] + 1;
	for(int i = 1; i < Lg; ++ i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	if(ch[u][0]) dfs(ch[u][0]); if(ch[u][1]) dfs(ch[u][1]);
}
inline int Lca(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	for(int i = Lg - 1; ~i; -- i) if(dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	if(u == v) return u;
	for(int i = Lg - 1; ~i; -- i) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
class seg {
	private:
		int Mx[N << 2], Mn[N << 2], sMx[N << 2], sMn[N << 2], tag[N << 2];
		inline int lft(int cur) {return cur << 1;}
		inline int rgt(int cur) {return cur << 1 | 1;}
		inline void Pushup(int cur) {Mx[cur] = max(Mx[lft(cur)], Mx[rgt(cur)]), Mn[cur] = min(Mn[lft(cur)], Mn[rgt(cur)]);}
		inline void PushupS(int cur) {sMx[cur] = max(sMx[lft(cur)], sMx[rgt(cur)]), sMn[cur] = min(sMn[lft(cur)], sMn[rgt(cur)]);}
		inline void Pushtag(int cur, int w) {Mx[cur] = (w ? sMx[cur] : -inf), Mn[cur] = (w ? sMn[cur] : inf);}
		inline void Pushdown(int cur) {
			if(tag[cur] == -1) return ;
			Pushtag(lft(cur), tag[cur]), Pushtag(rgt(cur), tag[cur]);
			tag[lft(cur)] = tag[rgt(cur)] = tag[cur], tag[cur] = -1;
		}
	public:
		inline void Build(int cur, int l, int r) {
			tag[cur] = -1, Mx[cur] = -inf, Mn[cur] = inf;
			if(l == r) {
				sMx[cur] = sMn[cur] = dfn[l];
				return ;
			}
			int mid = (l + r) >> 1;
			Build(lft(cur), l, mid), Build(rgt(cur), mid + 1, r);
			PushupS(cur);
		}
		inline void Modify(int cur, int l, int r, int L, int R, int w) {
			if(L <= l && r <= R) {
				Pushtag(cur, w), tag[cur] = w;
				return ;
			}
			int mid = (l + r) >> 1; Pushdown(cur);
			if(L <= mid) Modify(lft(cur), l, mid, L, R, w);
			if(R > mid) Modify(rgt(cur), mid + 1, r, L, R, w);
			Pushup(cur);
		}
		inline void Query(int& v1, int& v2) {v1 = Mn[1], v2 = Mx[1];}
}eg;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); cin >> n >> q;
	for(int i = 1; i < n; ++ i) cin >> op[i].u >> op[i].v >> op[i].w;
	Kruskal(), dfs(idx), eg.Build(1, 1, n);
	for(int i = 1, op, l, r, x; i <= q; ++ i) {
		cin >> op;
		if(op == 1) cin >> l >> r, eg.Modify(1, 1, n, l, r, 1);
		else if(op == 2) cin >> l >> r, eg.Modify(1, 1, n, l, r, 0);
		else {
			cin >> x, eg.Query(l, r);
			if(l == inf || (l == dfn[x] && r == dfn[x])) cout << -1 << '\n';
			else cout << wt[Lca(x, Lca(Mp[l], Mp[r]))] << '\n';
		}
	}
	return 0;
}