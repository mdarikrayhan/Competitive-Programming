#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
typedef pair<ll, ll> pii;
const int maxn = 5e5 + 5, mod = 998244353, maxp = 25, inf = 1e9;
const ll INF = 1e18;

struct node {
	int x, y, t, idx;
}a[maxn];

int n, k;

int s[maxn], tx[maxn];

int find(int x) {
	if (s[x] != x) return s[x] = find(s[x]);
	return s[x];
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		s[x] = y;
	}
}

bool cmpx(node u, node v) {
	if (u.x - v.x) return u.x < v.x;
	return u.y < v.y;
}

bool cmpy(node u, node v) {
	if (u.y - v.y) return u.y < v.y;
	return u.x < v.x;
}

bool check(int x) {
	int ct = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] != i) continue;
		if (tx[i] > x) ct++;
	}
	return ct <= x + 1;
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].t;
		a[i].idx = i;
		s[i] = i;
		tx[i] = a[i].t;
	}
	sort(a + 1, a + 1 + n, cmpx);
	for (int i = 2; i <= n; i++) {
		if (a[i].x != a[i - 1].x) continue;
		if (a[i].y - a[i - 1].y <= k) {
			merge(a[i].idx, a[i - 1].idx);
		}
	}
	sort(a + 1, a + 1 + n, cmpy);
	for (int i = 2; i <= n; i++) {
		if (a[i].y != a[i - 1].y) continue;
		if (a[i].x - a[i - 1].x <= k) {
			merge(a[i].idx, a[i - 1].idx);
		}
	}
	for (int i = 1; i <= n; i++) {
		int fa = find(a[i].idx);
		tx[fa] = min(tx[fa], a[i].t);
	}
	int l = 0, r = n;
	int ans = n;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt = 1;
	cin >> tt;
	while (tt--) solve();
	return 0;
}