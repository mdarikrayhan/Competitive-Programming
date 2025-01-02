// LUOGU_RID: 159437683
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")

#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair <int, int> pii;

const int N = 200010, O = 1e5;

int n, w, h;
pii ans[N];
struct node {
	int g, p, t, id;
	pii x, y;
} a[N];
vector <int> vec[N];

void mymain() {
	scanf("%d%d%d", &n, &w, &h);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i].g, &a[i].p, &a[i].t);
		vec[a[i].p-a[i].t+O].push_back(i);
		a[i].id = i;
		if (a[i].g == 1) a[i].x = {a[i].p, 0}, a[i].y = {a[i].p, h};
		else a[i].x = {0, a[i].p}, a[i].y = {w, a[i].p};
	}
	vector <node> v1, v2;
	for (int i = 0; i < N; i++) {
		if (vec[i].empty()) continue;
		v1.clear(), v2.clear();
		for (int j : vec[i]) {
			v1.push_back(a[j]), v2.push_back(a[j]);
		}
		sort(v1.begin(), v1.end(), [](const node &a, const node &b) {
			if (a.x.y != b.x.y) return a.x.y > b.x.y;
			return a.x.x < b.x.x;
		});
		sort(v2.begin(), v2.end(), [](const node &a, const node &b) {
			if (a.y.y != b.y.y) return a.y.y > b.y.y;
			return a.y.x < b.y.x;
		});
		for (int j = 0; j < (int)vec[i].size(); j++) {
			ans[v1[j].id] = v2[j].y;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d %d\n", ans[i].x, ans[i].y);
	}
}

void myclear() {
}

int main() {
	int _ = 1;
//	int _; scanf("%d", &_);
	while (_--) mymain(), myclear();
	
	return 0;
}