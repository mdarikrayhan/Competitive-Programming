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
string s;

void solve() {
	vector<PII> ve1;
	vector<int> ve2, ve3;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			ve1.push_back({i + j, i - j});
			if (s[j] == 'B') {
				ve2.push_back(i + j);
				ve3.push_back(i - j);
			}
		}
	}
	sort(ve2.begin(), ve2.end());
	sort(ve3.begin(), ve3.end());
	int res = INF;
	PII ans;
	for (auto i : ve1) {
		int now = max({abs(i.x - ve2[0]), abs(i.x - ve2.back()), abs(i.y - ve3[0]), abs(i.y - ve3.back())});
		//cout << (i.x + i.y) / 2 << " " << (i.x - i.y) / 2 << ": " << now << endl; 
		if (now < res) {
			res = now;
			ans = {(i.x + i.y) / 2, (i.x - i.y) / 2};
		}
	}
	cout << ans.x + 1 << " " << ans.y + 1 << endl;
}

signed main(void) {
	IOS;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}

