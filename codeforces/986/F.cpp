// LUOGU_RID: 159226408
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005, MAXM = 40000005;
long long n[MAXN], k[MAXN], kvc[MAXN];
vector<long long> kp[55];
int pr[MAXM / 10], ptot; bool tag[MAXM];
long long dis[55][100005]; vector<pair<int, long long> > G[100005]; bool vis[100005];
int qkpow(int a, int b, int mod) {
//	printf("qkpow %d %d %d\n", a, b, mod);
	int ans = 1; for (; b; b >>= 1, a = 1ll * a * a % mod) if (b & 1) ans = 1ll * ans * a % mod; return ans;
}
int main() {
	for (int i = 2; i <= 40000000; i++) {
		if (tag[i] == 0) pr[++ptot] = i;
		for (int j = 1; j <= ptot && i * pr[j] <= 40000000; j++) {
			tag[i * pr[j]] = 1; if (i % pr[j] == 0) break;
		}
	}
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%lld %lld", &n[i], &k[i]); kvc[i] = k[i];
	}
	sort(kvc + 1, kvc + t + 1); int m = unique(kvc + 1, kvc + t + 1) - kvc - 1;
	for (int i = 1; i <= m; i++) {
		long long K = kvc[i];
		for (int j = 1; j <= ptot && 1ll * pr[j] * pr[j] <= K; j++) {
			if (K % pr[j] == 0) {
				kp[i].push_back(pr[j]);
				while (K % pr[j] == 0) K /= pr[j];
			}
		}
		if (K > 1) kp[i].push_back(K);
//		for (long long x : kp[i]) printf("%lld\n", x);
		if (kp[i].size() >= 3) {
			memset(dis[i], 0x3f, sizeof dis[i]);
			memset(vis, 0, sizeof vis);
			for (int j = 0; j < kp[i][0]; j++) G[j].clear();
			for (int j = 1; j < (int)kp[i].size(); j++) {
				for (int k = 0; k < kp[i][0]; k++) G[k].push_back({(k + kp[i][j]) % kp[i][0], kp[i][j]});
			}
			dis[i][0] = 0;
			priority_queue<pair<int, long long>, vector<pair<int, long long> >, greater<pair<int, long long> > > pq;
			pq.push({0, 0}); while (pq.empty() == 0) {
				int u = pq.top().second; pq.pop(); if (vis[u]) continue;
				vis[u] = 1; for (auto v : G[u]) if (dis[i][v.first] > dis[i][u] + v.second) {
					pq.push({dis[i][v.first] = dis[i][u] + v.second, v.first});
				}
			}
		}
	}
	for (int i = 1; i <= t; i++) {
		k[i] = lower_bound(kvc + 1, kvc + m + 1, k[i]) - kvc;
		if (kp[k[i]].size() == 0) puts("NO");
		else if (kp[k[i]].size() == 1) puts(n[i] % kvc[k[i]] ? "NO" : "YES");
		else if (kp[k[i]].size() == 2) puts(n[i] % kp[k[i]][0] * qkpow(kp[k[i]][1] % kp[k[i]][0], kp[k[i]][0] - 2, kp[k[i]][0]) % kp[k[i]][0] * kp[k[i]][1] <= n[i] ? "YES" : "NO");
		else puts(dis[k[i]][n[i] % kp[k[i]][0]] <= n[i] ? "YES" : "NO");
	}
}
/*
1
952769774260879484 282726514981201
*/