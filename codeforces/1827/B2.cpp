// LUOGU_RID: 159948161
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(tar) tar.begin(),tar.end()
#define pii pair<int,int>
#define AC return 0;
int n, m, t;
const int maxx = 1e6 + 5;
const int mod = 1e9 + 7;
int a[maxx], f[maxx][20];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			f[i][0] = a[i];
		}
		for (int k = 1; k <= 19; k++) {
			for (int i = 1; i + (1 << (k - 1)) <= n; i++) {
				f[i][k] = max(f[i][k - 1], f[i + (1 << (k - 1))][k - 1]);
			}
		}
		vector<int>r(n + 1, n + 1);
		vector<int>l(n + 1);
		stack<int>st;
		st.push(n + 1);
		a[n + 1] = -1e18;
		int ans = 0;
		for (int i = n; i >= 1; i--) {
			while (!st.empty() && a[st.top()] > a[i]) {
				st.pop();
			}
			ans += (0 + n - i) * (n - i + 1) / 2;
			r[i] = st.top();
			st.push(i);
		}
		//a[i]是最小值 x第一个小与a[i]的位置，r是第一个小于a[i]的右边的
//		cout << ans << '\n';
		while (!st.empty())st.pop();
		a[0] = -1e18;
		st.push(0);
		for (int i = 1; i <= n; i++) {
			while (!st.empty() && a[st.top()] > a[i])st.pop();
			l[i] = st.top();
			st.push(i);
			int j = l[i];
			for (int k = 19; k + 1; k--) {
				if (j > (1 << k) && f[j - (1 << k)][k] < a[i])j -= (1 << k);
			}
//			cout << l[i] << " " << r[i] << " " << j << '\n';
			if (l[i] > 0)ans -= (r[i] - i) * (l[i] - j + 1);
		}
		cout << ans << '\n';
	}
	AC
}