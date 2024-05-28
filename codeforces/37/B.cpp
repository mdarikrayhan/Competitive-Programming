// LUOGU_RID: 159592139
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2010;
struct node{
	int p, atk, id, t; 
}a[MAXN];
int t;
int cnt;
int sum_atk;
int vis[MAXN];
int n, hp, max_hp, def;
bool cmp (node x, node y) {
	return x.atk > y.atk;
}
bool cmp2 (node x, node y) {
	return x.t < y.t;
}
bool check (double x, double y, double k) {
	if (x / y * 100.0 <= k) {
		return 1;
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> hp >> def;
	max_hp = hp;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].p >> a[i].atk;
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, cmp);
	for (t = 1; t <= 2010; ++t) {
		hp -= sum_atk;
		hp = min(hp + def, max_hp);
		if (hp <= 0) {
			break;
		}
		for (int i = 1; i <= n; ++i) {
			if (!vis[i] && check(hp, max_hp, a[i].p)) {
				++cnt;
				a[i].t = t;
				vis[i] = 1;
				sum_atk += a[i].atk;
				break;
			}
		}
		if (t == 2000) {
			cout << "NO" << endl;
			return 0;
		}
	}
	sort(a + 1, a + n + 1, cmp2);
	cout << "YES" << endl;
	cout << t - 1 << " " << cnt << endl;
	for (int i = 1; i <= n; ++i) {
		if (a[i].t) {
			cout << a[i].t - 1 << " " << a[i].id << endl;
		}
	}
 	return 0;
}