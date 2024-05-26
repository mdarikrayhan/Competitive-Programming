#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int t[n][2];
	memset(t, 0, sizeof t);
	for (int i = 0; i < n; i++) {
		int a, x;
		cin >> a >> x;
		a--;
		t[a][x]++;
	}
	vector<int> v[n + 1];
	for (int i = 0; i < n; i++) {
		if (t[i][0] + t[i][1] == 0) continue;
		v[t[i][0] + t[i][1]].push_back(t[i][1]);
	}
	priority_queue<int> pq;

	int ans1 = 0, ans2 = 0;
	for (int i = n; i >= 0; i--) {
		for (int x: v[i])	pq.push(x);
		if (!pq.size()) continue;
		ans1 += i;
		ans2 += min(pq.top(), i);
		pq.pop();
	}

	cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
