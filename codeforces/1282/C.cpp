#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200000 + 5;

struct node {
	int t, p;
} e[N];
int n, m, p, q, T, s[N], ans;
int cnt[2], a, b;

bool cmp(node a, node b) {
	return a.t < b.t;
}

void solve() {
	cnt[1] = cnt[0] = 0;
	ans = 0;
	cin >> n >> T >> a >> b;
	for (int i = 1; i <= n; i++){
		cin >> e[i].p;
		cnt[e[i].p]++;
	}
	for (int i = 1; i <= n; i++) cin >> e[i].t;
	sort(e + 1, e + n + 1, cmp);
	int bit = 0;
	for (int i = 1; i <= n + 1; i++) {
		int tm = e[i].t - 1;
		if (i == n + 1)tm = T;

		if (i - 1)bit += e[i - 1].p ? b : a;
		if (i - 1)cnt[e[i - 1].p]--;

		if (tm >= bit) {
			tm -= bit;
			int tpa = tm / a;
			tpa = min(tpa, cnt[0]);
			int tpb = (tm - tpa * a) / b;
			ans = max(ans, i - 1 + min(cnt[1], tpb) + tpa);
		}
	}
	cout << ans << endl;
}
signed main() {
	cin >> m;
	while (m--)
		solve();
	return 0;
}
    	 	 	 		  		 				    	 		 	