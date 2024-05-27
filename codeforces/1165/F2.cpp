// LUOGU_RID: 160041443
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], c[N], b[N], n, m, l, r;

vector<int> v[N];

bool CMP(int x, int y) {
	return v[x][b[x]] < v[y][b[y]];
}

bool D(int x) {
	int cnt = 0, tmp = 0, sum = x;
	for (int i = 1; i <= n; i++) {
		b[i] = v[i].size() - 1;
		for (int j = 1; j < v[i].size(); j++) {
			if (v[i][j] > x) {
				b[i] = j - 1;
				break;
			}
		}
	}
	sort (c + 1, c + 1 + n, CMP);
	for (int i = 1; i <= n; i++) {
		int o = v[c[i]][b[c[i]]] - cnt;
		if (a[c[i]] <= o) {
			sum -= a[c[i]], cnt += a[c[i]];
		} else {
		    sum -= o, cnt += o, tmp += (a[c[i]] - o);
		}
	}
	sum -= tmp * 2;
	return sum >= 0;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		c[i] = i, v[i].push_back(0);
	}
	for (int i = 1, x, y; i <= m; i++) {
		cin >> x >> y;
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}
	l = 0, r = 1e6;
	while (l < r) {
		int mid = (l + r) / 2;
		if (D(mid)) {
			r = mid; 
		} else {
			l = mid + 1;
		}
	}
	cout << l;
	return 0;
}