// LUOGU_RID: 160584379
#include <stdio.h>
#include <queue>
#define N 510
#define M 100100

using namespace std;

double p[N][N], pc[N][N];
int cnt[N][N], s1[N], s2[N], Cnt[N][N];
int n, m, c;
int a[N];
int head[N], to[M << 1], nnnnnn[M << 1];
int color[N], C = 0, CC;
int S[M], E[M];
double x[N], y[N];
double tp[N][N], I[N][N], tmp[N][N];
int b[N], rb[N];

void AddEdge(int s, int e, int i) {
	to[i] = e, nnnnnn[i] = head[s], head[s] = i;
}

void BFS(int u) {
	queue <int> q;
	color[u] = C;
	q.push(u);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int i = head[v]; i; i = nnnnnn[i]) {
			int w = to[i];
			if (color[w]) continue;
			if (a[w]) continue;
			color[w] = C;
			q.push(w);
		}
	}
}

void Multi(double a[N][N], double b[N][N], double c[N][N]) {
	for (int i = 1; i <= C; i ++) for (int j = 1; j <= C; j ++) {
		c[i][j] = 0;
		for (int k = 1; k <= C; k ++) c[i][j] += a[i][k] * b[k][j];
	}
}

void Pow(double a[N][N], int b, double c[N][N]) {
	if (!b) {
		for (int i = 1; i <= C; i ++) for (int j = 1; j <= C; j ++) c[i][j] = I[i][j];
		return;
	}
	Pow(a, b / 2, tp);
	Multi(tp, tp, tmp);
	if (b & 1) Multi(tmp, a, c);
	else {
		for (int i = 1; i <= C; i ++) for (int j = 1; j <= C; j ++) c[i][j] = tmp[i][j];
	}
}

int main() {
//	freopen ("D.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &c);
	for (int i = 1; i <= n; i ++) scanf("%d", a + i);
	for (int i = 1; i <= m; i ++) {
		int j, k;
		scanf("%d %d", &j, &k);
		AddEdge(j, k, i);
		AddEdge(k, j, i + m);
		S[i] = j, E[i] = k;
	}
	for (int i = 1; i <= n; i ++) if (!a[i] && !color[i]) C ++, BFS(i);
	CC = C, C = 0;
	for (int i = 1; i <= n; i ++) if (a[i]) b[++ C] = i, rb[i] = C;
	for (int i = 1; i <= m; i ++) {
		int s = S[i], e = E[i];
		if (color[s] && a[e]) {
			int x = color[s], y = rb[e];
			cnt[y][x] ++;
		} else if (a[s] && color[e]) {
			int x = color[e], y = rb[s];
			cnt[y][x] ++;
		} else if (a[s] && a[e]) {
			int x = rb[s], y = rb[e];
			Cnt[x][y] ++, Cnt[y][x] ++;
		}
	}
	for (int i = 1; i <= CC; i ++) {
		s1[i] = 0;
		for (int j = 1; j <= C; j ++) s1[i] += cnt[j][i];
	}
	for (int i = 1; i <= C; i ++) {
		s2[i] = 0;
		for (int j = 1; j <= CC; j ++) s2[i] += cnt[i][j];
		for (int j = 1; j <= C; j ++) s2[i] += Cnt[i][j];
	}
	for (int i = 1; i <= C; i ++) {
		for (int j = 1; j <= C; j ++)  {
			p[i][j] = 0;
			for (int k = 1; k <= CC; k ++) {
				p[i][j] += (1.0 * cnt[i][k] / s2[i]) * (1.0 * cnt[j][k] / s1[k]);
			}
			p[i][j] += 1.0 * Cnt[i][j] / s2[i];
		}
	}
	for (int i = 1; i <= C; i ++) I[i][i] = 1;
	int cc = color[1];
	for (int i = 1; i <= C; i ++) {
		x[i] = 1.0 * cnt[i][cc] / s1[cc];
	}

	c -= 2;
	Pow(p, c, pc);

	for (int i = 1; i <= C; i ++) {
		y[i] = 0;
		for (int j = 1; j <= C; j ++) y[i] += x[j] * pc[j][i];
	}
	printf("%.10lf\n", y[rb[n]]);
}
