#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(tar) tar.begin(),tar.end()
#define pii pair<int,int>
#define AC return 0;
int n, m, t, c = 0;
const int maxx = 1e6 + 5;
const int mod = 1e9 + 7;
int ask(int x) {
	++c;
	//	assert(c <= 2 * n);
	cout << "? " << x << '\n';
	cin >> x;
	return x;
}
signed main() {
	//	ios::sync_with_stdio(false);
	//	cin.tie(0);
	//	cout.tie(0);
	cin >> t;
	while (t--) {
		c = 0;
		cin >> n;
		vector<int>ans(n + 1);
		for (int i = 1; i <= n; i++) {
			if (ans[i])continue;
			set<int>st;

			vector<int>G;
			int x = ask(i);
			st.insert(x);
			G.push_back(x);
			while (true) {
				int y = ask(i);
				G.push_back(y);
				if (st.count(y)) {
					break;
				}
				st.insert(y);
//				x = y;
			}
			for (int j = 0; j < (int) G.size() - 1; j++) {
			//	cout << G[j] << " ";
				ans[G[j]] = G[j + 1];
			}
			///cout << '\n';
		}
		cout << "! ";
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
	}
	AC
}