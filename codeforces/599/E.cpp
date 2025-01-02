#include <bits/stdc++.h>
#define int long long
using namespace std;

#ifndef ONLINE_JUDGE
#include <debug-template.hpp>
#define debug(...) cerr << "[ " << #__VA_ARGS__ << " ]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int u[15], v[15], a[105], b[105], c[105];
int dp[15][(1 << 14)], n, m, q;

int calc (int root, int mask) {
	if (mask == 0) return 1;
	int &res = dp[root][mask];
	if (res != -1) return res;
	res = 0;
	for (int i = 0; i < q; i ++) {
		if (a[i] == root && b[i] == root && c[i] != root) return 0;
		if (a[i] == root && mask & (1ll << b[i]) && c[i] != root) return 0;
		if (b[i] == root && mask & (1ll << a[i]) && c[i] != root) return 0;
	}
	int id = 0;
	for (int i = 0; i < n; i ++) {
		if (mask & (1ll << i)) {
			id = i;
			break;
		}
	}
	for (int s = mask; s > 0; s = mask & (s - 1)) {
		if (s & (1ll << id)) {
			for (int new_root = 0; new_root < n; new_root ++) {
				if (s & (1ll << new_root)) {
					int t = mask ^ s;
					int ans1 = calc(root, t), ans2 = calc(new_root, s ^ (1ll << new_root));
					
					bool f = true;
					for (int i = 0; i < q; i ++) {
						if (c[i] == root) {
							if ((s & (1ll<<a[i])) && (s&(1ll<<b[i]))) {
								f = false;
								break;
							}
						}
						else {
							if ((s&(1ll<<a[i])) && (t&(1ll<<b[i]))) f = false;
							if ((t&(1ll<<a[i])) && (s&(1ll<<b[i]))) f = false;
							if ((s&(1ll<<c[i])) && ((t&(1ll<<a[i])) || (t&(1ll<<b[i])))) f = false;
							if ((t&(1ll<<c[i])) && ((s&(1ll<<a[i])) || (s&(1ll<<b[i])))) f = false;
							if (!f) break;
						}
					}
					
					for (int i = 0; i < m; i ++) {
						if ((s&(1ll<<u[i])) && (t&(1ll<<v[i]))) f = false;
						if ((s&(1ll<<v[i])) && (t&(1ll<<u[i]))) f = false;
						if (u[i] == root && v[i] == new_root) continue;
						if (v[i] == root && u[i] == new_root) continue;
						if (u[i] == root && (s&(1ll<<v[i]))) f = false;
						if (v[i] == root && (s&(1ll<<u[i]))) f = false;
						if (!f) break;
					}
					res += f * ans1 * ans2;
				}
			}
		}
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> q;
	for (int i = 0; i < m; i ++) {
		cin >> u[i] >> v[i];
		u[i] --, v[i] --;
	}
	for (int i = 0; i < q; i ++) {
		cin >> a[i] >> b[i] >> c[i];
		a[i] --, b[i] --, c[i] --;
	}
	memset(dp, -1, sizeof(dp));
	cout << calc(0, (1ll << n) - 2) << "\n";
	
	return 0;
}