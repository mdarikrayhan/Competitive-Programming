// LUOGU_RID: 160466784
// 長い夜の終わりを信じながら
// Think twice, code once.
#include <chrono>
#include <random>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define eputchar(c) putc(c, stderr)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(str) fputs(str, stderr), putc('\n', stderr)
using namespace std;

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int randi(int l, int r) {return gen() % (r - l + 1) + l;}

int T, n, m, flag, p[100005], good[100005];
int bak[100005], num[100005];
int timer, dfn[100005], anc[100005];
struct graph {
	int tot, hd[100005];
	int nxt[200005], to[200005];

	void clear(int n) {tot = 0; memset(hd, 0, sizeof(int) * n); return ;}
	void add(int u, int v) {
		nxt[++tot] = hd[u];
		hd[u] = tot;
		to[tot] = v;
		return ;
	}
} g;

void Tarjan(int now) {
	// eprintf("%d\n", now);
	dfn[now] = ++timer;
	bak[now] = 0, num[now] = 0;
	anc[now] = 1;
	for (int i = g.hd[now]; i; i = g.nxt[i])
		if (!dfn[g.to[i]]) {
			Tarjan(g.to[i]);
			num[now] += num[g.to[i]];
			if (!bak[now] || dfn[bak[g.to[i]]] < dfn[bak[now]]) bak[now] = bak[g.to[i]];
		} else if (!anc[g.to[i]]) flag = 0;
		else {
			if (!bak[now] || dfn[g.to[i]] < dfn[bak[now]]) bak[now] = g.to[i];
			num[now]++;
			num[g.to[i]]--;
		}
	anc[now] = 0;
	return ;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		g.clear(n + 5);
		for (int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			g.add(u, v);
		}
		for (int R = 1; R <= 100; R++) {
			int rt = randi(1, n);
			timer = 0;
			for (int i = 1; i <= n; i++) dfn[i] = 0;
			flag = 1;
			// eprintf("%d\n", rt);
			Tarjan(rt);
			if (flag) {
				// for (int i = 1; i <= n; i++) eprintf("%d ", bak[i]);
				// eputs("");
				for (int i = 1; i <= n; i++) p[i] = i, good[i] = 0;
				sort(p + 1, p + n + 1, [](const int &x, const int &y) {return dfn[x] < dfn[y];});
				int nn = 1;
				good[rt] = 1;
				for (int i = 2; i <= n; i++)
					if (num[p[i]] == 1) nn += good[p[i]] = good[bak[p[i]]];
				if (nn < (n + 4) / 5) {puts("-1"); break;}
				for (int i = 1; i <= n; i++)
					if (good[i]) printf("%d ", i);
				puts("");
				break;
			}
		}
		if (!flag) puts("-1");
	}
	return 0;
}