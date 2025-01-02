#include <bits/stdc++.h>
#define x first
#define y second
#define eps 1e-8
#define endl '\n'
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define IOS ios::sync_with_stdio(false);cin.tie(NULL);

using namespace std;
using PII = pair<int, int>;

const int N = 2e5 + 5, M = N << 1, MOD = 1e9 + 7;
int a[N], b[N];
int n, m, k;

bool check(int mid) {
	vector<int> ve;
	for (int i = 1; i <= n; i++) {
		int now = a[i], j = 0;
		while (true) {
			int maxv = now / b[i] + 1;
			j += maxv;
			if (j >= m)
				break;
			now -= b[i] * maxv;
			while (now < 0) {
				ve.push_back(j);
				now += mid;
				if (ve.size() >= m)
					return false;
			}
		}
	}
	sort(ve.begin(), ve.end());
	int now = 0;
	for (auto i : ve)
		if (++now > i)
			return false;
	return true;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	int l = 0, r = 2e12 + 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << (l == 2e12 + 1 ? -1 : l) << endl;
}

signed main(void) {
	IOS;
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}

