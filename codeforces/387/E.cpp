#include <algorithm>
#include <iostream>

using namespace std;

const int   N = 1000000;
const int INF = 0x3f3f3f3f;

int aa[N], bb[N], ll[N], rr[N], ii[N];
int ft_max[N], ft_min[N], ft_sum[N];
int n;

void update_max(int i, int a) {
	while (i < n) {
		ft_max[i] = max(ft_max[i], a);
		i |= i + 1;
	}
}

int query_max(int i) {
	int a = -1;
	while (i >= 0) {
		a = max(a, ft_max[i]);
		i &= i + 1, i--;
	}
	return a;
}

void update_min(int i, int a) {
	while (i < n) {
		ft_min[i] = min(ft_min[i], a);
		i |= i + 1;
	}
}

int query_min(int i) {
	int a = n;
	while (i >= 0) {
		a = min(a, ft_min[i]);
		i &= i + 1, i--;
	}
	return a;
}

void update_sum(int i, int a) {
	while (i < n) {
		ft_sum[i] += a;
		i |= i + 1;
	}
}

int query_sum(int i) {
	int a = 0;
	while (i >= 0) {
		a += ft_sum[i];
		i &= i + 1, i--;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a, a--;
		aa[i] = a;
	}
	for (int j = 0; j < m; j++) {
		int b; cin >> b, b--;
		bb[j] = b;
	}
	for (int a = 0; a < n; a++)
		ft_max[a] = -1;
	for (int i = 0, j = 0; i < n; i++)
		if (j < m && aa[i] == bb[j])
			update_max(bb[j++], i);
		else
			ll[i] = query_max(aa[i]) + 1;
	for (int a = 0; a < n; a++)
		ft_min[a] = n;
	for (int i = n - 1, j = m - 1; i >= 0; i--)
		if (j >= 0 && aa[i] == bb[j])
			update_min(bb[j--], i);
		else
			rr[i] = query_min(aa[i]) - 1;
	for (int i = 0; i < n; i++)
		ii[aa[i]] = i;
	for (int j = 0; j < m; j++)
		ii[bb[j]] = -1;
	long long ans = 0;
	for (int a = 0; a < n; a++) {
		int i = ii[a];
		if (i != -1) {
			int l = ll[i];
			int r = rr[i];
			ans += (r - query_sum(r)) - (l - 1 - query_sum(l - 1));
			update_sum(i, 1);
		}
	}
	cout << ans << '\n';
	return 0;
}
