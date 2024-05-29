# include <iostream>
# include <cstdio>
# include <cmath>
# include <algorithm>
# include <cstring>
# include <vector>
# include <map>
# include <assert.h>
# include <unordered_map>
using namespace std;
const int ms = 5.1e6;
const int mp = 9;
const int mn = 2e5;
int group[ms];
vector<int> nums[ms];
int c, d[1 << mp];
int last[mn][mp + mp];

void gen(int on, vector<int> &p, int v) {
	if (on == p.size()) {
		d[c++] = v;
	} else {
		gen(on + 1, p, v);
		gen(on + 1, p, v * p[on]);
	}
}
int n, q;
int table[ms][mp];
bool np[ms];

int main() {
	cin >> n >> q;
	for (int i = 1; i < ms; i++) {
		group[i] = 1;
	}
	for (int i = 2; i < ms; i++) {
		if (!np[i]) {
			for (int j = i; j < ms; j += i) {
				int e = 0;
				int x = j;
				while (x % i == 0) {
					x /= i;
					e++;
				}
				if (e & 1) {
					group[j] *= i;
					nums[j].push_back(i);
				}
				np[j] = true;
			}
		}
	}
	memset(table, -1, sizeof table);
	memset(last, -1, sizeof last);
	for (int i = 1; i <= n; i++) {
		int v;
		scanf("%d", &v);
		v = group[v];
		c = 0;
		gen(0, nums[v], 1);
		for (int j = 0; j < mp + mp; j++) {
			last[i][j] = last[i-1][j];
		}
		for (int j = 0; j < c; j++) {
			int lul = d[j];
			for (int k = 0; k < mp; k++) {
				if (table[lul][k] == -1) continue;
				int cost = int(nums[v].size()) - 2 * int(nums[lul].size()) + k;
				last[i][cost] = max(last[i][cost], table[lul][k]);
			}
			table[lul][nums[v].size()] = i;
		}
		for (int j = 1; j < mp + mp; j++) {
			last[i][j] = max(last[i][j - 1], last[i][j]);
		}
	}
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		int ans = 0;
		while (last[r][ans] < l) ans++;
		printf("%d\n", ans);
	}
	return 0;
}