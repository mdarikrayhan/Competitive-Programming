// LUOGU_RID: 160045917
//#pragma GCC optimize(2)
//#pragma GCC optimize(3, "Ofast", "inline")

#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, k, m, a[N];
bool vis[N];

void mymain() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	set <vector <int> > se;
	int mi = 1e9, mx = 0, cnt = 0;
	for (int i = 1; i <= m; i++) {
		int sum = 0;
		vector <int> vec;
		for (int j = 1; j <= n/k; j++) {
			int x; scanf("%d", &x);
			vec.push_back(x);
			vis[x] = true;
			sum += a[x];
		}
		sort(vec.begin(), vec.end());
		if (!se.count(vec)) {
			se.insert(vec), cnt++;
		}
		mi = min(mi, sum);
		mx = max(mx, sum);
	}
	vector <int> vec;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) vec.push_back(a[i]);
	}
	if (cnt < k && (int)vec.size() >= n/k) {
		sort(vec.begin(), vec.end());
		int sum = 0;
		for (int i = 0; i < n/k; i++) sum += vec[i];
		mi = min(mi, sum), mx = max(mx, sum);
		reverse(vec.begin(), vec.end());
		sum = 0;
		for (int i = 0; i < n/k; i++) sum += vec[i];
		mi = min(mi, sum), mx = max(mx, sum);
	}
	printf("%.10lf %.10lf\n", 1.0*mi/(n/k), 1.0*mx/(n/k));
}

void myclear() {
}

int main() {
	int _ = 1;
//	int _; scanf("%d", &_);
	while (_--) mymain(), myclear();
	
	return 0;
}