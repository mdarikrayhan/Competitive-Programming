// LUOGU_RID: 160434401
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define For(i, l, r) for (int i = (l); i <= (r); ++i)
const int N = 1e4 + 5;

struct IO{
	char c; int f;
#define gc() (getchar())
	template<class C>
	inline IO& operator >> (C &x) {
		x = 0; f = 1;
		while (!isdigit(c = gc()) && ~c) f |= -!(c ^ 45);
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = gc();
		x *= f; return *this;
	}
	inline bool operator ~ () const { return ~c; }
} io;

struct Edge { int to, id; };
vector<Edge > es[N];
int n, m, cnt, ID, val[N];
bool vis[N], dis[N], did[N];
vector<int > ans;

void dfs0(int u) {
    vis[u] = 1;
    for (auto &[v, id] : es[u]) if (!vis[v]) {
        dis[v] = !dis[u];
        did[id] = 1;
        dfs0(v);
    } else if (!did[id]) {
        did[id] = 1;
        if (dis[u] == dis[v]) {
            cnt++; ID = id;
            val[v]--; val[u]++;
        } else val[v]++, val[u]--;
    }
}

void dfs(int u) {
    vis[u] = 1;
    for (auto &[v, id] : es[u]) if (!vis[v]) {
        dfs(v);
        if (val[v] == cnt) ans.pb(id);
        val[u] += val[v];
    }
}

int main() {
    io >> n >> m;
    int u, v;
    For (i, 1, m) io >> u >> v, es[u].pb({v, i}), es[v].pb({u, i});
    For (i, 1, n) if (!vis[i]) dfs0(i);
    if (!cnt) {
        printf("%d\n", m);
        For (i, 1, m) printf("%d ", i);
        return 0;
    }
    if (cnt == 1) ans.pb(ID);
    memset(vis, 0, sizeof vis);
    For (i, 1, n) if (!vis[i]) dfs(i);
    printf("%d\n", (int)ans.size());
    sort(ans.begin(), ans.end());
    for (auto &x : ans) printf("%d ", x);

    return 0;
}