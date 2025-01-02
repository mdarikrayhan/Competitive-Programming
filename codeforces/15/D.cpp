// LUOGU_RID: 159790061

#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
#include <math.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;


int m, n, a, b;

const int N = 1005;

ll arr[N][N];
ll sum[N][N];

ll get_sum(int i, int j) {
	int ei = i+a-1, ej = j+b-1;
	if (!(ei <= m and ej <= n)) return 0;
	return sum[ei][ej] + sum[i-1][j-1] - sum[ei][j-1] - sum[i-1][ej];
}

struct node {
	int idx;
	ll val;
};


ll mn1[N][N], mn2[N][N];

struct T {
	ll cost;
	int ii, jj;

	bool operator < (const T& o) const {
		if (cost != o.cost) return cost < o.cost;
		if (ii != o.ii) return ii < o.ii;
		return jj < o.jj;
	}
} tt[N*N];


unsigned f[N][N];
int ans[N*N];

int main(void) {
	scanf("%d %d %d %d", &m, &n, &a, &b);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &arr[i][j]);
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i][j] = arr[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}


	deque<node> que;

	for (int row = 1; row <= m; row++) {
		ll* a = arr[row];
		que.clear();

		for (int j = 1; j <= n; j++) {
			while (que.size() and que.back().val >= a[j]) que.pop_back();
			que.push_back({j, a[j]});
			while (que.front().idx <= j-b) que.pop_front();
			if (j-b+1 >= 1) {
				mn1[row][j-b+1] = que.front().val;
			}
		}
	}

	for (int col = 1; col <= n; col++) {
		que.clear();

		for (int i = 1; i <= m; i++) {
			while (que.size() and que.back().val >= mn1[i][col]) que.pop_back();
			que.push_back({i, mn1[i][col]});
			while (que.front().idx <= i-a) que.pop_front();
			if (i-a+1 >= 1) mn2[i-a+1][col] = que.front().val;
		}
	}

	int idx = 0;
	for (int i = 1; i <= m-a+1; i++) {
		for (int j = 1; j <= n - b + 1; j++) {
			tt[idx++] = {get_sum(i, j) - mn2[i][j] * (a * b), i, j};
		}
	}
	sort(tt, tt+idx);

	int cnt = 0;
	for (int x = 0; x < idx; x++) {
		auto& t = tt[x];
		if (f[t.ii][t.jj]) continue;

		ans[cnt++] = x;

		int st_i = max(1, t.ii-a+1);
		int st_j = max(1, t.jj-b+1);
		for (int i = st_i; i <= t.ii+a-1; i++) {
			for (int j = st_j; j <= t.jj+b-1; j++) {
				f[i][j] = 1;
			}
		}
	}

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d %d %lld\n", tt[ans[i]].ii, tt[ans[i]].jj, tt[ans[i]].cost);
	}

	return 0;
}


