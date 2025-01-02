#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 50010, mod = 1e9 + 7;
int n, m, a[N];
int trie[N * 20][2], cnt[N * 20], tot;
int tr[N * 20][31];

void insert(int x) {
	int p = 0;
	for (int i = 30; i >= 0; i -- ) {
		int c = x >> i & 1;
		if (!trie[p][c]) trie[p][c] = ++ tot;
		p = trie[p][c];
		cnt[p] ++ ;
		for (int k = 30; k >= 0; k -- )
			if (x >> k & 1)
				tr[p][k] ++ ;
	}
}

ll count(int x) {
	ll res = 0;
	for (int i = 1; i <= n; i ++ ) {
		int p = 0;
		for (int j = 30; j >= 0; j -- ) {
			int c = a[i] >> j & 1;
			if (!(x >> j & 1)) {
				res += cnt[trie[p][c ^ 1]];
				p = trie[p][c];
			} else p = trie[p][c ^ 1];
			if (!p) break;
		}
		res += cnt[p];
	}
	return res / 2;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ ) {
		scanf("%d", &a[i]);
		insert(a[i]);
	}
	int l = 0, r = 2e9;
	while (l < r) {
		int mid = ((ll)l + r + 1) / 2;
		if (count(mid) >= m) l = mid;
		else r = mid - 1;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i ++ ) {
		int p = 0;
		for (int j = 30; j >= 0; j -- ) {
			int c = a[i] >> j & 1;
			if (!(l >> j & 1)) {
				ans += 1ll * cnt[trie[p][c ^ 1]] * (1 << j);
				for (int k = j - 1; k >= 0; k -- ) {
					if (a[i] >> k & 1) {
						ans += 1ll * (cnt[trie[p][c ^ 1]] - tr[trie[p][c ^ 1]][k]) * (1 << k);
					} else {
						ans += 1ll * tr[trie[p][c ^ 1]][k] * (1 << k);
					}
				}
				ans += (l & ((1ll << 31) - 1 - ((1 << j) - 1))) * cnt[trie[p][c ^ 1]];
				p = trie[p][c];
			} else {
				p = trie[p][c ^ 1];
			}
			if (!p) break;
		}
		ans += cnt[p] * l;
	}
	ans /= 2;
	ans -= 1ll * (count(l) - m) * l;
	printf("%d\n", ans % mod);
	return 0;
}
