#include <iostream>
#include <stdio.h>
#include <queue>
#define int long long
using namespace std;

const int maxN = 2e5 + 10;
const int M = 1e9 + 7;

int n;
int len = 0, ne[maxN << 1], to[maxN << 1], fi[maxN];
int in[maxN];
bool cir[maxN];
queue<int> que;

void link(int u, int v) {
	to[++len] = v, ne[len] = fi[u], fi[u] = len;
}

void toposort() {
	for (int i = 1; i <= n; i++) {
		if (!in[i]) {
			que.push(i);
		}
	}
	while (!que.empty()) {
		int p = que.front();
		que.pop();
		cir[p] = 0;
		for (int i = fi[p]; i; i = ne[i]) {
			in[to[i]]--;
			if (!in[to[i]]) {
				que.push(to[i]);
			}
		}
	}
}

int dfs(int p) {
	cir[p] = 0;
	for (int i = fi[p]; i; i = ne[i]) {
		if (cir[to[i]]) {
			return dfs(to[i]) + 1;
		}
	}
	return 1;
}

int qpow(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = res * x % M;
		x = x * x % M;
		y >>= 1;
	}
	return res;
}

signed main(void) {
	scanf("%lld", &n);
	int v;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &v);
		link(i, v), in[v]++;
	}
	
	for (int i = 1; i <= n; i++) cir[i] = 1;
	toposort();
	int sum = 0, temp, ans = 1;
	for (int i = 1; i <= n; i++) {
		if (cir[i]) {
			temp = dfs(i);
			ans = ans * ((qpow(2, temp) - 2 + M) % M) % M;
			sum += temp;
		}
	}
	ans = ans * (qpow(2, n - sum) % M) % M;
	printf("%lld\n", ans);
	return 0;
}
	   	   			     										 		 	