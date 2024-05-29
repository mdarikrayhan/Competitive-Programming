#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#define N_ 101000
using namespace std;
int n, m, Deg[N_], w[N_], Q[N_], Num[N_], K, D[90][N_], vis[N_], On[N_], TP[N_];
vector<int>E[N_];
set<int>Set[N_];
long long S1[N_], S2[N_];
long long res;
void Go(int st, int a) {
	vector<int>T;
	T.push_back(st);
	T.push_back(a);
	while (a > K) {
		for (auto &x : E[a]) {
			if (T[T.size() - 2] != x) {
				T.push_back(x);
				a = x;
				break;
			}
		}
	}
	for (auto &x : T)vis[x] = 1;
	a = *T.begin();
	int b = T.back(), i;
	int len = T.size() - 1;

	int tot = len + D[a][b];

	for (i = 1; i < len; i++) {
		S1[i] = S1[i - 1] + w[T[i]];
		S2[i] = S2[i - 1] + (long long)w[T[i]] * i;
	}

	//inside
	long long ss = 0;
	for (i = 1; i < len; i++) {
		int ed = min(i + tot / 2, len - 1);
		long long s1 = (S2[ed] - S2[i]) - i * (S1[ed] - S1[i]);
		long long s2 = -(S2[len - 1] - S2[ed]) + (tot + i)*(S1[len - 1] - S1[ed]);
		ss += (s1 + s2)*w[T[i]];
	}
	res += ss * 2;

	//outside
	for (i = 1; i < len; i++)On[T[i]] = 1;
	for (i = 1; i <= n; i++) {
		if (On[i])continue;
		int d1 = D[a][i], d2 = D[b][i];
		int u = min((d2 + len - d1) / 2, len - 1);

		long long s1 = S2[u] + d1 * S1[u];
		long long s2 = -(S2[len - 1] - S2[u]) + (d2 + len)*(S1[len - 1] - S1[u]);
		
		res += (s1 + s2)*w[i];

	}
	for (i = 1; i < len; i++)On[T[i]] = 0;

}
void BFS(int st) {
	int head = 0, tail = 0, i;
	for (i = 1; i <= n; i++)D[st][i] = 1e9;
	Q[++tail] = st; D[st][st] = 0;
	while (head < tail) {
		int x = Q[++head];
		for (auto &y : E[x]) {
			if (D[st][y] > D[st][x] + 1) {
				D[st][y] = D[st][x] + 1;
				Q[++tail] = y;
			}
		}
	}
}
int main() {
	int i, a, b;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		Set[a].insert(b);
		Set[b].insert(a);
	}
	int head = 0, tail = 0;
	for (i = 1; i <= n; i++) {
		w[i] = 1;
		Deg[i] = Set[i].size();
		if (Deg[i] == 1)Q[++tail] = i;
	}
	while (head < tail) {
		int x = Q[++head];
		for (auto &t : Set[x]) {
			Set[t].erase(x);
			res += 2ll * (n - w[x])*w[x];
			w[t] += w[x];
			if (Set[t].size() == 1)Q[++tail] = t;
		}
		Set[x].clear();
	}
	int cnt = 0;
	for (i = 1; i <= n; i++)if (Set[i].size() > 2)Num[i] = ++cnt;
	K = cnt;
	for (i = 1; i <= n; i++)if (Set[i].size() == 2)Num[i] = ++cnt;
	for (i = 1; i <= n; i++)TP[Num[i]] = w[i];
	for (i = 1; i <= n; i++) {
		for (auto &t : Set[i]) {
			E[Num[i]].push_back(Num[t]);
		}
		Set[i].clear();
	}
	n = cnt;
	for (i = 1; i <= n; i++)w[i] = TP[i];
	if (!K) K = 2;
	for (i = 1; i <= K; i++) {
		BFS(i);
		for (int j = 1; j <= n; j++)res += (long long)D[i][j] * w[i] * w[j];
	}
	for (i = 1; i <= K; i++) {
		for (auto &x : E[i]) {
			if (x > K && !vis[x]) {
				Go(i, x);
			}
		}
	}
	printf("%lld\n", res/2);
}