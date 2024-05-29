// LUOGU_RID: 159810658
/*
 * 僕は今 人生の中間だ
 * 風においてかれそうで
 * 必死に喰らいついてる
 * いつもの鐘の音も 窓際に積んだ埃も
 * 教室の匂いだって
 * 絶対忘れてやらないよ
 * いつか死ぬまで何回だって
 * こんなこともあったって 笑ってやんのさ
 *								—— 結束バンド《忘れてやらない》
 */

#include <bits/stdc++.h>
using i64 = long long;

constexpr int inf = 0x3f3f3f3f;
//{{{MinCut
namespace MinCut {
	constexpr int N = 3e5 + 10;
	std::vector<int> G[N];
	struct edge {
		int v;
		int flow, cap;
	} E[N << 1];
	int idx;
	int s, t;
	int tot;
	inline void add(int u, int v, int cap) {
		E[idx] = {v, 0, cap};
		G[u].push_back(idx++);
		E[idx] = {u, 0, 0};
		G[v].push_back(idx++);
	}
	int maxflow = 0;
	int dep[N];
	int cur[N];
	bool bfs() {
		memset(dep + 1, 0x3f, t * sizeof(int));
		std::queue<int> q;
		q.push(s);
		dep[s] = 0, cur[s] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (const int &i : G[u]) {
				auto &[v, flow, cap] = E[i];
				if (dep[v] == inf && cap > flow) {
					cur[v] = 0;
					dep[v] = dep[u] + 1;
					q.push(v);
					if (v == t)
						return true;
				}
			}
		}
		return false;
	}
	int dfs(int u, int resc) {
		if (!resc || u == t)
			return resc;
		int k, flow = 0;
		for (int &i = cur[u]; i < G[u].size(); i++) {
			auto &edg = E[G[u][i]];
			auto &rev = E[G[u][i] ^ 1];
			if (dep[edg.v] == dep[u] + 1 && edg.cap > edg.flow) {
				k = dfs(edg.v, std::min(resc, edg.cap - edg.flow));
				if (!k)
					dep[edg.v] = inf;
				edg.flow += k;
				rev.flow -= k;
				flow += k;
				resc -= k;
				if (!resc)
					return flow;
			}
		}
		return flow;
	}
	void dinic() {
		while (bfs()) {
			maxflow += dfs(s, inf);
		}
	}
	void init(int n, int m) {
		tot = n + m + 10;

	}
	inline int newnode() {
		return ++tot;
	}

	bool type2[N];
	std::pair<std::vector<int>, std::vector<int>> getsol() {
		memset(type2, 0, sizeof(type2));
		std::queue<int> q;
		q.push(s);
		type2[s] = true;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int i = 0; i < G[u].size(); i++) {
				auto &[v, flow, cap] = E[G[u][i]];
				if (cap > flow && !type2[v]) {
					q.push(v);
					type2[v] = true;
				}
			}
		}

		std::vector<int> ans1, ans2;
		for (int u = 1; u <= t; u++) {
			for (int i = 0; i < G[u].size(); i++) {
				auto &[v, flow, cap] = E[G[u][i]];
				if (type2[u] == type2[v])
					continue;
				if (cap == flow) {
					if (v == t)
						ans2.push_back(u);
					else if (u == s)
						ans1.push_back(v);
				}
			}
		}

		return std::make_pair(ans1, ans2);
	}
}
//}}}

constexpr int N = 2e4 + 10;
struct edge {
	int v;
	int id;
} E[N << 1];

int idx;
std::vector<int> G[N];
int n, m;

inline void add(int u, int v, int id) {
	E[idx] = {v, id};
	G[u].push_back(idx++);
};

int dep[N], son[N], siz[N], dfn[N], rnk[N], top[N], fa[N], dfc;
int en[N];
void dfs1(int u) {
	siz[u] = 1;
	dep[u] = dep[fa[u]] + 1;
	for (const int &i : G[u]) {
		const auto &[v, id] = E[i];
		if (v == fa[u])
			continue;
		fa[v] = u;
		en[v] = id;
		dfs1(v);
		siz[u] += siz[v];
		if (siz[son[u]] < siz[v])
			son[u] = v;
	}
}

int prefix[N];
void dfs2(int u, int tp) {
	dfn[u] = ++dfc;
	top[u] = tp;
	rnk[dfc] = u;

	// 前缀优化建图
	prefix[u] = MinCut::newnode();
	MinCut::add(en[u], prefix[u], inf);
	// 注意方向
	if (u != tp)
		MinCut::add(prefix[fa[u]], prefix[u], inf);

	if (son[u])
		dfs2(son[u], tp);
	for (const int &i : G[u]) {
		const auto &[v, id] = E[i];
		if (v == fa[u] || v == son[u])
			continue;
		dfs2(v, v);
	}
}
struct node {
	int l, r;
	int nd;
} tr[N << 2];

void build(int u, int l, int r) {
	tr[u].l = l, tr[u].r = r;
	if (l == r) {
		// 注意这里是编号
		tr[u].nd = en[rnk[l]];
		return ;
	} else {
		tr[u].nd = MinCut::newnode();
		int mid = l + r >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);
		MinCut::add(tr[u << 1].nd, tr[u].nd, inf);
		MinCut::add(tr[u << 1 | 1].nd, tr[u].nd, inf);
	}
}

void TreeLink(int u, int l, int r, int p) {
	if (l <= tr[u].l && tr[u].r <= r) {
		MinCut::add(tr[u].nd, p, inf);
		return ;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)
		TreeLink(u << 1, l, r, p);
	if (r > mid)
		TreeLink(u << 1 | 1, l, r, p);
}

void TreeLink(int l, int r, int p) {
	if (l > r)
		return ;
	TreeLink(1, l, r, p);
}

void LinkEdge(int u, int v, int p) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]])
			std::swap(u, v);
		MinCut::add(prefix[u], p, inf);
		u = fa[top[u]];
	}
	if (dep[u] > dep[v]) {
		std::swap(u, v);
	}
	TreeLink(dfn[u] + 1, dfn[v], p);
}

int main() {
#ifdef HeratinoNelofus
	freopen("input.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> m;
	MinCut::init(n, m);
	en[1] = n;
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		add(u, v, i);
		add(v, u, i);
	}
	dfs1(1);
	dfs2(1, 1);
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;
		// 右部点为居民
		LinkEdge(u, v, i + n);
	}
	MinCut::s = MinCut::newnode(), MinCut::t = MinCut::newnode();
	for (int i = 1; i <= n; i++)
		MinCut::add(MinCut::s, i, 1);
	for (int i = 1; i <= m; i++)
		MinCut::add(i + n, MinCut::t, 1);
	MinCut::dinic();	
	std::cout << MinCut::maxflow << '\n';

	auto [ans1, ans2] = MinCut::getsol();
	std::cout << ans2.size() << ' ';
	// 右边的点要 - n 才是路径编号
	for (const int &x : ans2)
		std::cout << x - n << ' ';
	std::cout << '\n';

	// 写反了……原来边要后输出
	std::cout << ans1.size() << ' ';
	for (const int &x : ans1)
		std::cout << x << ' ';
	std::cout << '\n';
	return 0;
}
